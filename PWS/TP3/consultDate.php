<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" />
	<link rel="stylesheet" href="./include/styles.css" />
	<title>Mon site !</title>
</head>
<body>
	<?php
		// Index.php
		include("./include/header.php");
	?>
	<div class="wrapper">
		<?php include("./include/menus.php"); ?>
		<section id="content">
      <form action='consultDate.php' method="POST">
         Date de parution inférieure à 1900 <input type="radio"  name="group1" value="inf1900"><br>
         Date de parution entre 1900 et 1999 <input type="radio" name="group1" value="medium"><br>
         Date de parution postérieure à 2000 <input type="radio" name="group1" value="sup2000"><br>
         <input type="submit" value="Afficher" name="submit">
      </form>

    	<?php
        require_once('initTableau.php');
        if (isset($_POST["group1"])){
          echo "<br><br><br>";
          echo "<table border=1 style=\"margin : 0 auto\"> ";
          echo "<tr><th>idMedia</th><th>idType</th><th>nomMedia</th><th>dateParution</th></tr>";
          
          
          if($_POST["group1"] == "inf1900"){
            foreach ($TabMedia as $cpt => $val){
              foreach ($val as $key => $value){
                if ($key == "dateDeParution" and $value < 1900){
                  echo "<tr> <td>".$val["idMedia"]."</td><td>".$val["idType"]."</td><td>".$val["nomMedia"]."</td><td>".$val["dateDeParution"]."</td></tr>";
                }
              }
            }
          }
          
          
          
          if($_POST["group1"] == "medium"){
            foreach ($TabMedia as $cpt => $val){
              foreach ($val as $key => $value){
                if ($key == "dateDeParution" and $value >= 1900 and $value < 1999){
                  echo "<tr> <td>".$val["idMedia"]."</td><td>".$val["idType"]."</td><td>".$val["nomMedia"]."</td><td>".$val["dateDeParution"]."</td></tr>";
                }
              }
            }
          }
          
          if($_POST["group1"] == "sup2000"){
            foreach ($TabMedia as $cpt => $val){
              foreach ($val as $key => $value){
                if ($key == "dateDeParution" and $value > 2000){
                  echo "<tr> <td>".$val["idMedia"]."</td><td>".$val["idType"]."</td><td>".$val["nomMedia"]."</td><td>".$val["dateDeParution"]."</td></tr>";
                }
              }
            }
          }
          
           echo "</table>";
        }
       ?>
		</section>
	</div>
	<?php include("./include/footer.php"); ?>
</body>
</html>
