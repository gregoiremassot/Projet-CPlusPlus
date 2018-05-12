// Binome : Grégoire MASSOT - David-Anthony SELLEM
#include <iostream>
#include "../h/Universite.h"
int main()
{
    /*Cours Biologie("2");
    cout << Biologie.getIdEleve(8);*/

    /*Enseignant Rastapopoulos("2");
    cout << Rastapopoulos.getIdue(0) << endl;*/

    /*EtudiantLicence DavidAnthony("1");
    cout << DavidAnthony.moyenne()<< endl;*/

    Universite ISFA("Universite");
    cout << ISFA.getCours(8)->moyenne() << endl;

    //cout << "Coucou !" << endl;
    return 0;
}