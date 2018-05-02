//
// Created by Grégoire on 26/04/2018.
//

#include "../h/Etudiant.h"
#include "../h/Cours.h"
#include <iostream>
#include <fstream>
using namespace std;


Etudiant::Etudiant(string nom_fichier)
{
    ifstream fichier("../Universite/Etudiants/" + nom_fichier + ".txt");  // on ouvre en lecture
    if(!fichier)
    {
        cout << "Impossible de lire le fichier" << endl;
    }
    else
    {
        string s, line;
        bool continuer = true;
        string nom_matiere, note;
        int i;
        cours_avec_notes ligne_Cours;

        getline(fichier, line);
        s = line;
        m_id = stoi(s);

        getline(fichier, line);
        s = line;
        m_name = s;

        while(getline(fichier, line))
        {
            s = line;
            nom_matiere = "";
            note = "";
            continuer = true;
            i = 0;

            while (continuer)
            {
                nom_matiere+=s[i];
                i++;
                if(s[i] == ';')
                {
                    continuer = false;
                    i++;
                }

            }

            while(i <s.length())
            {
                note += s[i];
                i++;
            }

            ligne_Cours.note = stoi(note);
            ligne_Cours.nom_cours = nom_matiere;
            m_liste_cours.push_back(ligne_Cours);

        }



    }
}


double Etudiant::moyenne()
{
    double moyenne;
    for (int k=0; k<m_liste_cours.size(); k++)
    {
        moyenne += m_liste_cours.at(k).note;
    }
    return moyenne/m_liste_cours.size();
};

int Etudiant::get_id()
{
    return m_id;
}

string Etudiant::get_name()
{
    return m_name;
}

double Etudiant::get_note_cours(int code_cours)
{
    return m_liste_cours[code_cours].note;
}