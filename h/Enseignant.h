//
// David-Anthony Sellem
//

#ifndef PROJET_CPP_ENSEIGNANT_H
#define PROJET_CPP_ENSEIGNANT_H
#include <string>
#include <vector>

using namespace std;
class Cours;
class Universite;

class Enseignant {

public:
    Enseignant(string nom_fichier);
    int getNumber();
    string getNom();
    int getIdue(int nombre);
    vector<int> get_vector_id_ue();
    void initialiserPointeursCours(Universite* universite);
    void afficherEtudiantDifficulte();
private:
    unsigned int m_number;
    string m_name;
    vector<int> m_id_ue;
    vector<Cours*> m_ue;
};


#endif //PROJET_CPP_ENSEIGNANT_H
