#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include "noeud.hpp"
#include <string>

/* classe dans laquelle se trouve les mots et l'arbre de lettre correspondant */
class Dictionnaire
{   public:
    //private:
        // origine de l'arbre de lettre
        Noeud* racine_arbre;
        // liste de mots du dictionnaire
        std::vector<std::string> list_mots;


    //public:
        Dictionnaire();
        ~Dictionnaire();

        // retourne la racine
        Noeud* Getracine_arbre();

        // retourne le mot à la position i
        std::string Getlist_mots(int i);

        //initialise le tableau et l'arbre à partir du fichier
        void init_dictionnaire();

        // insère le mot directement dans l'arbre et le dictionnaire
        void inserer_mot(std::string str);

        // vérifie avant l'insertion
        void inserer_mot_check(std::string str);

        // retourne la valeur d'un mot
        static int val_mot(std::string m);



};

#endif // DICTIONNAIRE_H
