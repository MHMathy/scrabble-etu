#include "lettre_joueurs.hpp"
#include "sac_de_lettres.hpp"

using namespace std;

lettres_joueur::lettres_joueur(){}

lettres_joueur::lettres_joueur(int nb_lettres_joueur){ //un joueur possède 7 lettres
    str_lettres_joueur+=sac_de_lettres::piocher_lettre(nb_lettres_joueur); 
}

lettres_joueur::~lettres_joueur(){}


void lettres_joueur::recharger(){
		sac_de_lettres::piocher_lettre(7-str_lettres_joueur.length()); //pioche un nombre de lettre égal à 7 moins le nbr qu'il a dans la main
}
