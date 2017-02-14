<?php
namespace ProjetBundle\Entity;
use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Validator\Constraints as Assert;
/**
* @ORM\Entity
*/
class Projet {
    /**
    * @ORM\GeneratedValue
    * @ORM\Id
    * @ORM\Column(type="integer")
    */
    private $id;
    /**
    * @ORM\Column(type="string",length=255)
    * @Assert\NotBlank()
    * @Assert\Length(
    *      min = 3,
    *      minMessage = "Your titre must be at least {{ limit }} characters long",
    * )
    */
    private $titre;
    /**
    * @ORM\Column(type="string",length=500)
    */
    private $description;
    /**
    * @ORM\ManyToOne(targetEntity="Departement")
    * @Assert\NotBlank()
    */
    private $departement;
    /**
    * @ORM\ManyToMany(targetEntity="Employe")
    */
    private $employes;
    /**
     * Constructor
     */
    public function __construct()
    {
        $this->employes = new \Doctrine\Common\Collections\ArrayCollection();
    }

    /**
     * Get id
     *
     * @return integer 
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * Set titre
     *
     * @param string $titre
     * @return Projet
     */
    public function setTitre($titre)
    {
        $this->titre = $titre;

        return $this;
    }

    /**
     * Get titre
     *
     * @return string 
     */
    public function getTitre()
    {
        return $this->titre;
    }

    /**
     * Set description
     *
     * @param string $description
     * @return Projet
     */
    public function setDescription($description)
    {
        $this->description = $description;

        return $this;
    }

    /**
     * Get description
     *
     * @return string 
     */
    public function getDescription()
    {
        return $this->description;
    }

    /**
     * Set departement
     *
     * @param \ProjetBundle\Entity\Departement $departement
     * @return Projet
     */
    public function setDepartement(\ProjetBundle\Entity\Departement $departement = null)
    {
        $this->departement = $departement;

        return $this;
    }

    /**
     * Get departement
     *
     * @return \ProjetBundle\Entity\Departement 
     */
    public function getDepartement()
    {
        return $this->departement;
    }

    /**
     * Add employes
     *
     * @param \ProjetBundle\Entity\Employe $employes
     * @return Projet
     */
    public function addEmploye(\ProjetBundle\Entity\Employe $employes)
    {
        $this->employes[] = $employes;

        return $this;
    }

    /**
     * Remove employes
     *
     * @param \ProjetBundle\Entity\Employe $employes
     */
    public function removeEmploye(\ProjetBundle\Entity\Employe $employes)
    {
        $this->employes->removeElement($employes);
    }

    /**
     * Get employes
     *
     * @return \Doctrine\Common\Collections\Collection 
     */
    public function getEmployes()
    {
        return $this->employes;
    }
}
