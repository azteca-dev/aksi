<?php

	require_once('./modulos/controllers.inc');
    require_once('./modulos/models.inc');
    $ordenController = new OrdenController();
    $ordenes = $ordenController->getOrderByStatus('complete');

    $ordenesSalidas = array();
    $ordenesEntradas = array();
    $indexSalidas = 0;
    $indexEntradas = 0;
    foreach ($ordenes as $orden) {
    	if($orden->modo == 'IN'){
    		$ordenesEntradas[$indexEntradas] = $orden;
    		$indexEntradas = $indexEntradas + 1;
    	}

    	if ($orden->modo == 'OUT'){
    		$ordenesSalidas[$indexSalidas] = $orden;
    		$indexSalidas = $indexSalidas + 1;
    	}
    }


?>

<div>
    <h1 class="page-header"><span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> Mis Surtidos</h1>
    <hr>
    <h3> Salidas  [<?=count($ordenesSalidas)?>] </h3>
    <div class="panel panel-default">
        <div class="panel-body">
 		<?php 
 			if (count($ordenesSalidas)>0){
 		?>
 				<table class="table">
				  <thead class="thead-dark">
				    <tr>
				      <th scope="col">#</th>
				      <th scope="col">Fecha</th>
				      <th scope="col">Tipo</th>
				      <th scope="col">Numero</th>
				      <th scope="col">Solicitante</th>
				      <th scope="col">Nota</th>
				    </tr>
				  </thead>
				  <tbody>
 		<?php
 			foreach ($ordenesSalidas as $ordenSalida) {
 		?>
 			 <tr>
		      <td><?=$ordenSalida->idorden?></td>
		      <td><?=$ordenSalida->fechaOrden?></td>
		      <td><?=$ordenSalida->tipoOrden?></td>
		      <td><?=$ordenSalida->numeroTipoOrden?></td>
		      <td><?=$ordenSalida->nombreSolicitante?></td>
		      <td><?=$ordenSalida->nota?></td>
		    </tr>
 		<?php
 			}
 		?>
 			</tbody>
 			</table>
 		<?php
 			}else{
 	    ?>
 	    	<h3>No tenemos ordenes de salida registradas</h3>
 	    <?php 
 			}
 		?>
        </div>
    </div>

	<h3> Entradas [<?=count($ordenesEntradas)?>]</h3>
    <div class="panel panel-default">
        <div class="panel-body">
        <?php 
 			if (count($ordenesEntradas)>0){
 		?>
 				<table class="table">
				  <thead class="thead-dark">
				    <tr>
				      <th scope="col">#</th>
				      <th scope="col">Fecha</th>
				      <th scope="col">Tipo</th>
				      <th scope="col">Numero</th>
				      <th scope="col">Solicitante</th>
				      <th scope="col">Nota</th>
				    </tr>
				  </thead>
				  <tbody>
 		<?php
 			foreach ($ordenesEntradas as $ordenEntrada) {
 		?>
 			 <tr>
		      <td><?=$ordenEntrada->idorden?></td>
		      <td><?=$ordenEntrada->fechaOrden?></td>
		      <td><?=$ordenEntrada->tipoOrden?></td>
		      <td><?=$ordenEntrada->numeroTipoOrden?></td>
		      <td><?=$ordenEntrada->nombreSolicitante?></td>
		      <td><?=$ordenEntrada->nota?></td>
		    </tr>
 		<?php
 			}
 		?>
 			</tbody>
 			</table>
 		<?php
 			}else{
 	    ?>
 	    	<h3>No tenemos ordenes de entrada registradas</h3>
 	    <?php 
 			}
 		?>
        </div>
    </div>

</div>