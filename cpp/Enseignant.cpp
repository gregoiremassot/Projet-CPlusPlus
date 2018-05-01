//
// Created by Grégoire on 26/04/2018.
//
#include "../h/Enseignant.h"
#include <iostream>
#include <fstream>

Enseignant::Enseignant(string nom_fichier)
{
    ifstream fichier("../Universite/Enseignants/" + nom_fichier + ".txt");  // on ouvre en lecture
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
        m_number = stoi(s);

        getline(fichier, line);
        s = line;
        m_name = s;

    }


}

int Enseignant::getNumber() {return m_number;};
string Enseignant::getNom() {return m_name;};