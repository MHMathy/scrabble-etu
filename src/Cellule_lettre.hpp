#ifndef CELLULE_LETTRE_H
#define CELLULE_LETTRE_H

#include <vector>
using namespace std;

struct Cellule_lettre {
	char lettre;
	int nb_lettre;
	int points;
	
	Cellule_lettre(); //constructeur
	Cellule_lettre(char, int, int); //constructeur avec paramètres
	~Cellule_lettre(); //destructeur
};

#endif // CELLULE_LETTRE_H
