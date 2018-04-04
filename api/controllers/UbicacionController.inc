<?php

require_once "./resources/exceptions.inc";
require_once "../modulos/services.inc";
require_once "../modulos/models.inc";
class UbicacionApiController {

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
				$this->searchUbicaciones();
				break;
			case 'POST':
				$this->saveUbicacion();
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


	public function searchUbicaciones(){
		try{

			$idUbicacion = '';

			if(isset($_GET['id'])){
				$idUbicacion = $_GET['id'];
			}

			$ubicacionService = new UbicacionService();
			$ubicacionService->getUbicaciones($idUbicacion);
			$result = $ubicacionService->Ubicaciones;
			if (count($result) == 0){
				throw new NotFoundException("the ubicacion not found id = [".$idUbicacion."]");
				
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


	private function saveUbicacion(){
		try{



			$objIn = file_get_contents('php://input');
			$objArr = json_decode($objIn, true);


			if(empty($objArr)){
				throw new BadRequestException("You must provider body json post");
			}

			if(is_null($objArr['idubicacion'])){
				throw new BadRequestException("You must provider idUbicacion field");
			}

			$descripcion = "";
			if(!is_null($objArr['description'])){
				$descripcion = $objArr['description'];
			}


			

			$newUbicacion = new UbicacionModel();
			$newUbicacion->idubicacion = $objArr['idubicacion'] ;
			$newUbicacion->nota = $descripcion;
			$newUbicacion->status = 'active';


			$ubicacionService = new UbicacionService();
			$ubicacionService->setUbicacion($newUbicacion);
			$result = $ubicacionService->Ubicaciones;
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