
renderer = null;
scene = null;
GUIcontrols = null;
stats = null;

/// Función que se llama para dibujar cada frame
function render() {
  stats.update();
  // La propia función se encola a sí misma para el siguiente render
  requestAnimationFrame(render);

  // Se actualiza la posición de la cámara
  scene.getCameraControls().update ();

  // Se dibuja la escena
  renderer.render(scene, scene.getCamera());

  // Se realizan los cambios para el siguiente frame
  scene.animate(GUIcontrols);

  // Si se tienen animaciones con TWEEN hay que actualizarlas
  TWEEN.update();
}

/// Se construye el renderer basado en WebGL
function createRenderer () {
  var renderer = new THREE.WebGLRenderer();
  renderer.setClearColor(new THREE.Color(0xEEEEEE), 1.0);
  renderer.setSize(window.innerWidth, window.innerHeight);
  return renderer;
}

/// El  DOM  que muestra estadística
function initStats() {

  var stats = new Stats();

  stats.setMode(0); // 0: fps, 1: ms

  // Alineación top-left
  stats.domElement.style.position = 'absolute';
  stats.domElement.style.left = '0px';
  stats.domElement.style.top = '0px';

  $("#Stats-output").append( stats.domElement );

  return stats;
}

/// Se crea la GUI
function createGUI (withStats) {
  /// Se crea la interfaz y se le añaden controles
  var gui = new dat.GUI();

  /// Todos los controles de la interfaz son 'variables' de una función
  GUIcontrols = new function() {
    var secondPendulum = false;
    // Las variables booleanas son checkbox
    this.axis = true;
    this.start_first_pendulum = true;
    this.start_second_pendulum = true;
    // Los numéricas son deslizadores
    this.lightIntensity = 0.5;
    // Las funciones son botones. Al pulsar el botón se ejecuta la función
    this.add_pendulum = function () {
      scene.addPendulum ();
      if (! secondPendulum) {
        secondPendulum = true;
        gui.add(GUIcontrols, 'start_second_pendulum');
      }
    };
  }

  // Ahora se le añaden los controles a la interfaz
  // Lo que va entre las comillas simples debe coincidir con el nombre dado a la variable en la función  GUIcontrols
  gui.add(GUIcontrols, 'axis');
  gui.add(GUIcontrols, 'start_first_pendulum');
  // Si es de tipo deslizador se le puede poner un mínimo y un máximo
  gui.add(GUIcontrols, 'lightIntensity', 0, 1.0);
  gui.add(GUIcontrols, 'add_pendulum');

  if (withStats)
    stats = initStats();
}

/// Función encargada de procesar un cambio de tamaño de la ventana
function onWindowResize () {
  // Se actualiza la cámara
  scene.setCameraAspect (window.innerWidth / window.innerHeight);
  // Y también el renderer
  renderer.setSize (window.innerWidth, window.innerHeight);
}

/// El main
$(function () {

  // Se crea el renderer
  renderer = createRenderer();

  // Se añade la salida del renderer a su elemento html
  $("#WebGL-output").append(renderer.domElement);

  window.addEventListener ("resize", onWindowResize);

  // Se crea la escena
  scene = new TheScene (renderer.domElement);

  // Se crea la GUI, con información estadística
  createGUI(true);

  // El primer render
  render();
});