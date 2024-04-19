#ifndef PARTICIPANT_H_INCLUDED
#define PARTICIPANT_H_INCLUDED
#include"personne.h"
using namespace std;
class Participant :public personne
{
  public :

    string role;

  public :
    Participant() ;
    Participant(int c,string n,string p ,int t ,string e,string a,int nblg, string);
    Participant(const Participant &);
    string getrole();

    void setrole(string);

    void afficherPersonne();
    void modifier();
    ~Participant();
    void saisir_participant();
    friend ostream& operator<<(ostream&, const Participant&);
    friend istream& operator>>(istream&,Participant&);
    Participant& operator=(const Participant &);
};



#endif // PARTICIPANT_H_INCLUDED
