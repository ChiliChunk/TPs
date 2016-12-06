<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Identification</title>
  </head>
  <body>
    <form action="identification.php" method="post">
      Veuillez entrer les indentifiants pour acceder aux donnees:<br>
      Login : <input type="text" name="login"/><br>
      Mot de Passe : <input type="password" name="mdp"/><br>
      <input type = "submit" value = "envoyer" name = "submit" /><br>
      <?php
      if (isset( $_POST["login"]) and isset($_POST["mdp"])){
        if ($_POST["login"] == "Barack" AND $_POST["mdp"] == "Obama"){
           header('Location: index.php');
        }
        else {
          echo "mauvais login ou mot de passe";
        }
      }
       ?>
  </body>
</html>
