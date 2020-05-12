#ifndef GADDAG_H
#define GADDAG_H

#include "dictionnaire.hpp"
#include "board.hpp"

/*
    cette classe se charge de parcourir l'arbre de dictionnaire pour identifier le meilleur
    comme c'est une classe qui ne fait que du calcul et ne stock pas d'information d'un tour a l'autre, on la met en static
*/
class Gaddag
{
    private:
        // struct d'un mot possible depuis une case
        struct Possible{
            char sens;
            std::string mot;
            int point;
        };

        // struct regroupant les mots possible par case du plateau
        struct Case_lettre{
            int num;
            char lettre;
            std::vector<Possible> list_possible;
        };

        // variable

        static Board plateau; // contient le plateau de jeu
        static std::string lettre_joueur; // les lettres du joueur qui utilise gaddag



        static Case_lettre mot_possible_case();

    public:
        static Dictionnaire* dico;
        // met à jour les informations de la class
        static void maj_info(Board b, std::string lettre_main);

        // parcours le plateau et le dictionnaire pour obtenir le meilleur mot
        static void gaddag_calcul();







};

#endif // GADDAG_H
