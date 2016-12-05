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
			echo "<br><br><br><br>"
			foreach ($film2 as $key => $value) {
				echo "<b>Element $key</b> :<br>";
				foreach ($value as $num => $valueValue) {
					echo "element $num : $valueValue<br>";
				}
			}

			// exercice 4

			 ?>

		</section>
	</div>
	<?php include("./include/footer.php"); ?>
</body>
</html>
