<?php
	$idOrden = $_GET["id"];
?>

<div class="panel panel-default">
    <div class="panel-body">
    	<div class="container">

            <section class="jumbotron text-center">
                <div class="container">
                <?php 
                    if (isset($_GET['error'])){
                        if ($_GET['error']!= ''){
                ?>
                  <div class="alert alert-danger" role="alert"><?= $_GET['error']?></div>
                <?php 
                    }}
                ?>
                  <h1 class="jumbotron-heading">¡Continuemos!</h1>
                  <p class="lead text-muted">Elige Terminar para cerrar el surtido ó Agregar para insertar mas refacciones al surtido</p>
                  <p>
                    <a href="index.php" class="btn btn-primary"> + Agregar</a>
                    <a href="completeOrden.php?id=<?= $idOrden ?>" class="btn btn-secondary">Terminar</a>
                  </p>
                </div>
            </section>

    	</div>
    </div>
</div>