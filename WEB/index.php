<!DOCTYPE html> <!-- Para indicarle el tipo de documento al navegador -->
<?php
session_start();

if(!isset($_GET["impresion"])){
echo'
<html>

<head> <!-- Información sobre la página web -->
	<meta charset="UTF-8"> <!-- Encodign -->
	<title>MotionFreak - Portada</title>
	<link rel="stylesheet" type="text/css" href="../css/estilo.css" />
	<link rel="stylesheet" type="text/css" href="../css/estilo-noticia.css" />

	<script src="/scripts/funciones.js"></script>

</head>

<body>';



	include 'header.php';
	$id_noticia = NULL;
	$seccion = NULL;
	$subseccion = NULL;


	if(isset($_GET["noticia"])){
		$id_noticia = $_GET["noticia"];
	}

	if(isset($_GET["seccion"])){
		$seccion = $_GET["seccion"];
	}

	if(isset($_GET["subseccion"])){
		$subseccion = $_GET["subseccion"];
	}

	$hd = new header($id_noticia, $seccion, $subseccion);
	$hd->mostrarHeader();


	echo '<div class="main">';

			include 'noticia.php';
			include 'sidebar.php';
			include 'vistaprincipal.php';



			$id_noticia = NULL;
			$seccion = NULL;
			$subseccion = NULL;

			if(isset($_GET["noticia"])){
				$id_noticia = $_GET["noticia"];
				$noti = new noticia($id_noticia);
				$noti->mostrarNoticia();

				$panel = new sidebar($id_noticia);
				$panel->mostrarSidebar();
			} else {
				if(isset($_GET["subseccion"])) {
					$subseccion = $_GET["subseccion"];
				} elseif(isset($_GET["seccion"])) {
					$seccion = $_GET["seccion"];
				}

				$principal = new vista_principal($seccion, $subseccion);
				$principal->mostrarVistaPrincipal();
			}


		echo '</div>';




	include 'footer.php';

	$ft = new footer();
	$ft->mostrar();
}else{
	include 'impresion.php';
	$impresion= new impresion($_GET["impresion"]);
	$impresion->mostrarimpresion();
}
?>


</body>

</html>
