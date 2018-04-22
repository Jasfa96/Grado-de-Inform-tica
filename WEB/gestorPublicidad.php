<?php

//Eliminar anuncio
//Modificar anuncio
class gestorPublicidad{
  private $bd;

  private $nombre_anuncio;
  private $url_anuncio;
  private $dir_imagen;

  private $id_anuncio;

  private $id_mod_anuncio;
  private $nueva_imagen;
  private $nueva_url;
  private $nuevo_nombre;
  public function gestorPublicidad(){
    $this->bd=new base_datos();
    $this->bd->conectar();

    if(isset($_GET["nombreAnuncio"]) && isset($_GET["urlAnuncio"]) && isset($_GET["dirImagen"])){
      $this->nombre_anuncio = $_GET["nombreAnuncio"];
      $this->url_anuncio = $_GET["urlAnuncio"];
      $this->dir_imagen = $_GET["dirImagen"];

      //echo "1º if-Valores:   $this->nombre_anuncio y $this->url_anuncio y $this->dir_imagen";
      $this->bd->addPubli($this->nombre_anuncio, $this->url_anuncio, $this->dir_imagen);
    } elseif (isset($_GET["idAnuncio"])){
      $this->id_anuncio = $_GET["idAnuncio"];

      //echo $this->id_anuncio;
      $this->bd->eliminarAnuncio($this->id_anuncio);
    } elseif (isset($_GET["idModAnuncio"]) && isset($_GET["nuevoNombre"]) && isset($_GET["nuevaURL"]) && isset($_GET["nuevaImagen"])){
      $this->id_mod_anuncio = $_GET["idModAnuncio"];
      $this->nueva_imagen = $_GET["nuevaImagen"];
      $this->nueva_url = $_GET["nuevaURL"];
      $this->nuevo_nombre = $_GET["nuevoNombre"];

      //echo "3º if-Valores: $this->id_mod_anuncio y $this->nueva_imagen y $this->nueva_url y $this->nuevo_nombre";
      $this->bd->modificarAnuncio($this->id_mod_anuncio, $this->nuevo_nombre, $this->nueva_url, $this->nueva_imagen);
    }
  }

  public function mostrar(){

    $resultado= $this->bd->obtenerPubli();
    if(mysqli_num_rows($resultado) == 0){
      echo "No hay publicidad";
    }else{
        echo '<div style="text-align:center;">';
        echo "<table border = '1' style=\"margin: 0 auto;\"> \n";
        echo "<tr><td>ID</td><td>Nombre</td><td>Enlace</td><td>Ruta de la imagen</td></tr> \n";
        while ($row = $resultado->fetch_array()){
          echo "<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td><td>$row[3]</td></tr> \n";
        }
        echo "</table></div> \n";
    }

    echo '<form class="formGestor" action="/panel.php">
      <div class="container">
      <p>Añadir anuncio:</p>
        <input type="hidden" name="gestorPublicidad">
        <p><label>Introduce el nombre identificativo del anuncio</label></p>
        <input type="text" name="nombreAnuncio">
        <p><label>Introduce la URL del anuncio</label></p>
        <input type="text" name="urlAnuncio">
        <p><label>Introduce la direccion de la imagen</label></p>
        <input type="text" name="dirImagen">
        <div class="clearfix">
          <input type="submit" class="signupbtn" value="Introducir nueva publicidad">
        </div>
      </div></form>';

      echo '<form class="formGestor" action="/panel.php">
        <div class="container">
        <p>Eliminar anuncio:</p>
          <input type="hidden" name="gestorPublicidad">
          <p><label>Introduce el ID del anuncio a eliminar</label></p>
          <input type="text" name="idAnuncio">

          <div class="clearfix">
            <input type="submit" class="signupbtn" value="Eliminar publicidad">
          </div>
        </div></form>';

      echo '<form class="formGestor" action="/panel.php">
        <div class="container">
        <p>Modificar anuncio anuncio:</p>
          <input type="hidden" name="gestorPublicidad">
          <p><label>Introduce el ID del anuncio a modificar</label></p>
          <input type="text" name="idModAnuncio">
          <p><label>Introduce el nuevo nombre</label></p>
          <input type="text" name="nuevoNombre">
          <p><label>Introduce la nueva URL</label></p>
          <input type="text" name="nuevaURL">
          <p><label>Introduce la nueva direccion de imagen</label></p>
          <input type="text" name="nuevaImagen">
          <div class="clearfix">
            <input type="submit" class="signupbtn" value="Modificar anuncio">
          </div>
      </div></form>';

    $this->bd->desconectar();
  }
}


	?>
