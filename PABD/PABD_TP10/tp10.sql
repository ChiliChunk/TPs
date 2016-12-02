SET SERVEROUTPUT ON;
ACCEPT pIdC PROMPT 'Saisir un numéro de chanson : ';
ACCEPT pTitre PROMPT 'Saisir un titre de chanson : ';
ACCEPT pAnnee PROMPT 'Saisir une année de parution : ';
ACCEPT pIdAuteur PROMPT 'Saisir un auteur : ';
ACCEPT pIdCompo PROMPT 'Saisir un compositeur : ';
DECLARE

 vIdC Chanson.idC%TYPE := &pIdC;
 vTitre Chanson.titre%TYPE := '&pTitre';
 vAnnee Chanson.annee%TYPE := &pAnnee;
 vIdAuteur Chanson.idAuteur%TYPE := &pIdAuteur;
 vIdCompo Chanson.idCompositeur%TYPE := &pIdCompo;
 exEtrangere EXCEPTION;
 PRAGMA  EXCEPTION_INIT (exEtrangere, -02291);

BEGIN
--Numero de chanson deja existant
SELECT COUNT(*) INTO C1
FROM CHANSON
WHERE idC = vIdC;
IF (C1>0) THEN
	RAISE ChansonDejaExistante;
END IF;



--TRAITEMENT
INSERT INTO Chanson
VALUES (vIdC, vTitre, vAnnee, vIdAuteur, vIdCompo);
DBMS_OUTPUT.PUT_LINE('Chanson '||vTitre||' ajoute');
UPDATE Artiste
SET NBA = NBA + 1
WHERE idA = vIdAuteur;
DBMS_OUTPUT.PUT_LINE('NBA mis a jour.');
UPDATE Artiste
SET NBC = NBC + 1
WHERE idA = vIdCompo;
DBMS_OUTPUT.PUT_LINE('NBC mis a jour.');
 COMMIT;


 EXCEPTION
When ChansonDejaExistante  then
	DBMS_OUTPUT.PUT_LINE('Numero de Chanson deja present dans la base, insertion non effecctuee');
	DBMS_OUTPUT.PUT_LINE ('Code erreur ' || SQLCODE) ;
	DBMS_OUTPUT.PUT_LINE ('Message d''erreur ' || SQLERRM) ; 

When exEtrangere then
	DBMS_OUTPUT.PUT_LINE('Erreur sur une clef etrangere');

END;
/
SHOW ERRORS;
L;


-------------------------------------------------EXO 2
SET SERVEROUTPUT ON;
ACCEPT pIdP PROMPT 'Saisir un identifiant de piste : ';
ACCEPT pDuree PROMPT 'Saisir la duree de la piste en secondes : ';
ACCEPT pIdC PROMPT 'Saisir un identifiant de chanson : ';
ACCEPT pIdA PROMPT 'Saisir un identifiant dalbum : ';
DECLARE
vIdP Piste.idP%TYPE := &pIdP;
vDuree Piste.duree%TYPE := &pDuree;
vIdC Chanson.idC%TYPE := &pIdC;
vIdA Album.idA%TYPE := &pIdA;
N1 NUMBER;
N2 NUMBER;
N3 NUMBER;
N4 NUMBER;
BEGIN
--PISTE deja existant
SELECT COUNT(*) INTO N1
FROM Piste
WHERE idP = vIdP;
IF (N1>0) THEN
	RAISE PisteDejaExistante;
END IF;
--Chanson inconnu
SELECT COUNT(*) INTO N2
FROM Chanson
WHERE idC = vIdC;
IF (N2<1) THEN
	Raise ChansonInconnue;
END IF;
--Num album inconnu
SELECT COUNT(*) INTO N3
FROM Album
WHERE idA = vIdA;
IF (N3<1) THEN
	Raise numAlbumInconnu;
END IF;
--Duree invalide
IF (vDuree<1) THEN
	Raise dureeInvalide;
END IF;
--TRAITEMENT
SELECT MAX(NoP) INTO N4
FROM PISTE, ALBUM A
WHERE vIdA = A.idA
AND idP= vIdP;
INSERT INTO Piste
VALUES (vIdP, N4+1,vDuree, vIdC, vIdA);
DBMS_OUTPUT.PUT_LINE('Piste '||vIdP||' ajoutée');
COMMIT;
EXCEPTION

WHEN PisteDejaExistante then
	DBMS_OUTPUT.PUT_LINE('Numero de Piste deja present dans la base, insertion non effecctuee');
	DBMS_OUTPUT.PUT_LINE ('Code erreur ' || SQLCODE) ;
	DBMS_OUTPUT.PUT_LINE ('Message d''erreur ' || SQLERRM) ;

WHen ChansonInconnue then
	DBMS_OUTPUT.PUT_LINE('Numero de chanson inconnu dans la base, insertion non effecctuee');
	DBMS_OUTPUT.PUT_LINE ('Code erreur ' || SQLCODE) ;
	DBMS_OUTPUT.PUT_LINE ('Message d''erreur ' || SQLERRM) ;

when numAlbumInconnu then
	DBMS_OUTPUT.PUT_LINE('Numero d album inconnu dans la base, insertion non effecctuee');
	DBMS_OUTPUT.PUT_LINE ('Code erreur ' || SQLCODE) ;
	DBMS_OUTPUT.PUT_LINE ('Message d''erreur ' || SQLERRM) ;

when dureeInvalide then
	DBMS_OUTPUT.PUT_LINE('Duree de piste invalide, insertion non effecctuee');
	DBMS_OUTPUT.PUT_LINE ('Code erreur ' || SQLCODE) ;
	DBMS_OUTPUT.PUT_LINE ('Message d''erreur ' || SQLERRM) ;

END;
/
SHOW ERRORS;
L;
