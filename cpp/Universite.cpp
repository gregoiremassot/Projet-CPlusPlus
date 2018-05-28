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
            m_etudiantslicence.push_back(new EtudiantLicence(id));
        }
        else if(type == "EtudiantMaster")
        {
            m_etudiantsmaster.push_back(new EtudiantMaster(id));
        }

    }
    Flux.seekg(0, ios::beg);
    Flux >> n;

    for(int i=0; i<n; i++)
    {
        Flux >> type;
        Flux >> id;

        if(type == "Enseignant")
        {
            getEnseignant(stoi(id))->initialiserPointeursCours(this);
        }
        else if(type == "Cours")
        {
            getCours(stoi(id))->initialiserPointeursEleves(this);
        }

        else if(type == "EtudiantLicence")
        {
            getEtudiant(stoi(id))->initialiserPointeursCours(this);
        }

        else if(type == "EtudiantMaster")
        {
            getEtudiant(stoi(id))->initialiserPointeursCours(this);
            getEtudiantMaster(stoi(id))->initialiserPointeursTutores(this);
        }
    }
}

Enseignant* Universite::getEnseignant(int idEnseignant)
{
    int i = 0;
    while( i < m_enseignants.size())
    {
        if(m_enseignants[i]->getNumber() == idEnseignant)
        {
            return m_enseignants[i];
        }
        i++;
    }
    return 0;
}

Cours* Universite::getCours(int idCours)
{
    int i = 0;
    while( i < m_cours.size())
    {
        if(m_cours[i]->getCode() == idCours)
        {
            return m_cours[i];
        }
        i++;
    }
    return 0;
}

Etudiant* Universite::getEtudiant(int idEtudiant)
{
    int i = 0;
    while( i < m_etudiantslicence.size())
    {
        if(m_etudiantslicence[i]->get_id() == idEtudiant)
        {
            return m_etudiantslicence[i];
        }
        i++;
    }
    i = 0;
    while( i < m_etudiantsmaster.size())
    {
        if(m_etudiantsmaster[i]->get_id() == idEtudiant)
        {
            return m_etudiantsmaster[i];
        }
        i++;
    }

    return 0;
}

EtudiantLicence* Universite::getEtudiantLicence(int idEtudiant)
{
    int i = 0;
    while( i < m_etudiantslicence.size())
    {
        if(m_etudiantslicence[i]->get_id() == idEtudiant)
        {
            return m_etudiantslicence[i];
        }
        i++;
    }
    return 0;
}

EtudiantMaster* Universite::getEtudiantMaster(int idEtudiant)
{
    int i = 0;
    while( i < m_etudiantsmaster.size())
    {
        if(m_etudiantsmaster[i]->get_id() == idEtudiant)
        {
            return m_etudiantsmaster[i];
        }
        i++;
    }
    return 0;
}

void Universite::afficherEtudiants()
{
    cout << "ID Nom Niveau" << endl;
    for(int i = 0; i < m_etudiantslicence.size(); i++)
    {
        cout << m_etudiantslicence[i]->get_id() << " " << m_etudiantslicence[i]->get_name() << " Licence" << endl;
    }

    for(int i = 0; i < m_etudiantsmaster.size(); i++)
    {
        cout << m_etudiantsmaster[i]->get_id() << " " << m_etudiantsmaster[i]->get_name() << " Master" << endl;
    }
}

void Universite::afficherCours()
{
    cout << "ID Nom" << endl;
    for(int i=0; i<m_cours.size(); i++)
    {
        cout << m_cours[i]->getCode() << " " << m_cours[i]->getNom() << endl;
    }
}

void Universite::afficherEnseignants()
{
    cout << "ID Nom" << endl;
    for(int i=0; i<m_enseignants.size(); i++)
    {
        cout << m_enseignants[i]->getNumber() << " " << m_enseignants[i]->getNom() << endl;
    }
}

void Universite::afficherNotes()
{
    for(int i=0; i<m_cours.size(); i++)
    {
        cout << "IDCours IDEnseignant IDEtudiant Note" << endl;
        for(int j=0; j<m_cours[i]->getEleves().size(); j++)
        {
            cout << m_cours[i]->getCode() << " " << m_cours[i]->getIdEnseignant() << " " << m_cours[i]->getEleves()[j].id_etudiant << " " << m_cours[i]->getEleves()[j].e_note << endl;
        }
    }
}
