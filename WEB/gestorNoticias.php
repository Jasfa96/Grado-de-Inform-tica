<?php
class gestorNoticias{
  private $bd;

  private $id_consulta;

  private $id_eliminar;

  private $n_titular;
  private $n_subtitulo;
  private $n_entradilla;
  private $n_cuerpo;
  private $n_seccion;
  private $n_miniatura;
  private $n_autor;

  private $id_publicar;
  private $id_ocultar;

  private $id_modificar;

  private $m_id;
  private $m_titular;
  private $m_subtitulo;
  private $m_entradilla;
  private $m_cuerpo;
  private $m_seccion;
  private $m_miniatura;

  public function gestorNoticias(){
    $this->bd=new base_datos();
    $this->bd->conectar();

    if(isset($_GET["idConsultarNoticia"])){
      $this->id_consulta = $_GET["idConsultarNoticia"];
      $this->visualizarNoticia();
    } elseif(isset($_GET["idEliminarNoticia"])){
      $this->id_eliminar = $_GET["idEliminarNoticia"];
      $this->bd->eliminarNoticia($this->id_eliminar);
    } elseif(isset($_GET["nuevoTitular"]) && isset($_GET["nuevoSubtitulo"]) && isset($_GET["nuevaEntradilla"]) && isset($_GET["nuevoCuerpo"]) && isset($_GET["nuevaSeccion"]) && isset($_GET["nuevaMiniatura"])){
      $this->n_titular = $_GET["nuevoTitular"];
      $this->n_subtitulo = $_GET["nuevoSubtitulo"];
      $this->n_entradilla = $_GET["nuevaEntradilla"];
      $this->n_cuerpo = $_GET["nuevoCuerpo"];
      $this->n_seccion = $_GET["nuevaSeccion"];
      $this->n_miniatura = $_GET["nuevaMiniatura"];
      $this->n_autor = $_SESSION['username'];

    /*  echo "$this->n_titular y $this->n_subtitulo y $this->n_entradilla y $this->n_cuerpo y $this->n_seccion y $this->n_miniatura y $this->n_autor";*/
      $this->bd->introducirNoticia($this->n_titular, $this->n_subtitulo, $this->n_entradilla, $this->n_cuerpo, $this->n_seccion, $this->n_miniatura, $this->n_autor);
    }
    elseif(isset($_GET["idPublicarNoticia"])){
      $this->id_publicar = $_GET["idPublicarNoticia"];
      $this->bd->publicarNoticia($this->id_publicar);
    }
    elseif(isset($_GET["idOcultarNoticia"])){
      $this->id_ocultar = $_GET["idOcultarNoticia"];
      $this->bd->ocultarNoticia($this->id_ocultar);
    } elseif(isset($_GET["idModificarNoticia"])){
      $this->id_modificar = $_GET["idModificarNoticia"];

      $this->alterarNoticia();
    } elseif(isset($_GET["modID"]) && isset($_GET["modTitular"]) && isset($_GET["modSubtitulo"]) && isset($_GET["modEntradilla"]) && isset($_GET["modCuerpo"]) && isset($_GET["modSeccion"]) && isset($_GET["modMiniatura"])){
      $this->m_id = $_GET["modID"];
      $this->m_titular = $_GET["modTitular"];
      $this->m_subtitulo = $_GET["modSubtitulo"];
      $this->m_entradilla = $_GET["modEntradilla"];
      $this->m_cuerpo = $_GET["modCuerpo"];
      $this->m_seccion = $_GET["modSeccion"];
      $this->m_miniatura = $_GET["modMiniatura"];

      //echo "$this->m_id y $this->m_titular y $this->m_subtitulo y $this->m_entradilla y $this->m_cuerpo y $this->m_seccion y $this->m_miniatura";

      $this->bd->editarNoticia($this->m_id, $this->m_titular, $this->m_subtitulo, $this->m_entradilla, $this->m_cuerpo, $this->m_seccion, $this->m_miniatura);

    }
}

  public function mostrar(){

    $resultado= $this->bd->obtenerNoticiasPublicadas();

    echo "<p>Tabla de noticias publicadas:</p>";
    if(mysqli_num_rows($resultado) == 0){
      echo "No hay noticias";
    }
    else{

      echo '<div style="text-align:center;">';
      echo "<table border = '1' style=\"margin: 0 auto;\"> \n";
      echo "<tr><td>ID</td><td>Titular</td><td>Autor</td></tr> \n";
      while ($row = $resultado->fetch_array()){
        echo "<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td></tr> \n";
      }
      echo "</table></div> \n";
    }

    $resultado= $this->bd->obtenerNoticiasNoPublicadas();

    echo "<p>Tabla de noticias pendientes de revisión:</p>";
    if(mysqli_num_rows($resultado) == 0){
      echo "No hay noticias";
    }
    else{

      echo '<div style="text-align:center;">';
      echo "<table border = '1' style=\"margin: 0 auto;\"> \n";
      echo "<tr><td>ID</td><td>Titular</td><td>Autor</td></tr> \n";
      while ($row = $resultado->fetch_array()){
        echo "<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td></tr> \n";
      }
      echo "</table></div> \n";
    }

if(isset($_SESSION['tipo']) && $_SESSION['tipo'] == "editor jefe"){
      echo '<form class="formGestor" action="/panel.php">
        <div class="container">
          <input type="hidden" name="gestorNoticias">
          <p style="font-weight: bold;">Consultar noticia</p>
          <p><label>Introduce el ID de la noticia que deseas ver</label></p>
          <input type="text" name="idConsultarNoticia">
          <div class="clearfix">
            <input type="submit" class="signupbtn" value="Consultar noticia">
          </div>
        </div></form>';

      echo '<form class="formGestor" action="/panel.php">
        <div class="container">
          <input type="hidden" name="gestorNoticias">
          <p style="font-weight: bold;">Modificar noticia</p>
          <p><label>Introduce el ID de la noticia que deseas modificar</label></p>
          <input type="text" name="idModificarNoticia">
          <div class="clearfix">
            <input type="submit" class="signupbtn" value="Consultar noticia">
          </div>
        </div></form>';

        echo '<form class="formGestor" action="/panel.php">
          <div class="container">
            <input type="hidden" name="gestorNoticias">
            <p style="font-weight: bold;">Publicar noticia</p>
            <p><label>Introduce el ID de la noticia que deseas publicar</label></p>
            <input type="text" name="idPublicarNoticia">
            <div class="clearfix">
              <input type="submit" class="signupbtn" value="Publicar noticia">
            </div>
          </div></form>';

          echo '<form class="formGestor" action="/panel.php">
            <div class="container">
              <input type="hidden" name="gestorNoticias">
              <p style="font-weight: bold;">Ocultar noticia</p>
              <p><label>Introduce el ID de la noticia que deseas ocultar</label></p>
              <input type="text" name="idOcultarNoticia">
              <div class="clearfix">
                <input type="submit" class="signupbtn" value="Ocultar noticia">
              </div>
            </div></form>';

      echo '<form class="formGestor" action="/panel.php">
        <div class="container">
          <input type="hidden" name="gestorNoticias">
          <p style="font-weight: bold;">Eliminar noticia</p>
          <p><label>Introduce el ID de la noticia que deseas eliminar</label></p>
          <input type="text" name="idEliminarNoticia">
          <div class="clearfix">
            <input type="submit" class="signupbtn" value="Eliminar noticia">
          </div>
        </div></form>';
    }
    echo '<form class="formGestor" action="/panel.php">
      <div class="container">
        <input type="hidden" name="gestorNoticias">
        <p style="font-weight: bold;">Introducir noticia</p>
        <p><label>Introduce el titular de la noticia</label></p>
        <input type="text" name="nuevoTitular">
        <p><label>Introduce el subtitulo de la noticia</label></p>
        <input type="text" name="nuevoSubtitulo">
        <p><label>Introduce la entradilla de la noticia</label></p>
        <input type="text" name="nuevaEntradilla">
        <p><label>Introduce el cuerpo de la noticia</label></p>
        <textarea type="textarea" name="nuevoCuerpo"></textarea>
        <p><label>Introduce el ID de la sección de la noticia</label></p>
        <input type="text" name="nuevaSeccion">
        <p><label>Introduce la dirección de la miniatura de la noticia</label></p>
        <input type="text" name="nuevaMiniatura">
        <div class="clearfix">
          <input type="submit" class="signupbtn" value="Introducir noticia">
        </div>
      </div></form>';
    }

  public function visualizarNoticia(){
     $noticia = $this->bd->obtenerNoticia($this->id_consulta);
     $numFilas = mysqli_num_rows($noticia);


     if ($numFilas> 0) {
        $fila = $noticia->fetch_array();
        echo "<p style=\"font-weight: bold;\">Visualizando la noticia con ID: $fila[0]</p>";
        echo "<p>Titular: $fila[1]</p>";
        echo "<p>Autor: $fila[2]</p>";
        echo "<p>Fecha: $fila[3]</p>";
        echo "<p>Subtitulo: $fila[4]</p>";
        echo "<p>Entradilla: $fila[5]</p>";
        echo "<p>Cuerpo: $fila[6]</p>";
        echo "<p>ID de la seccion: $fila[7]</p>";
        echo "<p>Imagen de miniatura: $fila[8]</p>";
        echo "<p>Fecha de ultima edicion: $fila[9]</p>";
        echo "<p>Esta publicada: ";
        if($fila[10] == 0){
          echo "SI";
        } else {
          echo "NO";
        }
        echo "</p>";


     }
  }

  public function alterarNoticia(){
    $noticia = $this->bd->obtenerNoticia($this->id_modificar);
    $numFilas = mysqli_num_rows($noticia);



    if ($numFilas> 0) {
       $fila = $noticia->fetch_array();

       echo '<form class="formGestor" action="/panel.php">
         <div class="container">
           <input type="hidden" name="gestorNoticias">
           <input type="hidden" name="modID" value="'.$this->id_modificar.'">
           <p style="font-weight: bold;">Formulario de modificación de la noticia ' . $fila[0] . '</p>
           <p><label>Titular</label></p>
           <input type="text" name="modTitular" value="'.$fila[1].'">
           <p><label>Subtitulo</label></p>
           <textarea type="textarea" name="modSubtitulo">'.$fila[4].'</textarea>
           <p><label>Entradilla</label></p>
           <textarea type="textarea" name="modEntradilla">'.$fila[5].'</textarea>
           <p><label>Cuerpo</label></p>
           <textarea type="textarea" name="modCuerpo">'.$fila[6].'</textarea>
           <p><label>ID de la sección</label></p>
           <input type="text" name="modSeccion" value="'.$fila[7].'">
           <p><label>Miniatura</label></p>
           <input type="text" name="modMiniatura" value="'.$fila[8].'">
           <div class="clearfix">
             <input type="submit" class="signupbtn" value="Actualizar noticia">
           </div>
         </div></form>';
       }
  }
}


	?>
