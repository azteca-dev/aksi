
<?php
    include("includes/header.php");
?>


<!-- Home del dasboard-->
<div ng-show="showDashHome">
    <h2 class="page-header"><span class="glyphicon glyphicon-th" aria-hidden="true"></span> Inicio</h2>
    <div class="panel panel-default">
        <div class="panel-body">

         <ul>

                    <li class="{{classMenuNotas}}"><a ng-click="showSection('Notas'); getNotas(1);" href="#"><span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> Registro de movimientos </a></li>
                    
                    <li class="{{classMenuConciliacion}}"><a ng-click="showSection('Conciliacion'); getConciliacion(1);" href="#"><span class="glyphicon glyphicon-stats" aria-hidden="true"></span> Productos</a></li>

                    <li class="{{classMenuNotas}}"><a ng-click="showSection('options');" href="#"><span class="glyphicon" aria-hidden="true">+</span> Refacciones </a></li>

                    <li class="{{classMenuNotas}}"><a ng-click="showSection('ubicaciones');" href="#"><span class="glyphicon" aria-hidden="true">+</span> Ubicaciones </a></li>

                    <li class="{{classMenuNotas}}"><a ng-click="showSection('options');" href="#"><span class="glyphicon" aria-hidden="true">+</span> Tecnicos </a></li>
         </ul>
        </div>
    </div>
</div>
<!-- Termina el div del home del dashboard-->



<!-- notificaciones -->
<div id="notifications">
     <div ng-show="isErrorSearchConciliacion">
         <div class="alert alert-danger" role="alert">{{errorSearchConciliacionMessage}}</div>
     </div>
     <div ng-show="isErrorSearchNota">
         <div class="alert alert-danger" role="alert">{{errorSearchNotaMessage}}</div>
     </div>
</div>
<!-- termina notificaciones -->


<!-- ********************************************** BEGIN SECCION OPTIONS ******************************************************** -->


<div ng-show="showDashOptions">
    <h1 class="page-header"><span class="glyphicon" aria-hidden="true">+</span> Opciones</h1>
    <div class="panel panel-default">
        <!-- Encabezado de la seccion de usuario -->
        <div class="panel-body">
            <ul>

                <li><a class="reporteExcelLink" href="/stock_file/stock_meli.xls"><img src="../Images/icono_excel.png" /> - Obtener inventario</a></li>
     <li><a href="#" data-toggle="modal" data-target="#createCustomVariation">Agregar un custom variations</a></li>

            </ul>
        </div>
    </div>
</div>
                      


<!-- ********************************************** FIN SECCION OPTIONS ********************************************************** -->

<!-- seccion de ubicaciones -->

<?php include("modulos/ubicaciones.php"); ?>

<!-- Inicia Seccion de reporte de call center -->




<!-- *************************************************   CONCILIACION ***********************************************************-->

<div ng-show="showDashConciliacion">
    <h2 class="page-header"><span class="glyphicon glyphicon-stats" aria-hidden="true"></span> Reporte de movimientos</h2>
    <div>
        <div class="panel panel-default">
            <div class="panel-body">
                <form name="" class="form-inline">
                   <div class="form-group">
                       <input id="searchConciliacionFechaIni" type='date' ng-model="searchConciliacionFechaIni" class="form-control" />
                    </div>
                     <div class="form-group">
                       <input id="searchConciliacionFechaFin"  type='date' ng-model="searchConciliacionFechaFin" class="form-control"  />
                    </div>
                    <div class="form-group">
                        <input type="text" ng-model="searchConciliacionNotaMarti" id="searchConciliacionNotaMarti" class="form-control" placeholder="Nota Martí"  >
                    </div>
                    
                    <div class="form-group">
                        <input type="text" ng-model="searchConciliacionNotaMeli" id="searchConciliacionNotaMeli" class="form-control" placeholder="Nota Mercadolibre"  >
                    </div>
                    <button type="submit" ng-click="getConciliacion(1);" class="btn btn-success">Buscar</button>
                    <a ng-show="isFoundedConciliacion" class="reporteExcelLink" href="DownloadConciliation?fechaFin={{searchConciliacionFechaFin}}&fechaIni={{searchConciliacionFechaIni}}&id={{searchConciliacionNotaMarti}}&notaMeli={{searchConciliacionNotaMeli}}&total={{conciliacionResponseData.paging.total}}"><img src="../Images/icono_excel.png" /> - Descargar reporte en excel</a>
                </form>
            <div ng-show="isSearchConciliacion" class="img_loader">
                <img src="../Images/loader.gif" />
            </div>
                <div ng-show="isFoundedConciliacion" class="table-responsive">

                <nav ng-show="ConPagemaxPage > 1">
                    <ul class="pagination">
                        <li ng-click="getConciliacion(ConPagecurrentPage - 1)" ng-show="ConPagecurrentPage > 1">
                            <a type="prev" href="#" aria-label="Previous"><span aria-hidden="true">&laquo;</span></a>
                        </li>

                        <li ng-repeat="page in ConPagepages" ng-click="getConciliacion(page)" >
                            <a href="#" >{{page}} <span class="sr-only">(current)</span></a>
                        </li>

                        <li ng-click="getConciliacion(ConPagecurrentPage + 1)" ng-show="ConPagecurrentPage < ConPagemaxPage">
                            <a href="#" aria-label="Next" type="next" >
                                <span aria-hidden="true">&raquo;</span>
                            </a>
                        </li>
                    </ul>
                </nav>
                <div id="paginationConciliacion"  class="total_report">
                    Total de movimientos = {{conciliacionResponseData.paging.total}}
                </div>
                    <table class="table table-striped" id="Table1">
                        <thead>
                            <tr>
                                <th># movimiento</th>
                                <th>Fecha</th>
                                <th>Concepto</th>
                                <th>$ Bruto</th>
                                <th>$ Neto</th>
                                <th>Nota martí</th>
                                <th>Nota meli</th>
                                <th>Referencia</th>
                                <th>Cobro envio cliente</th>
                                <th>Cuotas mensuales</th>
                            </tr>
                        </thead>
                        <tbody>
                            <tr  ng-repeat="movimiento in conciliacionResponseData.results" class="reportes">
                                <td>{{movimiento.movimiento_id}} </td>
                                <td>{{movimiento.fecha}}</td>
                                <td>{{movimiento.concepto}}</td>
                                <td>{{movimiento.importe_bruto}}</td>
                                <td>{{movimiento.importe_neto}}</td>
                                <td>{{movimiento.num_nota_marti}}</td>
                                <td>{{movimiento.num_nota_meli}}</td>
                                <td>{{movimiento.referencia_id}}</td>
                                <td>{{movimiento.cargo_envio_cliente}}</td>
                                <td>{{movimiento.cuotas_de_pago}} | ({{movimiento.operation_cuotas_type}})</td>
                            </tr>
                              
                            
                        </tbody>
                    </table>
                </div>

            </div>
        </div>
    </div>

</div>



<!-- inicia seccion de ayuda -->
<div id="helpyou" class="modal fade bs-example-modal-lg" role="dialog" aria-labelledby="myLargeModalLabel">
    <div class="modal-dialog modal-lg" role="document">
    <div class="modal-content">
        <div class="modal-header">
            <h1 class="page-header">AYUDA</h1>
        </div>
        <div class="modal-body">
           <p>
            <ul>
                <li><b>AKSI</b> - Sistema de control de inventario (version 1.0.0)</li>
                <li>Por: DPAZ</li>
                <li>Contactar a : <b>mixtli.paz@gmail.com</b></li>
            </ul>
           </p>
        </div>
        <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Cerrar</button>
        </div>
    </div>

    </div>
</div>
<!-- fin seccion de ayuda -->



<!-- inicia seccion de creacion de custom variation -->
<div id="createCustomVariation" class="modal fade bs-example-modal-lg" role="dialog" aria-labelledby="myLargeModalLabel">
    <div class="modal-dialog modal-lg" role="document">
    <div class="modal-content">
        <div class="modal-header">
            <h2 class="page-header">CREAR VARIANTE CUSTOMIZADA</h2>
        </div>
        <div class="modal-body">
           
           <div id="CV-search-item-main" ng-show="CVShowSearchItemMain">
                <input type="text" ng-model="CVItemMLMid" id="CVItemId" class="form-control" placeholder="MLM1234554" required />
                <button class="btn btn-success" ng-click="searchItem();" type="submit" >Buscar</button>
           </div>


           <div id="CV-find-item-main" ng-show="CVFindItemMain">
            <div class="row">
              <div class="col-4 col-md-4">
              <img src="{{CVSearchItemImgTumb}}" class="CV-thumbnail" />
              </div>
              <div class="col-12 col-md-12">
                <div class="row">
                    <h5>{{CVSearchItemTitle}}<br />
                    <span class="CV-mlmid">[{{CVItemMLMid}}]</span><br />
                    {{CVSearchItemPrice | currency}} | <a href="#" ng-click="addVariation();"> Agregar variación</a>
                    </h5>
                </div>
               
              </div>
            </div>
           </div>

           <div id="CV-notFound-item" ng-show="CVNotFundItem">
            <div class="alert alert-warning" role="alert">
                <p><h4 class="CV-message">El item no fue encontrado o ya tiene variante</h4></p>                
            </div>
           </div>


           <div id="CV-in-data-main" ng-show="CVInDataMain">
            <form>
              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="text" ng-model="CVDataTalla" class="form-control" id="inputPassword" placeholder="Talla" required />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="text" ng-model="CVDataColor" class="form-control" id="Password1" placeholder="Color" required />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="text" ng-model="CVDataInventario" class="form-control" id="Password2" placeholder="Inventario" required />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="text" ng-model="CVDataPrecio" class="form-control" id="Password3" placeholder="Precio" required />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="text" ng-model="CVDataSKU" class="form-control" id="Password4" placeholder="SKU" required />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <button type="submit" class="btn btn-success" ng-click="processVariation();" >Procesar</button> 
                  <button type="button" class="btn btn-default" ng-click="cancelVariation();" >Cancelar</button> 
                </div>
              </div>
            </form>
           </div>

           <div id="CV-error-message-main" ng-show="CVErrorMessageMain">
            <div class="alert alert-danger" role="alert">
                <p><h3 class="CV-message">:( Algo salió mal!!</h3></p>
                <p class="CV-message">Favor de intentar nuevamente o contactar al administrador</p>
            </div>
            <button type="button" class="btn btn-default" ng-click="volverItemVariation();" >Volver</button> 
            <button type="button" class="btn btn-default" ng-click="otroItemVariation();">Otro Item</button> 
           </div>
           
           <div id="CV-success-message-main" ng-show="CVSuccessMessageMain">
            <div class="alert alert-success" role="alert">
                <p><h3 class="CV-message">:) Listo la variante fue creada!!</h3></p>                
            </div>
            <button type="button" class="btn btn-default" ng-click="otroItemVariation();" >Otro Item</button> 
            <button type="button" class="btn btn-default" data-dismiss="modal" >Salir</button> 
           </div>

           <div id="CV-loader-gif" ng-show="CVLoaderGif">
            <img src="../../Images/loader.gif" />
           </div>

        </div>
        <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Salir</button>
        </div>
    </div>

    </div>
</div>
<!-- fin seccion de creacion de custom variation -->




<?php
    include("includes/footer.php");
?>
 

