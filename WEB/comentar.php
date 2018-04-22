<?php
	session_start();

  include 'database.php';
	if(isset($_GET["noticia"])){
	  $db = new base_datos();

	  $usuario = $_SESSION['username'];
	  $form_cuerpo = $_POST['cuerpo'];
		$noticia = $_GET["noticia"];

	  $db->conectar();

	  $db->comentarionoti($noticia, $usuario, $form_cuerpo);

	  $db->desconectar();

		header("Location: index.php/?noticia=$noticia");
		exit();
	}



?>
