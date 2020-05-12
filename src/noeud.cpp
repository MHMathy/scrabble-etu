#include "noeud.hpp"


Noeud::Noeud() : terminal(false), arr_pere(nullptr){}

Noeud::Noeud(Arrete* arr_p, bool term): terminal(term),arr_pere(arr_p){
    val = val_lettre(arr_p->lettre);
}

Noeud::~Noeud()
{
    for(int i=0;i<arr_fils.size();i++){
        delete arr_fils[i];
    }
}
/*
bool Noeud::Getterminal() { return terminal; }

Arrete* Noeud::Getarr_pere() { return arr_pere; }

Arrete* Noeud::Getarr_fils_pos(int i) { return arr_fils[i]; }
*/
Arrete* Noeud::get_arrete_lettre(char c){
    Arrete* adr = nullptr;
    for(int i= 0; i<arr_fils.size() ; i++){
        if(arr_fils[i]->lettre==c) adr=arr_fils[i]; // on identifie quel fils à la bonne lettre
    }
    return adr;
}

//void Noeud::Setarr_fils(Arrete* val) { arr_fils.push_back(val); }


int Noeud::val_lettre(char c){
    int val;
    switch(c){
        case '+':
            val = 0;
            break;
        case 'A':
            val = 1;
            break;
        case 'B':
            val = 3;
            break;
        case 'C':
            val = 3;
            break;
        case 'D':
            val = 2;
            break;
        case 'E':
            val = 1;
            break;
        case 'F':
            val = 4;
            break;
        case 'G':
            val = 2;
            break;
        case 'H':
            val = 4;
            break;
        case 'I':
            val = 1;
            break;
        case 'J':
            val = 8;
            break;
        case 'K':
            val = 10;
            break;
        case 'L':
            val = 1;
            break;
        case 'M':
            val = 2;
            break;
        case 'N':
            val = 1;
            break;
        case 'O':
            val = 1;
            break;
        case 'P':
            val = 3;
            break;
        case 'Q':
            val = 2;
            break;
        case 'R':
            val = 1;
            break;
        case 'S':
            val = 1;
            break;
        case 'T':
            val = 1;
            break;
        case 'U':
            val = 1;
            break;
        case 'V':
            val = 4;
            break;
        case 'W':
            val = 10;
            break;
        case 'X':
            val = 10;
            break;
        case 'Y':
            val = 10;
            break;
        case 'Z':
            val = 10;
            break;


    }
    return val;
}
