//
// Updated by Davidan97 on 6/05/2018.
//

#include "../h/Etudiant.h"
#include "../h/Cours.h"
#include <iostream>
#include <fstream>
using namespace std;

Etudiant::Etudiant() {}

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

double Etudiant::moyenne(void) // permet de calculer sa moyenne
{
    double moyenne;
    for (int k=0; k<m_liste_cours.size(); k++)
    {
        moyenne += m_liste_cours.at(k).note;
    }
    return moyenne/m_liste_cours.size();
};

/*int Etudiant::classement(int ID) // permet de calculer son classement à un cours
{
    int classement=1;

    for (i=0; i<m_liste.cours.at(ID).cours.m_eleve.size(); i++) // pour chacun des élèves du cours
    {
        if (m_liste.cours.at(ID).cours.m_eleve.at(i).m_note > m_liste_cours.at(ID).note)
        {
            classement++;
        }
    }
    return classement;
};

bool Etudiant::help(int ID) // renvoie True si l'étudiant a besoin d'aide / False sinon
{
  if(m_liste_cours.at(ID).note < 10)
    {
        return true;
    }
    else
    {
        return false;
    }
};*/



int Etudiant::get_id()
{
    return m_id;
}

string Etudiant::get_name()
{
    return m_name;
}

double Etudiant::get_note_cours(int num_cours)
{
    return m_liste_cours[num_cours].note;
}

string Etudiant::get_nom_cours(int num_cours)
{
    return m_liste_cours[num_cours].nom_cours;
}