
    public class PlayerController : MonoBehaviour
    {
        [HideInInspector] public bool statsFoldout; //To change the scriptablevalues in Editor

        [SerializeField] private Transform _playerContainer = null;

        [SerializeField] private float _accelSpeed = 2f ;
        [SerializeField] private float _maxAirAccel = 75f;
        private float _accelCounter = 0f;
        private float _ignoreCurrentTime;
        private float _ignoreCurrentTimePercent = 0.1f;

        //Variables
        [SerializeField] public PlayerData stats;  //Player statistics to change in the editor
        private BoxCollider2D _collider;  //Player collision box

        //Movement
        public Vector2 frameVelocity = new Vector2();
        private Vector2 _velocity; // Final Velocity given the Time.deltaTime
        private Vector2 _lastVelocity = new Vector2();
        private float _lastX;

        //Structs
        private PlayerControllerInput _playerInput;  //Optimisation for controll handling
        private RaycastOrigins _raycastOrigins;
        private CollisionInfo _collisions;

        //Input
        [SerializeField] private InputAction _moveInput;
        [SerializeField] private InputAction _dashInput;
        [SerializeField] private InputAction _jumpInput;
        [SerializeField] private InputAction _jumpHoldInput;

        public Vector2 PlayerInput => _playerInput.move;
        public static event Action<bool, float> GroundedChanged;
        public static event Action Jumped;
        public static event Action Turned;

        //StateMachine
        private Action DoActionFixed;
        private Action DoActionNotFixed;

        //Time
        private float _time;

        //Collisions
        private float _frameLeftGrounded = float.MinValue;
        private bool _grounded = false;
        public LayerMask collisionMask;

        private float _horizontalRaySpacing;
        private float _verticalRaySpacing;


        //Jump
        private bool _isDash = true;
        private bool _canJump;
        private bool _canDash;
        private bool _bufferedJumpUsable;
        private bool _endedJumpEarly;
        private bool _coyoteUsable;
        private float _timeJumpWasPressed;

        private bool _isLookingRight = true;
        public bool isDashing;
        private bool _dashEndingWithTime;
        private bool _dashEndingWithGround;
        private float _dashCountdown;

        private WindTotem _windTotem = null;

        private float _gravityModifier;

        //AIRCURRENT RELATED
        private bool _isInAirCurrent;
        public bool ignoreAirCurrent;
        public bool loadedCurrent;
        public bool lockXAxisMovement;
        public bool lockXAxisAndKeepAccel;
        private bool _airSlowdown;
        private float _airSlowdonFriction;
        private float _airBlowBackDirection;
        public bool enteredCurrent;
        public bool reseted;
        public bool quickChaine;
        private float _maxAirSpeed;

        private Vector2 _currentAirDirection;
        private Vector2 _lastAirDirection;
        private float _airCurrentSpeed;
        private float _lastAirSpeed;
        private float _lastMaxAirSpeed;
        public AirCurrent touchedCurrent = null;
        private bool HasBufferedJump => _bufferedJumpUsable && _time < _timeJumpWasPressed + stats.jumpBufferTime;
        private bool CanCoyote => _coyoteUsable && !_grounded && _time < _frameLeftGrounded + stats.coyoteTime;

        public static UnityEvent _event = new UnityEvent();

        private bool _groundedVisual;

        //Death+
        public bool isDead = false;
        private float _percentDeathTravel;
        [Range(0.1f, 3f)]
        [SerializeField] private float _speedDeath;
        [SerializeField] public Vector2 restartPos;
        [SerializeField] private float _timeBeforeTravel = .1f;
        private List<Interactif> _tempListCollectibles = new List<Interactif>();

        //Visual
        [SerializeField] private Transform _playerVisual;
        [SerializeField] private GameObject _playerSprite;

        //Dash
        [SerializeField] private GameObject _roundSprite;
        [SerializeField] private GameObject _trailAirstreamParent;
        [SerializeField] private ParticleSystem _trailAirSteam_1;
        [SerializeField] private ParticleSystem _trailAirstream2;
        [SerializeField] private ParticleSystem _trailAirStream3;
        [SerializeField] private ParticleSystem _dashSparkParticle;
        [SerializeField] private ParticleSystem _dashHibouShape;

        //DustTrail
        [SerializeField] private ParticleSystem _dustTrailWalking;
        [SerializeField] private ParticleSystem _dustTrailLanding;

        //Death
        [SerializeField] private GameObject _deathMovement;
        [SerializeField] private GameObject _deathSoul;
        //Collectible
        private const string COMMON_COLLECTIBLE_CONTAINER_TAG = "Common";
        private const string RARE_COLLECTIBLE_CONTAINER_TAG = "Rare";


        //Animation
        [SerializeField] private Animator _animator;
        private bool _airAnim = false;


        //INITIALISATION
        private void Awake()
        {
            _collider = GetComponent<BoxCollider2D>();

            _gravityModifier = stats.gravityModifier;
            _dashCountdown = stats.nbDash;
            //Connexions
            Turned += ChangeVisualSide;
            Turned += ImpulseWhenTurn;

            GameManager.OnPause += SetModeVoid;
            GameManager.OnResume += SetModePlay;

        }

        private void Start()
        {
            if (_playerContainer == null) { _playerContainer = transform.parent; }
            transform.parent = _playerContainer;
            CalculateRaySpacing();
            SetModePlay();

            _moveInput.Enable();
            _jumpInput.Enable();
            _jumpHoldInput.Enable();
            _dashInput.Enable();
        }

        private void CalculateRaySpacing()
        {
            Bounds bounds = _collider.bounds;
            bounds.Expand(stats.skinWidth * -2);

            stats.collisionPrecision = Mathf.Clamp(stats.collisionPrecision, 2, int.MaxValue);

            _horizontalRaySpacing = bounds.size.y / (stats.collisionPrecision - 1);
            _verticalRaySpacing = bounds.size.x / (stats.collisionPrecision - 1);
        }


        //StateMachine for Pause
        public void SetModeVoid()
        {
            DoActionFixed = DoActionVoid;
            DoActionNotFixed = DoActionVoid;
            _lastVelocity = frameVelocity;
        }
        private void DoActionVoid() { }
        public void SetModePlay()
        {
            DoActionFixed = DoActionPlayFixed;
            DoActionNotFixed = DoActionPlayNotFixed;
            frameVelocity = _lastVelocity;
            isDead = false;
        }
        private void DoActionPlayFixed()
        {
            CheckCollisions();
            
            HandleDirection();
            HandleDash();
            HandleGravity();
            HandleJump();
            ControlAnimation();

            ApplyMovement();
        }
        private void DoActionPlayNotFixed()
        {
            _time += Time.deltaTime;
            HandleInput();
        }
        public void SetModeDeath()
        {
            _animator.SetInteger("State", 0); //Idle
            DoActionFixed = DoActionDeath;
            _percentDeathTravel = 1 + _timeBeforeTravel;
            GetComponent<Collider2D>().enabled = false;
        }
        private void DoActionDeath()
        {
            if (_percentDeathTravel > 1)
            {
                _percentDeathTravel -= Time.deltaTime;
                if (_percentDeathTravel < 1) _percentDeathTravel = 1;
            }
            else
            {
                transform.position = GetComponent<BezierCurve>().GetPosOnBezier(_percentDeathTravel);

                _percentDeathTravel -= Time.deltaTime * _speedDeath;
                if (_percentDeathTravel < 0)
                {
                    isDead = false;
                    GetComponent<Collider2D>().enabled = true;
                    _deathMovement.SetActive(false);
                    TrailRenderer _trailRenderer = _deathMovement.GetComponent<TrailRenderer>();
                    _trailRenderer.emitting = false;
                    _deathSoul.SetActive(false);
                    _playerSprite.SetActive(true);
                    transform.position = restartPos;
                    SetModePlay();
                    SoundManager.GetInstance.PlaySFX(SoundEvents.GetInstance.playerRespawn, transform.position);
                }
            }
        }

        //For final anim
        public void SetModeFinalAnimA()
        {
            _velocity = Vector3.zero;
            DoActionFixed = DoModeBeforeFinalAnim;
        }
        public void SetModeFinalAnimB()
        {
            _animator.SetInteger("State", 8); //Hand Up
            DoActionFixed = DoActionVoid;
            Invoke(nameof(SetModeFinalAnimC), .5f);
        }
        public void SetModeFinalAnimC()
        {
            _animator.SetInteger("State", 0); //Idle
            Invoke(nameof(StartCredits), 15);
        }
        private void DoModeBeforeFinalAnim()
        {
            CheckCollisions();
            HandleGravity();
            ApplyMovement();
            if (_grounded)
            {
                SetModeFinalAnimB();
            }
        }
        private void StartCredits()
        {
            GameManager.GetInstance.StartCredit();
        }


        public void Pause()
        {
            if (DoActionFixed == DoActionVoid) SetModePlay();
            else
            {
                if (isDead) SetModeDeath();
                else SetModeVoid();
            }
        }

        //FRAME_UPDATES
        private void Update()
        {
            DoActionNotFixed();
        }

        private void FixedUpdate()
        {
            DoActionFixed();
        }

        private void UpdateRaycastOrigins()
        {
            Bounds bounds = _collider.bounds;
            bounds.Expand(stats.skinWidth * -2);

            _raycastOrigins.bottomLeft = new Vector2(bounds.min.x, bounds.min.y);
            _raycastOrigins.bottomRight = new Vector2(bounds.max.x, bounds.min.y);
            _raycastOrigins.topLeft = new Vector2(bounds.min.x, bounds.max.y);
            _raycastOrigins.topRight = new Vector2(bounds.max.x, bounds.max.y);
        }


        //INPUTS
        private void HandleInput()
        {
            _playerInput = new PlayerControllerInput
            {
                jumpDown = _jumpInput.triggered,
                jumpHeld = _jumpHoldInput.triggered,
                dashDown = _dashInput.triggered,
                move = _moveInput.ReadValue<Vector2>()
            };

            if (stats.snapInput) //Makes sure inputs are snapped to 1 or 0, even with joysticks
            {
                _playerInput.move.x = MathF.Abs(_playerInput.move.x) < stats.horizontalDeadZoneThreshold ? 0 : Mathf.Sign(_playerInput.move.x);
                _playerInput.move.y = Mathf.Abs(_playerInput.move.y) < stats.verticalDeadZoneThreshold ? 0 : Mathf.Sign(_playerInput.move.y);
            }

            if (_playerInput.jumpDown)
            {
                _canJump = true;
                _timeJumpWasPressed = _time;
                _event.Invoke();
            }

            if(_playerInput.jumpHeld)
            {
                _endedJumpEarly = true;
            }

            if (_playerInput.dashDown && !isDashing && !_dashEndingWithTime && !_dashEndingWithGround)
            {
                if (_isDash && !isDead)
                {
                    //dash sound here
                    SoundManager.GetInstance.PlaySFX(SoundEvents.GetInstance.PlayerDash, gameObject.transform.position);
                    _canDash = true;
                    if(_playerVisual.localScale.x == -1)
                    {
                        _trailAirstreamParent.transform.rotation = Quaternion.Euler(0,0,180);
                        var velocityOverLifetimeModule = _dashHibouShape.velocityOverLifetime;
                        var RendererModule = _dashHibouShape.GetComponent<ParticleSystemRenderer>(); ;
                        velocityOverLifetimeModule.x = -10;
                        RendererModule.flip = new Vector3(1,0,0) ;
                    }
                    else
                    {
                        _trailAirstreamParent.transform.rotation = Quaternion.Euler(0, 0, 0);
                        var velocityOverLifetimeModule = _dashHibouShape.velocityOverLifetime;
                        var RendererModule = _dashHibouShape.GetComponent<ParticleSystemRenderer>(); ;
                        velocityOverLifetimeModule.x = 10;
                        RendererModule.flip = new Vector3(0, 0, 0);
                    }
                    _roundSprite.SetActive(true);
                    _trailAirSteam_1.Play();
                    _trailAirstream2.Play();
                    _trailAirStream3.Play();
                    _dashSparkParticle.Play();
                    _dashHibouShape.Play();
                }
                else if (_windTotem != null)
                {
                    _windTotem.ActiveTotem();
                    //if (!_tempListCollectibles.Contains(_windTotem))
                    //{
                        _tempListCollectibles.Add(_windTotem);
                    //}
                }
            }
        }

        //GRAVITY
        private void HandleGravity()
        {
            if (isDashing)
                return;
            if (_grounded)
            {
                frameVelocity.y = 0;
            }
            else
            {
                float lInAirGravity = stats.fallAcceleration * stats.gravityModifier;
                if (_endedJumpEarly && frameVelocity.y > 0) lInAirGravity *= stats.jumpEndGravityMultiplier;
                frameVelocity.y = Mathf.MoveTowards(frameVelocity.y, -stats.maxFallSpeed, lInAirGravity * Time.fixedDeltaTime);
            }
        }

        //JUMP
        private void HandleJump()
        {
            if (!_endedJumpEarly && !_grounded && _playerInput.jumpHeld && frameVelocity.y > 0) _endedJumpEarly = true;

            if (!_canJump && !HasBufferedJump) return;

            if (_grounded || CanCoyote || _collisions.climbingSlope) Jump();

            _canJump = false;
        }
        private void Jump()
        {
            _endedJumpEarly = false;
            _timeJumpWasPressed = 0;
            _bufferedJumpUsable = false;
            _coyoteUsable = false;
            frameVelocity.y = stats.jumpPower;
            _groundedVisual = false;
            Jumped?.Invoke();
            SoundManager.GetInstance.PlayJump();
        }

        //DASH AND INTERACT
        private void HandleDash()
        {
            isDashing = true;
            _canDash = false;
            if (_canDash)
                Dash();
            else
                return ;
        }

        private void Dash()
        {
            float lScale = _isLookingRight ? 1 : -1;
            frameVelocity.y = 0;
            _lastX = frameVelocity.x;
            frameVelocity.x = stats.dashPower * lScale;
            Invoke(nameof(EndDash), stats.dashTime);
        }

        private void EndDash()
        {
            if(!_groundedVisual) frameVelocity.x /= stats.airDecelerationMultiplier;
            else frameVelocity.x /= stats.groundDecelerationMultiplier;
            frameVelocity.x += _lastX;
            _dashEndingWithTime = true;
            _dashCountdown--;
            if (_dashCountdown == 0) _dashEndingWithGround = true;
            isDashing = false;
            _roundSprite.SetActive(false);
            Invoke(nameof(DashEnded), stats.timeBtwDashes);
        }

        private void DashEnded() => _dashEndingWithTime = false;

        private void ResetDash() { _dashEndingWithGround = false; _dashCountdown = stats.nbDash; }


        public void DashBecomeInteract(WindTotem pWinTotem)
        {
            _isDash = false;
            _windTotem = pWinTotem;
        }

        public void InteractBecomeDash()
        {
            _isDash = true;
            _windTotem = null;
        }

        //AIRCURRENT
        public void SetInAirCurrent(bool pBool, Vector2 pDirection, float pAirSpeed, bool PExit, float pRefreshRate, float pMaxAirSpeed)
        {
            _isInAirCurrent = pBool;
            _currentAirDirection = pDirection;
            _airCurrentSpeed = pAirSpeed;
            _maxAirSpeed = pMaxAirSpeed;
            enteredCurrent = true;
            if (PExit)
            {
               // ignoreAirCurrent = true;
                //Invoke(nameof(OnAirCurrentExit), stats.airCurrentRefreshRate);
                Invoke(nameof(ResetAirCurrent), pRefreshRate);                
                if (_collisions.above) frameVelocity.y = 0;
                _accelCounter = 0f;
            }
            else
            {
                ignoreAirCurrent = false;
                _lastAirDirection = pDirection;
                _lastAirSpeed = pAirSpeed;
                _lastMaxAirSpeed = pMaxAirSpeed;
            }
        }

        public void SetSlowdown(bool pBool, float pSlowFriction, float pBlowBackDirection)
        {
            _airSlowdown = pBool;
            _airSlowdonFriction = pSlowFriction;
            _airBlowBackDirection = pBlowBackDirection;
        }

        public void OnAirCurrentExit(float pRefreshRate)
        {
            ignoreAirCurrent = true;
            //Invoke(nameof(OnAirCurrentExit), stats.airCurrentRefreshRate);
            Invoke(nameof(ResetAirCurrent), pRefreshRate);
            if (_collisions.above) frameVelocity.y = 0;
        }

        private void ResetAirCurrent()
        {
            ignoreAirCurrent = false;
        }

        //MOVEMENT
        private void HandleDirection()
        {
            if (isDashing)
                return;
            if (_playerInput.move.x == 0)
            {
                float lDeceleration = _grounded ? stats.groundDecceleration : stats.airDecceleration;
                frameVelocity.x = Mathf.MoveTowards(frameVelocity.x, 0, lDeceleration * Time.fixedDeltaTime);
            }
            else
            {
                if(_groundedVisual) //quand il marche et qu'il est par terre
                {
                    OnWalking();
                }
                bool lCheck = _playerInput.move.x > 0 ? true : false;
                if (lCheck != _isLookingRight) Turned?.Invoke();
                _isLookingRight = lCheck;

                frameVelocity.x = Mathf.MoveTowards(frameVelocity.x, _playerInput.move.x * stats.maxSpeed, stats.acceleration * Time.fixedDeltaTime);
            }
        }
        private void ApplyMovement()
        {
            _velocity = frameVelocity * Time.deltaTime;
            if (_airSlowdown && _playerInput.move != Vector2.zero) _velocity *= _airSlowdonFriction;
            else if (_airSlowdown) 
            {
                _velocity.x += _airSlowdonFriction * _airBlowBackDirection ;
            }
            
            UpdateRaycastOrigins();
            _collisions.Reset();
            
            _collisions.velocityOld = _velocity;

            if (_velocity.y < 0)
            {
                DescendSlope(ref _velocity);
            }
            if (_velocity.x != 0)
            {
                HorizontalCollisions(ref _velocity);
            }
            if (_velocity.y != 0)
            {
                VerticalCollisions(ref _velocity);
            }

            transform.Translate(_velocity);
        }

        private void ImpulseWhenTurn()
        {
            frameVelocity.x += stats.turnImpuslion * (_isLookingRight ? -1 : 1);
        }

        //COLLISIONS
        private void CheckCollisions()
        {
            if (!_grounded && _collisions.below) //touche le sol / landing player
            {
                //SoundManager.GetInstance.PlaySFX(SoundEvents.GetInstance.PlayerLanding, transform.position);// tentative landing apr�s jump
                enteredCurrent = false;
                quickChaine = false;
                _grounded = true;
                _coyoteUsable = true;
                _bufferedJumpUsable = true;
                _endedJumpEarly = false;
                GroundedChanged?.Invoke(true, Mathf.Abs(frameVelocity.y));
                ResetDash();
                
            }

            if (_grounded && !_collisions.below)
            {
                _grounded = false;
                _frameLeftGrounded = _time;
                GroundedChanged?.Invoke(true, 0);
                
            }

            if (!_endedJumpEarly && _collisions.above)
            {
                _endedJumpEarly = true;
            }

            if (loadedCurrent)
            {
                if (touchedCurrent.GetComponent<Collider2D>().OverlapPoint(transform.position) && enteredCurrent && !reseted)
                {               
                    if (lockXAxisMovement)
                    {
                        reseted = true;
                        ignoreAirCurrent = false;
                        SetInAirCurrent(true, _lastAirDirection, _lastAirSpeed, false, 0f, _lastMaxAirSpeed);
                    }
                    else if (transform.position.y <= touchedCurrent.resetPos.position.y)
                    {
                        if (quickChaine) enteredCurrent = false;
                        Debug.Log("enterdcurrent" + enteredCurrent);
                        reseted = true;
                        ignoreAirCurrent = false;
                        SetInAirCurrent(true, _lastAirDirection, _lastAirSpeed, false, 0f, _lastMaxAirSpeed);
                    }
                    
                }
            }
        }

        private void VerticalCollisions(ref Vector2 pVelocity)
        {
            float lDirectionY = Mathf.Sign(pVelocity.y);
            float lRayLength = Mathf.Abs(pVelocity.y) + stats.skinWidth;
            float lCounterHit = 0;

            for (int i = 0; i < stats.collisionPrecision; i++)
            {
                Vector2 lRayOrigin = (lDirectionY == -1) ? _raycastOrigins.bottomLeft : _raycastOrigins.topLeft;
                lRayOrigin += Vector2.right * (_verticalRaySpacing * i + pVelocity.x);
                RaycastHit2D lHit = Physics2D.Raycast(lRayOrigin, Vector2.up * lDirectionY, lRayLength, collisionMask);

                Debug.DrawRay(lRayOrigin, Vector2.up * lDirectionY * lRayLength, Color.red);

                if (lHit && !lHit.collider.CompareTag("InteractivObject") && (!(lHit.collider.CompareTag("Travers") && lHit.transform.position.y > transform.position.y)))
                {
                    lCounterHit ++;
                    if(!_groundedVisual)
                    {
                        _groundedVisual = true;
                        if(isDashing || _dashEndingWithTime) frameVelocity.x /= stats.groundDecelerationMultiplier;
                        OnGround();
                    }
                    pVelocity.y = (lHit.distance - stats.skinWidth) * lDirectionY;
                    lRayLength = lHit.distance;

                    if (_collisions.climbingSlope)
                    {
                        pVelocity.x = pVelocity.y / Mathf.Tan(_collisions.slopeAngle * Mathf.Deg2Rad) * Mathf.Sign(pVelocity.x);
                    }

                    _collisions.below = lDirectionY == -1;
                    _collisions.above = lDirectionY == 1;
                    if (_collisions.above && lHit.collider.GetComponent<PlatformDestroy>())
                    {
                        ResetDash();
                    }
                    if (lHit.collider.GetComponent<MovablePlatform>())
                    {
                        transform.parent = lHit.collider.transform;
                    }
                }
                else if ((!lHit || !(lHit.collider.GetComponent<MovablePlatform>())) && transform.parent.GetComponent<MovablePlatform>() && Vector3.Distance(transform.position, transform.parent.position) > 1.5f)
                {
                    transform.parent = _playerContainer;
                }
            }
            if (lCounterHit == 0 && _groundedVisual && !_collisions.climbingSlope && !_collisions.descendingSlope) _groundedVisual = false;
            if (_collisions.climbingSlope)
            {
                float lDirectionX = Mathf.Sign(pVelocity.x);
                lRayLength = Mathf.Abs(pVelocity.x) + stats.skinWidth;
                Vector2 lRayOrigin = ((lDirectionX == -1) ? _raycastOrigins.bottomLeft : _raycastOrigins.bottomRight) + Vector2.up * pVelocity.y;
                RaycastHit2D lHit = Physics2D.Raycast(lRayOrigin, Vector2.right * lDirectionX, lRayLength, collisionMask);

                if(lHit)
                {
                    float lSlopeAngle = Vector2.Angle(lHit.normal, Vector2.up);
                    if (lSlopeAngle != _collisions.slopeAngle)
                    {
                        pVelocity.x = (lHit.distance - stats.skinWidth) * lDirectionX;
                        _collisions.slopeAngle = lSlopeAngle;
                    }
                }
            }
        }

        private void HorizontalCollisions(ref Vector2 pVelocity)
        {
            float lDirectionX = Mathf.Sign(pVelocity.x);
            float lRayLength = Mathf.Abs(pVelocity.x) + stats.skinWidth;

            for (int i = 0; i < stats.collisionPrecision; i++)
            {
                Vector2 lRayOrigin = (lDirectionX == -1) ? _raycastOrigins.bottomLeft : _raycastOrigins.bottomRight;
                lRayOrigin += Vector2.up * (_horizontalRaySpacing * i);
                RaycastHit2D lHit = Physics2D.Raycast(lRayOrigin, Vector2.right * lDirectionX, lRayLength, collisionMask);
                Debug.DrawRay(lRayOrigin, Vector2.right * lDirectionX * lRayLength, Color.red);

                if (lHit && !lHit.collider.CompareTag("InteractivObject") && !lHit.collider.CompareTag("Travers"))
                {
                    float lSlopeAngle = Vector2.Angle(lHit.normal, Vector2.up);

                    if (i == 0 && lSlopeAngle <= stats.maxClimbAngle)
                    {
                        if (_collisions.descendingSlope)
                        {
                            _collisions.descendingSlope = false;
                            pVelocity = _collisions.velocityOld;
                        }
                        float lDistanceToSlopeSart = 0;
                        if (lSlopeAngle != _collisions.slopeAngleOld)
                        {
                            lDistanceToSlopeSart = lHit.distance - stats.skinWidth;
                            pVelocity.x -= lDistanceToSlopeSart * lDirectionX;
                        }
                        ClimbSlope(ref pVelocity, lSlopeAngle);
                        pVelocity.x += lDistanceToSlopeSart * lDirectionX;
                    }

                    if ((!_collisions.climbingSlope || lSlopeAngle > stats.maxClimbAngle) && !isDashing)
                    {
                        pVelocity.x = (lHit.distance - stats.skinWidth) * lDirectionX;
                        lRayLength = lHit.distance;

                        if (_collisions.climbingSlope)
                        {
                            pVelocity.y = Mathf.Tan(_collisions.slopeAngle * Mathf.Deg2Rad) * Mathf.Abs(pVelocity.x);
                        }

                        _collisions.left = lDirectionX == -1;
                        _collisions.right = lDirectionX == 1;
                    }

                    if (_collisions.climbingSlope && _dashCountdown == 0)
                    {
                        ResetDash();
                    }

                    if(isDashing && !lHit.collider.CompareTag("Destroy") && !_collisions.climbingSlope)
                    {
                        _lastX = -pVelocity.x;
                        EndDash();
                    }
                }
            }
        }

        //DEATH RELATED
        public void Death()
        {
            SoundManager.GetInstance.PlaySFX(SoundEvents.GetInstance.PlayerDie, transform.position);
            _deathSoul.SetActive(true);
            _playerSprite.SetActive(false);
            _deathMovement.SetActive(true);
            TrailRenderer _trailRenderer = _deathMovement.GetComponent<TrailRenderer>();
            _trailRenderer.emitting = true;
            isDead = true;
            GetComponent<BezierCurve>().lastPlayerDeathPos = transform.position;
            SetModeDeath();

            foreach (Interactif lTempInteractif in _tempListCollectibles)
            {
                if (lTempInteractif is WindTotem)
                {
                    ((WindTotem)lTempInteractif).ResetWind();
                }
                else if (lTempInteractif is PlatformDestroy)
                {
                    ((PlatformDestroy)lTempInteractif).Reset();
                }
                else if (lTempInteractif is Collectible)
                {
                    SaveManager.RemoveCountValue(SaveManager.CountValuesToSave.CommonCollectiblesCount);                   
                    ((Collectible)lTempInteractif).Reappear();
                    ((Collectible)lTempInteractif).ResetCount();
                }
                else if(lTempInteractif is DestroyableBox)
                {

                }
            }
            SaveManager.AddCountValue(SaveManager.CountValuesToSave.DeathCount);
           // SaveManager.ClearCountValues();
        }

        public void ResetRestartPos(Vector2 pNewRestartPos)
        {
            restartPos = pNewRestartPos;
            _tempListCollectibles = new List<Interactif>();
        }

        public void AddTempCollectible(Interactif pCollectible)
        {
            _tempListCollectibles.Add(pCollectible);
        }

        //COLLECTIBLE RELATED
        private void OnTriggerEnter2D(Collider2D collision)
        {
            if (collision.GetComponent<Collectible>())
            {
                string lCollectibleContainerTag = collision.transform.parent.tag;
                int lIndex = collision.transform.GetSiblingIndex();
                if(lCollectibleContainerTag == COMMON_COLLECTIBLE_CONTAINER_TAG)
                {
                    SaveManager.AddCountValue(SaveManager.CountValuesToSave.CommonCollectiblesCount);
                    SaveManager.ChangeListValue(SaveManager.ListValuesToSave.CommonCollectibles, false, lIndex);
                }
                else if(lCollectibleContainerTag == RARE_COLLECTIBLE_CONTAINER_TAG)
                {
                    SaveManager.AddCountValue(SaveManager.CountValuesToSave.RareCollectiblesCount);
                    SaveManager.ChangeListValue(SaveManager.ListValuesToSave.RareCollectibles, false, lIndex);
                }
            }
        }        

        public void ResetPos(Vector2 pPos)
        {
            transform.position = pPos;
        }

        private void OnDestroy()
        {
            //Connexions
            Turned -= ChangeVisualSide;
            Turned -= ImpulseWhenTurn;
        }
        private void ControlAnimation()
        {
            if (isDashing)
            {
                _animator.SetInteger("State", 2); //dash
            }
            else if (_isInAirCurrent)
            {
                _airAnim = true;
                if (_currentAirDirection.y == 0)
                {
                    _animator.SetInteger("State", 7); //Horizontal air curent
                }
                else if (_currentAirDirection.y != 0)
                {
                    _animator.SetInteger("State", 6); //Vertical air current
                }
            }
            else if (_groundedVisual)
            {
                if (_airAnim)
                {
                    _airAnim = false;
                    _animator.SetInteger("State", 4); //land
                }
                else if (_playerInput.move == Vector2.zero)
                {
                    _animator.SetInteger("State", 0); //idle
                }
                else
                {
                    _animator.SetInteger("State", 1); //walk
                }
            }
            else
            {
                _airAnim = true;
                _animator.SetInteger("State", 5); //Jump Fall
            }
        }
        
        //EDITOR
        private void OnValidate()
        {
            if (stats == null) Debug.LogWarning("No stats given", this);
        }
    }

    #region STRUCTS
    public struct PlayerControllerInput
    {
        public bool jumpDown;
        public bool jumpHeld;
        public bool dashDown;
        public Vector2 move;
    }

    struct RaycastOrigins
    {
        public Vector2 topLeft, topRight;
        public Vector2 bottomLeft, bottomRight;
    }

    public struct CollisionInfo
    {
        public bool above, below;
        public bool left, right;

        public bool climbingSlope;
        public bool descendingSlope;
        public float slopeAngle, slopeAngleOld;
        public Vector2 velocityOld;

        public void Reset()
        {
            above = below = false;
            left = right = false;

            climbingSlope = false;
            descendingSlope = false;

            slopeAngleOld = slopeAngle;
            slopeAngle = 0;
        }
    }
    #endregion