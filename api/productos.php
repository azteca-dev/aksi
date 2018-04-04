<?php
	require_once "controllers/ProductController.inc";
	$productController = new ProductApiController();
	$productController->manager();

?>