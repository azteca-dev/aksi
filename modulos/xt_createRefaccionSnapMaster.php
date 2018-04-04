<?php

require_once('app/controllers.inc');


	$idrefaccion 			= $_POST["idRefaccion"];
	$tipo 					= $_POST["tipo"];
	$cantidad 				= $_POST["cantidad"];
	$idubicacion 			= $_POST["idUbicacion"];
	$destino 				= $_POST["destino"];
	$referencia_destino 	= $_POST["destinoRef"];
	$idcliente 				= $_POST["idCliente"];
	$fuente_despacho 		= $_POST["fuenteDestino"];
	$idrefaccion_similar 	= $_POST["idRefaccionSimilar"];
	$nota 					= $_POST["nota"];

	$refaccionSnapMasterController = new RefaccionSnapMasterController();
	$RefaccionSnapMaster = new RefaccionSnapMasterModel();


	$RefaccionSnapMaster->idrefaccion 			= $idrefaccion;
	$RefaccionSnapMaster->tipo 					= $tipo;
	$RefaccionSnapMaster->cantidad 				= $cantidad;
	$RefaccionSnapMaster->idubicacion 			= $idubicacion;
	$RefaccionSnapMaster->destino 				= $destino;
	$RefaccionSnapMaster->referencia_destino 	= $referencia_destino;
	$RefaccionSnapMaster->idcliente 			= $idcliente;
	$RefaccionSnapMaster->fuente_despacho 		= $fuente_despacho;
	$RefaccionSnapMaster->idrefaccion_similar 	= $idrefaccion_similar;
	$RefaccionSnapMaster->nota 					= $nota;


	$refaccionSnapMasterController->registraSnap($RefaccionSnapMaster);

	header("Location:index.php");

  

?>