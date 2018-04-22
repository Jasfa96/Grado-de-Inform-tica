	<?php
	session_start();
	session_unset();
	session_destroy();
  echo "Sesión acabada";
  echo "<br><a href='index.php'>Volver a la página principal</a>";
	?>
