---------------------------------------------------1
--1

create or replace view VSPORTIF_FRA(idS, nom, prenom, intitule)
as select distinct sportif.idS , sportif.nom , sportif.prenom , sport.intitule
from sportif , sport , gagner_ind , discipline
where sportif.cio = 'FRA'
and gagner_ind.ids = sportif.idS
and discipline.ids = sport.ids
and discipline.idd = gagner_ind.idd;


--2
--capture 1.png

--3
insert into VSPORTIF_FRA values (720, 'Ladji', 'DOUCOURE', 'ATHLETICS');
      --Erreur SQL : ORA-01732: les manipulations de données sont interdites sur cette vue
      --01732. 00000 -  "data manipulation operation not legal on this view"


--4
set serveroutput on;
CREATE OR REPLACE TRIGGER t_i_vsportif_fra
INSTEAD OF INSERT
ON
 VSPORTIF_FRA
FOR EACH ROW
BEGIN
   insert into sportif values (:NEW.IDS , :NEW.prenom  ,:NEW.nom  , 'FRA' , 0);
EXCEPTION
   WHEN DUP_VAL_ON_INDEX THEN
      DBMS_OUTPUT.PUT_LINE('Violation de cle primaire');
END
;
/

--5
set serveroutput on;
insert into VSPORTIF_FRA values (720, 'Ladji', 'DOUCOURE', 'ATHLETICS');
  --1 ligne inséré.
  --on ne trouve pas l'ajout dans la vue car le sportif n'a pas encore de medaille
  --si on essaye d'ajouter plusieurs fois le meme tuple on retrouve le message "Violation de cle primaire"


  --6 on voit le tuple dans la table sportif mais pas dans la vue;
  select * from sportif
  where sportif.CIO = 'FRA';

  select * from VSPORTIF_FRA;

  
