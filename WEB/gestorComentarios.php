<?php
class gestorComentarios{
  private $bd;
  private $id_noticia;
  private $eliminar_comentario;
  private $nuevo_comentario;
  private $id_alterar;
  private $cuerpo;

  public function gestorComentarios(){
    $this->bd=new base_datos();
    $this->bd->conectar();

    if(isset($_GET["verNoticia"])){
      $this->id_noticia = $_GET["verNoticia"];

      if(isset($_GET["eliminarComentario"])){
        $this->eliminar_comentario = $_GET["eliminarComentario"];
        $this->bd->borrarComentario($this->eliminar_comentario);
      } elseif(isset($_GET["introducirComentario"])){
        $this->nuevo_comentario = $_GET["introducirComentario"];
        $usuario = $_SESSION['username'];
        $this->bd->comentarionoti($this->id_noticia, $usuario, $this->nuevo_comentario);
      } elseif(isset($_GET["alterarComentario"]) and isset($_GET["cuerpo"])){
        $this->id_alterar = $_GET["alterarComentario"];
        $this->cuerpo = $_GET["cuerpo"];
        $this->bd->editarComentario($this->id_alterar, $this->cuerpo);
      }
    }
  }

  public function mostrar(){
    echo '<form class="formGestor" action="/panel.php">
      <div class="container">
        <input type="hidden" name="gestorComentarios">
        <p><label>Selecciona el ID de una noticia para mostrar sus comentarios</label></p>
        <input id="verNoticia" type="text"  name="verNoticia" required>

        <div class="clearfix">
          <input type="submit" class="signupbtn" value="Ver Comentarios">
        </div>
      </div></form>';

    if(isset($_GET["verNoticia"])){

      $resultado= $this->bd->obtenerComentarios($this->id_noticia);
      if(mysqli_num_rows($resultado) == 0){
        echo "No hay comentarios";
      }
      else{

        echo '<div style="text-align:center;">';
        echo "<table border = '1' style=\"margin: 0 auto;\"> \n";
        echo "<tr><td>ID</td><td>Noticia</td><td>Autor</td><td>Fecha</td><td>Cuerpo</td></tr> \n";
        while ($row = $resultado->fetch_array()){
          echo "<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td><td>$row[3]</td><td>$row[4]</td></tr> \n";
        }
        echo "</table></div> \n";
      }

      echo '<form class="formGestor" action="/panel.php">
        <div class="container">
          <input type="hidden" name="gestorComentarios">
          <input type="hidden" name="verNoticia" value="' . $this->id_noticia . '">
          <p><label>Introduce el ID del comentario que deseas eliminar</label></p>
          <input type="text" name="eliminarComentario">
          <div class="clearfix">
            <input type="submit" class="signupbtn" value="Eliminar Comentario">
          </div>
        </div></form>';

      echo '<form class="formGestor" action="/panel.php">
        <div class="container">
          <input type="hidden" name="gestorComentarios">
          <input type="hidden" name="verNoticia" value="' . $this->id_noticia . '">
          <p><label>Introduce un nuevo comentario</label></p>
          <textarea type="textarea" onkeyup="filtro(\'mensaje\')" onkeydown="filtro(\'mensaje\')" name="introducirComentario" required></textarea>
          <div class="clearfix">
            <input type="submit" class="signupbtn" value="Introducir Comentario">
          </div>
        </div>
      </form>';

      echo '<form class="formGestor" action="/panel.php">
        <div class="container">
          <input type="hidden" name="gestorComentarios">
          <input type="hidden" name="verNoticia" value="' . $this->id_noticia . '">
          <p><label>Introduce el ID del comentario que deseas modificar</label></p>
          <input type="text" name="alterarComentario">
          <p><label>Introduce el nuevo contenido</label></p>
          <textarea type="textarea" onkeyup="filtro(\'mensaje\')" onkeydown="filtro(\'mensaje\')" name="cuerpo" required></textarea>
          <div class="clearfix">
            <input type="submit" class="signupbtn" value="Eliminar Comentario">
          </div>
        </div>
      </form>';

      $this->bd->desconectar();
    }
  }
}


	?>
