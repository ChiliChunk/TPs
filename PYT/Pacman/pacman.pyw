# -*- coding: latin-1 -*-

# importation de la librairie graphique
import wxRUR


# Classe de l'application Pacman
class AppPacman(wxRUR.Application) :
    def __init__(self) :
        # Initialise l'application graphique (appel au constructeur parent)
        wxRUR.Application.__init__(self,                )
        # Cr�e un attribut pacman en position (6,6) tourn� vers l'est
        self.pacman = wxRUR.Robot(self,                 )
        # Association de la m�thode 'deplacer_pacman'
        # � l'�v�nement "KeyEvent" (appui sur une touche)
        self.KeyEventHandler(onKeyEvent=self.deplacer_pacman)
        # Boucle de gestion des �v�nements de l'application
        self.MainLoop(      )
        # Fermeture de l'application
        self.Quit()

    # M�thode �v�nementielle de d�placement du pacman
    def deplacer_pacman(self, KeyEvent):
        pass


# Cr�e une instance de l'application Pacman
appPacman = AppPacman()