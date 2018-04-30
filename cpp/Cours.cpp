//
// Created by Grégoire on 26/04/2018.
//
#include <iostream>
#include <string>
#include "../h/Cours.h"
#include "../h/Enseignant.h"
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
        string line;
        string s;

        getline(fichier, line);
        s = line;
        m_code = stoi(s);

        getline(fichier, line);
        s = line;
        m_nom = s;
        cout << s;

        getline(fichier, line);
        s = line;
        m_enseignant->setNom(s);
    }


}