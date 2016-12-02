<?php public function multiplie($taille)
{
  echo "<table>";
  echo "<tr><th>X</th>";
  for ($i = 1 ; i <= $taille ; i++){
    echo "<th>$i</th>";
  }
  echo "</tr>";
  for ($i = 1 ; $i <= $taille ; $i++){
    for ($j = 1 ; $j <= $taille ; $i++){

      if ($j == 1 ){
        echo ("<tr><th>$i</th>")
      }
      elseif ($j ==taille) {
        echo "<td>$i*$j</td></tr>";
      }
      else {
          echo "<td>$i*$j</td>";
      }
    }
  }
  echo "</table>"
}

}
 ?>
