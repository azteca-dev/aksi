<?php

require_once "./resources/exceptions.inc";
require_once "../modulos/services.inc";
require_once "../modulos/models.inc";
class RefaccionApiController {

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
				$this->searchRefacciones();
				break;
			case 'POST':
				$this->saveRefaccion();
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


	public function searchRefacciones(){
		try{

			$idRefaccion = '';
			$idProducto = '';
			$posicion = '';
			$query = '';

			if(isset($_GET['query'])){
				$query = $_GET['query'];
			}

			if(isset($_GET['id'])){
				$idRefaccion = $_GET['id'];				
			}

			$refaccionService = new RefaccionService();
			$refaccionService->getRefaccion($idRefaccion,$idProducto,$posicion,$query);
			$result = $refaccionService->Refacciones;
			if (count($result) == 0){
				throw new NotFoundException("the producto not found query = [".$query."]");
				
			}


			if (!empty($idRefaccion)){

				$resultadoCompleto = array();
				$arrayStock = array();

				$index = 0;
				foreach ($result as $refaccion) {

					$stockPorUbicacionService = new StockDetailService();
					$stockPorUbicacionService->getStockDetail($refaccion->idrefaccion, '');
					$arrayStock = $stockPorUbicacionService->StockDetailMasterList;

					$refaccionSimilarService = new RefaccionSimilarService();
					$refaccionSimilarService->getRefaccionSimilar($refaccion->idrefaccion);
					$refacciones_similares = $refaccionSimilarService->RefaccionesSimilares;


					$resultadoCompleto[$index] = array(
						"idrefaccion" => $refaccion->idrefaccion,
						"idproducto" =>  $refaccion->idproducto,
						"descripcion" =>  $refaccion->descripcion,
						"status" =>  $refaccion->status,
						"posicion" =>  $refaccion->posicion,
						"fecha_reg" =>  $refaccion->fecha_reg,
						"fecha_mod" =>  $refaccion->fecha_mod,
						"nombre" =>  $refaccion->nombre,
						"url_diagrama_pdf" =>  $refaccion->url_diagrama_pdf,
						"refacciones_similares" => $refacciones_similares,
						"total" =>  $refaccion->total,
						"stock"=> $arrayStock
					);
					$index = $index+1;
				}

				http_response_code(200);
				echo json_encode($resultadoCompleto,JSON_PRETTY_PRINT);

			}else{

				http_response_code(200);
				echo json_encode($result,JSON_PRETTY_PRINT);
			}



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


	private function saveRefaccion(){

		try{

			$objIn = file_get_contents('php://input');
			$objArr = json_decode($objIn, true);


			if(empty($objArr)){
				throw new BadRequestException("You must provider body json post");
			}

			if(is_null($objArr['idrefaccion'])){
				throw new BadRequestException("You must provider idrefaccion field");
			}
			if(is_null($objArr['idproducto'])){
				throw new BadRequestException("You must provider idproduct field");
			}
			if(is_null($objArr['posicion'])){
				throw new BadRequestException("You must provider posicion field");
			}

			if(is_null($objArr['descripcion'])){
				throw new BadRequestException("You must provider description field");
			}


			$newRefaccion = new RefaccionModel();
			$newRefaccion->idrefaccion = $objArr['idrefaccion'];
			$newRefaccion->idproducto = $objArr['idproducto'] ;
			$newRefaccion->descripcion = $objArr['descripcion'];
			$newRefaccion->status = 'active';
			$newRefaccion->posicion = $objArr['posicion'];

			$refaccionService = new RefaccionService();
			$refaccionService->setRefaccion($newRefaccion);
			$result = $refaccionService->Refacciones;

			if(!is_null($result[0]->idrefaccion)){

				if(!is_null($objArr['ubicaciones'])){

					$ubicacionesList = $objArr['ubicaciones'];
					if(count($ubicacionesList)>0){

						$stockDetailService = new StockDetailService();
						foreach ($ubicacionesList as $idubicacion) {
							$stockDetailService->setInitialStockForUbication($result[0]->idrefaccion, $idubicacion);
						}
					}
				}

				
				if(!is_null($objArr['refacciones_similares'])){
					
					 $refaccionesSimilaresList = $objArr['refacciones_similares'];

					 if(count($refaccionesSimilaresList)>0){
					 	$refaccionSimilarService = new RefaccionSimilarService();
					 	foreach ($refaccionesSimilaresList as $idrefaccionSimilar) {
					 		$refaccionSimilar = new RefaccionSimilarModel();
							$refaccionSimilar->idrefaccion = $result[0]->idrefaccion;
							$refaccionSimilar->idrefaccion_similar = $idrefaccionSimilar;
							$refaccionSimilarService->setRefaccionSimilar($refaccionSimilar);
					 	}
					 }
	
				}
				
			}

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