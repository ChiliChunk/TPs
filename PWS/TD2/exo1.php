<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <?php
     $paysUE = array('Espagne' , 'France' , 'Allemagne');

     if (in_array ('Espagne' , $paysUE)){
       $rang = array_search ('Espagne' , $paysUE);
       echo ('L\'Espagne se trouve a la $rang place');
     }
    echo ("Salut");
     ?>
  </body>
</html>
