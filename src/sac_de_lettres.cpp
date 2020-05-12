#include "sac_de_lettres.hpp"
#include "lettres_joueur.hpp"
#include "Cellule_lettre.hpp"
#include <random>
#include <vector>
using namespace std;

sac_de_lettres::sac_de_lettres(int nb_lettres){
	tableau_lettres.resize(26);
	tableau_lettres[0] = Cellule_lettre('A', 9, 3); //A
	tableau_lettres[1] = Cellule_lettre('B', 2, 3); //B
	tableau_lettres[2] = Cellule_lettre('C',2, 3); //C
	tableau_lettres[3] = Cellule_lettre('D',3, 2); //D
	tableau_lettres[4] = Cellule_lettre('E', 15, 1); //E
	tableau_lettres[5] = Cellule_lettre('F', 2, 4); //F
	tableau_lettres[6] = Cellule_lettre('G', 2, 2); //G
	tableau_lettres[7] = Cellule_lettre('H', 2, 4); //H
	tableau_lettres[8] = Cellule_lettre('I', 8, 1); //I
	tableau_lettres[9] = Cellule_lettre('J', 1, 8); //J
	tableau_lettres[10] = Cellule_lettre('K', 1, 10); //K
	tableau_lettres[11] = Cellule_lettre('L', 5, 1); //L
	tableau_lettres[12] = Cellule_lettre('M', 3, 2); //M
	tableau_lettres[13] = Cellule_lettre('N', 6, 1); //N
	tableau_lettres[14] = Cellule_lettre('O', 6, 1); //O
	tableau_lettres[15] = Cellule_lettre('P', 2, 3); //P
	tableau_lettres[16] = Cellule_lettre('Q', 3, 8); //Q
	tableau_lettres[17] = Cellule_lettre('R', 6, 1); //R
	tableau_lettres[18] = Cellule_lettre('S', 6, 1); //S
	tableau_lettres[19] = Cellule_lettre('T', 6, 1); //T
	tableau_lettres[20] = Cellule_lettre('U', 6, 1); //U
	tableau_lettres[21] = Cellule_lettre('V', 2, 4); //V
	tableau_lettres[22] = Cellule_lettre('W', 1, 10); //W
	tableau_lettres[23] = Cellule_lettre('X', 1, 10); //X
	tableau_lettres[24] = Cellule_lettre('Y', 1, 10); //Y
	tableau_lettres[25] = Cellule_lettre('Z', 1, 10); //Z
}


sac_de_lettres::~sac_de_lettres(){
	delete tableau_lettres;
}


int sac_de_lettres::piocher_lettre(){
	int nb_lettres_restantes = nb_lettres;
	cout << "La probabilité de piocher une lettre est proportionnelle au nbr 
			d'exemplaires restant dans le sac : " << nb_lettres_restantes << end;
	srand(time(NULL));

	while (nb_lettres_joueur < 7) {
		for (int i = 0; i < 26; i++)
		{
			nb_max = 25;
			nb_min = 0;
			n = rand()%(nb_max-nb_min+1)+nb_min;
			char tirage[n];

			tirage[n] = tableau_lettres[i] - 1;
			nb_lettres_restantes = nb_lettres_restantes - 1;
		}
	}

}

void sac_de_lettres::points_lettres(i){ //i représente une lettre entre A et Z
	return tableau_lettres[i];
}