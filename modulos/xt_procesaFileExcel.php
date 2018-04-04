<?php

echo exec('whoami');
 if (isset($_POST["enviar"])){
 	echo "hizo clic en el boton enviar <br>";
 	$archivo = $_FILES["archivoExcel"]["name"];

 	$archivoTemporal = $_FILES["archivoExcel"]["tmp_name"];
 	$archivoEnServer = "./uploads/test_prueba1.xlsx";

 	echo $archivo."<br>".$archivoTemporal;

 	if(copy($archivoTemporal, $archivoEnServer)){
 		echo "<br> Se copio con exito";
 	}

 	if (file_exists($archivoEnServer)){
 		echo "<br> El archivo existe uff!";

 		$fp = fopen($archivoEnServer, "r");
 		while($datos = fgetcsv($fp, 1000,";" )){
 			//echo $datos[0];
 		}
 	}


 }

?>