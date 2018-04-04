<?php

require_once('dataBase.inc');
require_once('models.inc');

class UbicacionService extends DataBase {

	public $Ubicacion;
	public $Ubicaciones;


	function __construct(){
		$this->Ubicacion = new UbicacionModel();
		$this->Ubicaciones = array();
	}

	public function getUbicaciones($idUbicacion){
		$this->rows = array();
		$this->Ubicacion = new UbicacionModel();
		$this->Ubicaciones = array();

		$this->query = "call sp_search_ubicacion ('".$idUbicacion."')";
		$this->getResultFromQuery();

		$this->pushListUbicacion();
	}

	public function setUbicacion($Ubicacion){
		$this->rows = array();
		$this->Ubicacion = new UbicacionModel();
		$this->Ubicaciones = array();

		$this->query = "call sp_insupd_ubicacion ( '".$Ubicacion->idubicacion."', '".$Ubicacion->status."', '".$Ubicacion->nota."')";
		$this->getResultFromQuery();

		$this->pushListUbicacion();
	}

	private function pushListUbicacion(){
		if(count($this->rows) > 0){
			$Ubicaciones = array();
			$index = 0;
			foreach ($this->rows as $registro) {
				$this->Ubicacion = new UbicacionModel();
				foreach ($registro as $key => $value) {
					$this->Ubicacion->$key = $value;
				}
				$this->Ubicaciones[$index] = ($this->Ubicacion);
				$index ++;
			}
			$this->message = "Registro encontrado";

		}else{
			$this->message = "No hay registros";
		}
	}

	public function get(){}
	public function set(){}
	public function edit(){}
	public function delete(){}

	function __destruct(){

	}
}


//  ********************  servicio para el producto **************************************************** 

class ProductoService extends DataBase {

	public $Producto;
	public $Productos;


	function __construct(){
		$this->Producto = new ProductoModel();
		$this->Productos = array();
	}

	public function getProductos($idProducto, $query){
		$this->rows = array();
		$this->Producto = new ProductoModel();
		$this->Productos = array();

		$this->query = "call sp_search_producto ('".$idProducto."', '".$query."')";
		$this->getResultFromQuery();

		$this->pushListProducto();
	}

	public function setProducto($Producto){
		$this->rows = array();
		$this->Producto = new ProductoModel();
		$this->Productos = array();

		$this->query = "call sp_insupd_producto ('".$Producto->idproducto."','".$Producto->nombre."','".
		$Producto->status."','".$Producto->url_diagrama_pdf."')";
		$this->getResultFromQuery();

		$this->pushListProducto();
	}

	private function pushListProducto(){
		if(count($this->rows) > 0){
			$Productos = array();
			$index = 0;
			foreach ($this->rows as $registro) {
				$this->Producto = new ProductoModel();
				foreach ($registro as $key => $value) {
					$this->Producto->$key = $value;
				}
				$this->Productos[$index] = ($this->Producto);
				$index ++;
			}
			$this->message = "Registro encontrado";

		}else{
			$this->message = "No hay registros";
		}
	}

	public function get(){}
	public function set(){}
	public function edit(){}
	public function delete(){}

	function __destruct(){

	}
}



//  ********************  servicio para la refaccion **************************************************** 

class RefaccionService extends DataBase {

	public $Refaccion;
	public $Refacciones;


	function __construct(){
		$this->Refaccion = new RefaccionModel();
		$this->Refacciones = array();
	}

	public function getRefaccion($idRefaccion,$idProducto,$posicion,$query){
		$this->rows = array();
		$this->Refaccion = new RefaccionModel();
		$this->Refacciones = array();

		$this->query = "call sp_search_refaccion ('".$idRefaccion."','".$idProducto."','".$posicion."','".$query."')";
		
		$this->getResultFromQuery();

		$this->pushListRefaccion();
	}

	public function setRefaccion($Refaccion){
		$this->rows = array();
		$this->Refaccion = new RefaccionModel();
		$this->Refacciones = array();

		$this->query = "call sp_insupd_refaccion ('".$Refaccion->idrefaccion."','".$Refaccion->idproducto."','".$Refaccion->descripcion."','".$Refaccion->status."','".$Refaccion->posicion."')";

		$this->getResultFromQuery();

		$this->pushListRefaccion();
	}

	private function pushListRefaccion(){
		if(count($this->rows) > 0){
			$Refacciones = array();
			$index = 0;
			foreach ($this->rows as $registro) {
				$this->Refaccion = new RefaccionModel();
				foreach ($registro as $key => $value) {
					$this->Refaccion->$key = $value;
				}
				$this->Refacciones[$index] = ($this->Refaccion);
				$index ++;
			}
			$this->message = "Registro encontrado";

		}else{
			$this->message = "No hay registros";
		}
	}

	public function get(){}
	public function set(){}
	public function edit(){}
	public function delete(){}

	function __destruct(){

	}
}



//  *****************  servicio para la refaccion similar **************************************************** 

class RefaccionSimilarService extends DataBase {

	public $RefaccionSimilar;
	public $RefaccionesSimilares;


	function __construct(){
		$this->RefaccionSimilar = new RefaccionSimilarModel();
		$this->RefaccionesSimilares = array();
	}

	public function getRefaccionSimilar($idRefaccion){
		$this->rows = array();
		$this->RefaccionSimilar = new RefaccionSimilarModel();
		$this->RefaccionesSimilares = array();

		$this->query = "call sp_search_refaccion_similar ('".$idRefaccion."')";
		
		$this->getResultFromQuery();

		$this->pushListRefaccionSimilar();
	}

	public function setRefaccionSimilar($RefaccionSimilar){
		$this->rows = array();
		$this->RefaccionSimilar = new RefaccionSimilarModel();
		$this->RefaccionesSimilares = array();

		$this->query = "call sp_insupd_refaccion_similar ('".$RefaccionSimilar->idrefaccion."','".$RefaccionSimilar->idrefaccion_similar."')";

		$this->getResultFromQuery();

		$this->pushListRefaccionSimilar();
	}

	private function pushListRefaccionSimilar(){
		if(count($this->rows) > 0){
			$RefaccionesSimilares = array();
			$index = 0;
			foreach ($this->rows as $registro) {
				$this->RefaccionSimilar = new RefaccionSimilarModel();
				foreach ($registro as $key => $value) {
					$this->RefaccionSimilar->$key = $value;
				}
				$this->RefaccionesSimilares[$index] = ($this->RefaccionSimilar);
				$index ++;
			}
			$this->message = "Registro encontrado";

		}else{
			$this->message = "No hay registros";
		}
	}

	public function get(){}
	public function set(){}
	public function edit(){}
	public function delete(){}

	function __destruct(){

	}
}


//  ********************  servicio para los tecnicos ********************************************** 

class TecnicoService extends DataBase {

	public $Tecnico;
	public $Tecnicos;


	function __construct(){
		$this->Tecnico = new TecnicoModel();
		$this->Tecnicos = array();
	}

	public function getTecnico($idTecnico, $nombreTecnico, $departamento){
		$this->rows = array();
		$this->Tecnico = new TecnicoModel();
		$this->Tecnicos = array();

		$this->query = "call sp_search_tecnico(".$idTecnico.", '".$nombreTecnico."', '".$departamento."')";
		
		$this->getResultFromQuery();

		$this->pushListTecnico();
	}

	public function setTecnico($Tecnico){
		$this->rows = array();
		$this->Tecnico = new TecnicoModel();
		$this->Tecnicos = array();

		$this->query = "call sp_insupd_tecnico ('".$Tecnico->nombre."', '".$Tecnico->departamento."', '".$Tecnico->status."')";

		$this->getResultFromQuery();

		$this->pushListTecnico();
	}

	private function pushListTecnico(){
		if(count($this->rows) > 0){
			$Tecnicos = array();
			$index = 0;
			foreach ($this->rows as $registro) {
				$this->Tecnico = new TecnicoModel();
				foreach ($registro as $key => $value) {
					$this->Tecnico->$key = $value;
				}
				$this->Tecnicos[$index] = ($this->Tecnico);
				$index ++;
			}
			$this->message = "Registro encontrado";

		}else{
			$this->message = "No hay registros";
		}
	}

	public function get(){}
	public function set(){}
	public function edit(){}
	public function delete(){}

	function __destruct(){

	}
}


//  ********************  servicio para las entradas/salidas de inv ************************************* 

class RefaccionSnapMasterService extends DataBase {

	public $RefaccionSnapMaster;
	public $RefaccionSnapMasterList;


	function __construct(){
		$this->RefaccionSnapMaster = new RefaccionSnapMasterModel();
		$this->RefaccionSnapMasterList = array();
	}

/*
	public function getRefaccionSnapMaster($idTecnico, $nombreTecnico, $departamento){
		$this->rows = array();
		$this->RefaccionSnapMaster = new RefaccionSnapMasterModel();
		$this->RefaccionSnapMasterList = array();

		$this->query = "";
		
		$this->getResultFromQuery();

		$this->pushListRefaccionSnapMaster();
	}
*/
	public function setRefaccionSnapMaster($RefaccionSnapMaster){
		$this->rows = array();
		$this->RefaccionSnapMaster = new RefaccionSnapMasterModel();
		$this->RefaccionSnapMasterList = array();

		$this->query = "call sp_refaccion_inout ( current_timestamp, '".$RefaccionSnapMaster->idrefaccion."', '".$RefaccionSnapMaster->tipo."', ".$RefaccionSnapMaster->cantidad.", '".$RefaccionSnapMaster->idubicacion."', '".$RefaccionSnapMaster->destino."','".$RefaccionSnapMaster->referencia_destino."', '".$RefaccionSnapMaster->idcliente."', '".$RefaccionSnapMaster->fuente_despacho."', '".$RefaccionSnapMaster->idrefaccion_similar."', '".$RefaccionSnapMaster->nota."')";

		$this->getResultFromQuery();

		$this->pushListRefaccionSnapMaster();
	}

	private function pushListRefaccionSnapMaster(){
		if(count($this->rows) > 0){
			$RefaccionSnapMasterList = array();
			$index = 0;
			foreach ($this->rows as $registro) {
				$this->RefaccionSnapMaster = new RefaccionSnapMasterModel();
				foreach ($registro as $key => $value) {
					$this->RefaccionSnapMaster->$key = $value;
				}
				$this->RefaccionSnapMasterList[$index] = ($this->RefaccionSnapMaster);
				$index ++;
			}
			$this->message = "Registro encontrado";

		}else{
			$this->message = "No hay registros";
		}
	}

	public function get(){}
	public function set(){}
	public function edit(){}
	public function delete(){}

	function __destruct(){

	}
}



//  ********************  servicio para las gestion de inventario por ubicacion  ************************************* 

class StockDetailService extends DataBase {

	public $StockDetailMaster;
	public $StockDetailMasterList;


	function __construct(){
		$this->StockDetailMaster = new StockDetailModel();
		$this->StockDetailMasterList = array();
	}


	public function getStockDetail($idrefaccion, $idubicacion){
		$this->rows = array();
		$this->StockDetailMaster = new StockDetailModel();
		$this->StockDetailMasterList = array();

		$this->query = "call sp_get_stock('".$idrefaccion."', '".$idubicacion."');";

		$this->getResultFromQuery();

		$this->pushListStockDetailMaster();

	}

	// agregamos el metodo para crear ubicaciones de estoc por refaccion 

	public function setInitialStockForUbication($idrefaccion, $idubicacion){
		$this->rows = array();
		$this->StockDetailMaster = new StockDetailModel();
		$this->StockDetailMasterList = array();

		$this->query = "call sp_create_ubicacion_for_refaccion('".$idrefaccion."', '".$idubicacion."');";

		$this->executeSingleQuery();
	}


	private function pushListStockDetailMaster(){
		if(count($this->rows) > 0){
			$StockDetailMasterList = array();
			$index = 0;
			foreach ($this->rows as $registro) {
				$this->StockDetailMaster = new StockDetailModel();
				foreach ($registro as $key => $value) {
					$this->StockDetailMaster->$key = $value;
				}
				$this->StockDetailMasterList[$index] = ($this->StockDetailMaster);
				$index ++;
			}
			$this->message = "Registro encontrado";

		}else{
			$this->message = "No hay registros";
		}
	}

	public function get(){}
	public function set(){}
	public function edit(){}
	public function delete(){}

	function __destruct(){

	}
}



//  ********************  servicio para la administracion de las ordenes ********************************************** 

class OrdenService extends DataBase {

	public $Orden;
	public $Ordenes;


	function __construct(){
		$this->Orden = new OrdenModel();
		$this->Ordenes = array();
	}

	public function getOrden($idorden){
		$this->rows = array();
		$this->Orden = new OrdenModel();
		$this->Ordenes = array();

		$this->query = "call sp_get_orden(".$idorden.")";
		
		$this->getResultFromQuery();

		$this->pushListOrden();
	}

	public function getOrdenByStatus($status){
		$this->rows = array();
		$this->Orden = new OrdenModel();
		$this->Ordenes = array();

		$this->query = "call sp_get_orden_status('".$status."')";
		
		$this->getResultFromQuery();

		$this->pushListOrden();
	}

	public function insupdOrden($OrdenNew){
		$this->rows = array();
		$this->Orden = new OrdenModel();
		$this->Ordenes = array();

		$this->query = "call sp_insupd_order (".$OrdenNew->idorden.",'".$OrdenNew->tipoOrden."','".$OrdenNew->numeroTipoOrden."','".$OrdenNew->nombreSolicitante."','".$OrdenNew->fechaOrden."','".$OrdenNew->status."',1,'".$OrdenNew->nota."', '".$OrdenNew->modo."')";

		
		$this->getResultFromQuery();

		$this->pushListOrden();
	}

	private function pushListOrden(){
		if(count($this->rows) > 0){
			$Ordenes = array();
			$index = 0;
			foreach ($this->rows as $registro) {
				$this->Orden = new OrdenModel();
				foreach ($registro as $key => $value) {
					$this->Orden->$key = $value;
				}
				$this->Ordenes[$index] = ($this->Orden);
				$index ++;
			}
			$this->message = "Registro encontrado";

		}else{
			$this->message = "No hay registros";
		}
	}

	public function get(){}
	public function set(){}
	public function edit(){}
	public function delete(){}

	function __destruct(){

	}
}



//  ********************  servicio para la administracion de las refacciones por orden ******************************** 

class RefaccionesPorOrdenService extends DataBase {

	public $Refaccion;
	public $Refacciones;


	function __construct(){
		$this->Refaccion = new RefaccionesXOrdenModel();
		$this->Refacciones = array();
	}

	public function setRefaccion($RefaccionNew){
		$this->rows = array();
		$this->Refaccion = new RefaccionesXOrdenModel();
		$this->Refacciones = array();

		$this->query = "call sp_create_refaccionxorden('".$RefaccionNew->idrefaccion."', ".$RefaccionNew->idorden.", '".$RefaccionNew->idubicacion."', ".$RefaccionNew->numPiezas.", '".$RefaccionNew->idrefaccion_similar."', '".$RefaccionNew->nota."')";
		
		$this->getResultFromQuery();

		$this->pushListRefaccion();
	}

	public function getRefacciones($idorden){
		$this->rows = array();
		$this->Refaccion = new RefaccionesXOrdenModel();
		$this->Refacciones = array();

		$this->query = "call sp_get_refaccionxorden(".$idorden.")";
		
		$this->getResultFromQuery();

		$this->pushListRefaccion();
	}

	public function deleteRefaccion($RefaccionDelete){
		$this->rows = array();
		$this->Refaccion = new RefaccionesXOrdenModel();
		$this->Refacciones = array();

		$this->query = "call sp_delete_refaccionxorden('".$RefaccionDelete->idrefaccion."', ".$RefaccionDelete->idorden." , '".$RefaccionDelete->idubicacion."')";
		
		$this->executeSingleQuery();

		//$this->pushListRefaccion();
	}

	private function pushListRefaccion(){
		if(count($this->rows) > 0){
			$Refacciones = array();
			$index = 0;
			foreach ($this->rows as $registro) {
				$this->Refaccion = new RefaccionesXOrdenModel();
				foreach ($registro as $key => $value) {
					$this->Refaccion->$key = $value;
				}
				$this->Refacciones[$index] = ($this->Refaccion);
				$index ++;
			}
			$this->message = "Registro encontrado";

		}else{
			$this->message = "No hay registros";
		}
	}

	public function get(){}
	public function set(){}
	public function edit(){}
	public function delete(){}

	function __destruct(){

	}
}




?>