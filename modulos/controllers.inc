<?php
require_once('services.inc');

class UbicacionController {

	private $ubicacionService;

	function __construct(){
		$this->ubicacionService = new UbicacionService();
	}

	

	public function searchUbicaciones($idubicacion){
		$this->ubicacionService->getUbicaciones($idubicacion);
		return $this->ubicacionService->Ubicaciones;
	}

	public function createUbicacion($Ubicacion){
		$this->ubicacionService->setUbicacion($Ubicacion);
		
	}

	function __destruct(){
		
	}
}

class ProductoController {
	
	private $productoService;

	function __construct(){
		$this->productoService = new ProductoService();
	}

	public function searchProductos($idProducto, $query){
		$this->productoService->getProductos($idProducto, $query);
		return $this->productoService->Productos;
	}

	public function saveProducto($Producto){
		$this->productoService->setProducto($Producto);
	}


	function __destruct(){

	}

}


class RefaccionController{

	private $refaccionService;

	function __construct(){
		$this->refaccionService = new RefaccionService();
	}

	public function searchRefaccion($idRefaccion,$idProducto,$posicion,$query){
		$this->refaccionService->getRefaccion($idRefaccion,$idProducto,$posicion,$query);
		return $this->refaccionService->Refacciones;
	}

	public function saveRefaccion($Refaccion){
		$this->refaccionService->setRefaccion($Refaccion);
	}


	function __destruct(){

	}
}

class TecnicoController{

	private $tecnicoService;

	function __construct(){
		$this->tecnicoService = new TecnicoService();
	}

	public function searchTecnico($idTecnico, $nombreTecnico, $departamento){
		$this->tecnicoService->getTecnico($idTecnico, $nombreTecnico, $departamento);
		return $this->tecnicoService->Tecnicos;
	}

	public function saveTecnico($Tecnico){
		$this->tecnicoService->setTecnico($Tecnico);
	}

	function __destruct(){

	}
}


class RefaccionSnapMasterController {
	
	private $refaccionSnapMasterService;

	function __construct(){
		$this->refaccionSnapMasterService = new RefaccionSnapMasterService();
	}

	function registraSnap($RefaccionSnapMaster){
		$this->refaccionSnapMasterService->setRefaccionSnapMaster($RefaccionSnapMaster);
	}

	function __destruct(){

	}

}


class StockDetailController {
	
	private $stockDetailService;

	function __construct(){
		$this->stockDetailService = new StockDetailService();
	}

	function getStockDetail($idrefaccion, $idubicacion){
		$this->stockDetailService->getStockDetail($idrefaccion, $idubicacion);
		return $this->stockDetailService->StockDetailMasterList;
	}

	function creaInicialStockEnUbicacion($idrefaccion, $idubicacion){
		$this->stockDetailService->setInitialStockForUbication($idrefaccion, $idubicacion);
		
	}

	function __destruct(){

	}

}


class OrdenController {
	private $ordenService;
	
	function __construct(){
		$this->ordenService = new OrdenService();
	}

	function setOrden($Orden){
		$this->ordenService->insupdOrden($Orden);
		return $this->ordenService->Ordenes;
	}

	function getOrderById($idorden){
		$this->ordenService->getOrden($idorden);
		return $this->ordenService->Ordenes;
	}

	function getOrderByStatus($status){
		$this->ordenService->getOrdenByStatus($status);
		return $this->ordenService->Ordenes;
	}
}


class RefaccionesPorOrdenController {
	private $refaccionesPorOrdenService;
	
	function __construct(){
		$this->refaccionesPorOrdenService = new RefaccionesPorOrdenService();
	}

	function setRefaccion($newRefaccion){
		$this->refaccionesPorOrdenService->setRefaccion($newRefaccion);
		return $this->refaccionesPorOrdenService->Refacciones;
	}

	function getRefacciones($idorden){
		$this->refaccionesPorOrdenService->getRefacciones($idorden);
		return $this->refaccionesPorOrdenService->Refacciones;
	}

	function deleteRefaccion($delRefaccion){
		$this->refaccionesPorOrdenService->deleteRefaccion($delRefaccion);
	}
}


























?>