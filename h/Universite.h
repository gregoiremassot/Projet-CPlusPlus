//
// Created by Grégoire on 28/04/2018.
//

#ifndef PROJET_CPP_UNIVERSITE_H
#define PROJET_CPP_UNIVERSITE_H

#include <vector>
#include "../h/Enseignant.h"
#include "../h/Cours.h"
#include "../h/EtudiantLicence.h"
#include "../h/EtudiantMaster.h"

using namespace std;

class Cours;
class Etudiant;
class Enseignant;


class Universite
{
public:
    Universite();
    Universite(string nom_fichier);
private:
    vector<Cours*> m_cours;
    vector<Etudiant*> m_etudiants;
    vector<Enseignant*> m_enseignants;
};


#endif //PROJET_CPP_UNIVERSITE_H
