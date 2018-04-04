<?php
require_once('constants.inc');
require_once('controllers.inc');        
?>

<div id="formProducto" class="modal fade bs-example-modal-lg" role="dialog" aria-labelledby="myLargeModalLabel">
    <div class="modal-dialog modal-lg" role="document">
    <div class="modal-content">
        <div class="modal-header">
            <h3>Nuevo Producto</h3>
        </div>
        <div class="modal-body">
          
          <div ng-show="buscaProductoShow">
            <div ng-show="muestraAlerta" class="alert alert-success" role="alert">{{messageInfo}}</div>
            <form class="form-inline">            
                <div class="form-group">
                <input type="text" name="queryProducto" class="form-control" id="inputQueryProducto" ng-model="queryProducto" placeholder="Producto"  />
                </div>

                <button class="btn btn-success" ng-click="buscaProductos();"  >Buscar Producto</button>
                 | <a href="#" ng-click="muestraNuevoProducto('');">Nuevo Producto</a>
                 
                 
            </form>
            <div ng-show="productos.length > 0">
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th>Producto</th>                          
                            <th>Descripcion</th>
                            <th>Accion</th>

                        </tr>
                    </thead>
                    <tbody>
                      <tr ng-repeat="producto in productos">
                          <td>{{producto.idproducto}}</td>
                          <td>{{producto.nombre}}</td>
                          <td><a href="#" ng-click="muestraNuevoProducto(producto.idproducto);" >Modificar</a></td>
                      </tr>
                    </tbody>
                    </table>
            </div>           
          </div>

          <div ng-show="nuevoProductoShow">
           <form>
              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="text" name="idProducto" class="form-control" id="inputPassword" placeholder="Producto" 
                  ng-model="idProductoForm"required />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="textarea" name="nombreProducto" height="100px" class="form-control" id="Password1" placeholder="Descripcion" ng-model="nombreProductoForm" required />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <input type="text" name="urlDiagrama" class="form-control" id="inputPassword" placeholder="archivo pdf" required ng-model="urlDiagramaForm" />
                </div>
              </div>

              <div class="form-group row">
                <label for="inputPassword" class="col-sm-2 col-form-label"></label>
                <div class="col-sm-10">
                  <button type="button" class="btn btn-success" ng-click="creaProducto();">Guardar</button> 
                  <button type="button" class="btn btn-default" ng-click="muestraBuscaProducto();">Cancelar</button> 
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
</div>
