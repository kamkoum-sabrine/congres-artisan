#include<iostream>
#include"evaluation.h"
#include"personne.h"
#include"Employe.h"
#include"Artisan.h"
#include<string>
using namespace std;

/**void evaluation::saisir_evaluation()
{
    cout<<"saisir l'id de l'evaluation : "<<endl;
    cin>>id_evaluation;
    cout<<"saisir la date de l'evaluation "<<endl;
    cin>>date_evaluation;
    cout<<"saisir les points correspendants a cet evaluation : "<<endl;
    cin>>points;
}**/
evaluation::evaluation(double score,Artisan& artisan, personne& participant)
{
    this->score = score;
    this->artisan = artisan;
    this->participant = participant;
    ///this->employe = employe;
}

void evaluation::editerEvaluation()
{
    /*char rep,rep2;
    do
    {

        cout<<"Que voulez-vous modifiez ? P : points , D : Date de l'evaluation : "<<endl;
        cin>>rep;
        switch(rep)
        {
            case 'P' :
              cout<<"saisir le nouveau nombre des points : "<<endl;
              cin>>points;
              break;
            case 'D' :
                cout<<"saisir la nouvelle date de l'evaluation : "<<endl;
                cin>>date_evaluation;
                break;
            default :
               cout<<"Reponse invalide !"<<endl;
               break;

        }
        cout<<"Voulez-vous encore modifiez ? O : oui , N : non : "<<endl;
        cin>>rep2;
    }
    while(rep2!='N');*/

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
/**istream& operator>>(istream &i,evaluation &e)
{
    cout<<"Ajout d'une evaluation" <<endl;
    i>>e.id_evaluation;
    cout<<"Saisir la date de l'evaluation : "<<endl;
    i>>e.date_evaluation;
    cout<<"Saisir les points de cette evaluation : "<<endl;
    i>>e.points;
    return i ;
}**/
evaluation::~evaluation(){}
