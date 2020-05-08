#pragma once
#include <vector>

/*
struct sac_de_lettres{
    vector<char> sac_lettre;
}*/

struct sac_de_lettres{
	int nb_lettres;
	/*char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
					'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	std::vector<alphabet> tableau_lettres(lettre); //création d'un tableau de caractère de taille 26 lettres de l'alphabet
	*/
	//const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//unsigned char tableau_lettres(26);

	sac_de_lettres(int nb_lettres); //constructeur, initialise la sac de lettres 
	~sac_de_lettres(); //destructeur, détruit le sac de lettres
};
