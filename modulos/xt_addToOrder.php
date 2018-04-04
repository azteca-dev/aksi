<?php
	require_once('controllers.inc');
	require_once('models.inc');

	$typeOrderMode = $_POST["typeOrderMode"];

	$typeOrderToSearch = "openout";

	if ($typeOrderMode == 'IN'){
		$typeOrderToSearch = 'openin';
	}


	
	// identificamos si hay ordenes abiertas y si no creamos una

	$ordenController = new OrdenController();
	$orden = $ordenController->getOrderByStatus($typeOrderToSearch);
	$idorden = 0;

	if (count($orden)>0){
		$idorden = $orden[0]->idorden;

	}else{

		$newOrden = new OrdenModel();

		$newOrden->idorden = 0;
		$newOrden->tipoOrden = 'NEW';
		$newOrden->numeroTipoOrden = 'NEW';
		$newOrden->nombreSolicitante = 'NEW';
		//$newOrden->fechaCreacion;
		//$newOrden->fechaOrden;
		$newOrden->status = $typeOrderToSearch;
		$newOrden->idUserCreator = 1;
		$newOrden->nota = 'N/D';
		//$newOrden->fechaActualizacion;
		$newOrden->modo = $typeOrderMode;
		
		$newOrdenOpen = $ordenController->setOrden($newOrden);

		$idorden = $newOrdenOpen[0]->idorden;
	}


	$refaccionesPreprocesado = array();
	$listaRefacciones = array();
	$newRefaccion = new RefaccionesXOrdenModel();

	
	$idrefaccion = $_POST['idrefaccion'];


	$index = 0;
	foreach($_POST as $nombre_campo => $valor){ 
   		if(strpos($nombre_campo, "ref__") > -1 ){
   			$refaccionesPreprocesado[$index] = $nombre_campo;
   			$index = $index+1;
   		}
	}

	$index = 0;
	foreach ($refaccionesPreprocesado as $key) {
		$cantidad = $_POST[str_replace("ref__", "cant__", $key)];
		$ubicacion = str_replace("__", "",str_replace("ref__", "", $key));
		$newRefaccion = new RefaccionesXOrdenModel();
		$newRefaccion->idrefaccion = $idrefaccion;
		$newRefaccion->idorden = $idorden;
		$newRefaccion->idubicacion = $ubicacion;
		$newRefaccion->numPiezas = $cantidad;
		$newRefaccion->idrefaccion_similar = 'sin similar';
		$newRefaccion->nota = 'sin nota';
		$listaRefacciones[$index] = $newRefaccion;
		$index = $index+1;

	}

	try{
		foreach ($listaRefacciones as $ref) {
			$refaccionesPorOrdenController =  new RefaccionesPorOrdenController();
			$refaccionesPorOrdenController->setRefaccion($ref);
		}
	}catch(Exception $e){
		$error = "No pudimos completar tu peticion [".$e->getMessage()."]";
	}



	header("Location:../pivote.php?id=".$idorden."&error=".$error);

?>