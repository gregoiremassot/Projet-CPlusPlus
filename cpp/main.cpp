// Binome : Grégoire MASSOT - David-Anthony SELLEM
#include <iostream>
#include "../h/Enseignant.h"
#include "../h/Cours.h"
int main()
{
    Cours Biologie("1");
    cout << Biologie.getIdEleve(1);

    /*Enseignant Rastapopoulos("1");
    cout << Rastapopoulos.getIdue(1) << endl;*/

    //Etudiant DavidAnthony("1");
    //cout << DavidAnthony.get_note_cours(0)<< endl;

    //cout << "Coucou !" << endl;
    return 0;
}