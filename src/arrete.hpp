#ifndef ARRETE_H
#define ARRETE_H

class Noeud; // permet d'éviter les conflits lors de la compilation

/* classe associant 2 noeud dans l'arbre du dictionnaire et comportant un lettre sur l'arrete */
class Arrete
{
    public:
        // noeud de début
        Noeud* debut;
        // noeud de fin
        Noeud* fin;
        // lettre associé à l'arrete
        char lettre;

        // il faut un noeud de départ pour créer une nouvelle arrete, la lettre qu'on associe et si oui ou non un noeud terminal est au bout de l'arrete
        Arrete(Noeud* depart, char letr,bool term);
        ~Arrete();
        /*
        // accès aux données membres
        Noeud* Getdebut();
        Noeud* Getfin();
        char Getlettre();
        */

};

#endif // ARRETE_H
