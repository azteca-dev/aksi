<?php

require_once('app/controllers.inc');


	$idrefaccion 	= $_POST["idrefaccion"];
	$idproducto 	= $_POST["idproducto"];
	$descripcion 	= $_POST["descripcion"];
	$posicion 		= $_POST["posicion"];


	$refaccionController = new RefaccionController();
	$Refaccion = new RefaccionModel();
	$Refaccion->idrefaccion = $idrefaccion;
	$Refaccion->idproducto = $idproducto;
	$Refaccion->descripcion = $descripcion;
	$Refaccion->posicion = $posicion;

	$refaccionController->saveRefaccion($Refaccion);


	header("Location:index.php");

  

?>