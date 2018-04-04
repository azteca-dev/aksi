<?php

require_once('app/controllers.inc');


	$nombre = $_POST["nombre"];
	$departamento = $_POST["depto"];


	$tecnicoController = new TecnicoController();
	$Tecnico = new TecnicoModel();
	$Tecnico->nombre = $nombre;
	$Tecnico->departamento = $departamento;
	


	$tecnicoController->saveTecnico($Tecnico);

	header("Location:index.php");

  

?>