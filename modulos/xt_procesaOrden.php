<?php

	require_once('controllers.inc');
	require_once('models.inc');

	if (isset($_POST['id'])) {
		$idorden = $_POST['id'];
		$tipoSurtido 	= $_POST['tipoSurtido'];
		$numReferencia 	= $_POST['numReferencia'];
		$nomSolicitante = $_POST['nomSolicitante'];
		$fechaOrden 	= $_POST['fechaOrden'];
		$notaOrden 		= $_POST['notaOrden'];
		$tipoMode		= $_POST['tipoMode'];

		$status = "complete";

		$ordenProcess = new OrdenModel();
		$ordenProcess->idorden 				= $idorden;
		$ordenProcess->tipoOrden 			= $tipoSurtido;
		$ordenProcess->numeroTipoOrden		= $numReferencia;
		$ordenProcess->nombreSolicitante	= $nomSolicitante;
		//$ordenProcess->fechaCreacion		= $numReferencia;
		$ordenProcess->fechaOrden			= $fechaOrden;
		$ordenProcess->status 				= $status;
		$ordenProcess->idUserCreator 		= 1;
		$ordenProcess->nota 				= $notaOrden;
		$ordenProcess->modo 				= $tipoMode;
		//$ordenProcess->fechaActualizacion 	= ;


		// LLAMAMOS LA RUTINA DE UPDATE

		$ordenController = new OrdenController();
		$ordenUpdate = $ordenController->setOrden($ordenProcess);

		// HACEMOS LA REDIRECCION

		header("Location:../index.php");

	}else{
		echo "Erro al procesar la order faltan datos";
	}


?>