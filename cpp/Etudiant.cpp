//
// Created by Grégoire on 26/04/2018.
//

#include "../h/Etudiant.h"
#include "../h/Cours.h"
#include <string>
#include <vector>


double Etudiant::moyenne()
{
    for (int k=0; k<m_liste_cours.size(); k++)
    {
        moyenne += m_liste_cours.at(k).note;
    }
    return moyenne/m_liste_cours.size();
};
