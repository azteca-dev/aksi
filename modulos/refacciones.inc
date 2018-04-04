<?php
require_once('constants.inc');
require_once('controllers.inc');        
?>

<!-- inicia formulario de alta/modificacion de ubicaciones -->
<div id="formRefaccion" class="modal fade bs-example-modal-lg" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel">
    <div class="modal-dialog modal-lg" role="document">
    <div class="modal-content">
        <div class="modal-header">
            <h3>Nueva Refaccion</h3>
        </div>
        <div class="modal-body">
        
        <div ng-show="buscaRefaccionShow">
            <div ng-show="muestraAlertaRefaccion" class="alert alert-success" role="alert">{{messageInfoRefaccion}}</div>
            <form class="form-inline">            
                <div class="form-group">
                <input type="text" name="queryProducto" class="form-control" id="inputQueryProducto" ng-model="queryRefaccion" placeholder="Refaccion"  />
                </div>

                <button class="btn btn-success" ng-click="buscaRefacciones();"  >Buscar Refaccion</button>
                 | <a href="#" ng-click="muestraNuevaRefaccion('');">Nueva Refaccion</a>
                 
                 
            </form>
            <div ng-show="refacciones.length > 0">
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th>idReefaccion</th>                          
                            <th>Descripcion</th>
                            <th>Clave</th>
                            <th>Accion</th>

                        </tr>
                    </thead>
                    <tbody>
                      <tr ng-repeat="refaccion in refacciones">
                          <td>{{refaccion.idrefaccion}}</td>
                          <td>{{refaccion.descripcion}}</td>
                          <td>{{refaccion.idproducto}}-{{refaccion.posicion}}</td>
                          <td><a href="#" ng-click="muestraNuevaRefaccion(refaccion.idrefaccion);" >Modificar</a></td>
                      </tr>
                    </tbody>
                    </table>
            </div>           
        </div>

        <div ng-show="nuevaRefaccionShow"  >  

            <div class="row">
                <div class="col-md-6">
                   <form >
                     <div class="form-group row">
                        <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                        <div class="col-sm-10">
                          
                          <select class="form-control" ng-model="idProductoform">
                              <option value="">selecciona un producto</option>
                              <option ng-repeat="prodSel in productosSelect"  value="{{prodSel.idproducto}}"  ng-selected="selectedProdId == prodSel.idproducto">{{prodSel.idproducto}}-{{prodSel.nombre}}</option>
                          </select>
                        </div>
                      </div>

                      <div class="form-group row">
                        <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                        <div class="col-sm-10">
                          <input type="text" name="idProducto" class="form-control" id="inputPassword" placeholder="idRefaccion" required ng-model="idRefaccionform" />
                        </div>
                      </div>


                      <div class="form-group row">
                        <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                        <div class="col-sm-10">
                          <input type="text" name="idProducto" class="form-control" id="inputPassword" placeholder="Posicion" required ng-model="posicionform" />
                        </div>
                      </div>

                      <div class="form-group row">
                        <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                        <div class="col-sm-10">
                          <input type="textarea" name="nombreProducto" height="100px" class="form-control" id="Password1" placeholder="Descripcion" required ng-model="descripcionRefaccionform" />
                        </div>
                      </div>

                      <div class="form-group row">
                        <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                        <div class="col-sm-10">
                          <input type="text" ng-model="arrayUbicaciones" disabled name="arrayUbicaciones" class="form-control" > 
                          | <a href="#" ng-click="muestraBuscaUbicacionPorRefaccion();">Agregar ubicacion</a>
                          | <a href="#" ng-click="limpiaUbicacionesToRefaccion();">Limpiar</a>
                        </div>
                      </div>


                      <div class="form-group row">
                        <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                        <div class="col-sm-10">
                          <input type="text" ng-model="arrayRefaccionSimilar" disabled name="arraySimilares" class="form-control" >
                          | <a href="#" ng-click="muestraBuscaRefaccionSimilar();">Agregar Similar</a>
                          | <a href="#" ng-click="limpiaRefaccionSimilar();">Limpiar</a>
                        </div>
                      </div>


                      <div class="form-group row">
                        <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                        <div class="col-sm-10">
                          <button type="submit" class="btn btn-success" ng-click="creaRefaccion();">Guardar</button> 
                          <button type="button" class="btn btn-default" ng-click="muestraBuscaRefaccion();">Cancelar</button>  
                        </div>
                      </div>
                    </form>
            </div>
                <div class="col-md-6" style="overflow: auto !important; max-height: 300px;">
                    <div ng-show="buscaUbicacionParaRefaccionShow">
                            <form class="form-inline">            
                                <div class="form-group">
                                <input type="text" name="queryProducto" class="form-control" id="inputQueryUbicacion" ng-model="queryUbicacionParaRefaccion" placeholder="Ubicacion"  />
                                </div>

                            <button class="btn btn-success" ng-click="buscaUbicacionesParaRefaccion();"  >Buscar Ubicacion</button>
                            </form>
                            <div ng-show="ubicacionesParaRefaccion.length > 0" >
                            <table class="table table-striped">
                                <thead>
                                    <tr>
                                        <th>Ubicacion</th>                          
                                        <th>Accion</th>

                                    </tr>
                                </thead>
                                <tbody>
                                  <tr ng-repeat="ubicacionParaRefaccion in ubicacionesParaRefaccion">
                                      <td>{{ubicacionParaRefaccion.idubicacion}}</td>
                                      <td><a href="#" ng-click="addUbicacionToRefaccion(ubicacionParaRefaccion.idubicacion);" >Agregar</a></td>
                                  </tr>
                                </tbody>
                                </table>
                            </div>
                    </div>

                    <div ng-show="buscaRefaccionSimilarShow">
                            <form class="form-inline">            
                                <div class="form-group">
                                <input type="text" name="queryProducto" class="form-control" id="inputQueryUbicacion" ng-model="queryRefaccionSimilar" placeholder="Refaccion"  />
                                </div>

                            <button class="btn btn-success" ng-click="buscaRefaccionesSimilares();"  >Buscar Refaccion</button>
                            </form>
                            <div ng-show="refaccionesSimilares.length > 0" >
                            <table class="table table-striped">
                                <thead>
                                    <tr>
                                        <th>idRefaccion</th>                          
                                        <th>Accion</th>

                                    </tr>
                                </thead>
                                <tbody>
                                  <tr ng-repeat="refaccionSimilar in refaccionesSimilares">
                                      <td>{{refaccionSimilar.idrefaccion}} - {{refaccionSimilar.descripcion}}</td>
                                      <td><a href="#" ng-click="addRefaccionSimilar(refaccionSimilar.idrefaccion);" >Agregar</a></td>
                                  </tr>
                                </tbody>
                                </table>
                            </div>
                    </div>

                    

                </div>
            </div>


        </div>    


        </div>
        <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Cerrar</button>
        </div>
    </div>

    </div>
</div>
<!-- termina formulario de alta/modificacion de ubicaciones -->

