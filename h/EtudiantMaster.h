//
// Updated by Davidan97 on 6/05/2018.
//

#ifndef PROJET_CPP_ETUDIANTMASTER_H
#define PROJET_CPP_ETUDIANTMASTER_H
#include "Etudiant.h"
#include "EtudiantLicence.h"

using namespace std;

class EtudiantMaster : public Etudiant
{
public:
    EtudiantMaster(string nom_fichier);
    void initialiserPointeursTutores(Universite* universite);
    //vector<bool> help_tutores(void);
    void getTutores();

private:
    vector<int> m_id_tutores;
    vector<EtudiantLicence*> m_tutores;
};

#endif //PROJET_CPP_ETUDIANTMASTER_H