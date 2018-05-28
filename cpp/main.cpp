// Binome : Grégoire MASSOT - David-Anthony SELLEM
#include <iostream>
#include "../h/Universite.h"

using namespace std;
int main()
{
    Universite ISFA("Universite");
    int continuer = 1;
    int choix;
    int idEtudiant, idCours;
    double note;
    while(continuer == 1)
    {
        cout << "-- MENU --" << endl;
        cout << "1- Afficher la moyenne d'un étudiant" << endl;
        cout << "2- Afficher le classement d'un étudiant dans un cours " << endl;
        cout << "3- Afficher les etudiants tutores qu'il faut aider" << endl;
        cout << "4- Modifier notes d'un étudiant" << endl;
        cout << "5- Afficher la moyenne sur un cours" << endl;
        cout << "6- Afficher le classement des étudiants sur un Cours" << endl;
        cout << "7- Afficher les étudiants en difficulté dans un cours" << endl;
        cout << "8- Afficher les étudiants en difficulté dans des cours prodigués par un enseignant" << endl;
        cout << "10- Afficher la liste des étudiants" << endl;
        cout << "11- Afficher la liste des cours" << endl;
        cout << "12- Afficher la liste des enseignants" << endl;
        cout << "13- Afficher la liste des notes" << endl;

        cout << "Choix : ";
        cin >> choix;

        switch(choix)
        {
            case 1:
                cout << "Donner l'id de l'étudiant" << endl;
                cin >> idEtudiant;
                cout << "Moyenne : " << ISFA.getEtudiant(idEtudiant)->moyenne() << endl;
                break;

            case 2:
                cout << "Donnez l'id de l'étudiant" << endl;
                cin >> idEtudiant;
                cout << "Donnez l'id du cours" << endl;
                cin >> idCours;
                ISFA.getEtudiant(idEtudiant)->getClassementCours(idCours);

            case 3:
                cout << "Donnez l'id de l'étudiant" << endl;
                cin >> idEtudiant;
                ISFA.getEtudiantMaster(idEtudiant)->getTutores();
                break;

            case 4:
                cout << "Donner l'id de l'étudiant" << endl;
                cin >> idEtudiant;
                cout << "Donner l'id du cours" << endl;
                cin >> idCours;
                cout << "Donner la nouvelle note" << endl;
                cin >> note;
                ISFA.getCours(idCours)->modifierNote(idEtudiant, note);
                ISFA.getEtudiant(idEtudiant)->modifierNoteCours(idCours, note);
                break;

            case 5:
                cout << "Donnez l'id du Cours" << endl;
                cin >> idCours;
                cout << "Moyenne sur le cours : " << ISFA.getCours(idCours)->moyenne() << endl;
                break;

            case 6:
                cout << "Donnez l'id du Cours" << endl;
                cin >> idCours;
                ISFA.getCours(idCours)->getClassementCours();
                break;

            case 7:
                cout << "Donner l'ID du cours" << endl;
                cin >> idCours;
                cout << "Etudiant" << endl;
                for(int k =0; k<ISFA.getCours(idCours)->help_cours().size();k++)
                {
                    cout << ISFA.getCours(idCours)->help_cours()[k] << endl;
                }
                break;

            case 8:
                cout << "Donner l'ID de l'enseignant" << endl;
                cin >> idEtudiant;
                ISFA.getEnseignant(idEtudiant)->afficherEtudiantDifficulte();
                break;

            case 10:
                ISFA.afficherEtudiants();
                break;

            case 11:
                ISFA.afficherCours();
                break;

            case 12:
                ISFA.afficherEnseignants();
                break;

            case 13:
                ISFA.afficherNotes();
                break;

            default :
                continuer = 0;
                break;
        }
        cout << endl;
    }

    return 0;
}