DROP TABLE IF EXISTS Medias;
DROP TABLE IF EXISTS Types;

CREATE TABLE Types (
idType VARCHAR(4),
nomType VARCHAR(25),
PRIMARY KEY (idType);
) Engine=InnoDB;

CREATE TABLE Medias (
idMedia VARCHAR(3),
idType VARCHAR(4) NOT NULL,
nomMedia VARCHAR(50),
dateParution mediumint(4),
PRIMARY KEY (idMedia),
FOREIGN KEY (idType) REFERENCES Types(idType)
)Engine=InnoDB;


INSERT INTO Types (idType, nomType) VALUES ('100', 'Romans');
INSERT INTO Types (idType, nomType)  VALUES ('200', 'Essais');
INSERT INTO Types (idType, nomType) VALUES ('300', 'DVD');

INSERT INTO Medias (idMedia, idType, nomMedia, dateParution) VALUES ('115', '100','Crime et châtiment',1866);
INSERT INTO Medias (idMedia, idType, nomMedia, dateParution) VALUES ('198', '100', 'Madame Bovary', 1857);
INSERT INTO Medias (idMedia, idType, nomMedia, dateParution) VALUES ('231', '200', 'Notre Patrie', 1905);
INSERT INTO Medias (idMedia, idType, nomMedia, dateParution) VALUES ('302', '300', 'Django Unchained', 2013);
INSERT INTO Medias (idMedia, idType, nomMedia, dateParution) VALUES ('357', '300', 'Forrest Gump', 1994);

COMMIT;
