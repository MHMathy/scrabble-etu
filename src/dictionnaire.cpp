#include "dictionnaire.hpp"
#include "arrete.hpp"
#include <iostream>
#include <fstream>

Dictionnaire::Dictionnaire(){
    racine_arbre = new Noeud;
}

Dictionnaire::~Dictionnaire()
{
    delete racine_arbre;
}


Noeud* Dictionnaire::Getracine_arbre() { return racine_arbre; }

std::string Dictionnaire::Getlist_mots(int i) { return list_mots[i]; }


void Dictionnaire::inserer_mot(std::string str){

    //std::cout<<std::endl;
    //std::cout<<" on ajoute: "<<str<<std::endl;
    Noeud* temp = racine_arbre;
    list_mots.push_back(str);
    str.insert(str.begin(),'+');
    for(int i=0; i<str.length()-1;i++){ // on fait les differente compositions avec le char '+'
        temp = racine_arbre;
        str.insert(str.begin(),str[i+1]);
        str.erase(i+2,1);
        //std::cout<<str<<std::endl;
        for(int i=0; i<str.length();i++){ // on insère chaque version dans l'arbre
            Arrete* adr = temp->get_arrete_lettre(str[i]); // on cherche si il existe déjà une arrete avec la lettre souhaité
            if(adr!=nullptr){ // si il existe
                temp = adr->fin; // on passe au noeud à la fin de l'arrete
                //std::cout<<str[i]<<"t ";
            }
            else{
                Arrete* new_arr = new Arrete(temp,str[i],i==(str.length()-1));// sinon on le crée
                temp->arr_fils.push_back(new_arr); // et on l'ajoute aux arretes fils du noeud actuel
                temp = new_arr->fin; // on change le noeud actuel avec le noeud en bout de la nouvelle arrete
                //std::cout<<str[i]<<"f ";
            }
        }
    }
}

void Dictionnaire::inserer_mot_check(std::string str){
    bool exist = false;
    for(int i=0;i<list_mots.size();i++){
        if(list_mots[i]==str){ // vérifie si le mot existe déjà dans le dictionnaire
            exist = true;
            return;
        }
    }

    inserer_mot(str);
}

//initialise le tableau et l'arbre à partir du fichier
void Dictionnaire::init_dictionnaire()
{
    std::cout<<"Chargement des mots dans le dictionnaire et création de l'arbre . . ."<<std::endl;
    std::ifstream fichier ("data/dico.txt");
    std::string str;

    while (std::getline(fichier, str)) {
        //on ajoute le mot au dictionnaire et à l'arbre
        inserer_mot(str);
    }
    std::cout<<"Chargement fini!"<<std::endl;
}

int Dictionnaire::val_mot(std::string m){
    int val=0;
    for(int i=0;i<m.length();i++){
        val+= Noeud::val_lettre(m[i]);
    }
    return val;
}

/*
int main(){
    Dictionnaire dico = Dictionnaire();
    dico.set_list_mots();
    std::cout<<"valeur: "<<Dictionnaire::val_mot("TRU+C")<<std::endl;
    return 0;
}
*/
