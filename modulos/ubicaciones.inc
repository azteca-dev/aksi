<?php
require_once('constants.inc');
require_once('controllers.inc');        
?>

<!-- inicia formulario de alta/modificacion de ubicaciones -->
<div id="formUbicacion" class="modal fade bs-example-modal-lg" role="dialog" aria-labelledby="myLargeModalLabel">
    <div class="modal-dialog modal-lg" role="document">
    <div class="modal-content">
        <div class="modal-header">
            <h3>Nueva Ubicacion</h3>
        </div>
        <div class="modal-body">
          
          <div ng-show="buscaUbicacionShow">
            <div ng-show="muestraAlertaUbicacion" class="alert alert-success" role="alert">{{messageInfoUbicacion}}</div>
            <form class="form-inline">            
                <div class="form-group">
                <input type="text" name="queryProducto" class="form-control" id="inputQueryUbicacion" ng-model="queryUbicacion" placeholder="Ubicacion"  />
                </div>

                <button class="btn btn-success" ng-click="buscaUbicaciones();"  >Buscar Ubicacion</button>
                 | <a href="#" ng-click="muestraNuevaUbicacion('');">Nueva Ubicacion</a>
                 
                 
            </form>
            <div ng-show="ubicaciones.length > 0">
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th>Ubicacion</th>                          
                            <th>Accion</th>

                        </tr>
                    </thead>
                    <tbody>
                      <tr ng-repeat="ubicacion in ubicaciones">
                          <td>{{ubicacion.idubicacion}}</td>
                          <td><a href="#" ng-click="muestraNuevaUbicacion(ubicacion.idubicacion);" >Modificar</a></td>
                      </tr>
                    </tbody>
                    </table>
            </div>           
          </div>   


        <div ng-show="nuevaUbicacionShow">    
           <form >
              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="text" name="idUbicacion" class="form-control" id="inputPassword" placeholder="Ubicacion" ng-model="idUbicacionForm" required />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="textarea" name="nota" height="100px" class="form-control" id="Password1" placeholder="Nota" required ng-model="ubicacionNotaForm" />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <button type="submit" class="btn btn-success" ng-click="creaUbicacion();" >Guardar</button> 
                  <button type="button" class="btn btn-default" ng-click="muestraBuscaUbicacion();" >Cancelar</button> 
                </div>
              </div>
            </form>
        </div>    

        </div>
        <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Cerrar</button>
        </div>
    </div>

    </div>
</div>
<!-- termina formulario de alta/modificacion de ubicaciones -->
