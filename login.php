<!DOCTYPE html>

<html>
<head runat="server">
    <meta name="viewport" content="width=device-width" />
    <title>Login</title>
    <link href="content/bootstrap.min.css" rel="stylesheet" />
    <link href="content/login.css" rel="stylesheet" />
</head>
<body>
    <div class="jumbotron">
      <div class="container">
        <h2>AKSI-INVENTARIO</h2>
      </div>
    </div>
    <div class="container"> 
        <div class="block-login">
        <div>
        <p class="lead title_login"><span class="glyphicon glyphicon-user" aria-hidden="true"></span></p>
        <p class="lead title_login">!Hola! Para seguir, ingresa tu email  y password</p>
        </div>
        <form class="form-signin" action="processLogin">
            <input type="email" id="inputEmail" name="email" class="form-control box_login" placeholder="Email" required autofocus>            
            <input type="password" id="inputPassword" name="pass" class="form-control box_login" placeholder="Password" required>
            <div class="checkbox">
                <label class="error_message_login">
                    <h4>Error</h4>
                </label>
            </div>
            <button class="btn btn-lg btn-primary btn-block" type="submit">Entrar</button>
        </form>
        </div>
    </div>    
    <script src="content/public/js/angular.min.js"></script>
    <script src="content/public/js/angular-resource.min.js"></script>
    <script src="content/public/js/underscore-min.js"></script>
    <script src="content/public/js/angular-file-upload.js"></script>
    <script src="content/public/js/angular-file-upload-shim.js"></script>
    <script src="content/public/js/app.js"></script>
    <script src="content/public/js/controller.js"></script>
    <script src="content/public/js/service.js"></script>
</body>
</html>
