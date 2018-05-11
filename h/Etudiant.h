//
// Updated by Davidan97 on 6/05/2018.
//

#ifndef PROJET_CPP_ETUDIANT_H
#define PROJET_CPP_ETUDIANT_H
#include <string>
#include <vector>
#include <fstream>
#include "iostream"
using namespace std;

class Cours;

struct cours_avec_notes
{
    Cours* cours;
    string nom_cours;
    double note;
};

using namespace std;
class Cours;

class Etudiant {

public:
    Etudiant(void);
    Etudiant(string nom_fichier); // Constructeur
    int get_id(void);
    double moyenne(void);
    //int classement(int ID);
    //bool help(int ID);
    string get_name(void);
    double get_note_cours(int code_cours);
    string get_nom_cours(int code_cours);

protected:
    unsigned int m_id;
    string m_name;
    vector<cours_avec_notes> m_liste_cours;
};


#endif //PROJET_CPP_ETUDIANT_H
