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
        int num_joueur; //numero du joueur
        int score; //score du joueur
        lettres_joueur lettre_main; //lettre de la main du joueur
        Joueur(); //constructeur
        Joueur(int n); //constructeur avec n égal au numero du joueur
        ~Joueur();
    };

    Joueur j1,j2; //initialisation de 2 joueurs 
    Dictionnaire dico; 
    Board b;
    void init();
    scrabble();
    ~scrabble();
    void joue_partie();
    void tour_joueur(Joueur j,bool t1);

};

#endif // SCRABBLE_H
