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

	// pour retenir quel cailloux reste a casser
	private int aCasser;

	@Override
	public Collection<Stone> grind(Stone pierre, int diametre) {
		ArrayList<Stone> alCailloux = new ArrayList<Stone>();
		alCailloux.add(pierre);
		// tant que tout les cailloux n'ont pas la bonne taille max
		while (tousCasse(alCailloux, diametre) == false) {
			// on casse le cailloux trop grand
			alCailloux.add(alCailloux.get(aCasser).split());
		}
		return alCailloux;
	}

	/**
	 * fonction permettant de savoir si tout les cailloux de la list sont casse
	 * a la bonne taille et met a jour l'attribut aCasser en fonction du rang du
	 * cailloux a casser dans la list
	 * 
	 * @param tabCailloux
	 * @param diametre
	 * @return true / false
	 */
	private boolean tousCasse(ArrayList<Stone> tabCailloux, int diametre) {
		for (int i = 0; i < tabCailloux.size(); i++) {
			if (tabCailloux.get(i).diameter() > diametre) {
				this.aCasser = i;
				return false;
			}
		}
		return true;
	}

}
