USE universite;

DROP TABLE IF EXISTS cours;
DROP TABLE IF EXISTS etudiant;
DROP TABLE IF EXISTS enseignant;
DROP TABLE IF EXISTS suivre;

CREATE TABLE etudiant
(
  numero INT PRIMARY KEY ,
  nom VARCHAR(50)
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
  CONSTRAINT fk_numero_enseignant
    FOREIGN KEY(numero_enseignant)
    REFERENCES enseignant(numero)
);

CREATE TABLE suivre
(
  code_cours INT,
  numero_etudiant INT,
  note INT
  -- PRIMARY KEY(code_cours, numero_etudiant)
);

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

SELECT enseignant.numero, enseignant.nom, GROUP_CONCAT(cours.code SEPARATOR ';')
FROM enseignant INNER JOIN cours ON enseignant.numero = cours.numero_enseignant
GROUP BY enseignant.numero, enseignant.nom;


