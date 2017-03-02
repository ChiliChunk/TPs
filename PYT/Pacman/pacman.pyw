# -*- coding: latin-1 -*-

# importation de la librairie graphique
import wxRUR


# Classe de l'application Pacman
class AppPacman(wxRUR.Application) :
    def __init__(self) :
        wxRUR.Application.__init__(self,title="Pacman Nicolas Briet" , world="pacman.wld")

        self.lesRobots = []
        self.lesRobots.append(wxRUR.Robot(self,col=1,row=1, orient='E', colour="light blue"))
        self.lesRobots.append(wxRUR.Robot(self,col=10,row=1, orient='W', colour="blue"))
        self.lesRobots.append(wxRUR.Robot(self,col=1,row=10, orient='E', colour="purple"))
        self.lesRobots.append(wxRUR.Robot(self,col=10,row=10, orient='W', colour="green"))
        self.lesRobots.append(wxRUR.Robot(self,col=1,row=6, orient='E', colour="grey"))

        self.pacman = wxRUR.Robot(self,col=6,row=6, orient='E' , colour='pacman')
        self.casesParcourues = set([])

        self.casesParcourues.add(self.pacman.getPos())

        self.pacman.set_trace_style(style=-1, colour='yellow')
        self.KeyEventHandler(onKeyEvent=self.deplacer_pacman)
        self.MainLoop()
        self.Quit()


    def deplacer_pacman(self, KeyEvent):
        touche = KeyEvent.GetKeyCode()
        #gauche
        if touche == 314:
            wxRUR.Robot.turn(self.pacman,orient='W')
        #haut
        elif touche == 315:
            wxRUR.Robot.turn(self.pacman,orient='N')
        #droite
        elif touche == 316:
            wxRUR.Robot.turn(self.pacman,orient='E')
        #bas
        elif touche == 317:
            wxRUR.Robot.turn(self.pacman,orient='S')
        #move
        if wxRUR.Robot.front_is_clear(self.pacman):
            wxRUR.Robot.move(self.pacman)
            self.casesParcourues.add(self.pacman.getPos())
            for robot in self.lesRobots:
                if self.pacman.getPos() == robot.getPos():
                    self.ShowMessage("WASTED")
                    self.ExitMainLoop()
        #gagne
        if (len(self.casesParcourues) == 100):
            self.ShowMessage("Vous avez gagné!")
            self.ExitMainLoop()

appPacman = AppPacman()
