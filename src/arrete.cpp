#include "arrete.hpp"
#include "noeud.hpp"

Arrete::Arrete(Noeud* depart, char letr,bool term) : debut(depart),lettre(letr)
{
    fin = new Noeud(this,term);
}

Arrete::~Arrete()
{
    delete fin;
}
/*
Noeud* Arrete::Getdebut(){ return debut;}
Noeud* Arrete::Getfin(){return fin;}

char Arrete::Getlettre() { return lettre; }
*/
