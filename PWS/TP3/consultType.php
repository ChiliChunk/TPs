<?php
  //$pNomType doit etre compris dans {Romans,Essais,DVD}
  function getIdType ($pNomType , $tabType){
    foreach ($tabType as $cpt => $sousTab){
      foreach ($sousTab as $key => $value){
      if ($key == 'nomType' and $value == $pNomType){
        return $sousTab['idType'];
      }
     }
    }
  }
  
  function afficherMedia ($pIdMedia , $TabMedia){
    echo "<table border=1 style=\"margin:0 auto\"> ";
    foreach ($TabMedia as $cpt => $val){
      foreach ($val as $key => $value){
        if ($key == 'idType' and $value == $pIdMedia){
          echo "<tr> <td>".$val["idMedia"]."</td><td>".$val["idType"]."</td><td>".$val["nomMedia"]."</td><td>".$val["dateDeParution"]."</td></tr>";

        }
      }
    }
    echo "</table>";
  }
?>
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
			<form action='consultType.php' method="POST">
         Romans <input type="radio"  name="group1" value="romans"><br>
         Essais <input type="radio" name="group1" value="essais"><br>
         DVD <input type="radio" name="group1" value="dvd"><br>
         <input type="submit" value="Rechercher" name="submit">
         <?php
           require_once('initTableau.php');
          //on recupere l'id du media voulu
          if (isset($_POST["group1"])){
            if ($_POST["group1"] == "romans"){
              $id = getIdType('Romans' , $tabType);
              afficherMedia ($id, $TabMedia);
            }
            if ($_POST["group1"] == "essais"){
              $id = getIdType('Essais', $tabType);
              afficherMedia ($id, $TabMedia);
            }
            if ($_POST["group1"] == "dvd"){
              $id = getIdType('DVD', $tabType);
              afficherMedia ($id, $TabMedia);
            }
          }
         ?>
		</section>
	</div>
	<?php include("./include/footer.php"); ?>
</body>
</html>
