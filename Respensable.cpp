#include"Respensable.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void respensable::saisir_respensable()

{
    personne::saisir_personne();
    int nbsessions;
    cout<<"saisir le role : "<<endl;
    cin>>role;
    cout<<"saisir le nombre de sessions : "<<endl;
    cin>>nbsessions;
    for (int i = 0; i < nbsessions; i++) {
        int* session = new int; // Allouer dynamiquement un nouvel entier
        cout << "Saisir la session numero " << i+1 << " : ";
        cin >> *session;
        sessions.push_back(session);
    }
}
respensable::respensable(string role,int Cin,string nom,string prenom ,int tel ,string email,string adresse,int nblangues):personne(Cin, nom, prenom, tel, email, adresse,nblangues)
{
    this->role=role;
}
respensable::respensable(const respensable &r) : personne(r) {
    role = r.role;
    tasks=r.tasks;
    // Copie des sessions
    for (list<int*>::const_iterator it = r.sessions.begin(); it != r.sessions.end(); ++it) {
        int* session = new int(**it); // Allouer dynamiquement un nouvel entier et copier la valeur
        sessions.push_back(session);
    }
}

respensable::~respensable() {
    // Libérer la mémoire allouée pour les sessions
    for (list<int*>::iterator it = sessions.begin(); it != sessions.end(); ++it) {
        delete *it; // Supprimer chaque pointeur de session
    }
    sessions.clear(); // Effacer la liste des sessions
}


// Surcharge de l'operateur d'assignation
respensable& respensable::operator=(const respensable &autre) {
    if (this != &autre) { // Vérifier que ce n'est pas la même instance
        // Copie des attributs de l'objet passé en argument dans l'objet actuel
        personne::operator=(autre); // Appel de l'opérateur d'assignation de la classe de base

        // Copie de l'attribut spécifique à responsable
        role = autre.role;
        tasks = autre.tasks;

        // Suppression des anciennes sessions
        for (list<int*>::iterator it = sessions.begin(); it != sessions.end(); ++it) {
            delete *it;
        }
        sessions.clear(); // Effacer la liste

        // Copie des nouvelles sessions
        for (list<int*>::const_iterator it = autre.sessions.begin(); it != autre.sessions.end(); ++it) {
            int* newSession = new int(**it); // Allouer une nouvelle mémoire et copier la valeur
            sessions.push_back(newSession);
        }
    }
    return *this;
}
void respensable::afficherPersonne()
{
    personne::afficherPersonne();
    cout<<"le role est : "<<role<<endl;
    cout<<"Affichage des sessions : "<<endl;
     int i = 1;
    // Déclaration manuelle de l'itérateur
    list<int*>::const_iterator it;
    for (it = sessions.begin(); it != sessions.end(); ++it) {
        cout << "Session numero " << i << " : " << **it << endl; // Affichage de la session
        ++i;
    }
    // Affichage des tâches attribuées au responsable
    cout << "Tâches attribuées au responsable : " << endl;
    set<string>::const_iterator it_tasks;
    for (it_tasks = tasks.begin(); it_tasks != tasks.end(); ++it_tasks) {
        cout << "Tâche : " << *it_tasks << endl;
    }
}

void respensable::modifier() {
    // Demander à l'utilisateur s'il souhaite modifier les informations
    char choix;
    cout << "Voulez-vous modifier les informations du responsable ? (o/n) ";
    cin >> choix;
    if (choix == 'o' || choix == 'O') {
        int choixParam;
        do {
            // Demander à l'utilisateur ce qu'il souhaite modifier
            cout << "Quel paramètre souhaitez-vous modifier ?" << endl;
            cout << "1. Nom" << endl;
            cout << "2. Prenom" << endl;
            cout << "3. Email" << endl;
            cout << "4. Adresse" << endl;
            cout << "5. Nombre de logements" << endl;
            cout << "6. Role" << endl;
            cout << "7. Tâches" << endl;
            cout << "8. Sessions" << endl;
            cin >> choixParam;

            switch (choixParam) {
                case 1: {
                    string nouveauNom;
                    cout << "Nouveau nom : ";
                    cin >> nouveauNom;
                    personne::setnom(nouveauNom);
                    break;
                }
                case 2: {
                    string nouveauPrenom;
                    cout << "Nouveau prenom : ";
                    cin >> nouveauPrenom;
                    personne::setprenom(nouveauPrenom);
                    break;
                }
                case 3: {
                    string nouvelEmail;
                    cout << "Nouvel email : ";
                    cin >> nouvelEmail;
                    personne::setemail(nouvelEmail);
                    break;
                }
                case 4: {
                    string nouvelleAdresse;
                    cout << "Nouvelle adresse : ";
                    cin >> nouvelleAdresse;
                    personne::setadresse(nouvelleAdresse);
                    break;
                }
                case 5: {
                    int nouveauNbLogements;
                    cout << "Nouveau nombre de logements : ";
                    cin >> nouveauNbLogements;
                   personne::setnblangues(nouveauNbLogements);
                    break;
                }
                case 6: {
                    cout << "Nouveau role : ";
                    cin >> role;
                    break;
                }
                case 7: {
                    // Supprimer les anciennes tâches
                    tasks.clear();
                    // Saisir les nouvelles tâches
                    int nbTaches;
                    cout << "Saisir le nombre de taches : ";
                    cin >> nbTaches;
                    cout << "Saisir les taches : " << endl;
                    for (int i = 0; i < nbTaches; ++i) {
                        string task;
                        cout << "Tache " << i+1 << " : ";
                        cin >> task;
                        tasks.insert(task);
                    }
                    break;
                }
                case 8: {
                    // Supprimer les anciennes sessions
                    for (list<int*>::iterator it = sessions.begin(); it != sessions.end(); ++it) {
                        delete *it; // Supprimer chaque pointeur de session
                    }
                    sessions.clear(); // Effacer la liste des sessions

                    // Saisir les nouvelles sessions
                    int nbSessions;
                    cout << "Saisir le nombre de sessions : ";
                    cin >> nbSessions;
                    for (int i = 0; i < nbSessions; ++i) {
                        int* session = new int;
                        cout << "Saisir l'identifiant de la session " << i+1 << " : ";
                        cin >> *session;
                        sessions.push_back(session);
                    }
                    break;
                }
                default:
                    cout << "Choix invalide. Veuillez saisir à nouveau." << endl;
            }
        } while (choixParam < 1 || choixParam > 9);
    }
}





void respensable::ajouter_session(int* sess)
{
   sessions.push_back(sess);
}

void respensable::supprimer_session() {
    // Vérifier si la liste des sessions est vide
    if (sessions.empty()) {
        cout << "La liste des sessions est vide. Aucune session à supprimer." << endl;
        return;
    }

    // Afficher les sessions disponibles
    cout << "Sessions disponibles :" << endl;
    int i = 1;
    for (list<int*>::iterator it = sessions.begin(); it != sessions.end(); ++it) {
        cout << i << ". Session " << **it << endl;
        ++i;
    }

    // Demander à l'utilisateur de saisir le numéro de la session à supprimer
    int numero;
    do {
        cout << "Saisir le numéro de la session à supprimer : ";
        cin >> numero;

        // Vérifier si le numéro est valide
        if (numero < 1 || numero > sessions.size()) {
            cout << "Numéro de session invalide. Veuillez saisir un numéro valide." << endl;
        }
    } while (numero < 1 || numero > sessions.size()); // Répéter tant que l'indice est invalide

    // Supprimer la session
    list<int*>::iterator it = sessions.begin();
    advance(it, numero - 1); // Déplacer l'itérateur jusqu'à la position de la session à supprimer
    delete *it; // Supprimer la session
    sessions.erase(it); // Effacer la session de la liste

    cout << "Session numéro " << numero << " supprimée avec succès." << endl;
}

ostream& operator<<(ostream& os, const respensable& r) {
    os << static_cast<const personne&>(r); // Appel de l'opérateur << de la classe de base personne
    os << "Role: " << r.role << endl;
    os << "Tasks:" << endl;
    for (set<string>::const_iterator it = r.tasks.begin(); it != r.tasks.end(); ++it) {
        os << "- " << *it << endl;
    }
    os << "Sessions:" << endl;
    for (list<int*>::const_iterator it = r.sessions.begin(); it != r.sessions.end(); ++it) {
        os << "- Session: " << **it << endl;
    }
    return os;
}
istream& operator>>(istream &in, respensable &r)
{
    // Utiliser la surcharge de l'opérateur >> de la classe personne
    in >> static_cast<personne&>(r);

    cout << "Saisir le rôle : " << endl;
    in >> r.role;

    // Saisie des sessions
    cout << "Saisir le nombre de sessions : ";
    int nbSessions;
    in >> nbSessions;
    for (int i = 0; i < nbSessions; ++i) {
        int* session = new int;
        cout << "Saisir l'identifiant de la session " << i + 1 << " : ";
        in >> *session;
        r.sessions.push_back(session);
    }

     // Saisie des tâches attribuées au responsable
    cout << "Saisir les tâches attribuées au responsable : " << endl;
    string task;
    while (true) {
        cout << "Saisir une tâche (ou 'fin' pour terminer la saisie) : ";
        in >> task;
        if (task == "fin") {
            break;
        }
        r.tasks.insert(task);
    }

    return in;
}

int respensable::calculerExperience() {
    return sessions.size();
}

void respensable::afficherArtisanGagnant( vector<evaluation>& evaluations) {
    double meilleurScore = 0;
    Artisan artisanGagnant ;
    // Parcourir toutes les évaluations pour trouver le score maximum avec une boucle for classique
    for (int i = 0; i < evaluations.size(); ++i) {
         evaluation& eval = evaluations[i];

        if (eval.getScore() > meilleurScore) {
            meilleurScore = eval.getScore();
            artisanGagnant = eval.getArtisan();
        }
    }
    cout<<artisanGagnant;
}

void respensable::ecrireResponsableDansFichier()
{
     ofstream fichier ("responsableDB.txt",ios::app);
    if (!fichier)
        cout << "erreur"<<endl ;
    fichier<<*this ;
    fichier.close();

}
