<?php
class gestorCategorias{
  private $bd;

  private $categoria;
  private $categoriaPadre;
  private $modicategoria;
  private $modicategoriaPadre;
  private $modi2categoria;
  private $modi2categoriaPadre;
  private $elicategoria;

  public function gestorCategorias(){
    $this->bd=new base_datos();
    $this->bd->conectar();
    if(isset($_GET["Categoria"]) && isset($_GET["Categoriapadre"])){
      $this->categoria=$_GET["Categoria"];
      $this->categoriaPadre=$_GET["Categoriapadre"];
      $this->bd->introducirSeccion($this->categoria, $this->categoriaPadre);
    }elseif(isset($_GET["modiCategoria"]) && isset($_GET["modiCategoriapadre"])){
      $this->modicategoria=$_GET["modiCategoria"];
      $this->modicategoriaPadre=$_GET["modiCategoriapadre"];
      $this->bd->editarNombreSeccion($this->modicategoria, $this->modicategoriaPadre);
    }elseif(isset($_GET["modi2Categoria"]) && isset($_GET["modi2Categoriapadre"])){
      $this->modi2categoria=$_GET["modi2Categoria"];
      $this->modi2categoriaPadre=$_GET["modi2Categoriapadre"];
      $this->bd->editarPadreSeccion($this->modi2categoria, $this->modi2categoriaPadre);
    }elseif(isset($_GET["eliCategoria"])){
      $this->elicategoria=$_GET["eliCategoria"];
      $this->bd->eliminarCategoria($this->elicategoria);
    }
  }


  public function mostrar(){
    $resultado= $this->bd->obtenerTablaCategorias();
    if(mysqli_num_rows($resultado) == 0){
      echo "No hay Categorias";
    }else{
        echo '<div style="text-align:center;">';
        echo "<table border = '1' style=\"margin: 0 auto;\"> \n";
        echo "<tr><td>ID</td><td>Seccion</td><td>ID de Seccion Padre</td></tr> \n";
        while ($row = $resultado->fetch_array()){
          echo "<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td></tr> \n";
        }
        echo "</table></div> \n";
      }

      echo '<form class="formGestor" action="/panel.php">
        <div class="container">
          <input type="hidden" name="gestorCategorias">
          <p><label>Introduce nombre de la nueva categoria</label></p>
          <input type="text" name="Categoria">
          <p><label>Introduce la id del padre de la nueva categoria (Dejalo en NULL si no tiene)</label></p>
          <input type="text" name="Categoriapadre">
          <div class="clearfix">
            <input type="submit" class="signupbtn" value="Introducir nueva categoria">
          </div>
        </div></form>';

        echo '<form class="formGestor" action="/panel.php">
          <div class="container">
            <input type="hidden" name="gestorCategorias">
            <p><label>Introduzca el id de la categoria a modificar</label></p>
            <input type="text" name="modiCategoria">
            <p><label>Introduce el nuevo nombre</label></p>
            <input type="text" name="modiCategoriapadre">
            <div class="clearfix">
              <input type="submit" class="signupbtn" value="Modificar Categoria">
            </div>
          </div></form>';

          echo '<form class="formGestor" action="/panel.php">
            <div class="container">
              <input type="hidden" name="gestorCategorias">
              <p><label>Introduzca el id de la categoria a modificar, tambien puede convertir una subcategoria en una categoria padre (Usando NULL como categoria padre). </label></p>
              <input type="text" name="modi2Categoria">
              <p><label>Introduce el nuevo padre</label></p>
              <input type="text" name="modi2Categoriapadre">
              <div class="clearfix">
                <input type="submit" class="signupbtn" value="Modificar Categoria">
              </div>
            </div></form>';

          echo '<form class="formGestor" action="/panel.php">
            <div class="container">
              <input type="hidden" name="gestorCategorias">
              <p><label>Introduce la id de la seccion que quiere eliminar(No se puede eliminar una categoria principal sin eliminar sus subcategorias previamente)</label></p>
              <input type="text" name="eliCategoria">
              <div class="clearfix">
                <input type="submit" class="signupbtn" value="Eliminar Categoria">
              </div>
            </div></form>';


      $this->bd->desconectar();
    }
  }



	?>
