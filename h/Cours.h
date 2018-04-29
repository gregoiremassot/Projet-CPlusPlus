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
private:
    unsigned int m_code;
    string m_nom;
    Enseignant* m_enseignant;
    vector<eleve> m_eleves;

};


#endif //PROJET_CPP_COURS_H
