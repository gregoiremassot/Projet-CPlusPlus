//
// David-Anthony Sellem
//
#include "../h/Enseignant.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "../h/Universite.h"
class Etudiant;

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
                if(s[i] == ';' | i == s.length())
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
vector<int> Enseignant::get_vector_id_ue() {return m_id_ue;}

void Enseignant::initialiserPointeursCours(Universite* universite)
{
    for(int i = 0; i < m_id_ue.size(); i++)
    {
        if(universite->getCours(m_id_ue[i]) != 0)
        {
            m_ue.push_back(universite->getCours(m_id_ue[i]));
        }
    }
}

void Enseignant::afficherEtudiantDifficulte()
{
    cout << "IDCours Cours Eleve" << endl;
    for(int i=0; i < m_ue.size(); i++)
    {
        for(int j=0; j< m_ue[i]->help_cours().size();j++)
        {
            cout << m_ue[i]->getCode() << " " << m_ue[i]->getNom() << " " << m_ue[i]->help_cours()[j] << endl;
        }
    }
}