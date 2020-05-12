#ifndef NOEUD_H
#define NOEUD_H

#include <vector>
#include "arrete.hpp"

/* noeud de l'arbre qui assigne une valeur à la lettre de l'arrete précédente */
class Noeud{

    public:
        // valeur de lettre de l'arrete précedente
        int val;
        // booleen indiquant si c'est la fin d'un mot
        bool terminal;
        // adresse de l'arrete avant le noeud
        Arrete* arr_pere;
        // adresses des arretes fils reliés au noeud
        std::vector<Arrete*> arr_fils;

        Noeud();
        Noeud(Arrete* arr_p, bool term);
        ~Noeud();
        /*
        // retourne le booleen terminal
        bool Getterminal();

        // retourne l'adresse de l'arrete père
        Arrete* Getarr_pere();

        // retourne la liste d'arrete filss
        std::vector Getarr_fils_list();

        // retourne l'adresse de l'arrete à la position i
        Arrete* Getarr_fils_pos(int i);

        // ajoute val à la liste des fils
        void Setarr_fils(Arrete* val);

        */

        // retourne l'adresse de l'arrete ayant pour lettre c
        Arrete* get_arrete_lettre(char c);



        // retourne la valeur d'une lettre
        static int val_lettre(char c);



};

#endif // NOEUD_H
