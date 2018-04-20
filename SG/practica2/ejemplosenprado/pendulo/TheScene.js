
/// Clase fachada, la escena
TheScene = function (renderer) {
  THREE.Scene.call (this);
  
  // private
  
  var ambientLight = null;
  var spotLight = null;
  var camera = null;
  // El objeto que permite interactuar con la cámara
  var trackballControls = null;
  var axis = null;
  var pendulum = null;
  
  /// Se crea la cámara, es necesario el renderer para interactuar con ella
  /**
   * @param renderer - El renderer que muestra la imagen y al mismo tiempo captura la interacción del usuario
   */
  var createCamera = function (self, renderer) {
    // Se define una cámara en perspectiva, con un ángulo de visión de 45 grados,
    // Un ratio de aspecto según las dimensiones de la ventana
    // Y unos planos de recorte cercano y lejano
    camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 1000);
    
    // Dónde se sitúa y hacia donde mira
    camera.position.set (30, 30, 30);
    var look = new THREE.Vector3 (0,0,0);
    camera.lookAt(look);
    
    // El objeto que permite orbitar la cámara, reencuadrarla y hacer zoom
    trackballControls = new THREE.TrackballControls (camera, renderer);
    trackballControls.rotateSpeed = 5;
    trackballControls.zoomSpeed = -2;
    trackballControls.panSpeed = 0.5;
    trackballControls.target = look;
  }
  
  /// Se crean las luces y se añaden a la escena
  var createLights = function (self) {
    // Una ambiental
    ambientLight = new THREE.AmbientLight(0x0c0c0c);
    self.add (ambientLight);
    
    // Una focal
    spotLight = new THREE.SpotLight( 0xffffff );
    spotLight.position.set( 60, 60, 40 );
    self.add (spotLight);
  }
  
  /// Se crea el modelo
  /**
   * @return La raiz de la rama del modelo
   */
  var createModel = function () {
    return new Pendulum (Math.random()+1);
  }
  
  /// Inicializador
  /**
   * @param renderer - El renderer donde se visualizará la escena
   */
  var init = function (self, renderer) {
    createLights (self);
    createCamera (self, renderer);
    axis = new THREE.AxisHelper (25);
    self.add (axis);
    pendulum = createModel ();
    self.add (pendulum);
  }
  
  // public

  /// Crea y añade otro péndulo al final de la cadena
  this.addPendulum = function () {
    var otherPendulum = new Pendulum (Math.random()+1);
    pendulum.addPendulum (otherPendulum);
  }
  
  /// Teniendo en cuenta los controles de la GUI se modifica en la escena todo lo necesario. Se realliza mediante mensajes a los objetos que correspondan. Los mensajes al modelo se realizan a través de su fachada.
  this.animate = function (controls) {
    // Se muestran o no los ejes
    if (controls.axis) {
      if (axis.parent === null)
        this.add (axis);
    } else {
      if (axis.parent !== null)
        this.remove (axis);
    }
    // Se regula la intensidad de la luz focal
    spotLight.intensity = controls.lightIntensity;
    // Se detienen o reanudan la oscilación de los pénudlos primero y segundo
    pendulum.startStopPendulum (0, controls.start_first_pendulum);
    pendulum.startStopPendulum (1, controls.start_second_pendulum);
  }
  
  /// Getter de la cámara
  this.getCamera = function () {
    return camera;
  }
  
  /// Getter del controlador de la cámara
  this.getCameraControls = function () {
    return trackballControls;
  }
  
  /// Modifica el ratio de aspecto de la cámara
  /**
   * @param anAspectRatio - El nuevo ratio de aspecto de la cámara
   */
  this.setCameraAspect = function (anAspectRatio) {
    camera.aspect = anAspectRatio;
    camera.updateProjectionMatrix();
  }
  
  /// Detiene o reanuda la oscilación de un péndulo
  /**
   * @param what - Sobre qué péndulo se opera. 0 para el primero de la cadena, 1 para el siguiente y así sucesivamente
   * @param onOff - True para que oscile, false para que se pare
   */
  this.startStopPendulum = function (what, onOff) {
    pendulum.startStopPendulum (what, onOff);
  }
  
  // constructor
  
  init (this, renderer);
}

TheScene.prototype = Object.create (THREE.Scene.prototype);
TheScene.prototype.constructor = TheScene;

