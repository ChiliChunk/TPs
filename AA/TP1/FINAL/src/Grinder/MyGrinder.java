package Grinder;

/* Nicolas BRIET
 * Guilhem SUSA
 * IUT Blagnac
 * Groupe 3A
 */
import java.util.ArrayList;
import java.util.Collection;

import stone.Grinder;
import stone.Stone;

public class MyGrinder implements Grinder {

	//Liste des pierres
	private ArrayList<Stone> alCailloux = new ArrayList<Stone>(); //création
	
	@Override
	public Collection<Stone> grind(Stone pierre, int diametre) {
		this.alCailloux.add(pierre);//modification
		
		//tant qu'il y a une pierre dont le diamètre est superieur au paramètre
		while(tousCasse(this.alCailloux,diametre)==false){
			//parcourrir la liste
			for (int i = 0; i < this.alCailloux.size(); i++) {//consultation
				//quand trouve une pierre au mauvais diamètre
				if (this.alCailloux.get(i).diameter() > diametre) {//consultation
					//la casse et ajoute le deuxième morceau dans la liste
					this.alCailloux.add(this.alCailloux.get(i).split());//modification
				}
			}
		}
		return alCailloux;
	}

	/**
	 * fonction permettant de savoir si tout les cailloux de la liste sont casse
	 * a la bonne taille et met a jour l'attribut aCasser en fonction du rang du
	 * cailloux a casser dans la liste
	 * 
	 * @param tabCailloux
	 * @param diametre
	 * @return true / false
	 */
	
	private boolean tousCasse(ArrayList<Stone> tabCailloux, int diametre) {
		boolean isOK=true;
		for(int j=0;j<this.alCailloux.size(); j++){//consultation
			if (this.alCailloux.get(j).diameter() > diametre) {//consultation
				isOK= false;
			}
		}
		return isOK;
	}
	 
}
