//
// Updated by Davidan97 on 6/05/2018.
//

#include "../h/Etudiant.h"
#include "../h/Cours.h"
#include "../h/Universite.h"
#include <iostream>
#include <fstream>
#include <c++/algorithm>

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
    double moyenne = 0;
    for (int k=0; k<m_liste_cours.size(); k++)
    {
        moyenne += m_liste_cours[k].note;
    }
    if(m_liste_cours.size() > 0)
        return moyenne/m_liste_cours.size();
    else
        return 0;
};

bool Etudiant::help() // renvoie True si l'étudiant a besoin d'aide / False sinon
{
  if(moyenne() < 10) return true;
  else return false;

};



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
    int i = 0;
    while (i < m_liste_cours.size())
    {
        if(num_cours == stoi(m_liste_cours[i].nom_cours))
            return m_liste_cours[i].note;

        i++;
    }
    return 0;
}

string Etudiant::get_nom_cours(int num_cours)
{
    return m_liste_cours[num_cours].nom_cours;
}

void Etudiant::initialiserPointeursCours(Universite* universite)
{
    for(int i = 0; i < m_liste_cours.size(); i++)
    {
        if(universite->getCours(stoi(m_liste_cours[i].nom_cours)) != 0)
        {
            m_liste_cours[i].cours = universite->getCours(stoi(m_liste_cours[i].nom_cours));
        }
    }
}

void Etudiant::getClassementCours(int id_cours)
{
    int classement;
    vector<eleve> eleves_cours;
    bool continuer = true;
    for(int i=0; i<m_liste_cours.size(); i++)
    {
        if(m_liste_cours[i].cours->getCode() == id_cours)
        {
            eleves_cours = m_liste_cours[i].cours->getEleves();
            sort(eleves_cours.begin(), eleves_cours.end(), less_than_note());

            continuer = true;
            classement=1;
            while(continuer)
            {
                //cout << classement << endl;
                if(eleves_cours[classement-1].id_etudiant == get_id())
                {
                    continuer = false;
                }
                else
                {
                    classement++;
                }
            }
            cout << "Classement : " << classement << endl;
        }
    }
}

void Etudiant::modifierNoteCours(int idCours, double nouvelleNote)
{
    for(int i=0; i < m_liste_cours.size(); i++)
    {
        if(m_liste_cours[i].cours->getCode() == idCours)
        {
            m_liste_cours[i].note = nouvelleNote;
        }
    }
}