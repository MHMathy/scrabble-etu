#pragma once
#include <vector>

struct sac_de_lettres{
	int nb_lettres;
	std::vector<Cellule_lettres> sac_lettre;
	
	sac_de_lettres(int nb_lettres); //constructeur, initialise la sac de lettres 
	~sac_de_lettres(); //destructeur, détruit le sac de lettres

	piocher_lettres();
};
