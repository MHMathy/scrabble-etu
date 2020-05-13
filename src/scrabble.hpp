#ifndef SCRABBLE_H
#define SCRABBLE_H
#include "lettre_joueurs.hpp"
#include "board.hpp"
#include "gaddag.hpp"

#include <iostream>
#include <sstream>

class scrabble
{
public:
    struct Joueur{
        int num_joueur;
        int score;
        lettres_joueur lettre_main;
        Joueur();
        Joueur(int n);
        ~Joueur();
    };

    Joueur j1,j2;
    Dictionnaire dico;
    Board b;
    void init();
    scrabble();
    ~scrabble();
    void joue_partie();
    void tour_joueur(Joueur j,bool t1);

};

#endif // SCRABBLE_H
