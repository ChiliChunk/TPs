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
			<h2>AfficheTitres</h2>
			<br/>
			<?php
			  for ($i = 1; $i < 7; $i++) {
				echo "<h$i> $i :Titre de niveau $i</h$i>\n";
			  }
			?>
		</section>
	</div>
	<?php include("./include/footer.php"); ?>
</body>
</html>
