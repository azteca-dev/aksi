<div ng-show="showDashUbicaciones">
    <h1 class="page-header"><span class="glyphicon glyphicon-list-alt" aria-hidden="true"></span> Ubicaciones</h1>
    <div class="panel panel-default">
        <!-- Encabezado de la seccion de usuario -->
        <div class="panel-body">
            <form name="" class="form-inline">
                <div class="form-group">
                    <label for="searchNotasFechaIni">Desde</label>
                   <input id="Date1" type='date' ng-model="searchNotaFechaIni" class="form-control" />
                </div>
                 <div class="form-group">
                    <label for="searchNotasFechaFin">Hasta</label>
                   <input id="Date2"  type='date' ng-model="searchNotaFechaFin" class="form-control"  />
                </div>
                <div class="form-group">
                    <label for="searchNotasNotaMarti">Nota Martí</label>
                    <input type="text" ng-model="searchNotaNotaMarti" id="Text1" class="form-control"  >
                </div>
                <div class="form-group">
                    <label for="searchNotasNotaMeli">Nota Mercadolibre</label>
                    <input type="text" ng-model="searchNotaNotaMeli" id="Text2" class="form-control"  >
                </div>
                <button type="submit" ng-click="getNotas(1);" class="btn btn-success">Buscar</button>
                <a ng-show="isFoundedNotas" class="reporteExcelLink" href="DownloadCallCenter?fechaFin={{searchNotaFechaFin}}&fechaIni={{searchNotaFechaIni}}&id={{searchNotaNotaMarti}}&notaMeli={{searchNotaNotaMeli}}&total={{notasResponseData.paging.total}}"><img src="../Images/icono_excel.png" /> - Descargar reporte en excel</a>
            </form>
            <div ng-show="isSearchNotas" class="img_loader">
                <img src="../Images/loader.gif" />
            </div>

            <div ng-show="isFoundedNotas" class="table-responsive">
                
                 <nav ng-show="maxPage > 1">
                    <ul class="pagination">
                        <li ng-click="getNotas(currentPage - 1)" ng-show="currentPage > 1">
                            <a type="prev" href="#" aria-label="Previous"><span aria-hidden="true">&laquo;</span></a>
                        </li>

                        <li ng-repeat="page in pages" ng-click="getNotas(page)" >
                            <a href="#" >{{page}} <span class="sr-only">(current)</span></a>
                        </li>

                        <li ng-click="getNotas(currentPage + 1)" ng-show="currentPage < maxPage">
                            <a href="#" aria-label="Next" type="next" >
                                <span aria-hidden="true">&raquo;</span>
                            </a>
                        </li>
                    </ul>
                </nav>
                <div id="Div1"  class="total_report">
                    Total de notas = {{notasResponseData.paging.total}}
                </div>
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th>Nota</th>                          
                            <th>Fecha</th>
                            <th>Cliente</th>
                            <th>Guia</th>
                        </tr>
                    </thead>
                  
                    <tbody>
                        <tr ng-repeat="nota in notasResponseData.results" class="reportes">
                            <td>
                            {{nota.nota_marti_id}}<br/>
                            {{nota.nota_meli}}
                            </td>
                            <td>{{nota.fecha_pedido}}</td>
                            <td>
                                {{nota.nombre_cliente}}<br />
                            </td>
                            <td valign="top">
                                {{nota.num_guia}} 
                            </td>
                            
                        </tr>
                    </tbody>
                   
                </table>
            </div>

        </div>
    </div>
</div>