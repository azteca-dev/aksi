<?php
	require_once('controllers.inc');
	require_once('models.inc');

	$idorden = $_GET['id'];

    $ordenController = new OrdenController();
    $currentOrden = $ordenController->getOrderById($idorden);


if ($currentOrden[0]->status == 'openout' || $currentOrden[0]->status == 'openin'){

	$refaccionesPorOrdenController =  new RefaccionesPorOrdenController();
	$refacciones = $refaccionesPorOrdenController->getRefacciones($idorden);
	$totalRefaccion = count($refacciones);

?>

<div>
    <h1 class="page-header"><span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> Completa tu surtido [#<?php echo $idorden ?>]</h1>
    <div class="panel panel-default">
        <!-- Encabezado de la seccion de usuario -->
        <div class="panel-body">
           

            <div  class="table-responsive">

                <div class="total_report">Detalle de piezas</div>
                <hr>
<?php
if ($totalRefaccion>0) {

?>
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th>Refaccion</th>                          
                            <th>Descripcion</th>
                            <th>Ubicacion</th>
                            <th>Piezas</th>
                            <th>Similar</th>
                            <th>Nota</th>
                            <th>Acciones</th>
                        </tr>
                    </thead>
                    <tbody>
 <?php 
 	foreach ($refacciones as $refaccion) {
	
  ?>                 
                        <tr class="reportes">
                            <td><?php echo $refaccion->idrefaccion ?></td>
                            <td><?php echo $refaccion->descripcion ?></td>
                            <td><?php echo $refaccion->idubicacion ?></td>
                            <td><?php echo $refaccion->numPiezas ?></td>
                            <td><?php echo $refaccion->idrefaccion_similar ?></td>
                            <td><?php echo $refaccion->nota ?></td>
                            <td>  <a class="btn btn-danger" href="modulos/xt_elimina_refaccion_orden.php?id=<?php echo $idorden ?>&refaccion=<?php echo $refaccion->idrefaccion ?>&ubicacion=<?php echo $refaccion->idubicacion ?>" role="button">Eliminar</a></td>
                        </tr>
                    
 <?php 	} ?>      
                </tbody>           
                </table>

<?php
} else{
?>
		<div>Aun no incluyes ninguna refaccion en este surtido.</div>
<?php
}
?>

            </div>

            <a class="btn btn-primary" href="index.php" role="button">Agregar mas refacciones</a>

            <div class="total_report">Datos adicionales</div>
            <hr>

             <form name="" action="reviewOrden.php" method="POST" >
             	<input type="hidden" name="id" value="<?php echo $idorden ?>">
                <input type="hidden" name="tipoMode" value="<?=$currentOrden[0]->modo?>">

                <!--
                <div class="form-group">
                    <label for="searchNotasFechaIni">Modo de surtido</label>
                    <select class="form-control custom-select" name="tipoMode">
                      <option selected>Selecciona el modo de surtido</option>
                      <option value="IN">SALIDA</option>
                      <option value="OUT">IN</option>
                    </select>    
                </div>
            -->

             	<div class="form-group">
                    <label for="searchNotasFechaIni">Tipo de surtido</label>
                   	<select class="form-control custom-select" name="tipoSurtido">
					  <option selected>Selecciona el tipo de surtido</option>
					  <option value="ORDEN DE TRABAJO">Order de Trabajo</option>
					  <option value="PEDIDO">Pedido</option>
					  <option value="USO INTERNO">Uso Interno</option>
					</select>
                </div>

                 <div class="form-group">
                    <label for="searchNotasFechaFin">#referencia</label>
                   <input type="text" id="referencia" name="numReferencia" class="form-control" placeholder="#Referencia"  >
                </div>

                <div class="form-group">
                    <label for="searchNotasNotaMeli">Nombre del solicitante</label>
                    <input type="text"  id="Text2" class="form-control" name="nomSolicitante" placeholder="Quien solicta"  >
                </div>

                <div class="form-group">
                    <label for="searchNotasFechaIni">Fecha de la Orden</label>
                   <input id="Date1" type='date' ng-model="searchNotaFechaIni" name="fechaOrden" class="form-control" />
                </div>
                 
                <div class="form-group">
                    <label for="searchNotasNotaMarti">Nota:</label>
                    <input type="text"  id="Text1" name="notaOrden" class="form-control"  >
                </div>
             
			<hr>

                <button type="submit"  class="btn btn-success">Continuar</button>
                
            </form>

        </div>
    </div>
</div>

<?php
} else {

?>

   <div class="panel panel-default">
        <!-- Encabezado de la seccion de usuario -->
        <div class="panel-body">
                <h1> Esta orden ya fue procesada ... </h1>
        </div>
    </div> 

<?php
}  
?>