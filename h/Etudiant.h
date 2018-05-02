//
// Created by Grégoire on 26/04/2018.
//

#ifndef PROJET_CPP_ETUDIANT_H
#define PROJET_CPP_ETUDIANT_H
#include <string>
#include <vector>
#include "Cours.h"

struct cours_avec_notes{
    Cours* cours;
    double note;
};

using namespace std;
class Cours;

class Etudiant {

public:
    Etudiant(void); // Constructeur
    int moyenne(void);

private:
    unsigned int m_id;
    string m_name;
    vector<cours_avec_notes> m_liste_cours;
};


#endif //PROJET_CPP_ETUDIANT_H
