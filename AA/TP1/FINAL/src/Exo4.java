/* Nicolas BRIET
 * Guilhem SUSA
 * IUT Blagnac
 * Groupe 3A
 */
import Grinder.MyGrinder;
import Grinder.MyGrinderB;
import stone.Grinder;
import stone.GrinderBench;
import stone.Stone;

public class Exo4 {

	public static void main(String[] args) {

		//Grinder MonGrinder = new MyGrinder() ;
		Grinder MonGrinderB = new MyGrinderB() ;
		Stone grosCailloux = Stone.makeHugeStone();
		
		/*
		 * Avec HugeStone : 17069 ms
		 * Avec BigStone : 153 ms
		 * Avec SmallStone : 5 ms
		 */
		
		//GrinderBench.benchmark(MonGrinder,4,grosCailloux);
		GrinderBench.benchmark(MonGrinderB,4,grosCailloux);

	}

}
