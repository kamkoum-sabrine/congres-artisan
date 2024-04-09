#include"Respensable.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
respensable::respensable()
{

}
respensable::respensable(string role,int c,string n,string p ,int t ,string e,string a):personne(c,n,p,t,e,a)
{
    int nbsessions;
    this->role=role;
    cout<<"saisir le nombre de sessions : "<<endl;
    cin>>nbsessions;
    for(int i=0;i<nbsessions;i++)
    {
        int session;
        cout<<"saisir la session numero "<<i+1<<endl;
        cin>>session;
        sessions.push_back(session);
    }
}
void respensable::afficherPersonne()
{
    personne::afficherPersonne();
    cout<<"le role est : "<<role<<endl;
    cout<<"Affichage des sessions : "<<endl;
    for(int i =0;i<sessions.size();i++)
    {
        cout<<"Session numero "<<i+1<<endl;
        cout<<sessions[i]<<endl;
    }
}
void respensable::editer()
{
    char rep,reponse;
    do
    {
        cout<<"Que voulez-vous modifiez ? T :numéro de téléphone , A : adresse de résidence , M : adresse mail  , R : Role"<<endl;
        cin>>rep;
        switch(rep)
        {
            case 'T':
              cout<<"saisir le nouveau numéro de telephone : "<<endl;
              cin>>tel;
            break;
            case 'A':
             cout<<"saisir la nouvelle adresse de résidence : "<<endl;
             cin>>adresse;
             break;
            case 'M':
              cout<<"saisir la nouvelle adresse mail : "<<endl;
              cin>>email;
            break;
            case 'R' :
              cout<<"saisir le nouveau role : "<<endl;
              cin>>role;
              break;
            default :
              cout<<"réponse invalide !"<<endl;
              break;


        }
        cout<<"voulez-vous modifiez encore ? , O : Oui , N : Non "<<endl;
        cin>>reponse;

    }
    while(reponse!='N');

}
respensable::respensable(const respensable &r):personne(r)
{
    role=r.role;
    for(int i=0;i<sessions.size();i++)
    {
        int session;
        session=sessions[i];
        sessions.push_back(session);
    }

}
string respensable::getrole()
{
    return role;
}
void respensable::ajouter_session()
{
    int nb_sessions;
    cout<<"combien de sessions voulez-vous ajoutez ? "<<endl;
    cin>>nb_sessions;
    for(int i=0;i<nb_sessions;i++)
    {
        int nouvelle_session;
        cout<<"saisir une session "<<endl;
        cin>>nouvelle_session;
        sessions.push_back(nouvelle_session);
    }
}
void respensable::getsessions()
{
    cout<<"Affichage des sessions correspendantes a ce respensable : "<<endl;
    for(int i=0;i<sessions.size();i++)
    {
      cout<<"Session "<<i+1<<" : "<<sessions[i]<<endl;

    }
}
void respensable::setrole(string role)
{
    this->role=role;
}


