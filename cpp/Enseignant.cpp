//
// Created by Grégoire on 26/04/2018.
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

/*vector<cancre> Enseignant::need_help()
{
    vector<cancre> need_help;
    cancre temoin;

    for (int c=0; c<m_ue.size(); c++) // pour chacun des cours de l'enseignant
    {
        for (int e=0; e<m_ue.at(c).m_eleve.size(); e++) // et chacun des élèves à ces cours
        {
            temoin.c_etudiant = m_ue.at(c).m_eleves.at(e);
            temoin.c_help = temoin.c_etudiant.help(m_ue.at(c).m_code);

            if ( not temoin.c_help)
            {
                need_help.push_back(temoin);
            }
        }
    }
    return need_help;
};*/

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