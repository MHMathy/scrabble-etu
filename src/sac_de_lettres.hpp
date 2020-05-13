#pragma once
#include "Cellule_lettre.hpp"
#include <string>
#include <vector>

struct sac_de_lettres{
	static int nb_lettres_total;
	static std::vector<Cellule_lettre> tableau_lettres;
	
	static void init(); //constructeur, initialise la sac de lettres
	static string piocher_lettre(int nb);

	static int points_lettres(char c);
};
