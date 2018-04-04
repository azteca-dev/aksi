<?php
	require_once('controllers.inc');
	require_once('models.inc');

	$idorden = $_POST['id'];
	$refaccionesPorOrdenController =  new RefaccionesPorOrdenController();
	$refacciones = $refaccionesPorOrdenController->getRefacciones($idorden);
	$totalRefaccion = count($refacciones);

	$tipoSurtido 	= $_POST['tipoSurtido'];
	$numReferencia 	= $_POST['numReferencia'];
	$nomSolicitante = $_POST['nomSolicitante'];
	$fechaOrden 	= $_POST['fechaOrden'];
	$notaOrden 		= $_POST['notaOrden'];
    $tipoMode       = $_POST['tipoMode'];

?>

<div>
    <h1 class="page-header"><span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> Confirmar surtido [#<?php echo $idorden ?>]</h1>
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

           

            <div class="total_report">Datos adicionales</div>
            <hr>

            <form action="modulos/xt_procesaOrden.php" method="POST">
                <input type="hidden" name="id" value="<?php echo $idorden ?>">
                <input type="hidden" name="tipoSurtido" value="<?php echo $tipoSurtido ?>">
                <input type="hidden" name="numReferencia" value="<?php echo $numReferencia ?>">
                <input type="hidden" name="nomSolicitante" value="<?php echo $nomSolicitante ?>">
                <input type="hidden" name="fechaOrden" value="<?php echo $fechaOrden ?>">
                <input type="hidden" name="notaOrden" value="<?php echo $notaOrden ?>">
                <input type="hidden" name="tipoMode" value="<?php echo $tipoMode ?>">


                <div class="form-group">
                    <label for="searchNotasFechaIni">Modo: <h2> <b><?php echo $tipoMode ?></b></h2></label>
                </div>

             	<div class="form-group">
                    <label for="searchNotasFechaIni">Tipo de surtido: <b><?php echo $tipoSurtido ?></b></label>
                </div>

                 <div class="form-group">
                    <label for="searchNotasFechaFin">#referencia : <b><?php echo $numReferencia ?></b> </label>
                </div>

                <div class="form-group">
                    <label for="searchNotasNotaMeli">Nombre del solicitante : <b><?php echo $nomSolicitante ?></b> </label>
                </div>

                <div class="form-group">
                    <label for="searchNotasFechaIni">Fecha de la Orden : <b><?php echo $fechaOrden ?></b> </label>
                </div>
                 
                <div class="form-group">
                    <label for="searchNotasNotaMarti">Nota: <b><?php echo $notaOrden ?></b> </label>
                </div>
             
			<hr>


                 <button type="submit"  class="btn btn-success">Confirmar</button>  |  <a href=""> Regresar </a>
            </form>    

        </div>
    </div>
</div>
