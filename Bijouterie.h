#ifndef BIJOUTERIE_H_INCLUDED
#define BIJOUTERIE_H_INCLUDED
#include "Creation.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Bijouterie :public Creation
{
  protected :
    string typeMetal;
    vector<string*> pierresUtilises;
  public :
    Bijouterie() ;
    Bijouterie(int id, string nom, string description,string typeMetal);
    Bijouterie(const Bijouterie &);
    Bijouterie & operator=(const Bijouterie &);
    virtual ~Bijouterie(){
        for (unsigned i = 0; i <pierresUtilises.size(); ++i) {
            delete pierresUtilises[i];
        }
    };

    vector<string*> getPierresUtilises();
    void setPierresUtilises(vector<string*>);

    void ajouterPierresUtilises(string*);
    void saisirBijouterie();
    virtual void afficher();
    void modifier();
    friend std::ostream& operator<<(std::ostream&, const Bijouterie& );
};



#endif // BIJOUTERIE_H_INCLUDED
