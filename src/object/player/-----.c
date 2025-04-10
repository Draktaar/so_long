
    public class PlayerController : MonoBehaviour
    {
        [HideInInspector] public bool statsFoldout; //To change the scriptablevalues in Editor

        [SerializeField] private Transform _playerContainer = null;

        [SerializeField] private double _accelSpeed = 2f ;
        [SerializeField] private double _maxAirAccel = 75f;
        private double _accelCounter = 0f;
        private double _ignoreCurrentTime;
        private double _ignoreCurrentTimePercent = 0.1f;

        //Variables
        [SerializeField] public PlayerData stats;  //Player statistics to change in the editor
        private BoxCollider2D _collider;  //Player collision box

        //Movement
        public Vector2 frameVelocity = new Vector2();
        private Vector2 _velocity; // Final Velocity given the Time.deltaTime
        private Vector2 _lastVelocity = new Vector2();
        private double _lastX;

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
        public static event Action<bool, double> GroundedChanged;
        public static event Action Jumped;
        public static event Action Turned;

        //StateMachine
        private Action DoActionFixed;
        private Action DoActionNotFixed;

        //Time
        private double _time;

        //Collisions
        private double _frameLeftGrounded = double.MinValue;
        private bool _grounded = false;
        public LayerMask collisionMask;

        private double _horizontalRaySpacing;
        private double _verticalRaySpacing;


        //Jump
        private bool _isDash = true;
        private bool _canJump;
        private bool _canDash;
        private bool _bufferedJumpUsable;
        private bool _endedJumpEarly;
        private bool _coyoteUsable;
        private double _timeJumpWasPressed;

        private bool _isLookingRight = true;
        public bool isDashing;
        private bool _dashEndingWithTime;
        private bool _dashEndingWithGround;
        private double _dashCountdown;

        private WindTotem _windTotem = null;

        private double _gravityModifier;

        //AIRCURRENT RELATED
        private bool _isInAirCurrent;
        public bool ignoreAirCurrent;
        public bool loadedCurrent;
        public bool lockXAxisMovement;
        public bool lockXAxisAndKeepAccel;
        private bool _airSlowdown;
        private double _airSlowdonFriction;
        private double _airBlowBackDirection;
        public bool enteredCurrent;
        public bool reseted;
        public bool quickChaine;
        private double _maxAirSpeed;

        private Vector2 _currentAirDirection;
        private Vector2 _lastAirDirection;
        private double _airCurrentSpeed;
        private double _lastAirSpeed;
        private double _lastMaxAirSpeed;
        public AirCurrent touchedCurrent = null;
        private bool HasBufferedJump => _bufferedJumpUsable && _time < _timeJumpWasPressed + stats.jumpBufferTime;
        private bool CanCoyote => _coyoteUsable && !_grounded && _time < _frameLeftGrounded + stats.coyoteTime;

        public static UnityEvent _event = new UnityEvent();

        private bool _groundedVisual;

        //Death+
        public bool isDead = false;
        private double _percentDeathTravel;
        [Range(0.1f, 3f)]
        [SerializeField] private double _speedDeath;
        [SerializeField] public Vector2 restartPos;
        [SerializeField] private double _timeBeforeTravel = .1f;
        private List<Interactif> _tempListCollectibles = new List<Interactif>();


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

        private void DoActionPlayFixed()
        {
            CheckCollisions();
            
            HandleDirection();
            HandleDash();
            HandleGravity();
            HandleJump();

            ApplyMovement();
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
                double lInAirGravity = stats.fallAcceleration * stats.gravityModifier;
                if (_endedJumpEarly && frameVelocity.y > 0) lInAirGravity *= stats.jumpEndGravityMultiplier;
                frameVelocity.y = Mathf.MoveTowards(frameVelocity.y, -stats.maxFallSpeed, lInAirGravity * Time.fixedDeltaTime);
            }
        }

        //JUMP
        private void HandleJump()
        {
            if (!_endedJumpEarly && !_grounded && _playerInput.jumpHeld && frameVelocity.y > 0)
                _endedJumpEarly = true;
            if (!_canJump && !HasBufferedJump)
                return;
            if (_grounded || CanCoyote || _collisions.climbingSlope)
                Jump();
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
            double lScale = _isLookingRight ? 1 : -1;
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

        //MOVEMENT
        private void HandleDirection()
        {
            if (isDashing)
                return;
            if (_playerInput.move.x == 0)
            {
                double lDeceleration = _grounded ? stats.groundDecceleration : stats.airDecceleration;
                frameVelocity.x = Mathf.MoveTowards(frameVelocity.x, 0, lDeceleration * Time.fixedDeltaTime);
            }
            else
            {
                bool lCheck = _playerInput.move.x > 0 ? true : false;
                if (lCheck != _isLookingRight) Turned?.Invoke();
                _isLookingRight = lCheck;

                frameVelocity.x = Mathf.MoveTowards(frameVelocity.x, _playerInput.move.x * stats.maxSpeed, stats.acceleration * Time.fixedDeltaTime);
            }
        }
        private void ApplyMovement()
        {
            _velocity = frameVelocity * Time.deltaTime;
            UpdateRaycastOrigins();
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
            double lDirectionY = Mathf.Sign(pVelocity.y);
            double lRayLength = Mathf.Abs(pVelocity.y) + stats.skinWidth;
            double lCounterHit = 0;

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
                double lDirectionX = Mathf.Sign(pVelocity.x);
                lRayLength = Mathf.Abs(pVelocity.x) + stats.skinWidth;
                Vector2 lRayOrigin = ((lDirectionX == -1) ? _raycastOrigins.bottomLeft : _raycastOrigins.bottomRight) + Vector2.up * pVelocity.y;
                RaycastHit2D lHit = Physics2D.Raycast(lRayOrigin, Vector2.right * lDirectionX, lRayLength, collisionMask);

                if(lHit)
                {
                    double lSlopeAngle = Vector2.Angle(lHit.normal, Vector2.up);
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
            double lDirectionX = Mathf.Sign(pVelocity.x);
            double lRayLength = Mathf.Abs(pVelocity.x) + stats.skinWidth;

            for (int i = 0; i < stats.collisionPrecision; i++)
            {
                Vector2 lRayOrigin = (lDirectionX == -1) ? _raycastOrigins.bottomLeft : _raycastOrigins.bottomRight;
                lRayOrigin += Vector2.up * (_horizontalRaySpacing * i);
                RaycastHit2D lHit = Physics2D.Raycast(lRayOrigin, Vector2.right * lDirectionX, lRayLength, collisionMask);
                Debug.DrawRay(lRayOrigin, Vector2.right * lDirectionX * lRayLength, Color.red);

                if (lHit && !lHit.collider.CompareTag("InteractivObject") && !lHit.collider.CompareTag("Travers"))
                {
                    double lSlopeAngle = Vector2.Angle(lHit.normal, Vector2.up);

                    if (i == 0 && lSlopeAngle <= stats.maxClimbAngle)
                    {
                        if (_collisions.descendingSlope)
                        {
                            _collisions.descendingSlope = false;
                            pVelocity = _collisions.velocityOld;
                        }
                        double lDistanceToSlopeSart = 0;
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

        public void ResetPos(Vector2 pPos)
        {
            transform.position = pPos;
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
        public double slopeAngle, slopeAngleOld;
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