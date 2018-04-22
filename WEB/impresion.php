<?php
include 'database.php';
  class impresion{
    private $bd;
    private $noticia;

    public function impresion($not = NULL){
      $this->bd = new base_datos();
      $this->noticia = $not;
    }

    public function mostrarimpresion(){
        $this->bd->conectar();
        $resultado= $this->bd->obtenerNoticia($this->noticia);
        $this->bd->desconectar();

        $numFilas = mysqli_num_rows($resultado);

        if ($numFilas> 0) {
          $fila = $resultado->fetch_array();
        }

        if($fila[10]==0){

          echo '<html><head> <meta charset="UTF-8"> <title>MotionFreak - Impresion</title> <link rel="stylesheet" type="text/css" href="../css/estilo-imprimir.css" /> </head> <body>';
          echo "<img src=\"/img/MF.png\" class=\"img-logo\">";
          echo "<article>";
        	echo "<img class=\"bordes\" src=\"$fila[8]\">";
        	echo "<h1 class=\"titular-grande\">$fila[1]</h1>";
        	echo "<p>Escrito por $fila[2] - $fila[3]</p>";

        	echo "<h3 class=\"subtitulo\"> $fila[4] </h3>";
        	echo "<h4 class=\"entradilla\"> $fila[5] </h4>";
        	echo "$fila[6]";
        	echo "</article>";

          echo'</body> </html>';
        } else{
          echo "Noticia no publicada";
        }


      }
    }
