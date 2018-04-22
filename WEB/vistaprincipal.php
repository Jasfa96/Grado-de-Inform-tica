<?php

  class vista_principal{
    private $bd;
    private $seccion;
    private $subseccion;

    public function vista_principal($sec = NULL, $subsec = NULL){
      $this->bd = new base_datos();
      $this->seccion = $sec;
      $this->subseccion = $subsec;
    }

    public function mostrarVistaPrincipal(){
        $this->bd->conectar();

      if(is_null($this->seccion) && is_null($this->subseccion)){
        $noticias = $this->bd->obtenerUltimasNoticias(); //por definir
      } elseif (is_null($this->seccion)){
        $noticias = $this->bd->obtenerNoticiasSubseccion($this->subseccion);
      } else {
        $noticias = $this->bd->obtenerNoticiasSeccion($this->seccion);
      }

        $numFilas = mysqli_num_rows($noticias);
        /*echo '<a class="cuadro-noticia" href="noticia.html">
				<article class="noticia-importante">
					<span class="centrar-img">
						<img class="img-noticia-grande" src="/img/horizon-zero-dawn-geralt-aloy.jpg" ALT="Horizon y The Witcher">
					</span>
						<h2 class="titular-grande">Horizon Zero Dawn - CD Projekt RED felicita a Guerrilla Games</h2>
						Si esta mañana os contamos que Sony y Microsoft habían felicitado a Nintendo por los lanzamientos de The Legend of Zelda Breath of the Wild y Nintendo Switch, ahora os queremos informar de una nueva felicitación entre dos conocidas compañías del sector. En esta ocasión, ha sido CD Projekt, responsables de The Witcher 3 Wild Hunt, la que ha felicitado a Guerrilla Games por Horizon Zero Dawn para PS4. Además de la felicitación a través de un tuit, CD Projekt también ha publicado una imagen protagonizada por Geralt de Rivia y Aloy.
				</article>
			</a>';*/

        if ($numFilas> 0) {
          $contador = 0;
          echo '<div class="izquierda">';

           while($contador<2 && ($fila = $noticias->fetch_array()) ){

             if($fila[10] == 0){
               echo "<a class=\"cuadro-noticia\" href=\"index.php?noticia=$fila[0]\">";
               echo '<article class="noticia-importante"><span class="centrar-img">';
               echo "<img class=\"img-noticia-grande\" src=\"$fila[8]\" ALT=\"$fila[1]\">";
               echo '</span>';
               echo "<h2 class=\"titular-grande\">$fila[1]</h2>";
               echo $fila[4];
               echo '</article></a>';
               $contador++;
             }

           }
           echo '</div>';

           echo '<div class="centro">';

           while($contador<5 &&  ($fila = $noticias->fetch_array()) ){ //Formato columna centro
             if($fila[10] == 0){
               echo "<a class=\"cuadro-noticia\" href=\"index.php?noticia=$fila[0]\">";
               echo '<article class="resumen-noticia"><span class="centrar-img">';
               echo "<img class=\"img-noticia-mediana\" src=\"$fila[8]\" ALT=\"$fila[1]\">"; // AQUI IMAGEN MINIATURA
               echo '</span>';
               echo "<h2 class=\"titular-mediano\">$fila[1]</h2>";
               echo $fila[4];
               echo '</article></a>';
               $contador++;
             }

           }

          echo '</div>';

           echo '<div class="derecha">';
           while($contador<10 &&  ($fila = $noticias->fetch_array()) ){ //Formato columna derecha
             if($fila[10] == 0){
               echo "<a class=\"cuadro-noticia\" href=\"index.php?noticia=$fila[0]\">";
               echo '<article class="resumen-noticia"><span class="centrar-img">';
               echo "<img class=\"img-noticia-pequeña\" src=\"$fila[8]\" ALT=\"$fila[1]\">"; // AQUI IMAGEN MINIATURA
               echo '</span>';
               echo "<h2 class=\"titular-pequeño\">$fila[1]</h2>";
               echo '</article></a>';
               $contador++;
             }
           }

           }

           $resultado= $this->bd->obtenerPubli();
           $this->bd->desconectar();

           while($contador<13 && ($fila = $resultado->fetch_array())){
               echo '<a class="cuadro-noticia" href=" '. $fila[2] .' ">'; //HABRA QUE PONER URL
               echo '<article class="resumen-noticia">';
               echo '<span class="centrar-img">';
               echo '<img class="img-noticia-pequeña "';
               echo "src=\"$fila[3]\" ALT=\"publi\">";
               echo '</span>';
               echo '</article> </a>';
               $contador++;
           }

           echo '</div>';

        }


    }

?>
