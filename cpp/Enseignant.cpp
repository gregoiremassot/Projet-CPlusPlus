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
        int i = 0;
        string nombre;
        bool stop = 0;
        string line, s;

        getline(fichier, line);
        s = line;
        m_number = stoi(s);

        getline(fichier, line);
        s = line;
        m_name = s;

        getline(fichier, line);
        s = line;

        while(i < s.length())
        {
            stop = 0;
            nombre = "";
            while(!stop && i<s.length())
            {

                nombre += s[i];
                i++;
                if(s[i] == ';')
                {
                    stop = 1;
                    m_id_ue.push_back(stoi(nombre));
                    i++;
                }
            }

        }

    }


}

int Enseignant::getNumber() {return m_number;};
string Enseignant::getNom() {return m_name;};
int Enseignant::getIdue(int nombre) {return m_id_ue[nombre];};