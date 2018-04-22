<?php
include 'database.php';


	 $db = new base_datos();

   $form_user = $_POST['username'];
	 $form_pass = $_POST['password'];
   $form_email = $_POST['email'];

   $db->conectar();

	 $db->registro($form_user, $form_pass, $form_email);

   $db->desconectar();

	?>
