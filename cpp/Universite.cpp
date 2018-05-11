//
// Created by Grégoire on 28/04/2018.
//

#include "../h/Universite.h"

Universite::Universite() {}

Universite::Universite(string nom_fichier)
{
    ifstream Flux("../Universite/" + nom_fichier + ".txt");
    int n;
    Flux >> n;
    string type, id;

    for(int i=0; i<n; i++)
    {
        Flux >> type;
        Flux >> id;

        if(type == "Enseignant")
        {
            m_enseignants.push_back(new Enseignant(id));
        }
        else if(type == "Cours")
        {
            m_cours.push_back(new Cours(id));
        }
        else if(type == "EtudiantLicence")
        {
            m_etudiants.push_back(new EtudiantLicence(id));
        }
        else if(type == "EtudiantMaster")
        {
            m_etudiants.push_back(new EtudiantMaster(id));
        }

    }
}