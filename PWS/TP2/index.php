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
			<?php
			//exercice1
				$film["Tu ne tueras point"] = array("gibson",'usa',2016 );
				$film['Sully'] = array('eastwood' , 'usa' , 2016);
				$film['Rogue One'] = array ('edwards','usa',2016);
			// exercice 2
				$film2["Tu ne tueras point"] = array('realisateur' => "gibson",
		                          'pays' => 'usa',
		                          'annee' => 2016
															);
				$film2["Sully"] = array('realisateur' =>'eastwood',
																'pays' => 'usa',
															'annee' => 2016);
				$film2["Rogue One"] = array('realisateur' => 'edwards',
			 															'pays' => 'usa',
																	'annee' =>2016);
			// exercice 3
			foreach ($film as $key => $value) {
				echo "<b>Element $key</b> :<br>";
				foreach ($value as $num => $valueValue) {
					echo "element $num : $valueValue<br>";
				}
			}
			echo "<br><br><br><br>";
			foreach ($film2 as $key => $value) {
				echo "<b>Element $key</b> :<br>";
				foreach ($value as $num => $valueValue) {
					echo "element $num : $valueValue<br>";
				}
			}

			// exercice 4
			echo "<br><br><br><br>";
			echo"Avant Tri";
			var_dump($film);
			echo "<br>ApresTri";
			asort($film);
			var_dump($film);

			echo "<br>Element au hasard : <b>".array_rand($film2,1)."</b>";

			echo "<br>Talbeau Monde";
			$monde = array('Afrique' , 'Amerique' , 'Asie' , 'Europe' , 'Oceanie');
			var_dump($monde);
			echo"<br>Melange:";
			shuffle($monde);
			var_dump($monde);

			// exercice 5
			$tabNaissance = array ("25/08/1997", "26/04/1999" , "30/07/1968" , "05/02/2015" , "10/09/1940");
			echo"<br><br><br>Date de naissance:";
			var_dump($tabNaissance);
			$cpt = 0;
			foreach ($tabNaissance as $key) {
				$annees[$cpt] = explode("/",$key)[2];
				$cpt++;
			}
			echo "<br>Annees de Naissances";
			var_dump($annees);

			 ?>

		</section>
	</div>
	<?php include("./include/footer.php"); ?>
</body>
</html>
