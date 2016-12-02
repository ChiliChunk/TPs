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
			<h2>Welcome</h2>
			<p>Bienvenue sur mon site !</p>
		</section>
	</div>
	<?php include("./include/footer.php"); ?>
</body>
</html>
