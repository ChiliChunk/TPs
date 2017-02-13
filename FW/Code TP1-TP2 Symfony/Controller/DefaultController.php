<?php

namespace ProjetBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use ProjetBundle\Entity\Departement;

class DefaultController extends Controller {
    public function indexAction($name) {
        /*
	    // on recupere le gestionnaire de donnees
		$em = $this->getDoctrine()->getManager();
		
		$dept1 = new Departement();
		$dept1->setNom('Ressources Humaines');
		$em->persist($dept1);
		
		$dept2 = new Departement();
		$dept2 ->setNom('Comptabilité');
		$em->persist($dept2);
		
		// le flush fait l’equivalent d’un commit
		$em->flush();
		*/
		return $this->render('ProjetBundle:Default:index.html.twig', array('name' => $name));
    }
}