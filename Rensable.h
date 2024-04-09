#ifndef RENSABLE_H_INCLUDED
#define RENSABLE_H_INCLUDED
#include<iostream>
#include"personne.h"
#include<string>
#include<vector>

using namespace std;
class respensable :public personne
{
  protected :
    string role;
    vector<int> sessions;
  public :
    respensable() ;
    respensable(string role,int c,string n,string p ,int t ,string e,string a);
    respensable(const respensable &);
    string getrole();
    void getsessions();
    void setrole(string);
    void saisir_sessions();
    void ajouter_session();
    void editer();
    void supprimer();


};

#endif // RENSABLE_H_INCLUDED
