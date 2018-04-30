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
  note INT,
  PRIMARY KEY(code_cours, numero_etudiant)
);