using namespace std;

struct lettres_joueur {
	int nb_lettres_joueur;
	unsigned char lettres_joueur(7);

	lettres_joueur(int nb_lettres_joueur);
	~lettres_joueur();

	void recharger();

};
