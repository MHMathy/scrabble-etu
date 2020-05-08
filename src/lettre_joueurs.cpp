#include "lettre_joueur.hpp"
#include "sac_de_lettres.hpp"
using namespace std;

lettres_joueur::lettres_joueur(int nb_lettres_joueur){
	while (nb_lettres_joueur < 8) //un joueur possède 7 lettres
	{
		lettres_joueur.piocher_lettre();
	}	
	cout << lettres_joueur << endl;
}

lettres_joueur::~lettres_joueur(){
	if ((nb_lettres_joueur == 0) && (nb_lettres == 0))
	{
		cout << "Partie terminée" << endl;
	}	
	delete;
}


void lettres_joueur::recharger(){
	if (nb_lettres_joueur < 7)
		piocher_lettre();
	cout << lettres_joueur << endl;
}
