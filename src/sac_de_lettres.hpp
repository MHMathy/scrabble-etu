#pragma once
#include "Cellule_lettre.hpp"
#include <string>
#include <vector>

struct sac_de_lettres{
	 static int nb_lettres_total;
	 static std::vector<Cellule_lettre> tableau_lettres;
	/*char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
					'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	std::vector<alphabet> tableau_lettres(lettre); //création d'un tableau de caractère de simp taille 26 lettres de l'alphabet
	*/
	//const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//unsigned char tableau_lettres(26);

	static void init(); //constructeur, initialise la sac de lettres


	static string piocher_lettre(int nb);

	static int points_lettres(char c);
};
