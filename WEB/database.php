<?php
  class base_datos{
    private $conexion;
    private $esta_conectado;

    public function base_datos(){
      $this->esta_conectado = false;
    }

    public function conectar(){
      if(!$this->esta_conectado){
        $this->conexion = mysqli_connect ('localhost', 'motionfreak', 'password', 'MotionFreak');
        $this->conexion->set_charset("utf8");
        $this->esta_conectado = true;
      }
    }


    public function desconectar(){
      if($this->esta_conectado){
        mysqli_close($this->conexion);
        $this->esta_conectado = false;
      }
    }

    public function obtenerMenusPrincipales(){
      if($this->esta_conectado){
        $seleccion = "SELECT seccion FROM `secciones` WHERE seccionPadre IS NULL ";

        $resultado = $this->conexion->query ($seleccion);

        return $resultado;
      }
    }

    public function obtenerSubmenusNoticia($id_noticia){
      if($this->esta_conectado){
        $seleccion = "SELECT seccion FROM secciones where seccionPadre=(SELECT seccionPadre from secciones where id=(SELECT seccion FROM noticias_publicadas where identificador=$id_noticia))";

        $resultado = $this->conexion->query ($seleccion);

        return $resultado;
      }
    }

    public function obtenerTablaCategorias(){
      if($this->esta_conectado){
        $seleccion = "SELECT * FROM `secciones` ";
        $resultado = $this->conexion->query ($seleccion);
        return $resultado;
      }
    }

    public function obtenerUltimasNoticias(){
      if($this->esta_conectado){
        $seleccion = "SELECT * FROM `noticias_publicadas` ORDER BY fecha DESC LIMIT 10";

        $resultado = $this->conexion->query ($seleccion);

        return $resultado;
      }
    }

    public function obtenerNoticiasRelacionadas($subseccion){
      if($this->esta_conectado){
        $subseccion = "\"$subseccion\"";

        $seleccion = "SELECT * FROM `noticias_publicadas` WHERE seccion=$subseccion ORDER BY fecha DESC LIMIT 10;";

        $resultado = $this->conexion->query ($seleccion);

        return $resultado;
      }
    }

    public function obtenerNoticiasPublicadas(){
      if($this->esta_conectado){
        $seleccion = "SELECT * FROM `noticias_publicadas` where publicada=0";

        $resultado = $this->conexion->query($seleccion);
        return $resultado;
      }
    }

    public function obtenerNoticiasNoPublicadas(){
      if($this->esta_conectado){
        $seleccion = "SELECT * FROM `noticias_publicadas` where publicada=1";

        $resultado = $this->conexion->query($seleccion);
        return $resultado;
      }
    }

    public function eliminarNoticia($id_noticia){
      if($this->esta_conectado){
        $operacion =  "DELETE FROM `noticias_publicadas` WHERE `noticias_publicadas`.`identificador` = $id_noticia";
        $this->conexion->query($operacion);
      }
    }

    public function introducirNoticia($titular, $subtitulo, $entradilla, $cuerpo, $seccion, $miniatura, $autor){
      if($this->esta_conectado){
        $titular = "\"$titular\"";
        $subtitulo = "\"$subtitulo\"";
        $entradilla = "\"$entradilla\"";
        $cuerpo = "\"$cuerpo\"";
        $miniatura = "\"$miniatura\"";
        $usuario = "\"$autor\"";

        $operacion = "INSERT INTO `noticias_publicadas` (`titular`, `autor`, `fecha`, `subtitulo`, `entradilla`, `cuerpo`, `seccion`, `miniatura`, `publicada`) VALUES ($titular, $usuario, CURRENT_TIMESTAMP, $subtitulo, $entradilla, $cuerpo, $seccion, $miniatura, 1);";
        $this->conexion->query($operacion);
      }
    }

    public function login($usuario, $password){
        if($this->esta_conectado){
        	$sql = "SELECT * FROM Usuarios WHERE nombre = '$usuario';";

        	$result = $this->conexion->query($sql);

          $seguridad='normal';

        	if ($result->num_rows > 0) {
        	 $row = $result->fetch_array(MYSQLI_ASSOC);
        	 if (strcmp($password, $row['password']) == 0) {

        	    $_SESSION['loggedin'] = true;
        	    $_SESSION['username'] = $usuario;
        	    $_SESSION['start'] = time();
        	    $_SESSION['expire'] = $_SESSION['start'] + (60 * 60);
              $_SESSION['tipo'] = $row['tipo'];

        	    echo "Bienvenido! " . $_SESSION['username'];

            if (strcmp($seguridad, $row['tipo']) !== 0){
        	    echo "<br><br><a href=panel.php>Panel de Control</a>";
              echo "<br><a href='index.php'>Volver a la página principal</a>";
            } else {
              echo "<br><a href='index.php'>Volver a la página principal</a>";
            }

        	 }else {
          	   echo "Password incorrecta.";

          	   echo "<br><a href='index.php'>Volver a Intentarlo</a>";
          	 }
         } else {
        	   echo "Usuario incorrecto.";

        	   echo "<br><a href='index.php'>Volver a Intentarlo</a>";
         }
      }

    }

    public function borrarComentario($id_comentario){
      if($this->esta_conectado){
        $operacion = "DELETE FROM `comentarios` WHERE `comentarios`.`id` = $id_comentario ";
        $this->conexion->query($operacion);


      }
    }

    public function editarComentario($id_comentario, $cuerpo){
      if($this->esta_conectado){
        $cuerpo = "\"$cuerpo\"";
        $operacion = "UPDATE `comentarios` SET `cuerpo` = $cuerpo WHERE `comentarios`.`id` = $id_comentario;";
        $this->conexion->query($operacion);
      }
    }

    public function editarNombreSeccion($id_seccion, $nombre){
      if($this->esta_conectado){
        $nombre = "\"$nombre\"";
        $operacion = "UPDATE `secciones` SET `seccion` = $nombre WHERE `secciones`.`id` = $id_seccion;";
        $this->conexion->query($operacion);
      }
    }

    public function editarPadreSeccion($id_seccion, $id_padre){
      if($this->esta_conectado){
        $operacion = "UPDATE `secciones` SET `seccionPadre` = $id_padre WHERE `secciones`.`id` = $id_seccion;";
        $this->conexion->query($operacion);
      }
    }

    public function publicarNoticia($id_publicar){
      if($this->esta_conectado){
        $operacion = "UPDATE `noticias_publicadas` SET `publicada` = '0' WHERE `noticias_publicadas`.`identificador` = $id_publicar;";
        $this->conexion->query($operacion);
      }
    }

    public function ocultarNoticia($id_publicar){
      if($this->esta_conectado){
        $operacion = "UPDATE `noticias_publicadas` SET `publicada` = '1' WHERE `noticias_publicadas`.`identificador` = $id_publicar;";
        $this->conexion->query($operacion);
      }
    }

    public function editarNoticia($id, $titular, $subtitulo, $entradilla, $cuerpo, $seccion, $miniatura){
      if($this->esta_conectado){
        $titular="\"$titular\"";
        $subtitulo="\"$subtitulo\"";
        $entradilla="\"$entradilla\"";
        $cuerpo="\"$cuerpo\"";
        $miniatura="\"$miniatura\"";


        $operacion = "UPDATE `noticias_publicadas` SET `titular` = $titular, `subtitulo` = $subtitulo, `entradilla` = $entradilla, `cuerpo` = $cuerpo, `seccion` = $seccion, `miniatura` = $miniatura WHERE `noticias_publicadas`.`identificador` = $id;";
        $this->conexion->query($operacion);
      }
    }


    public function introducirSeccion($seccion, $id_padre){
      if($this->esta_conectado){
        if($id_padre.is_null()){
          $query = "INSERT INTO secciones (seccion, seccionPadre) VALUES ('$seccion', '$id_padre')";
        }else{
          $query = "INSERT INTO secciones (seccion) VALUES ('$seccion')";
        }
        $this->conexion->query($query);
      }
    }


    public function comentarionoti($noticia, $usuario, $cuerpo){
      if($this->esta_conectado){
        $query = "INSERT INTO comentarios (noticia, autor, cuerpo) VALUES ('$noticia', '$usuario',  '$cuerpo')";

        if ($this->conexion->query($query) === TRUE){

        } else {
      	   echo "Error." . $query . "<br>" . $this->conexion->error;
        }
      }
    }

    public function registro($usuario, $password, $email){
      if($this->esta_conectado){
        $buscarUsuario = "SELECT * FROM Usuarios WHERE nombre = '$usuario';";

       	 $result = $this->conexion->query($buscarUsuario);

       	 $count = mysqli_num_rows($result);

       	 if ($count == 1) {
       	 echo "<br />". "El Nombre de Usuario ya a sido tomado." . "<br />";

       	 echo "<a href='index.php'>Por favor escoga otro Nombre</a>";
       	 }
       	 else{

       	 $query = "INSERT INTO Usuarios (nombre, password, email)
       	           VALUES ('$usuario', '$password', '$email')";

       	 if ($this->conexion->query($query) === TRUE) {

       	 echo "<br />" . "<h2>" . "Usuario Creado Exitosamente!" . "</h2>";
       	 echo "<h4>" . "Bienvenido: " . $usuario . "</h4>" . "\n\n";
       	 echo "<h5>" . "Volver a la " . "<a href='/index.php'>página principal</a>" . "</h5>";
       	 }

       	 else {
       	 echo "Error al crear el usuario." . $query . "<br>" . $this->conexion->error;
       	   }
       	 }
       }
    }


    public function obtenerNoticiasSubseccion($subseccion){
      if($this->esta_conectado){
        $subseccion = "\"$subseccion\"";

        $seleccion = "SELECT * FROM `noticias_publicadas` WHERE seccion=(SELECT id from `secciones` WHERE seccion=$subseccion) ORDER BY fecha DESC LIMIT 10; ";

        $resultado = $this->conexion->query ($seleccion);

        return $resultado;
      }
    }

    public function obtenerComentarios($id_noticia){
      if($this->esta_conectado){
        $seleccion = "SELECT * FROM `comentarios` WHERE noticia=$id_noticia";

        $resultado = $this->conexion->query($seleccion);

        return $resultado;
      }
    }

    public function obtenerPubli(){
      if($this->esta_conectado){
        $seleccion = "SELECT * FROM publi";
        $resultado = $this->conexion->query($seleccion);
        return $resultado;
      }
    }

    public function addPubli($nombre, $url, $img){
      if($this->esta_conectado){
        $nombre = "\"$nombre\"";
        $url = "\"$url\"";
        $img = "\"$img\"";
        $operacion = "INSERT INTO `publi` (`Nombre`, `Enlace`, `Imagen`) VALUES ($nombre, $url, $img);";
        $this->conexion->query($operacion);
      }
    }

    public function eliminarAnuncio($id_anuncio){
      if($this->esta_conectado){
        $operacion = "DELETE FROM `publi` WHERE `publi`.`ID` = $id_anuncio";
        $this->conexion->query($operacion);
      }
    }

    public function modificarAnuncio($id_anuncio, $nombre, $url, $img){
      if($this->esta_conectado){
        $nombre = "\"$nombre\"";
        $url = "\"$url\"";
        $img = "\"$img\"";
        $operacion = "UPDATE `publi` SET `Nombre` = $nombre, `Enlace` = $url, `Imagen` = $img WHERE `publi`.`ID` = $id_anuncio";
        $this->conexion->query($operacion);
      }
    }

    public function obtenerGaleria($id_noticia){
      if($this->esta_conectado){
        $seleccion = "SELECT dir_img FROM `imagenes` WHERE id_noticia = $id_noticia;";

        $resultado = $this->conexion->query($seleccion);
        return $resultado;
      }
    }

    public function obtenerNoticiasSeccion($seccion){
      if($this->esta_conectado){
        $seccion = "\"$seccion\"";
        $seleccion = "SELECT * FROM `noticias_publicadas` WHERE seccion IN (SELECT DISTINCT id from `secciones` WHERE seccionPadre=(SELECT id from secciones where seccion=$seccion)) ORDER BY fecha DESC LIMIT 10;";

        $resultado = $this->conexion->query ($seleccion);

        return $resultado;
      }
    }

    public function obtenerSeccionPadre($subseccion){
      if($this->esta_conectado){
        $subseccion = "\"$subseccion\"";
        $seleccion = "SELECT seccion FROM `secciones` where id=(SELECT seccionPadre from secciones WHERE seccion=$subseccion);";

        $resultado = $this->conexion->query ($seleccion);

        $fila = $resultado->fetch_array();

        $resultado = $fila[0];

        return $resultado;
      }
    }

    public function obtenerSubmenusCategoria($categoria){
      if($this->esta_conectado){
        $categoria ="\"$categoria\"";
        $seleccion = "SELECT seccion from secciones where seccionPadre=(SELECT id FROM secciones WHERE seccion=$categoria); ";

        $resultado = $this->conexion->query ($seleccion);

        return $resultado;
      }
    }

    public function eliminarCategoria($id_categoria){
      if($this->esta_conectado){
        $seleccion = "DELETE FROM `secciones` WHERE `secciones`.`id` = $id_categoria";
        $seleccion = $this->conexion->query ($seleccion);
      }
    }

    public function obtenerNoticia($id_noticia){
      if($this->esta_conectado){
        $seleccion = "SELECT * FROM noticias_publicadas where identificador = '$id_noticia';";

        $resultado = $this->conexion->query($seleccion);

        return $resultado;
      }
    }

    public function obtenerSeccionNoticia($id_noticia){
      if($this->esta_conectado){
        $seleccion = "select seccion from secciones where id=(select seccion from noticias_publicadas where identificador=$id_noticia);";

        $resultado = $this->conexion->query($seleccion);

        return $resultado;
      }
    }
  }

?>
