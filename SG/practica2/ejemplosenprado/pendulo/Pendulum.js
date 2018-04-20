 

/// La clase para un péndulo, preparado para colgarle otro e ir formando una cadena
Pendulum = function (aTime) {
  THREE.Object3D.call (this);

  // private
  
  // En caso de tener un péndulo hijo, se referencia con este atributo
  var child = null;
  // El nodo de donde se colgará el péndulo hijo
  var connection = null;
  // El objeto encargado de la oscilación
  var interpolator = null;
  
  /// El inicializador
  /**
   * @param aTime - El período del péndulo en segundos
   */
  var init = function (self, aTime) {
    // Se recibe el tiempo en segundos y se almacena en milisegundos
    var time = aTime * 1000;
    // La longitud del péndulo. Podría haber sido otro parámetro.
    var length = 7.0; 
    
    // Se implementa el grafo diseñado
    var material = new THREE.MeshPhongMaterial ({color: 0x7d5700, specular: 0xe3c900, shininess: 17});
    var cylinder = new THREE.Mesh (new THREE.CylinderGeometry (length/20,length/20,length), material);
    cylinder.geometry.applyMatrix (new THREE.Matrix4().makeTranslation (0,-length/2,0));
       
    var sphere = new THREE.Mesh (new THREE.SphereGeometry (length/5), material);
    
    sphere.position.y = -length;
    sphere.matrixAutoUpdate = false;
    sphere.updateMatrix();
    
    connection = new THREE.Object3D();
    sphere.add (connection);
    cylinder.add (sphere);
    
    
    var rotationAxis = new THREE.Vector3 (1,0,1).normalize();
    var rotation = { angle: -1 };
    var right = { angle: 1 };
    interpolator = new TWEEN.Tween (rotation).to (right, time)
    .onUpdate (function() {cylinder.quaternion.setFromAxisAngle (rotationAxis, rotation.angle)})
    .easing (TWEEN.Easing.Quadratic.InOut)
    .yoyo (true)
    .repeat (Infinity)
    .start();
    
    self.add (cylinder);
  }
  
  // public
  
  /// Se encadena otro péndulo al final de la cadena de péndulos del que éste forma parte
  /**
   * @param otherPendulum - El péndulo a encadenar
   */
  this.addPendulum = function (otherPendulum) {
    if (child === null) {
      child = otherPendulum;
      connection.add (child);
    } else 
      child.addPendulum (otherPendulum);
  }
  
  /// Se reanuda o detiene la oscilación de un péndulo de la cadena
  /**
   * @param what - Indica sobre qué péndulo concreto se va a operar. 0, el pendulo que recibe el mensaje, 1, el primero de su cadena de hijos, 2, el siguiente y así sucesivamente
   * @param onOff - Indica si se para, false, o si se reanuda, true
   */
  this.startStopPendulum = function (what, onOff) {
    if (what === 0) {
      if (onOff) {
        interpolator.resume();
      } else {
        interpolator.pause();
      }
    } else if (child !== null) {
      child.startStopPendulum (what-1, onOff);
    }
  }
  
  // constructor
  
  init (this, aTime);
}

Pendulum.prototype = Object.create (THREE.Object3D.prototype);
Pendulum.prototype.constructor = Pendulum;
