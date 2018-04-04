<?php
require_once('constants.inc');
require_once('controllers.inc');        
?>
<div>
    <h1 class="page-header"><span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> HOME</h1>

    <div class="nav-scroller bg-white box-shadow">
      <nav class="nav nav-underline">
         <a data-toggle="modal" data-target="#formRefaccion" class="nav-link" href="#">Refacción</a>
        | <a data-toggle="modal" data-target="#formProducto" class="nav-link" href="#">Producto</a>
        | <a data-toggle="modal" data-target="#formUbicacion" class="nav-link" href="#">Ubicación</a>
      </nav>
    </div>

	  <section class="jumbotron text-center">
	    <div class="container">
	      <form  class="form-inline" action="index.php" method="POST">
	      	<input type="hidden" name="search" value="1">
	      
           <input type="text" name="idDescripcion"  class="form-control form-control-lg text_box_search" placeholder="Escribe los que buscas" >
	      
	      <p>
	         <button type="submit"  class="btn btn-success">Buscar</button>
	      </p>
	      </form>
	    </div>
	  </section>

<?php
 if (isset($_POST['search'])){
?>
	<h3><small>Resultados para la busqueda : </small> <?php echo $_POST["idDescripcion"] ?></h3>
    <div class="panel panel-default">
        <div class="panel-body">
           		
            <div  class="table-responsive">
                  
                <?php


                 if(isset($_POST["idRefaccion"])){
                    $idRefaccion = $_POST["idRefaccion"];
                }else{
                	$idRefaccion = "";
                }

                 if(isset($_POST["idProducto"])){
                    $idProducto = $_POST["idProducto"];
                }else{
                    $idProducto = "";
                }

                 if(isset($_POST["idPosicion"])){
                    $posicion = $_POST["idPosicion"];
                }else{
                    $posicion = "";
                }

                 if(isset($_POST["idDescripcion"])){
                    $query = $_POST["idDescripcion"];
                }else{
                    $query = "";
                }

                    $refaccionController = new RefaccionController();
                    
                    $Refacciones = $refaccionController->searchRefaccion($idRefaccion,$idProducto,$posicion,$query);
                   
                    $totalRefacciones = count($Refacciones);
                

                ?>

                <?php

                if( $totalRefacciones > 0){

                    
                ?>
                <div id="Div1"  class="total_report">
                    Total de refacciones = <?php echo $totalRefacciones ?>
                </div>
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th>Refaccion</th>                          
                            <th>Producto</th>
                            <th>Inventario</th>
                            <th>Acciones</th>

                        </tr>
                    </thead>
                    <tbody>

                <?php
                    foreach ($Refacciones as $Refaccion) {

                        
                        echo '    <tr  class="reportes">';
                        echo '        <td>';
                        echo    $Refaccion->idrefaccion;
                        echo '<br>'.$Refaccion->descripcion.' </td>';
                        echo '        <td>'.$Refaccion->idproducto.'-'.$Refaccion->posicion.'  <a href="uploads/pdf/190903.pdf">Diagrama</a> <br>';
                        echo '        '.$Refaccion->nombre.'</td>';
                        echo '        <td>'.$Refaccion->status.' <br> <a href="stock_detail.php?id='.$Refaccion->idrefaccion.'" >[ '.$Refaccion->total.' ]</a></td>';
                        echo '        <td valign="top">';
                        echo '            <a href="#" >Editar</a> <br>';
                        echo '            <a href="stock_detail.php?id='.$Refaccion->idrefaccion.'&type=IN" >Agregar Inventario</a> <br>';
                        echo '        </td>';
                                
                        echo '    </tr>';
                        

                    }
                ?> 
                    </tbody>
                    </table>
                

                <?php
                }else{
                    echo "ups no hay refacciones registradas con ese filtro seleccionado";
                }

                ?>

            </div>

        </div>
    </div>

<?php    
} // fin del iff de busqueda 
?>



<!-- Opciones de agregacion -->
<?php
include("productos.inc");
include("ubicaciones.inc");
include("refacciones.inc");
?>

<!-- Terminan opciones de agregacion -->




</div>



