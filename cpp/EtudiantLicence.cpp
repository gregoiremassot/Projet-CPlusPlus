//
// Gregoire Massot
//

#include "../h/EtudiantLicence.h"

using namespace std;

EtudiantLicence::EtudiantLicence(string nom_fichier)
{
    ifstream fichier("../Universite/Etudiants/Licence/" + nom_fichier + ".txt");  // on ouvre en lecture

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
        getline(fichier, line);
        s = line;
        m_id = stoi(s);

        getline(fichier, line);
        s = line;
        m_name = s;

        getline(fichier, line);
        s = line;

        while (i < s.length()) {
            stop = 0;
            matiere = "";
            while (!stop && i < s.length()) {

                matiere += s[i];
                i++;
                if (s[i] == ';' | i == s.length()) {
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
        while (i < s.length()) {
            stop = 0;
            note = "";
            while (!stop && i < s.length()) {

                note += s[i];
                i++;
                if (s[i] == ';' | i == s.length()) {
                    stop = 1;
                    m_liste_cours[j].note = stoi(note);
                    j++;
                    i++;
                }
            }

        }
    }
}