#ifndef LETTRE_JOUEUR_H
#define LETTRE_JOUEUR_H

#include <string>
using namespace std;

struct lettres_joueur {
	int nb_lettres_joueur; //le nombre de lettre du joueur, il doit être égal à 7 après avoir pioché
	string str_lettres_joueur; //string qui montre les lettres du joueur

	void recharger(); //permet au joueur de piocher pour arriver à 7 lettres dans la main

	lettres_joueur();
	~lettres_joueur();
	lettres_joueur(int nb_lettres_joueur);

};



#endif // LETTRE_JOUEUR_H
