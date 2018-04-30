//
// Created by Grégoire on 26/04/2018.
//

#ifndef PROJET_CPP_ETUDIANT_H
#define PROJET_CPP_ETUDIANT_H
#include <string>
#include <vector>

using namespace std;
class Cours;

class Etudiant {
private:
    unsigned int m_id;
    string m_name;
    vector<Cours> cours_avec_notes;
};


#endif //PROJET_CPP_ETUDIANT_H
