import java.util.Locale;
import java.util.Scanner;

public class ClasseApplicationAgenceBancaire {

	// Scanner partagé par toutes les méthodes : un seul suffit pour toute l'application.
	private Scanner lect;
	
	// L'agence bancaire gérée par l'application en cours.
	private AgenceBancaire monAg;

	// Constructeur
	public ClasseApplicationAgenceBancaire(AgenceBancaire ag) {
		this.lect = new Scanner(System.in);
		this.lect.useLocale(Locale.US);
		this.monAg = ag;
	}

	// Lancer l'application : le menu + réponses du système
	public void runApplication() {

		String choix;
		boolean continuer;

		continuer = true;
		while (continuer) {
			this.afficherMenu();
			choix = this.lect.next();
			choix = choix.toLowerCase();
			switch (choix) {
			case "q":
				System.out.println("ByeBye");
				this.tempo();
				continuer = false;
				break;
			case "cb":
				this.creerCompteBancaire();
				this.tempo();
				break;
			case "ce":
				this.creerCompteEpargne();
				this.tempo();
				break;
			case "cj":
				this.creerCompteJeune();
				this.tempo();
				break;
			case "cm":
				this.creerCompteMoneo();
				this.tempo();
				break;
			case "s":
				this.supprimerUnCompte();
				this.tempo();
				break;
			case "l":
				this.monAg.afficher();
				this.tempo();
				break;
			case "v":
				this.voirUnCompte();
				this.tempo();
				break;
			case "p":
				this.comptesDUnPropretaire();
				this.tempo();
				break;
			case "d":
				this.deposerSurUnCompte();
				this.tempo();
				break;
			case "r":
				this.retirerSurUnCompte();
				this.tempo();
				break;
			case "t":
				this.transfertEntreDeuxComptes();
				this.tempo();
				break;				
			default:
				System.out.println("Erreur de saisie ...");
				this.tempo();
				break;
			}
		}
	}

	// Saisir les infos pour un CompteMoneo
	// Créer l'objet CompteMoneo
	// Ajouter cet objet à l'agence gérée
	private void creerCompteMoneo () {
		// Il faudra traiter toutes les exceptions possibles car
		// c'est une interface utilisateur.
		// On donnera à chaque fois un message écran explicite pour l'utilisateur 
		// par exemple un chargé de clientèle dans une agence
		// (pas un simple System.out.println (e) ou System.out.println (e.getMessage()) 
		CompteMoneo cm ;
		System.out.println("Créer un compte moneo ");
		System.out.println("Not Yet Implemented");
	}
	
	// Saisir les infos pour un CompteBancaire
	// Créer l'objet CompteBancaire
	// Ajouter cet objet à l'agence gérée
	private void creerCompteBancaire () {
		// Il faudra traiter toutes les exceptions possibles car
		// c'est une interface utilisateur.
		// On donnera à chaque fois un message écran explicite pour l'utilisateur 
		// par exemple un chargé de clientèle dans une agence
		// (pas un simple System.out.println (e) ou System.out.println (e.getMessage()) 
		CompteBancaire cb;
		System.out.println("Créer un compte bancaire ");
		System.out.println("Not Yet Implemented");
	}
	
	// Saisir les infos pour un CompteEpargne
	// Créer l'objet CompteEpargne
	// Ajouter cet objet à l'agence gérée
	private void creerCompteEpargne () {
		// Il faudra traiter toutes les exceptions possibles car
		// c'est une interface utilisateur.
		// On donnera à chaque fois un message écran explicite pour l'utilisateur 
		// par exemple un chargé de clientèle dans une agence
		// (pas un simple System.out.println (e) ou System.out.println (e.getMessage()) 
		CompteEpargne cep ;
		System.out.println("Créer un compte épargne ");
		System.out.println("Not Yet Implemented");
	}

	// Saisir les infos pour un CompteJeune
	// Créer l'objet CompteJeune
	// Ajouter cet objet à l'agence gérée
	private void creerCompteJeune () {
		// Il faudra traiter toutes les exceptions possibles car
		// c'est une interface utilisateur.
		// On donnera à chaque fois un message écran explicite pour l'utilisateur 
		// par exemple un chargé de clientèle dans une agence
		// (pas un simple System.out.println (e) ou System.out.println (e.getMessage()) 
		CompteJeune cj;
		System.out.println("Créer un compte jeune ");
		System.out.println("Not Yet Implemented");
	}

	// Transfert entre deux comptes
	// Saisir les numéros de deux comptes, 
	// Saisir le montant à transférer
	// Réaliser le transfert
	private void transfertEntreDeuxComptes () {
		// Il faudra traiter toutes les exceptions possibles car
		// c'est une interface utilisateur.
		// On donnera à chaque fois un message écran explicite pour l'utilisateur 
		// par exemple un chargé de clientèle dans une agence
		// (pas un simple System.out.println (e) ou System.out.println (e.getMessage()) 
		System.out.println("Transfert entre deux comptes");
		System.out.println("Not Yet Implemented");
	}
	
	// Affichage des options du menu
	private void afficherMenu() {
		System.out.println("Menu de " + this.monAg.getNomAgence() + " ("
				+ this.monAg.getLocAgence() + ")");
		System.out.println("cb - Créer un nouveau compte bancaire dans l'agence");
		System.out.println("ce - Créer un nouveau compte epargne dans l'agence");
		System.out.println("cj - Créer un nouveau compte jeune dans l'agence");
		System.out.println("cm - Créer un nouveau Compte moneo dans l'agence");
		System.out.println("s - Supprimer un compte de l'agence (par son numéro)");
		System.out.println("l - Liste des comptes de l'agence");
		System.out.println("v - Voir un compte (par son numéro)");
		System.out.println("p - voir les comptes d'un Propriétaire (par son nom)");
		System.out.println("d - Déposer de l'argent sur un compte");
		System.out.println("r - Retirer de l'argent sur un compte");
		System.out.println("t - Transférer une somme entre deux comptes");
		System.out.println("q - Quitter");
		System.out.print("Choix -> ");
	}

	// Temporisation : attend la frappe de caractères par l'utilisateur
	private void tempo() {
		String s;

		System.out.print("Tapper un car + return pour continuer ... ");
		s = this.lect.next(); // Inutile à stocker mais ...
	}

	// Afficher avec son solde un compte à l'écran
	private void voirUnCompte () {
		String numero;
		Compte c;
		
		System.out.print("Num compte -> ");
		numero = this.lect.next();
		c = this.monAg.getCompte(numero);
		if (c == null) {
			System.out.println("Compte inexistant ...");
		} else {
			c.afficher();
		}
	}
	
	// Supprimer un compte à partir de la saisie de son numéro
	private void supprimerUnCompte() {
		String numero;
		System.out.print("Num compte -> ");
		numero = this.lect.next();
		try {
			this.monAg.removeCompte(numero);
			System.out.println("Suppression effectuée\n");
		} catch (ABCompteInexistantException e) {
			System.out.println("Numéro de compte inexistant");
			System.out.println(e.getMessage());
		}
	}

	// Affichage de tous les comptes d'un propriétaire 
	private void comptesDUnPropretaire() {
		Compte[] t;
		String nom;
		
		System.out.print("Propriétaire -> ");
		nom = this.lect.next();
		
		t = this.monAg.getComptesDe(nom);
		if (t.length == 0) {
			System.out.println("pas de compte à ce nom ...");
		} else {
			System.out.println("  " + t.length + " comptes pour " + nom);
			for (int i = 0; i < t.length; i++)
				t[i].afficher();
		}
	}

	// Déposer de l'argent sur un compte par saisie du numéro de compte et du montant
	private void deposerSurUnCompte() {
		Compte c;
		String numero;
		double montant;
		
		System.out.print("Num compte -> ");
		numero = this.lect.next();
		System.out.print("Montant à déposer -> ");
		montant = this.lect.nextDouble();
		c = this.monAg.getCompte(numero);
		if (c == null) {
			System.out.println("Compte inexistant ...");
		} else {
			System.out.println("Solde avant dépôt: " + c.soldeCompte());
			try {
				c.deposer(montant);
				System.out.println("Montant déposé, solde : " + c.soldeCompte());
			} catch (CompteException e) {
				System.out.println("Erreur de dépot, solde inchangé : " + c.soldeCompte());
				System.out.println(e.getMessage());
			}
		}
	}

	// Retrait d'argent sur un compte par saisie du numéro de compte et du montant
	private void retirerSurUnCompte() {
		String numero;
		double montant;
		Compte c;

		System.out.print("Num compte -> ");
		numero = this.lect.next();
		System.out.print("Montant à retirer -> ");
		montant = this.lect.nextDouble();
		c = this.monAg.getCompte(numero);
		if (c == null) {
			System.out.println("Compte inexistant ...");
		} else {
			System.out.println("Solde avant retrait : " + c.soldeCompte());
			try {
				c.retirer(montant);
				System.out.println("Montant retiré, solde : " + c.soldeCompte());
			} catch (CompteException e) {
				System.out.println("Erreur de dépot, solde inchangé : " + c.soldeCompte());
				System.out.println(e.getMessage());
			}
		}

	}
}
