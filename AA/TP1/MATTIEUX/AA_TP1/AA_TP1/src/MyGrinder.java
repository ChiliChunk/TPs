import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import stone.Grinder;
import stone.Stone;

public class MyGrinder implements Grinder {

	private List<Stone> liste = new ArrayList<Stone>();
	private boolean verif;
	
	
	@Override
	public Collection<Stone> grind(Stone pierre, int diam) {
		
		int i = 0;
		verif = false;
		liste.add(pierre);
		
		while(verif!=true){
			while (i < liste.size()){
				while(liste.get(i).diameter()>diam){
					liste.add(liste.get(i).split());
				}
				i++;
			}
			verif=true;
		}
		
		return liste;
	}
	

}
