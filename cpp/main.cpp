// Binome : Grégoire MASSOT - David-Anthony SELLEM
#include <iostream>
#include "../h/Enseignant.h"
#include "../h/Cours.h"
#include "../h/EtudiantLicence.h"
#include "../h/EtudiantMaster.h"
int main()
{
    /*Cours Biologie("2");
    cout << Biologie.getIdEleve(8);*/

    /*Enseignant Rastapopoulos("2");
    cout << Rastapopoulos.getIdue(0) << endl;*/

    EtudiantMaster DavidAnthony("31");
    cout << DavidAnthony.get_nom_cours(0)<< endl;

    //cout << "Coucou !" << endl;
    return 0;
}