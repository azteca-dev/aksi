'use strict'

/* Controllers */

function AKSIController ($scope,$timeout,$filter,Categories,Category,Attributes,Productos,Ubicaciones,Refacciones,Excel,Broadcast){
    $scope.nombre = 'David Paz';
    $scope.categories = [];
    $scope.categoriesPathRoot = [];
    $scope.listAllowed = false;
    $scope.listAllowedByCategory = [];
    $scope.isSearching = false;
    $scope.isSearchAttributes = false;
    $scope.listAttributes = [];
    $scope.categoriaEspejo = "";
    $scope.holaAngular = "Hola desde angualr :) !!";

    $scope.ubicaciones = [];
    $scope.refacciones = [];

    $scope.nuevoProductoShow = false;
    $scope.buscaProductoShow = true;

    $scope.nuevaUbicacionShow = false;
    $scope.buscaUbicacionShow = true;

    $scope.nuevaRefaccionShow = false;
    $scope.buscaRefaccionShow = true;

    $scope.idProductoForm = "";
    $scope.nombreProductoForm = "";
    $scope.urlDiagramaForm = "";

    $scope.messageInfo = "";
    $scope.muestraAlerta = false;

    $scope.messageInfoUbicacion = "";
    $scope.muestraAlertaUbicacion = false;

    $scope.messageInfoRefaccion = "";
    $scope.muestraAlertaRefaccion = false;

    $scope.buscaUbicacionParaRefaccionShow = false;
    $scope.buscaRefaccionSimilarShow = false;

    $scope.arrayUbicaciones = "";
    $scope.arrayRefaccionSimilar = "";

    $scope.listaUbicaciones = [];
    $scope.listaRefaccionesSimilares = [];

    $scope.selectedProdId = "";


    $scope.buscaProductos = function(){
        $scope.muestraAlerta = false;
        $scope.messageInfo = "";
        var params = {query:$scope.queryProducto};
        $scope.productos = [];
        Productos.search(params,{}, function (data) {
            $scope.productos = data;
        },function (error){
           $scope.productos = [];
           $scope.messageInfo = "No se encontraron resultados...";
           $scope.muestraAlerta = true;

        });
    };

    $scope.muestraNuevoProducto = function(idProducto){
        $scope.messageInfo = "";
        $scope.muestraAlerta = false;
        $scope.buscaProductoShow = false;
        $scope.nuevoProductoShow = true;

        $scope.idProductoForm = "";
        $scope.nombreProductoForm = "";
        $scope.urlDiagramaForm = "";


        if(idProducto != ''){
            var params = {query:idProducto};
            Productos.search(params,{}, function (data) {
                $scope.idProductoForm = data[0].idproducto;
                $scope.nombreProductoForm = data[0].nombre;
                $scope.urlDiagramaForm = data[0].url_diagrama_pdf;
            },function (error){

                $scope.idProductoForm = "";
                $scope.nombreProductoForm = "";
                $scope.urlDiagramaForm = "";

            });
        }

    }

    $scope.muestraBuscaProducto = function(){
        $scope.messageInfo = "";
        $scope.muestraAlerta = false;
        $scope.buscaProductoShow = true;
        $scope.nuevoProductoShow = false;
    }


    $scope.creaProducto =  function (){

        $scope.messageInfo = "";
        $scope.muestraAlerta = false;
        var dataPost = {
            idproduct : $scope.idProductoForm,
            description : $scope.nombreProductoForm
        };

        Productos.create({},dataPost, function (data) {
            $scope.messageInfo = "Producto creado/modificado satisfactoriamente";
            $scope.muestraAlerta = true;
            $scope.buscaProductoShow = true;
            $scope.nuevoProductoShow = false;

        },function (error){

            $scope.messageInfo = "Error al crear/modificar el producto";
            $scope.muestraAlerta = true;
            $scope.buscaProductoShow = true;
            $scope.nuevoProductoShow = false;

        });
    }

// ubicaciones

    $scope.buscaUbicaciones = function(){
        $scope.muestraAlertaUbicacion = false;
        $scope.messageInfoUbicacion = "";
        var params = {id:$scope.queryUbicacion};
        $scope.ubicaciones = [];
        Ubicaciones.search(params,{}, function (data) {
            $scope.ubicaciones = data;
        },function (error){
           $scope.ubicaciones = [];
           $scope.messageInfoUbicacion = "No se encontraron resultados...";
           $scope.muestraAlertaUbicacion = true;

        });
    };

    $scope.muestraNuevaUbicacion = function(idUbicacion){
        $scope.messageInfoUbicacion = "";
        $scope.muestraAlertaUbicacion = false;
        $scope.buscaUbicacionShow = false;
        $scope.nuevaUbicacionShow = true;

        $scope.idUbicacionForm = "";
        $scope.ubicacionNotaForm = "";


        if(idUbicacion != ''){
            var params = {id:idUbicacion};
            Ubicaciones.search(params,{}, function (data) {
                $scope.idUbicacionForm = data[0].idubicacion;
                $scope.ubicacionNotaForm = data[0].nota;                
            },function (error){

                $scope.idUbicacionForm = "";
                $scope.ubicacionNotaForm = "";

            });
        }

    }

    $scope.muestraBuscaUbicacion = function(){
        $scope.messageInfoUbicacion = "";
        $scope.muestraAlertaUbicacion = false;
        $scope.buscaUbicacionShow = true;
        $scope.nuevaUbicacionShow = false;
    }


    $scope.creaUbicacion =  function (){

        $scope.messageInfoUbicacion = "";
        $scope.muestraAlertaUbicacion = false;
        var dataPost = {
            idubicacion : $scope.idUbicacionForm,
            description : $scope.ubicacionNotaForm
        };

        Ubicaciones.create({},dataPost, function (data) {
            $scope.messageInfoUbicacion = "Ubicacion creado/modificado satisfactoriamente";
            $scope.muestraAlertaUbicacion = true;
            $scope.buscaUbicacionShow = true;
            $scope.nuevaUbicacionShow = false;

        },function (error){

            $scope.messageInfoUbicacion = "Error al crear/modificar el producto";
            $scope.muestraAlertaUbicacion = true;
            $scope.buscaUbicacionShow = true;
            $scope.nuevaUbicacionShow = false;

        });
    }





// refacciones

    $scope.buscaRefacciones = function(){
        $scope.muestraAlertaRefaccion = false;
        $scope.messageInfoRefaccion = "";
        var params = {query:$scope.queryRefaccion};
        $scope.refacciones = [];
        Refacciones.search(params,{}, function (data) {
            $scope.refacciones = data;
        },function (error){
           $scope.refacciones = [];
           $scope.messageInfoRefaccion = "No se encontraron resultados...";
           $scope.muestraAlertaRefaccion = true;

        });
    };

    $scope.muestraNuevaRefaccion = function(idRefaccion){
        $scope.messageInfoRefaccion = "";
        $scope.muestraAlertaRefaccion = false;
        $scope.buscaRefaccionShow = false;
        $scope.nuevaRefaccionShow = true;

        $scope.idRefaccionform = "";
        $scope.descripcionRefaccionform = "";
        $scope.posicionform = "";
        $scope.selectedProdId = "";
        $scope.idProductoform  = "";

        var params = {query:' '};
        $scope.productosSelect = [];
        Productos.search(params,{}, function (dataProd) {
            $scope.productosSelect = dataProd;
        },function (error){
           $scope.productosSelect = [];

        });


        if(idRefaccion != ''){
            $scope.buscaUbicacionParaRefaccionShow = false;
            $scope.buscaRefaccionSimilarShow = false;
            $scope.selectedProdId = "";
            var params = {id:idRefaccion};
            Refacciones.search(params,{}, function (data) {
                $scope.idRefaccionform = data[0].idrefaccion;
                $scope.descripcionRefaccionform = data[0].descripcion;   
                $scope.posicionform = data[0].posicion;
                $scope.selectedProdId = data[0].idproducto;
                $scope.idProductoform = data[0].idproducto;
            },function (error){

                $scope.idRefaccionform = "";
                $scope.descripcionRefaccionform = "";
                $scope.posicionform = "";
                $scope.selectedProdId = "";
                $scope.idProductoform  = "";

            });
        }

    }

    $scope.muestraBuscaRefaccion = function(){
        $scope.messageInfoRefaccion = "";
        $scope.muestraAlertaRefaccion = false;
        $scope.buscaRefaccionShow = true;
        $scope.nuevaRefaccionShow = false;
    }


    $scope.creaRefaccion =  function (){

        

        $scope.messageInfoRefaccion = "";
        $scope.muestraAlertaRefaccion = false;

        // hacemos las validaciones de los datos

        var iniciaCarga = true;

        if($scope.idRefaccionform == ""){
            iniciaCarga = false;
        }

        if($scope.descripcionRefaccionform == ""){
            iniciaCarga = false;
        }

        if($scope.idProductoform == ""){
            iniciaCarga = false;
        }

        if($scope.posicionform == ""){
            iniciaCarga = false;
        }


        if (iniciaCarga){
            var dataPost = {
                idrefaccion : $scope.idRefaccionform,
                descripcion : $scope.descripcionRefaccionform,
                idproducto : $scope.idProductoform,
                status : 'active',
                posicion : $scope.posicionform,
                ubicaciones : $scope.listaUbicaciones,
                refacciones_similares : $scope.listaRefaccionesSimilares
            };

            Refacciones.create({},dataPost, function (data) {
                $scope.messageInfoRefaccion = "Ubicacion creado/modificado satisfactoriamente";
                $scope.muestraAlertaRefaccion = true;
                $scope.buscaRefaccionShow = true;
                $scope.nuevaRefaccionShow = false;

            },function (error){

                $scope.messageInfoRefaccion = "Error al crear/modificar el producto";
                $scope.muestraAlertaRefaccion = true;
                $scope.buscaRefaccionShow = true;
                $scope.nuevaRefaccionShow = false;

            });
        }
    }



// funciones para el tema de la creacion, modificacion de refacciones

     $scope.buscaUbicacionesParaRefaccion = function(){
        var params = {id:$scope.queryUbicacionParaRefaccion};
        $scope.ubicacionesParaRefaccion = [];
        Ubicaciones.search(params,{}, function (dataUbicaciones) {
            $scope.ubicacionesParaRefaccion = dataUbicaciones;
        },function (error){
           $scope.ubicacionesParaRefaccion = [];
        });
    };

    $scope.muestraBuscaUbicacionPorRefaccion = function(){

        $scope.buscaUbicacionParaRefaccionShow = !($scope.buscaUbicacionParaRefaccionShow);
        $scope.buscaRefaccionSimilarShow = false;

    }

    $scope.addUbicacionToRefaccion = function(idUbicacion){

        if($scope.arrayUbicaciones == ""){
            $scope.arrayUbicaciones = idUbicacion;
        }else{
            $scope.arrayUbicaciones = $scope.arrayUbicaciones + ","+idUbicacion;    
        }

        $scope.listaUbicaciones.push(idUbicacion);
        

        
    }

    $scope.limpiaUbicacionesToRefaccion = function(){
        $scope.arrayUbicaciones = "";
        $scope.listaUbicaciones = [];
    }


     $scope.buscaRefaccionesSimilares = function(){
        var params = {query:$scope.queryRefaccionSimilar};
        $scope.refaccionesSimilares = [];
        Refacciones.search(params,{}, function (dataRefaccionSimilar) {
            $scope.refaccionesSimilares = dataRefaccionSimilar;
        },function (error){
           $scope.refaccionesSimilares = [];

        });
    };

    $scope.muestraBuscaRefaccionSimilar = function(){

        $scope.buscaRefaccionSimilarShow = !($scope.buscaRefaccionSimilarShow);
        $scope.buscaUbicacionParaRefaccionShow = false;
    }

    $scope.addRefaccionSimilar = function(idRefaccionSimilar){

        if($scope.arrayRefaccionSimilar == ""){
            $scope.arrayRefaccionSimilar = idRefaccionSimilar;
        }else{
            $scope.arrayRefaccionSimilar = $scope.arrayRefaccionSimilar + ","+idRefaccionSimilar;    
        }

        $scope.listaRefaccionesSimilares.push(idRefaccionSimilar);
    }

     $scope.limpiaRefaccionSimilar = function(){
        $scope.arrayRefaccionSimilar = "";
        $scope.listaRefaccionesSimilares = [];
    }
    





// otra cosas no funcional  

    $scope.searchCategories = function(){
        console.log("buscando categorias");
        var params = {};
        $scope.listAllowed = false;
        $scope.categories = "buscando...";
        $scope.isSearching = true;
        console.log("iniciando busqueda de categorias..");
        Categories.get(params, function (data){
            $scope.categoriesPathRoot = [];
            $scope.categories = data;
        },function (error){
            $scope.categoriesPathRoot = [];
            $scope.categories = "No encontradas..";
        });
    };

    






  

    $scope.searchCategory = function(catId){
        var params = {categoryId:catId};
        $scope.categoriesPathRoot = [];
        $scope.isSearching = true;
        $scope.categoriaEspejo = "";
        Category.get(params,{}, function (data) {
            $scope.categories = data.children_categories;
            $scope.categoriesPathRoot = data.path_from_root;
            $scope.listAllowed = data.settings.listing_allowed;
            $scope.categoriaEspejo = data.settings.mirror_category;
            $scope.attributeTypes = data.attribute_types;
        },function (error){
           $scope.categories = "No encontradas..";
           $scope.categoriesPathRoot = [];
           $scope.listAllowed = false;

        });
    };

    $scope.searchListAllowedByCategory = function (catId, index){
        
        if(catId){
            var params = {categoryId:catId};
             Category.get(params,{}, function (data) {
                $scope.listAllowedByCategory[index] = data.settings.listing_allowed;

            },function (error){
               $scope.listAllowedByCategory[index] = false;
            });
        }
    };

    $scope.searchAttributes = function (catId, catName){
        var params = {categoryId:catId};
        Attributes.get(params, {}, function (data){
            $scope.attrCatId = catId;
            $scope.attrCatName = catName;
           $scope.listAttributes = data;
        },function (error){
            $scope.listAttributes = [];
        });
    };

    $scope.exportToExcel=function(tableId){ // ex: '#my-table'
            $scope.exportHref=Excel.tableToExcel(tableId,'testExcelAngular');
            $timeout(function(){location.href=$scope.exportHref;},100); // trigger download
        };
}
