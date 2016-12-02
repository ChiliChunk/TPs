
public class ClassEssai {
	public static void main(String[] args) {

		Compte cUn, cDeux, cTrois;
		
		cUn = new CompteBancaire ("11", "Moi","666", 15.2);
		cDeux = new CompteEpargne ("12", "Lui", 3.2);
		cTrois = new CompteMoneo ("13", "Eux", "321");
		
		try{
			cUn.deposer(54);
			cDeux.deposer(564);
			cTrois.deposer(65587);
		}catch (Exception e){
			System.out.println(e.getMessage());
		}
	}

}
