//
// Created by Grégoire on 26/04/2018.
//
#include <iostream>
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
        string nombre;
        bool stop = 0;
        int i = 0;

        getline(fichier, line);
        s = line;
        m_code = stoi(s);

        getline(fichier, line);
        s = line;
        m_nom = s;

        getline(fichier, line);
        s = line;
        m_id_enseignant = stoi(s);

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
                    m_id_eleve.push_back(stoi(nombre));
                    i++;
                }
            }

        }
    }


}

int Cours::getCode() { return m_code;};
string Cours::getNom() { return m_nom;};
int Cours::getIdEnseignant() { return m_id_enseignant;};
int Cours::getIdEleve(int i) {return m_id_eleve[i];};
