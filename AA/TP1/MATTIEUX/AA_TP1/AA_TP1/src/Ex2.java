import stone.Stone;

public class Ex2 {

	public static void main(String[] args) {

		Stone grandCaillou = Stone.makeBigStone();
		Stone secondCaillou;
		System.out.println(grandCaillou.toString());
		
		int cpt=0;
		
		while(grandCaillou.diameter()>5){
			secondCaillou=grandCaillou.split();
			if(grandCaillou.diameter()>secondCaillou.diameter()){
				grandCaillou = secondCaillou;
			}
			cpt++;

		}
		System.out.println(grandCaillou.toString());
		System.out.println(cpt);
	}

}
