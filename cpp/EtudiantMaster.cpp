//
// Gregoire Massot
//

#include <vector>
#include <fstream>
#include <iostream>
#include "../h/EtudiantMaster.h"
#include "../h/Universite.h"

using namespace std;

EtudiantMaster::EtudiantMaster(string nom_fichier)
{
    ifstream fichier("../Universite/Etudiants/Master/" + nom_fichier + ".txt");  // on ouvre en lecture

    if (!fichier)
    {
        cout << "Impossible de lire le fichier" << endl;
    }
    else
    {
        string s, line;
        string matiere;
        int i = 0;
        int stop;
        string note;
        string tutore;

        getline(fichier, line);
        s = line;
        m_id = stoi(s);


        getline(fichier, line);
        s = line;
        m_name = s;

        getline(fichier, line);
        s = line;

        while (i < s.length())
        {
            stop = 0;
            matiere = "";
            while (!stop && i < s.length())
            {

                matiere += s[i];
                i++;
                if (s[i] == ';' | i == s.length())
                {
                    stop = 1;
                    m_liste_cours.push_back(cours_avec_notes());
                    m_liste_cours[m_liste_cours.size() - 1].nom_cours = matiere;
                    i++;
                }
            }

        }

        getline(fichier, line);
        s = line;
        int j = 0;
        i = 0;
        while (i < s.length())
        {
            stop = 0;
            note = "";
            while (!stop && i < s.length())
            {

                note += s[i];
                i++;
                if (s[i] == ';' | i == s.length())
                {
                    stop = 1;
                    m_liste_cours[j].note = stoi(note);
                    j++;
                    i++;
                }
            }

        }

        getline(fichier, line);
        s = line;
        i = 0;
        while (i < s.length())
        {
            stop = 0;
            tutore = "";
            while (!stop && i < s.length())
            {

                tutore += s[i];
                i++;
                if (s[i] == ';' | i == s.length())
                {
                    stop = 1;
                    m_id_tutores.push_back(stoi(tutore));
                    i++;
                }
            }

        }



    }
}


void EtudiantMaster::initialiserPointeursTutores(Universite* universite)
{
    for(int i = 0; i < m_id_tutores.size(); i++)
    {
        if(universite->getEtudiantLicence(m_id_tutores[i]) != 0)
        {
            m_tutores.push_back(universite->getEtudiantLicence(m_id_tutores[i]));
        }
    }
}

void EtudiantMaster::getTutores()
{
    cout << "id  nom moyenne" << endl;
    for(int i=0; i < m_tutores.size(); i++)
    {
        if(m_tutores[i]->moyenne() <= 10)
        {
            cout << m_tutores[i]->get_id() << "  " << m_tutores[i]->get_name() << " " << m_tutores[i]->moyenne() << endl;
        }
    }
}


/*EtudiantMaster::help_tutores(void)
{
  vector<bool> help_tutores;

  for(i=0; i<m_tutores.size(); i++) // pour chacun de mes tutores
  {
    bool stop;
    int loop=0;

    while(not m_tutores.at(i).help(loop) and loop<m_tutores.at(i).m_liste_cours.size()) //tant qu'il n'y a pas un cours où il a besoin d'aide ET qu'il y a des cours à vérifier
    {
      loop++; // je passe au cours suivant
    }

      help_tutores.push_back(m_tutores.at(i).help(loop)); // le dernier cours vérifier me dit s'il a bseoin d'aide ou pas.

  }

  //return help_tutores;
};*/

