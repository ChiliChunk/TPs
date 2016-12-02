import stone.Stone;

public class Ex1 {

	public static void main(String[] args) {
		
		Stone petitCaillou = Stone.makeSmallStone();
		
		System.out.println(petitCaillou.toString());
		
		petitCaillou.split();
		
		System.out.println(petitCaillou.toString());

		
		
		
		
		

	}

}
