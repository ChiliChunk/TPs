<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" />
	<link rel="stylesheet" href="./include/styles.css" />
	<title>Site Nicolas Briet</title>
</head>
<body>
	<?php
		// Index.php

		include("./include/header.php");
	?>
	<div class="wrapper">
		<?php include("./include/menus.php"); ?>
		<section id="content">
			<h2>Test Multiplie</h2>
			<br/>
			<?php
			  require_once("Fonction.php");
			  multiplie(12);
			?>
		</section>
	</div>
	<?php include("./include/footer.php"); ?>
</body>
</html>
