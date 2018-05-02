//
// Created by Grégoire on 28/04/2018.
//

#ifndef PROJET_CPP_UNIVERSITE_H
#define PROJET_CPP_UNIVERSITE_H

#include "Etudiant.h"
#include "Enseignant.h"
#include "Cours.h"

#include <vector>

using namespace std;

class Cours;
class Etudiant;
class Enseignant;


class Universite
{
private:
    vector<Cours*> m_cours;
    vector<Etudiant*> m_etudiants;
    vector<Enseignant*> m_enseignants;
};


#endif //PROJET_CPP_UNIVERSITE_H
