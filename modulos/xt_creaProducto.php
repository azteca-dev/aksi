<?php

require_once('controllers.inc');


	$idProducto 	= $_POST["idProducto"];
	$nombreProducto = $_POST["nombreProducto"];
	$urlDiagrama 	= $_POST["urlDiagrama"];


	$productoController = new ProductoController();
	$Producto = new ProductoModel();
	$Producto->idproducto = $idProducto;
	$Producto->nombre = $nombreProducto;
	$Producto->url_diagrama_pdf = $urlDiagrama;
	$Producto->status = "active";


	$productoController->saveProducto($Producto);

	header("Location:../index.php");

  

?>