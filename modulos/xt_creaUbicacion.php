<?php

require_once('controllers.inc');


	$idUbicacion = $_POST["idUbicacion"];
	$nota = $_POST["nota"];


	$ubicacionController = new UbicacionController();
	$Ubicacion = new UbicacionModel();
	$Ubicacion->idUbicacion = $idUbicacion;
	$Ubicacion->status = "active";
	$Ubicacion->nota = $nota;


	$ubicacionController->createUbicacion($Ubicacion);

	header("Location:../ubicaciones.php");

  

?>