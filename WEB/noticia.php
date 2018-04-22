<?php
	class noticia{
		private $bd;
		private $id_noticia;

		public function noticia($identificador){
			$this->id_noticia = $identificador;
			$this->bd = new base_datos();
		}

		public function mostrarNoticia(){
			$this->bd->conectar();
			$noticia = $this->bd->obtenerNoticia($this->id_noticia);
			$seccion = $this->bd->obtenerSeccionNoticia($this->id_noticia);

			$numFilas = mysqli_num_rows($seccion);

      if ($numFilas> 0) {
         $fila = $seccion->fetch_array();
				 $seccion = $fila[0];
      }

			$seccionPadre = $this->bd->obtenerSeccionPadre($seccion);
			$numFilas = mysqli_num_rows($seccionPadre);

      if ($numFilas> 0) {
         $fila = $seccionPadre->fetch_array();
				 $seccionPadre = $fila[0];
      }

			$numFilas = mysqli_num_rows($noticia);

      if ($numFilas> 0) {
         $fila = $noticia->fetch_array();
      }
			if($fila[10] == 0){


			echo '<div class="noticia" id="noti"> <div class="seccion">';
			echo "$seccionPadre -> $seccion";
			echo '</div> <article class="noticia-importante"> <h1 class="titular-grande">';
			echo "$fila[1]";
			echo '</h1> <p class="pie-de-foto"> Escrito por ';
			echo "$fila[2] - $fila[3]";
			echo ' Fecha de ultima edición: ';
			echo "$fila[9]";
			echo '</p> <h3 class="subtitulo">';
			echo "$fila[4]";
			echo '</h3> <h4 class="entradilla">';
			echo "$fila[5]";
			echo '</h4>';
			echo "$fila[6]";
			echo '<span class="boton-centrado"> <a class="boton-imprimir" href="index.php?impresion=' . $fila[0] . '" ALT="MotionFreak">';
			echo '<img class="boton-imprimir" src="/img/Printer-icon.png"  ALT="MotionFreak">';
			echo '</a> </span> ';

			echo '<h1 class="titular-grande"> GALERÍA </h1>';
			$galeria = $this->bd->obtenerGaleria($this->id_noticia);

			$numFilas = mysqli_num_rows($galeria);

      if ($numFilas> 0) {
         while($fila = $galeria->fetch_array()){
					 echo "<img class=\"img-noticia-mediana\" src=\"$fila[0]\">";
				 }
      }

			echo '</article> </div>';

		} else {
			echo "Noticia no publicada";
		}

			$this->bd->desconectar();
		}
	}
?>
