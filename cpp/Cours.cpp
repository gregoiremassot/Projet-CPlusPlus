//
// Created by Grégoire on 26/04/2018.
//
#include <iostream>
#include <string>
#include "../h/Cours.h"
#include <fstream>

using namespace std;

Cours::Cours(string nom_fichier)
{
    ofstream fichier("Universite/Cours/" + nom_fichier + ".txt");  // on ouvre en lecture

    if(fichier)
    {
        /*string ligne;
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            cout << ligne << endl;  // on l'affiche
        }*/
        cout << "Coucou !";
    }


}