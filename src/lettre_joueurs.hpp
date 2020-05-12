#include <string>
using namespace std;

struct lettres_joueur {
	int nb_lettres_joueur;
	string str_lettres_joueur(7);

	lettres_joueur(int nb_lettres_joueur);
	~lettres_joueur();

	void recharger();

};
