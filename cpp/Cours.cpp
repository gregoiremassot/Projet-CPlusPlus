//
// Updated by Davidan97 on 6/05/2018.
//
#include <iostream>
#include "../h/Cours.h"
#include "../h/Enseignant.h"
#include <fstream>
#include <algorithm>

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

double Cours::moyenne(void)
{
    double moyenne=0;
    for(i=0; i<m_eleves.size(); i++)
    {
        moyenne+=m_eleves.at(i).e_note;
    }
    moyenne/=m_eleves.size();
    return moyenne;
}

vector<bool> Cours::help_cours(void) // renvoit True (besoin d'aide) or False pour chaque étudiant du cours
{
    vector<bool> help_cours;

    for(i=0;i<m_eleve.size();i++)
    {
        if(m_eleves.at(i).e_notes <10)
        {
            help_cours.push_back(true);
        }
        else
        {
            help_cours.push_back(false);
        }
    }
        return help_cours;
};


int Cours::getCode() { return m_code;};
string Cours::getNom() { return m_nom;};
int Cours::getIdEnseignant() { return m_id_enseignant;};
int Cours::getIdEleve(int i) {return m_id_eleve[i];};

