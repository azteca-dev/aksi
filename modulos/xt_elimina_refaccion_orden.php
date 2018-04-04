<?php


	require_once('controllers.inc');
	require_once('models.inc');


	$idorden = $_GET["id"];
	$idrefaccion = $_GET["refaccion"];
	$idubicacion =  $_GET['ubicacion'];

	$refaccionesPorOrdenController =  new RefaccionesPorOrdenController();
	$delRefaccion = new RefaccionesXOrdenModel();
	$delRefaccion->idorden = $idorden;
	$delRefaccion->idrefaccion = $idrefaccion;
	$delRefaccion->idubicacion = $idubicacion;

	$refaccionesPorOrdenController->deleteRefaccion($delRefaccion);
	
	header("Location:../completeOrden.php?id=".$idorden);


?>