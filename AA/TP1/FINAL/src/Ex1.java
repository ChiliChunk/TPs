/* Nicolas BRIET
 * Guilhem SUSA
 * IUT Blagnac
 * Groupe 3A
 */
import stone.Stone;

public class Ex1 {

	public static void main(String[] args) {
		
		Stone cailloux = Stone.makeBigStone();
		System.out.println(cailloux.toString());
		
		Stone cailloux2 = cailloux.split();
		
		System.out.println(cailloux.toString());
		System.out.println(cailloux2.toString());

		
	}
	

}
