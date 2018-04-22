<?php
	session_start();

	if (isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == true) {

	} else {
   echo "Esta pagina es solo para usuarios registrados.<br>";
   echo "<br><br><a href='index.php'>Volver a la pagina de inicio</a>";

	exit;
	}

	$now = time();

	if($now > $_SESSION['expire']) {
	session_destroy();

	echo "Su sesion a terminado,
	<a href='index.php'>Necesita Hacer Login</a>";
	exit;
	}
	?>

	<!DOCTYPE html> <!-- Para indicarle el tipo de documento al navegador -->
	<?php
	session_start();

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


/*
		if(isset($_GET["noticia"])){
			$id_noticia = $_GET["noticia"];
		}

		if(isset($_GET["seccion"])){
			$seccion = $_GET["seccion"];
		}

		if(isset($_GET["subseccion"])){
			$subseccion = $_GET["subseccion"];
		}
		*/

		$hd = new header($id_noticia, $seccion, $subseccion);
		$hd->mostrarHeader();


		echo '<div class="main">';


    if(isset($_SESSION['tipo']) && $_SESSION['tipo'] == "redactor"){
			echo "<a class=\"boton-gestor\" href=\"panel.php?gestorNoticias\">";
			echo 'Gestor de noticias';
			echo '</a>';


			if(isset($_GET["gestorNoticias"])){
				include 'gestorNoticias.php';
				$gestor = new gestorNoticias();
				$gestor->mostrar();
			}
		} elseif(isset($_SESSION['tipo']) && $_SESSION['tipo'] == "editor jefe"){
			echo "<a class=\"boton-gestor\" href=\"panel.php?gestorNoticias\">";
			echo 'Gestor de noticias';
			echo '</a>';

			echo "<a class=\"boton-gestor\" href=\"panel.php?gestorComentarios\">";
			echo 'Gestor de comentarios';
			echo '</a>';

			echo "<a class=\"boton-gestor\" href=\"panel.php?gestorCategorias\">";
			echo 'Gestor de categorías';
			echo '</a>';

			echo "<a class=\"boton-gestor\" href=\"panel.php?gestorPublicidad\">";
			echo 'Gestor de publicidad';
			echo '</a>';

			if(isset($_GET["gestorNoticias"])){
				include 'gestorNoticias.php';
				$gestor = new gestorNoticias();
				$gestor->mostrar();
			}

			if(isset($_GET["gestorComentarios"])){
				include 'gestorComentarios.php';
				$gestor = new gestorComentarios();
				$gestor->mostrar();
			}

		if(isset($_GET["gestorCategorias"])){
			include 'gestorCategorias.php';
			$gestor = new gestorCategorias();
			$gestor->mostrar();
		}

		if(isset($_GET["gestorPublicidad"])){
			include 'gestorPublicidad.php';
			$gestor = new gestorPublicidad();
			$gestor->mostrar();
		}
	}

		echo '</div>';




		include 'footer.php';

		$ft = new footer();
		$ft->mostrar();

		echo '</body></html>';
	?>
