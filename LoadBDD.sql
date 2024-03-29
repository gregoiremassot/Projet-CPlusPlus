USE universite;

-- Creéation des tables

DROP TABLE IF EXISTS cours;
DROP TABLE IF EXISTS etudiant;
DROP TABLE IF EXISTS enseignant;
DROP TABLE IF EXISTS suivre;

CREATE TABLE etudiant
(
  numero INT PRIMARY KEY ,
  nom VARCHAR(50),
  niveau VARCHAR(10),
  id_tuteur INT
);

CREATE TABLE etudiant_licence
(
  numero INT PRIMARY KEY ,
  nom VARCHAR(50),
  niveau VARCHAR(10),
  id_tuteur INT
);

CREATE TABLE enseignant
(
  numero INT PRIMARY KEY,
  nom VARCHAR(50)
);

CREATE TABLE cours
(
  code INT PRIMARY KEY,
  nom VARCHAR(50),
  numero_enseignant INT,
  niveau VARCHAR(10),
  CONSTRAINT fk_numero_enseignant
    FOREIGN KEY(numero_enseignant)
    REFERENCES enseignant(numero)
);

CREATE TABLE suivre
(
  numero_etudiant INT,
  code_cours INT,
  note INT
  -- PRIMARY KEY(code_cours, numero_etudiant)
);

-- Chargement des tables

LOAD DATA INFILE 'C:/projetcpp/projetcpp/BDD/Enseignant.csv'
INTO TABLE enseignant
FIELDS TERMINATED BY ';'
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

SELECT * FROM enseignant;

LOAD DATA INFILE 'C:/projetcpp/projetcpp/BDD/Etudiant.csv'
INTO TABLE etudiant
FIELDS TERMINATED BY ';'
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

SELECT * FROM etudiant;

LOAD DATA INFILE 'C:/projetcpp/projetcpp/BDD/Cours.csv'
INTO TABLE cours
FIELDS TERMINATED BY ';'
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

SELECT * FROM cours;

LOAD DATA INFILE 'C:/projetcpp/projetcpp/BDD/Notes.csv'
INTO TABLE suivre
FIELDS TERMINATED BY ';'
LINES TERMINATED BY '\n'
IGNORE 1 ROWS;

SELECT * FROM suivre;

DELETE t1 FROM suivre t1

INNER JOIN suivre t2
WHERE t1.numero_etudiant = t2.numero_etudiant
AND t1.code_cours = t2.code_cours
AND t1.note < t2.note;


-- TXT Enseignant
SELECT enseignant.numero, enseignant.nom, GROUP_CONCAT(cours.code SEPARATOR ';')
FROM enseignant INNER JOIN cours ON enseignant.numero = cours.numero_enseignant
GROUP BY enseignant.numero, enseignant.nom;

-- TXT Etudiant Master
SELECT A.numero, A.nom, A.matieres, A.notes, B.filleuls FROM
  (SELECT etudiant.numero, etudiant.nom, GROUP_CONCAT(cours.code SEPARATOR ';') AS matieres, GROUP_CONCAT(suivre.note SEPARATOR ';') AS notes
  FROM etudiant
  INNER JOIN suivre ON etudiant.numero = suivre.numero_etudiant
  INNER JOIN cours ON cours.code = suivre.code_cours
  WHERE etudiant.niveau = 'Master'
GROUP BY etudiant.numero, etudiant.nom) A
INNER JOIN (SELECT master.numero, master.nom, GROUP_CONCAT(licence.numero SEPARATOR ';') AS filleuls
FROM etudiant AS master
LEFT JOIN etudiant AS licence ON licence.id_tuteur = master.numero
GROUP BY master.numero) B
ON A.numero = B.numero;

-- TXT Etudiant Licence
SELECT etudiant.numero, etudiant.nom, GROUP_CONCAT(cours.code SEPARATOR ';') AS matieres, GROUP_CONCAT(suivre.note SEPARATOR ';') AS notes
  FROM etudiant
  INNER JOIN suivre ON etudiant.numero = suivre.numero_etudiant
  INNER JOIN cours ON cours.code = suivre.code_cours
  WHERE etudiant.niveau = 'Licence'
GROUP BY etudiant.numero, etudiant.nom;

-- TXT Cours
SELECT cours.code, cours.nom, cours.numero_enseignant, cours.niveau, GROUP_CONCAT(suivre.numero_etudiant SEPARATOR ';') AS etudiants
FROM cours
INNER JOIN suivre ON suivre.code_cours = cours.code
GROUP BY cours.code, cours.nom, cours.numero_enseignant, cours.niveau;

-- TXT Universite

SELECT "Cours", cours.code FROM Cours ORDER BY cours.code
INTO OUTFILE 'liste_cours.txt'
FIELDS TERMINATED BY ' '
LINES TERMINATED BY '\n';

SELECT "Enseignant", enseignant.numero FROM enseignant ORDER BY enseignant.numero
INTO OUTFILE './liste_enseignants.txt'
FIELDS TERMINATED BY ' '
LINES TERMINATED BY '\n';

SELECT "EtudiantMaster", etudiant.numero FROM etudiant WHERE etudiant.niveau = 'Master' ORDER BY etudiant.numero
INTO OUTFILE './liste_etudiant_master.txt'
FIELDS TERMINATED BY ' '
LINES TERMINATED BY '\n';

SELECT "EtudiantLicence", etudiant.numero FROM etudiant WHERE etudiant.niveau = 'Licence' ORDER BY etudiant.numero
INTO OUTFILE './liste_etudiant_licence.txt'
FIELDS TERMINATED BY ' '
LINES TERMINATED BY '\n';

-- Requetes de comparaison SQL/C++ --


-- 1- Moyenne - Etudiant
SELECT AVG(note) FROM suivre WHERE suivre.numero_etudiant = 10;
SELECT AVG(note) FROM suivre WHERE suivre.numero_etudiant = 33;

-- 2- Classement Etudiant
SELECT etudiant.numero, etudiant.nom, suivre.code_cours, suivre.note FROM etudiant
INNER JOIN suivre ON suivre.numero_etudiant = etudiant.numero
WHERE code_cours = 7
ORDER BY note DESC;

-- 3- EtudiantsTutores qu'il faut aider - EtudiantMaster
SELECT etudiant.numero, etudiant.nom, etudiant.niveau, etudiant.id_tuteur, AVG(suivre.note) AS moyenne FROM etudiant
  INNER JOIN suivre ON etudiant.numero = suivre.numero_etudiant
WHERE etudiant.id_tuteur=34
GROUP BY etudiant.numero
HAVING moyenne < 10;

-- 5- Moyenne - Cours
SELECT AVG(note) FROM suivre WHERE code_cours = 8
GROUP BY code_cours;

-- 6- Classement Etudiants - Cours
SELECT etudiant.numero, etudiant.nom, suivre.code_cours, suivre.note FROM etudiant
INNER JOIN suivre ON suivre.numero_etudiant = etudiant.numero
WHERE code_cours = 7
ORDER BY note DESC;

-- 7- Etudiants en difficulté - Cours
SELECT suivre.note, etudiant.nom FROM suivre
INNER JOIN etudiant ON etudiant.numero = suivre.numero_etudiant
WHERE suivre.code_cours = 12 AND suivre.note < 10;

-- 8- Etudiants en difficulté - Enseignant
SELECT suivre.code_cours, etudiant.nom, enseignant.numero, suivre.note FROM suivre
INNER JOIN etudiant ON etudiant.numero = suivre.numero_etudiant
INNER JOIN cours ON cours.code = suivre.code_cours
INNER JOIN enseignant ON enseignant.numero = cours.numero_enseignant
WHERE enseignant.numero=1 AND suivre.note < 10;

SHOW TABLES ;





