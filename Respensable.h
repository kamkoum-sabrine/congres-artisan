#ifndef RESPENSABLE_H_INCLUDED
#define RESPENSABLE_H_INCLUDED
#include<vector>
#include<string>
#include<iostream>
#include"personne.h"

using namespace std;
class respensable :public personne
{
  protected :
    string role;
    vector<int> sessions;
  public :
    respensable() ;
    respensable(string role,int c,string n,string p ,int t ,string e,string a,int nbLangues);
    respensable(const respensable &);
    string getrole();
    void getsessions();
    void setrole(string);
    //void saisir_sessions();
    void ajouter_session();
    void editer();
    void supprimer();
    void afficher();


};

#endif // RESPENSABLE_H_INCLUDED
