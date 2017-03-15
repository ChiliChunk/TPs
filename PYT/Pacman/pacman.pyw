# -*- coding: latin-1 -*-

# importation de la librairie graphique
import wxRUR
import math


# Classe de l'application Pacman
class AppPacman(wxRUR.Application) :

    def __init__(self) :
        wxRUR.Application.__init__(self,title="Pacman Nicolas Briet" , world="pacman.wld")

        difficulte = wxRUR.Application.InputInt(self,text="Choisissez un nombre entre 1 et 5",title="Difficulté du Jeu")

        self.lesRobots = []
        self.lesRobots.append(wxRUR.Robot(self,col=1,row=1, orient='E', colour="light blue"))
        self.lesRobots.append(wxRUR.Robot(self,col=10,row=1, orient='W', colour="blue"))
        self.lesRobots.append(wxRUR.Robot(self,col=1,row=10, orient='E', colour="purple"))
        self.lesRobots.append(wxRUR.Robot(self,col=10,row=10, orient='W', colour="green"))
        self.lesRobots.append(wxRUR.Robot(self,col=1,row=6, orient='E', colour="grey"))

        self.pacman = wxRUR.Robot(self,col=6,row=6, orient='E' , colour='pacman')
        self.casesParcourues = set([])
        #pos de base
        self.casesParcourues.add(self.pacman.getPos())
        self.deplacement = { 'E':(1,0) , 'W':(-1,0) , 'S':(0,-1) , 'N':(0,1)}
        self.pacman.set_trace_style(style=-1, colour='yellow')
        self.KeyEventHandler(onKeyEvent=self.deplacer_pacman)
        self.numRobot = 0

        self.TimerEventHandler(onTimerEvent = self.deplacer_un_robot , TimerPeriod = 0.5)
        self.MainLoop()
        duration = wxRUR.Application.TimeLoop(self)
        self.ShowMessage("Terminé , temps : "+str(duration))
        self.Quit()

    def deplacer_un_robot(self,TimerEvent):
        self.numRobot += 1
        self.numRobot = self.numRobot % len(self.lesRobots)
        robot = self.lesRobots[self.numRobot]
        robot.turn(self.direction_poursuite(robot))
        robot.move()
        if robot.getPos() == self.pacman.getPos():
            self.ShowMessage("WASTED")
            self.ExitMainLoop()

    def direction_poursuite(self,robot):
        totalDirection = {'N':-1 , 'S':-1 , 'E':-1 , 'W':-1}
        for direction in totalDirection:
            totalDirection[direction]=self.distance_au_pacman(robot,direction)
        directionFinale = None

        while directionFinale == None:

            min_val = min(totalDirection.itervalues())
            minDirection = [k for k, v in totalDirection.iteritems() if v == min_val]
            for dire in minDirection:
                if robot.is_clear(dire):
                    directionFinale = dire
            if directionFinale == None:
                for truc in minDirection:
                    del totalDirection[truc]

        return directionFinale


    def distance_au_pacman(self , robot , direction):
        xRobot = robot.getPos()[0] + self.deplacement[direction][0]
        yRobot = robot.getPos()[1] + self.deplacement[direction][1]

        xPacman = self.pacman.getPos()[0]
        yPacman = self.pacman.getPos()[1]


        deltaX = xRobot-xPacman
        deltaY = yRobot-yPacman
        res = 0.0
        res = math.sqrt(math.pow(deltaX , 2) + math.pow(deltaY , 2))
        return res

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
