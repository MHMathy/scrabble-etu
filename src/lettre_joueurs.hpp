#ifndef LETTRE_JOUEUR_H
#define LETTRE_JOUEUR_H

#include <string>
using namespace std;

struct lettres_joueur {

	int nb_lettres_joueur;
	string str_lettres_joueur;



	void recharger();

	lettres_joueur();
	~lettres_joueur();
	lettres_joueur(int nb_lettres_joueur);

};



#endif // LETTRE_JOUEUR_H
