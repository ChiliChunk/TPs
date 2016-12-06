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
         Date de parution inférieure à 1900 <input type="radio" name="group1"  id="inf1900"><br>
         Date de parution entre 1900 et 1999 <input type="radio" name="group1" id="medium"><br>
         Date de parution postérieure à 2000 <input type="radio" name="group1" id="sup2000"><br>
         <input type="submit" value="Rechercher" name="submit">
      </form>

    	<?php
        require_once('initTableau.php');
        if (isset($_POST["inf1900"])){
          echo "Salut";
        }
       ?>
		</section>
	</div>
	<?php include("./include/footer.php"); ?>
</body>
</html>
