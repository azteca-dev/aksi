<?php

require_once "./resources/exceptions.inc";
require_once "../modulos/services.inc";
require_once "../modulos/models.inc";
class ProductApiController {

	public function manager(){
		header('Content-Type: application/JSON; charset=utf-8');
		header('Access-Control-Allow-Origin: *');
		header('Access-Control-Allow-Credentials: true');
		header('Access-Control-Allow-Methods: PUT, GET, POST, DELETE, OPTIONS');
		header('Access-Control-Allow-Headers: X-Requested-With');
		header('Content-Type: text/html; charset=utf-8');

		$method = $_SERVER['REQUEST_METHOD'];

		switch ($method) {
			case 'GET':
				$this->searchProductos();
				break;
			case 'POST':
				$this->saveProducto();
				break;
			case 'PUT':
				$this->notAllowed($method);
			break;
			case 'DELETE':
				$this->notAllowed($method);
			break;
			default:
				$this->notAllowed($method);
				break;
		}
	}

	private function notAllowed($method){
		http_response_code(405);
		$response = array("status" => 405, "message"=>"Method".$method." not allowed", "error"=>"not_allowed");
		echo json_encode($response, JSON_PRETTY_PRINT);
	}


	public function searchProductos(){
		try{

			$idProducto = '';
			$query = '';

			if(isset($_GET['query'])){
				$query = $_GET['query'];
			}

			$productoService = new ProductoService();
			$productoService->getProductos($idProducto, $query);
			$result = $productoService->Productos;
			if (count($result) == 0){
				throw new NotFoundException("the producto not found query = [".$query."]");
				
			}
			http_response_code(200);
			echo json_encode($result,JSON_PRETTY_PRINT);



		}catch(NotFoundException $e){
			$this->renderException($e);
		}catch(BadRequestException $e){
			$this->renderException($e);
		}catch(ConflictException $e){
			$this->renderException($e);
		}catch(Exception $exc){
			http_response_code(500);
			$response = array("status" => 500, "message"=>$exc->getMessage(), "error"=>'internal_server');
			echo json_encode($response, JSON_PRETTY_PRINT);
		}

		
	}


	private function saveProducto(){
		try{



			$objIn = file_get_contents('php://input');
			$objArr = json_decode($objIn, true);


			if(empty($objArr)){
				throw new BadRequestException("You must provider body json post");
			}

			if(is_null($objArr['idproduct'])){
				throw new BadRequestException("You must provider idproduct field");
			}
			if(is_null($objArr['description'])){
				throw new BadRequestException("You must provider description field");
			}

			

			$newProduct = new ProductoModel();
			$newProduct->idproducto = $objArr['idproduct'] ;
			$newProduct->nombre = $objArr['description'];
			$newProduct->status = 'active';
			$newProduct->url_diagrama_pdf = 'no disponible';

			$productoService = new ProductoService();
			$productoService->setProducto($newProduct);
			$result = $productoService->Productos;
			http_response_code(201);
			echo json_encode($result,JSON_PRETTY_PRINT);



		}catch(NotFoundException $e){
			$this->renderException($e);

		}catch(BadRequestException $e){
			$this->renderException($e);

		}catch(ConflictException $e){
			$this->renderException($e);

		}catch(Exception $exc){
			http_response_code(500);
			$response = array("status" => 500, "message"=>$exc->getMessage(), "error"=>'internal_server');
			echo json_encode($response, JSON_PRETTY_PRINT);
		}
	}

	private function renderException($e){
		http_response_code($e->code);
		$response = array("status" => $e->code, "message"=>$e->message, "error"=>$e->error);
		echo json_encode($response, JSON_PRETTY_PRINT);
	}

}


?>