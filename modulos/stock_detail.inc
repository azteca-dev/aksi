<?php

require_once('constants.inc');
require_once('controllers.inc');   


if(isset($_GET["id"])){

	$idrefaccion = $_GET["id"];
	$stockDetailController =  new StockDetailController();
	$stocks = $stockDetailController->getStockDetail($idrefaccion,"");

	$typeOrderMode = "OUT";
	if(isset($_GET["type"])){
		$typeOrderMode = $_GET["type"];
	}



?>
<form action="modulos/xt_addToOrder.php" method="POST" name="refaccionesAddToPedido">
	<input type="hidden" name="idrefaccion" value="<?= $idrefaccion ?>"/>
	<input type="hidden" name="typeOrderMode" value="<?= $typeOrderMode ?>"/>
	<h1 class="page-header"><span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> Selecciona el numero de pizas</h1>
	<div class="panel panel-default">
        <div class="panel-body">
        	<div class="container">
        	  <div class="row align-items-center">
        	  	<div class="col-md-4 ml-md-auto">
			      <h3># <?php echo $idrefaccion ?></h3>
			    </div>

			    <div class="col-md-4 ml-md-auto">
			      <a href="">AGREGAR</a> | <a href="">BUSCAR SIMILAR</a> | <a href="">SURTIR <b>SIN</b> STOCK</a>
			    </div>

        	  </div>
<?php
	if(count($stocks)> 0 ){
                   
   	 	foreach ($stocks as $stock) {
   	 		if ($stock->idubicacion != 'total') {
?>

			  <div class="row align-items-center">
			    <div class="col-md-2 ml-md-auto">
			      <?php echo $stock->idubicacion ?>
			    </div>
			    <div class="col-md-2 ml-md-auto">
			      <?php echo $stock->stock ?>
			    </div>
			    <div class="col-md-2 ml-md-auto">
			      <a href="">Eliminar</a> | <a href="">Modificar</a>
			    </div>
			    <div class="col-md-2 ml-md-auto">
			       <input type="text" name="<?php echo 'cant__'.$stock->idubicacion.'__'?>"  class="form-control" placeholder="Cantidad" >
			    </div>
			    <div class="col-md-2 ml-md-auto">
			      <input type="checkbox" name="<?php echo 'ref__'.$stock->idubicacion.'__'?>"/>
			    </div>
			  </div>

<?php
			}else{
				?>
					<h3> <small><?php echo $stock->idubicacion ?> :</small> <?php echo $stock->stock ?> </h3>
				<?php
			}
    	}
	}
?>


			  <div class="row align-items-center">
			  	<div class="col-md-4 ml-md-auto">
			      
			    </div>

			    <div class="col-md-4 ml-md-auto">
			     <button type="submit"  class="btn btn-success">Continuar</button> | <a href="">cancelar</a> 
			    </div>
        	  </div>

			</div>
        </div>
    </div>

</form>
<?php 

}else{
    echo "Ocurrio un problema, no podemos encontrar el id de la refaccion que quieres procesar";
}


?>