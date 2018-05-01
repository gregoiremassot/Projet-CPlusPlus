// Binome : Grégoire MASSOT - David-Anthony SELLEM
#include <iostream>
#include "../h/Enseignant.h"
#include "../h/Cours.h"
int main()
{
    Cours Biologie("1");
    cout << Biologie.getIdEleve(1);
    return 0;
}