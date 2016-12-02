<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" />
	<link rel="stylesheet" href="./include/styles.css" />
	<title>Site Nicolas Briet</title>
</head>
<body>
	<?php

		include("./include/header.php");
	?>
	<div class="wrapper">
		<?php include("./include/menus.php"); ?>
		<section id="content">
			<h2>AffecterCategories</h2>
			<br/>
			<?php

			$age = 14;
			$poids = 78.5;
			$categoriePoids = NULL;

			$categAge = ($age >= 21) ? 'senior' : 'junior';
			echo "Votre catégorie d'âge est $categAge <br/>";

			if(isset($poids)) {
				switch ($poids) {

					case $poids < 60:
						$categoriePoids = "super-légers";
					break;

					case $poids < 66:
						$categoriePoids = "mi-légers";
					break;

					case $poids < 73:
						$categoriePoids = "légers";
					break;

					case $poids < 81:
						$categoriePoids = "moyens";
					break;

					case $poids <90:
						$categoriePoids = "super-moyens";
					break;

					case $poids < 100:
						$categoriePoids = "mi-lourds";
					break;

					case $poids >= 100:
						$categoriePoids = "lourds";
					break;

				}

				echo "Votre catégorie de poids est $categoriePoids <br/>";
			}
		?>
		<?php include("./include/AffecterCategories.php"); ?>
		</section>
	</div>
	<?php include("./include/footer.php"); ?>
</body>
</html>
