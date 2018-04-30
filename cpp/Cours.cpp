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
    ifstream fichier("../Universite/Cours/" + nom_fichier + ".txt");  // on ouvre en lecture
    if(!fichier)
    {
        cout << "Impossible de lire le fichier" << endl;
    }
    else
    {
        std::string line;
        while (std::getline(fichier, line))
        {
            //std::istringstream iss(line);
            cout << line << endl;
        }
    }


}