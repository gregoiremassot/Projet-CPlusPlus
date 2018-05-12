//
// Created by Grégoire on 28/04/2018.
//

#ifndef PROJET_CPP_UNIVERSITE_H
#define PROJET_CPP_UNIVERSITE_H

#include <vector>
#include "../h/Enseignant.h"
#include "../h/Cours.h"
#include "../h/Etudiant.h"
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

    Enseignant* getEnseignant(int idEnseignant);
    Cours* getCours(int idCours);
    EtudiantLicence* getEtudiantLicence(int idEtudiant);
    EtudiantMaster* getEtudiantMaster(int idEtudiant);
    Etudiant* getEtudiant(int idEtudiant);
private:
    vector<Cours*> m_cours;
    vector<EtudiantLicence*> m_etudiantslicence;
    vector<EtudiantMaster*> m_etudiantsmaster;
    vector<Enseignant*> m_enseignants;
};


#endif //PROJET_CPP_UNIVERSITE_H
