<?php

class UbicacionModel {
	public $idubicacion;
	public $status;
	public $fecha_reg;
	public $fecha_mod;
	public $nota;
}


class ProductoModel{
	public $idproducto;
	public $nombre;
	public $status;
	public $fecha_registro;
	public $fecha_mod;
	public $url_diagrama_pdf;
}

class RefaccionModel {
	public $idrefaccion;
	public $idproducto;
	public $descripcion;
	public $status;
	public $posicion;
	public $fecha_reg;
	public $fecha_mod;
	public $nombre;
	public $url_diagrama_pdf;
	public $total;
}

class RefaccionSimilarModel {
	public $idrefaccion;
	public $idrefaccion_similar;
}

class TecnicoModel {
	public $idtecnico;
	public $nombre;
	public $departamento;
	public $fecha_reg;
	public $status;
}

class RefaccionSnapMasterModel{
	public $idRefaccionSnapMaster;
	public $idrefaccion;
	public $fecha_reg;
	public $tipo;
	public $cantidad;
	public $idubicacion;
	public $destino;
	public $referencia_destino;
	public $idcliente;
	public $fuente_despacho;
	public $idrefaccion_similar;
	public $nota;
}

class StockDetailModel{
	public $idrefaccion;
	public $idubicacion;
	public $stock;
}

class OrdenModel{
	public $idorden;
	public $tipoOrden;
	public $numeroTipoOrden;
	public $nombreSolicitante;
	public $fechaCreacion;
	public $fechaOrden;
	public $status;
	public $idUserCreator;
	public $nota;
	public $fechaActualizacion;
	public $modo;
}


class RefaccionesXOrdenModel{
	public $idrefaccion;
	public $idorden;
	public $idubicacion;
	public $numPiezas;
	public $idrefaccion_similar;
	public $nota;
	public $descripcionRefaccion;
}


?>