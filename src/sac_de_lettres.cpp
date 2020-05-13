#include "sac_de_lettres.hpp"
#include "lettre_joueurs.hpp"
#include "Cellule_lettre.hpp"
#include <random>
#include <vector>
#include <iostream>
using namespace std;

int sac_de_lettres::nb_lettres_total;
std::vector<Cellule_lettre> sac_de_lettres::tableau_lettres;

void sac_de_lettres::init(){
    std::cout<<"HERE 3";
    nb_lettres_total = 102;
	tableau_lettres.push_back( Cellule_lettre( 'A', 9, 3)); //A
	tableau_lettres.push_back( Cellule_lettre( 'B', 2, 3)); //B
	tableau_lettres.push_back( Cellule_lettre( 'C', 2, 3)); //C
	tableau_lettres.push_back( Cellule_lettre( 'D', 3, 2)); //D
	tableau_lettres.push_back( Cellule_lettre( 'E', 15,1)); //E
	tableau_lettres.push_back( Cellule_lettre( 'F', 2, 4)); //F
	tableau_lettres.push_back( Cellule_lettre( 'G', 2, 2)); //G
	tableau_lettres.push_back( Cellule_lettre( 'H', 2, 4)); //H
	tableau_lettres.push_back( Cellule_lettre( 'I', 8, 1)); //I
	tableau_lettres.push_back( Cellule_lettre( 'J', 1, 8)); //J
	tableau_lettres.push_back( Cellule_lettre( 'K', 1, 10));//K
	tableau_lettres.push_back( Cellule_lettre( 'L', 5, 1)); //L
	tableau_lettres.push_back( Cellule_lettre( 'M', 3, 2)); //M
	tableau_lettres.push_back( Cellule_lettre( 'N', 6, 1)); //N
	tableau_lettres.push_back( Cellule_lettre( 'O', 6, 1)); //O
	tableau_lettres.push_back( Cellule_lettre( 'P', 2, 3)); //P
	tableau_lettres.push_back( Cellule_lettre( 'Q', 3, 8)); //Q
	tableau_lettres.push_back( Cellule_lettre( 'R', 6, 1)); //R
	tableau_lettres.push_back( Cellule_lettre( 'S', 6, 1)); //S
	tableau_lettres.push_back( Cellule_lettre( 'T', 6, 1)); //T
	tableau_lettres.push_back( Cellule_lettre( 'U', 6, 1)); //U
	tableau_lettres.push_back( Cellule_lettre( 'V', 2, 4)); //V
	tableau_lettres.push_back( Cellule_lettre( 'W', 1, 10));//W
	tableau_lettres.push_back( Cellule_lettre( 'X', 1, 10));//X
	tableau_lettres.push_back( Cellule_lettre( 'Y', 1, 10));//Y
	tableau_lettres.push_back( Cellule_lettre( 'Z', 1, 10));//Z
}


string sac_de_lettres::piocher_lettre(int nb){
	//cout<<"La probabilité de piocher une lettre est proportionnelle au nbrd'exemplaires restant dans le sac : "<<nb_lettres<<end;
	string retour;
	srand(time(NULL));
    int n,p,v;
    for (int i = 0; i < nb; i++)
    {
        p=0;
        v=0;

        n = rand()%nb_lettres_total;
        for(int k=0;i<n;i++){
            v+=1;

            if(v==tableau_lettres[p].nb_lettre){
                v=0;
                p+=1;
            }
        }
        retour += tableau_lettres[p].lettre;
        std::cout<<"Nbl "<<tableau_lettres[p].nb_lettre<<std::endl;
        tableau_lettres[p].nb_lettre--;

    }
    return retour;
}

int sac_de_lettres::points_lettres(char i){ //i représente une lettre entre A et Z
    for(auto l : tableau_lettres){
        if(l.lettre==i)return l.points;
    }
	/*
	tableau_lettres[0] = 1; //A
	tableau_lettres[1] = 3; //B
	tableau_lettres[2] = 3; //C
	tableau_lettres[3] = 2; //D
	tableau_lettres[4] = 1; //E
	tableau_lettres[5] = 4; //F
	tableau_lettres[6] = 2; //G
	tableau_lettres[7] = 4; //H
	tableau_lettres[8] = 1; //I
	tableau_lettres[9] = 8; //J
	tableau_lettres[10] = 10; //K
	tableau_lettres[11] = 1; //L
	tableau_lettres[12] = 2; //M
	tableau_lettres[13] = 1; //N
	tableau_lettres[14] = 1; //O
	tableau_lettres[15] = 3; //P
	tableau_lettres[16] = 2; //Q
	tableau_lettres[17] = 1; //R
	tableau_lettres[18] = 1; //S
	tableau_lettres[19] = 1; //T
	tableau_lettres[20] = 1; //U
	tableau_lettres[21] = 4; //V
	tableau_lettres[22] = 10; //W
	tableau_lettres[23] = 10; //X
	tableau_lettres[24] = 10; //Y
	tableau_lettres[25] = 10; //Z
	*/
}
