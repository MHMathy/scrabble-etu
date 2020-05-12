#include "lettre_joueur.hpp"
#include "sac_de_lettres.hpp"
using namespace std;

lettres_joueur::lettres_joueur(int nb_lettres_joueur=7){
	for(int i=0;i<nb_lettres_joueur;i++) //un joueur possède 7 lettres
	{
		lettres_joueur.piocher_lettre();
	}
	cout << lettres_joueur << endl;
}

lettres_joueur::~lettres_joueur(){}

char lettre_joueur::piocher_lettre(){

}

void lettres_joueur::recharger(){
	if (nb_lettres_joueur < 7)
		piocher_lettre();
	cout << lettres_joueur << endl;
}