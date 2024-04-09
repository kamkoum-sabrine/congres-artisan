#include<iostream>
#include"evaluation.h"
#include<string>
using namespace std;
evaluation::evaluation()
{
    cout<<"saisir l'id de l'evaluation : "<<endl;
    cin>>id_evaluation;
    cout<<"saisir la date de l'evaluation "<<endl;
    cin>>date_evaluation;
    cout<<"saisir les points correspendants a cet evaluation : "<<endl;
    cin>>points;
}
evaluation::evaluation(int i,int p,string d)
{
    id_evaluation=i;
    date_evaluation=d;
    points=p;
}
void evaluation::setId(int id)
{
    id_evaluation=id;
}
void evaluation::setDate_evaluation(string date)
{
    date_evaluation=date;
}
void evaluation::setPoints(int point)
{
    points=point;
}
int evaluation::getid()
{
    return id_evaluation;
}
