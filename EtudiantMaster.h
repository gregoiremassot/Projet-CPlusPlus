//
// Created by Grégoire on 28/04/2018.
//

#ifndef PROJET_CPP_ETUDIANTMASTER_H
#define PROJET_CPP_ETUDIANTMASTER_H
#include "Etudiant.h"
#include "EtudiantLicence.h"

using namespace std;

class EtudiantMaster : public Etudiant {
private:
    vector<EtudiantLicence> tutores;
};


#endif //PROJET_CPP_ETUDIANTMASTER_H
