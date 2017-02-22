# -*- coding: latin-1 -*-

# importation de la librairie graphique
import wxRUR


# Classe de l'application Pacman
class AppPacman(wxRUR.Application) :
    def __init__(self) :
        # Initialise l'application graphique (appel au constructeur parent)
        wxRUR.Application.__init__(self,                )
        # Crée un attribut pacman en position (6,6) tourné vers l'est
        self.pacman = wxRUR.Robot(self,                 )
        # Association de la méthode 'deplacer_pacman'
        # à l'évènement "KeyEvent" (appui sur une touche)
        self.KeyEventHandler(onKeyEvent=self.deplacer_pacman)
        # Boucle de gestion des évènements de l'application
        self.MainLoop(      )
        # Fermeture de l'application
        self.Quit()

    # Méthode évènementielle de déplacement du pacman
    def deplacer_pacman(self, KeyEvent):
        pass


# Crée une instance de l'application Pacman
appPacman = AppPacman()