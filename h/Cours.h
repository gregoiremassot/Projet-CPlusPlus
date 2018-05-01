//
// Created by Grégoire on 26/04/2018.
//

#ifndef PROJET_CPP_COURS_H
#define PROJET_CPP_COURS_H

#include <string>
#include <vector>
#include "structures.h"
using namespace std;

class Enseignant;

class Cours
{
public:
    Cours(string nom_fichier);
    int getCode();
    string getNom();
    int getIdEnseignant();
    int getIdEleve(int i);
private:
    unsigned int m_code;
    string m_nom;
    int m_id_enseignant;
    Enseignant* m_enseignant;

    vector<int> m_id_eleve;
    vector<eleve> m_eleves;

};


#endif //PROJET_CPP_COURS_H
