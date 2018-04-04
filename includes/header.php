<!DOCTYPE html>

<?php
    require_once('./modulos/controllers.inc');
    require_once('./modulos/models.inc');
    $ordenController = new OrdenController();
    $orden = $ordenController->getOrderByStatus('openout');
    $idorden = 0;
    $etiquedaSurtidos = '<a class="dropdown-item" href="#">Salidas [0]</a>';
    if (count($orden)>0){
        $idorden = $orden[0]->idorden;

        $etiquedaSurtidos = '<a class="dropdown-item" href="completeOrden.php?id='.$idorden.'">Salidas ['.$idorden.']</a>';
    }

    $ordenEntrada = $ordenController->getOrderByStatus('openin');
    $idordenEntrada = 0;
    $etiquedaSurtidosEntrada = '<a class="dropdown-item" href="#">Entradas [0]</a>';
    if (count($ordenEntrada)>0){
        $idordenEntrada = $ordenEntrada[0]->idorden;

        $etiquedaSurtidosEntrada = '<a class="dropdown-item" href="completeOrden.php?id='.$idordenEntrada.'">Entradas ['.$idordenEntrada.']</a>';
    }



?>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta charset="utf8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <title>AKSY-ALMACEN</title>
    <link href="Content/bootstrap.min.css" rel="stylesheet"/>
    <link rel='stylesheet prefetch' href='https://netdna.bootstrapcdn.com/font-awesome/4.0.0/css/font-awesome.min.css'>
    <link href="Content/Site.css" rel="stylesheet" />
    

</head>
<body ng-app="AKSI" ng-controller="AKSIController">

    <nav class="navbar navbar-inverse navbar-fixed-top">
        <div class="container-fluid">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand" id="logo" href="index.php">AKSI</a>
            </div>
            <div id="navbar" class="navbar-collapse collapse">
                <ul class="nav navbar-nav navbar-right mr-auto">
                    <li class="nav-item dropdown">
                        <a class="nav-link dropdown-toggle" href="http://example.com" id="dropdown01" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Surtidos</a>
                        <div class="dropdown-menu" aria-labelledby="dropdown01">
                          <?=$etiquedaSurtidos?>
                          <?=$etiquedaSurtidosEntrada?>
                        </div>
                    </li>
                    <li><a href="#">Administrador</a></li>
                    <li><a  data-toggle="modal" data-target="#helpyou" href="#">Ayuda</a></li>
                    <li><a href="login.php">Salir</a></li>
                </ul>
            </div>
        </div>
    </nav>


    <div class="container-fluid">
        <div class="row">
            <div class="col-sm-1 col-md-1 sidebar">
                <ul class="nav nav-sidebar">
                    <li class="<?=$classMenuInicio?>"><a  href="index.php"><span class="glyphicon glyphicon-th" aria-hidden="true"></span></a></li>
 
                    <li class="<?=$classMenuOrdenes?>"><a href="surtidos.php"><span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> </a></li>

                    <li class="<?=$classMenuReportes?>"><a href="reportes.php"><span class="glyphicon glyphicon-stats" aria-hidden="true"></span></a></li>
 

                </ul>
            </div>
            <div class="col-sm-8 col-sm-offset-0 col-md-11 col-md-offset-0 main">
