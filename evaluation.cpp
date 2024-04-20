#include<iostream>
#include"Artisan.h"
#include"Participant.h"
#include"evaluation.h"
#include<string>
using namespace std;

evaluation::evaluation(double score,Artisan& artisan, Participant& participant)
{
    this->score = score;
    this->artisan = artisan;
    this->participant = participant;
}

void evaluation::editerEvaluation()
{
    char reponse;
    do {
        cout << "Que voulez-vous modifier pour cette evaluation ?" << endl;
        cout << "S : Score, Q : Quitter" << endl;
        cin >> reponse;

        switch (toupper(reponse)) {
            case 'S':
                cout << "Saisir le nouveau score : ";
                cin >> score;
                break;

            case 'Q':
                return; // Quitter la methode
            default:
                cout << "Reponse invalide !" << endl;
                continue; // Revenir au debut de la boucle pour redemander une reponse valide
        }

        do {
            cout << "Voulez-vous encore modifier ? O : OUI, N : NON" << endl;
            cin >> reponse;

            if (toupper(reponse) != 'O' && toupper(reponse) != 'N') {
                cout << "Reponse invalide !" << endl;
            }
        } while (toupper(reponse) != 'O' && toupper(reponse) != 'N');

    } while (toupper(reponse) == 'O');
}



void evaluation :: afficher_evaluation()
{
    cout<<"Artisan : "<<artisan<<endl<<"Participant: "<<participant<<endl<<"***Score*** "<<score<<endl;
}
ostream& operator<<(ostream& o,const evaluation &e)
{
    o<<"Affichage des informations relatives a cette evaluation : "<<endl;
    o<<"Participant : "<<e.participant<<endl;
    o<<"Artisan : "<<e.artisan<<endl;
    o<<"score :"<<e.score<<endl;
    return o;
}

evaluation::~evaluation(){}
