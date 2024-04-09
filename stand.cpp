#include"stand.h"
#include<iostream>
#include"string"
using namespace std;
stand::stand()
{
    cout<<"saisir l identifiant du stand : "<<endl;
    cin>>id_stand;
    cout<<"saisir l 'emplacement du stand : "<<endl;
    cin>>emplacement;

}
stand::stand(int id_stand,string emplacement)
{
    this->id_stand=id_stand;
    this->emplacement=emplacement;

}
void stand::setId(int id_stand)
{
  this->id_stand=id_stand;
}
int stand::getId()
{
    return id_stand;
}
void stand::setEmplacement(string emplacement)
{
    this->emplacement=emplacement;
}
string stand::getEmplacement()
{
  return emplacement;
}
void stand::afficherStand()
{
    cout<<"AFFICHAGE DU STAND"<<endl;
    cout<<"l'identifiant de ce stand est : "<<id_stand<<endl;
    cout<<"l'emplacement de ce stand est : "<<emplacement<<endl;
}
void stand::editerStand()
{
    char reponse,rep;
    do
    {
        cout<<"Que voulez-vous modifier pour ce stand ? I : identifiant , E : emplacement"<<endl;
        cin>>reponse;
        switch(reponse)
        {
            case 'I':
              cout<<"Saisir le nouveau identifiant  : "<<endl;
              cin>>id_stand;
               break;
            case 'E':
              cout<<"Saisir le nouveau emplacement : "<<endl;
              cin>>emplacement;
              break;
            default :
               cout<<"Réponse invalide ! "<<endl;
                break;
        }
        cout<<"Voulez-vous encore modifier ? O : OUI , N: NON"<<endl;
        cin>>rep;
    }
    while(rep!='N');
}
