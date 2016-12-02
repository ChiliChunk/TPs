/* Nicolas BRIET
 * Guilhem SUSA
 * IUT Blagnac
 * Groupe 3A
 */
import stone.Stone;

public class Exo2 {

	public static void main(String[] args) {

		Stone cailloux1 = Stone.makeBigStone();
		Stone cailloux2;
		int i = 0;
		while (cailloux1.diameter() > 5) {
			cailloux2 = cailloux1.split();

			// optimisation
			if (cailloux1.diameter() > cailloux2.diameter()) {
				cailloux1 = cailloux2;
			}
			i++;
		}
		System.out.println(cailloux1.toString());
		System.out.println("Nombre de division de l'enorme cailloux : " + i);

	}

}
