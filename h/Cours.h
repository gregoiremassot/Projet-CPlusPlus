//
// Created by Grégoire on 26/04/2018.
//

#ifndef PROJET_CPP_COURS_H
#define PROJET_CPP_COURS_H

#include <string>
#include <vector>
#include "Etudiant.h"

using namespace std;

class Etudiant;
class Enseignant;
class Universite;

struct eleve
{
    Etudiant* e_etudiant;
    double e_note;
    int id_etudiant;
};

struct less_than_note
{
    inline bool operator() (const eleve& struct1, const eleve& struct2)
    {
        return (struct1.e_note > struct2.e_note);
    }
};

class Cours
{
public:
    Cours(string nom_fichier);
    int getCode();
    string getNom();
    int getIdEnseignant();
    int getIdEleve(int i);
    double moyenne(void);
    void initialiserPointeursEleves(Universite* universite);
    vector<string> help_cours(void);
    void getClassementCours();

private:
    unsigned int m_code;
    string m_nom;
    int m_id_enseignant;
    string m_niveau;
    Enseignant* m_enseignant;

    vector<int> m_id_eleve;
    vector<eleve> m_eleves;

};


#endif //PROJET_CPP_COURS_H