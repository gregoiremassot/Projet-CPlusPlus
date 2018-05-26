// Binome : Grégoire MASSOT - David-Anthony SELLEM
#include <iostream>
#include "../h/Universite.h"

using namespace std;
int main()
{
    /*Cours Biologie("2");
    cout << Biologie.getIdEleve(8);*/

    /*Enseignant Rastapopoulos("2");
    cout << Rastapopoulos.getIdue(0) << endl;*/

    /*EtudiantLicence DavidAnthony("1");
    cout << DavidAnthony.moyenne()<< endl;*/

    Universite ISFA("Universite");
    int continuer = 1;
    int choix;

    while(continuer == 1)
    {
        cout << "1- Afficher la liste des cours | 2- ...";
        cin >> choix;
        switch(choix)
        {
            case 1:
                cout << "Choix 1";
                break;

            case 2:
                cout << "Choix 2";
                break;

            case 3:
                cout << "Choix 3";
                break;

            default :
                continuer = 0;
                break;
        }
    }

    //cout << ISFA.getCours(8)->moyenne() << endl;
    //ISFA.getCours(8)->help_cours();
    //cout << ISFA.getEtudiant(33)->moyenne() << endl;
    //ISFA.getEtudiantMaster(35)->getTutores();
    //ISFA.getCours(8)->getClassementCours();
    //ISFA.getEnseignant(2)->afficherEtudiantDifficulte();
    ISFA.getEtudiant(2)->getClassementCours(7);

    return 0;
}