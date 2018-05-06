//
// Updated by Davidan97 on 6/05/2018.
//

#include "../h/EtudiantMaster.h"
#include <vector>

using namespace std;

EtudiantMaster::help_tutores(void)
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

  return help_tutores;
};

