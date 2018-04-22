<?php

  class sidebar{

    private $bd;
    private $id_noticia;

    public function sidebar($noticia){
      $this->bd = new base_datos();
      $this->id_noticia = $noticia;
    }

    public function mostrarSidebar(){
      $contador = 0;
      echo '<div class="panel-derecho" id="panel-lateral">';
      echo "<div class=\"boton-comentario\" onclick=\"toggle(document.getElementById('caja-comentarios'))\">";
      echo 'Mostrar comentarios';
      echo '</div>'; //caja-comentarios igual va entre '' en vez de ""

      echo '<div class="noticias-relacionadas" id="not-relacionadas">';
      $this->bd->conectar();
      $resultado= $this->bd->obtenerNoticia($this->id_noticia);
      $fila = $resultado->fetch_array();
      $resultado= $this->bd->obtenerNoticiasRelacionadas($fila[7]);

      while($contador<3 && ($fila = $resultado->fetch_array())){
        if($fila[10]==0){
          if($fila[0] != $this->id_noticia) {
            echo '<a class="cuadro-noticia" href="index.php?noticia='. $fila[0] .'">'; //HABRA QUE PONER URL
            echo '<article class="resumen-noticia">';
            echo '<span class="centrar-img">';
            echo '<img class="img-noticia-pequeña "';
            echo "src=\"$fila[8]\" ALT=\"$fila[1]\">";
            echo '</span> <h2 class="titular-pequeño">';
            echo "$fila[1]";
            echo '</h2> </article> </a>';
            $contador++;
          }
        }
      }
      $contador = 0;
      $resultado= $this->bd->obtenerPubli();

      while($fila = $resultado->fetch_array()){
          echo '<a class="cuadro-noticia" href=" '. $fila[2] .' " alt=" ' . $fila[1] . '">';
          echo '<article class="resumen-noticia">';
          echo '<span class="centrar-img">';
          echo '<img class="img-noticia-pequeña "';
          echo "src=\"$fila[3]\" ALT=\"publi\">";
          echo '</span>';
          echo '</article> </a>';
          $contador++;
      }
      echo '</div>';


      echo '<div class="target" id="caja-comentarios">';
      echo '<div id="lista-comentarios">';

      $resultado= $this->bd->obtenerComentarios($this->id_noticia);
      if(mysqli_num_rows($resultado) == 0){
        echo "No hay comentarios";
      }
      else{
        while($fila = $resultado->fetch_array()){

        echo '<article class="comentario"> <p class="autor-comentario">';
        echo $fila['autor'];
        echo '</p> <p class="fecha-hora-comentario" id="fecha">';
        echo ' - ' . $fila['fecha'];
        echo '</p> <p class="cuerpo-comentario">';
        echo $fila['cuerpo'];
        echo '</p> </article>';
        }
        echo '</div>';
      }

      if (isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == true) {
      echo '<form class="formComentarios" action="/comentar.php?noticia=' . $this->id_noticia . '" method="post">
        <div class="container">
          <label><b>¡Comenta!</b></label>
          <textarea id="cuerpo" type="textarea" onkeyup="filtro(\'mensaje\')" onkeydown="filtro(\'mensaje\')" placeholder="Introduce tu comentario" name="cuerpo" required></textarea>

          <div class="clearfix">
            <button type="submit" class="signupbtn">Comentar</button>
          </div>
        </div>';
    }
		echo '</div> </div>';

    $this->bd->desconectar();

    }
  }
?>
