<?php
  include 'database.php';
  class header {
    private $noticia;
    private $seccion;
    private $subseccion;
    private $db;

    public function header($noti = NULL, $sec = NULL, $sub = NULL){
      $this->noticia = $noti;
      $this->seccion = $sec;
      $this->subseccion = $sub;
      $this->db = new base_datos();
    }

    public function mostrarHeader(){
      echo '<span class="centrar-img">
    		<h1>
    		<a href="index.php"><img class="logo-periodico" src="../img/MotionFreak.png"  ALT="MotionFreak"> </a>
    		</h1>
    	</span>

    	<nav>
    		<ul>
    			<li><a href="index.php">Inicio</a></li>';


      $this->db->conectar();

      if(is_null($this->noticia) && is_null($this->seccion) && is_null($this->subseccion)){
        $resultado = $this->db->obtenerMenusPrincipales();
      } elseif(is_null($this->seccion) && is_null($this->subseccion)) {
        $resultado = $this->db->obtenerSubmenusNoticia($this->noticia);
      } elseif(is_null($this->seccion)) {
        $this->seccion = $this->db->obtenerSeccionPadre($this->subseccion);
        $resultado = $this->db->obtenerSubmenusCategoria($this->seccion);
      } else{
          $resultado = $this->db->obtenerSubmenusCategoria($this->seccion);
      }

      $this->db->desconectar();

      $numFilas = mysqli_num_rows($resultado);

      if ($numFilas> 0) {
         while ( $fila = $resultado->fetch_array() ) {
          if(is_null($this->seccion) && is_null($this->noticia)){
            echo '<li><a href="index.php?seccion=' . $fila[0] . '">' . $fila[0] . '</a></li>';
          } else {
            echo '<li><a href="index.php?subseccion=' . $fila[0] . '">' . $fila[0] . '</a></li>';
          }
         }
      }
      echo'</ul></nav>';
      if (isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == true) {
        echo'<div class="fleft"><button class="log" onClick="window.location = \'/logout.php\';">Desconectar</button></div>';

        if(isset($_SESSION['tipo']) && ($_SESSION['tipo'] == "editor jefe" || $_SESSION['tipo'] == "redactor") ){
          echo'<div class="fleft"><button class="log" onClick="window.location = \'/panel.php\';">Panel de Control</button></div>';
        }

    	} else {
      echo'<div class="fleft">
      <button class="login" onclick="document.getElementById(\'id01\').style.display=\'block\'">Registrarse</button></div>
      <button class="login" onclick="document.getElementById(\'id02\').style.display=\'block\'">Login</button></div>

      <div id="id01" class="modal">
        <span onclick="document.getElementById(\'id01\').style.display=\'none\'" class="close" title="Close Modal">&times;</span>
        <form class="modal-content animate" action="/registro-usuario.php" method="post">
          <div class="container">
            <label><b>Usuario</b></label>
            <input type="text" placeholder="Introduce tu usuario" name="username" required>

            <label><b>Email</b></label>
            <input type="text" placeholder="Introduce tu correo" name="email" required>

            <label><b>Password</b></label>
            <input type="password" placeholder="Introduce tu contraseña" name="password" required>


            <div class="clearfix">
              <button type="button" onclick="document.getElementById(\'id01\').style.display=\'none\'" class="cancelbtn">Cancel</button>
              <button type="submit" class="signupbtn">Registrarse</button>
            </div>
          </div>
        </form>
      </div>

      <div id="id02" class="modal">
        <span onclick="document.getElementById(\'id02\').style.display=\'none\'" class="close" title="Close Modal">&times;</span>
        <form class="modal-content animate" action="/checklogin.php" method="post">
          <div class="container">
          <label><b>Usuario</b></label>
          <input type="text" placeholder="Introduce tu usuario" name="username" required>

          <label><b>Password</b></label>
          <input type="password" placeholder="Introduce tu contraseña" name="password" required>

            <div class="clearfix">
              <button type="button" onclick="document.getElementById(\'id02\').style.display=\'none\'" class="cancelbtn">Cancel</button>
              <button type="submit" class="signupbtn">Sign Up</button>
            </div>
          </div>
        </form>
      </div>
    </div>';
  }


    }
  }

?>
