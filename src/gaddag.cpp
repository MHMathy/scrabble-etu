#include "gaddag.hpp"
#include "board.hpp"
Dictionnaire* Gaddag::dico;
Board Gaddag::plateau;
std::string Gaddag::lettre_joueur;

void Gaddag::gaddag_calcul(){
    int var,pos_lettre;
    std::string lettre_main = lettre_joueur;
    std::string mot_actu = "";
    std::vector<Case_lettre> case_plateau;
    std::vector<int> arbre_pos;

    Noeud* ntemp;
    for(int i=0;i<255;i++){
        //std::cout<<i<<std::endl;
        if(plateau.spots[i].letter==0){continue;}

        else{
            arbre_pos.clear();
            arbre_pos.push_back((int)0);
            Case_lettre case_actu = {i,plateau.spots[i].letter};
            mot_actu=case_actu.lettre;
            ntemp = dico->Getracine_arbre()->get_arrete_lettre(case_actu.lettre)->fin;

            std::cout<<std::endl<<"Lettre: "<<case_actu.lettre<<std::endl;
                for(int i=0;i<ntemp->arr_fils.size();i++){
                    std::cout<<ntemp->arr_fils[i]->lettre<<" ";
                }
                std::cout<<")"<<std::endl;


            do{
                std::cout<<"(";

                for (auto const& i: arbre_pos) {
                    std::cout << i << " ";
                }
                std::cout<<")";
                var = arbre_pos.back();
                arbre_pos.pop_back();
                if(var<0){
                    std::cout<<" lettre retour "<<ntemp->arr_pere->lettre<<std::endl;
                    if(var==-1){
                        if(ntemp->arr_pere->lettre!='+')lettre_main+=ntemp->arr_pere->lettre;
                        mot_actu.pop_back();
                    }

                    ntemp = ntemp->arr_pere->debut;
                    continue;
                }
                ntemp = ntemp->arr_fils[var]->fin;
                pos_lettre = lettre_main.find(ntemp->arr_pere->lettre);
                if(ntemp->arr_pere->lettre=='+')pos_lettre=0;
                /*
                std::cout<<std::endl;
                for (auto const& i: arbre_pos) {
                    std::cout << i << " ";
                }*/

                std::cout<<"lettre "<<ntemp->arr_pere->lettre<<" pos "<<pos_lettre;
                //std::string osef;std::cin>>osef;

                if(pos_lettre>=0 || ntemp->arr_pere->lettre=='+'){
                //if(pos_lettre>=0){
                    std::cout<<" step 1";
                    mot_actu+= ntemp->arr_pere->lettre;
                    if(ntemp->arr_pere->lettre!='+')lettre_main.erase(pos_lettre,1);


                    if(ntemp->terminal==true){
                        case_actu.list_possible.push_back({'h',mot_actu,Dictionnaire::val_mot(mot_actu)});
                    }/*
                    if(!(ntemp->arr_fils.empty())){
                        if(var==ntemp.size()-1){
                            arbre_pos.push_back(-1)
                        }
                        arbre_pos.push_back(0);
                    }*/
                }

                std::cout<<" step 2(";
                std::cout<<"actu "<<mot_actu<<" main "<<lettre_main;
                if(var+1<ntemp->arr_pere->debut->arr_fils.size()){
                    arbre_pos.push_back(var+1);
                }
                else arbre_pos.push_back(-1);
                /*
                if(var+1>=ntemp->arr_pere->debut->arr_fils.size() || ntemp->arr_fils.empty()){
                    arbre_pos.push_back(-1);
                }*/


                if(pos_lettre>=0){
                    if(!(ntemp->arr_fils.empty()))arbre_pos.push_back(0);
                    else arbre_pos.push_back(-1);
                }
                else arbre_pos.push_back(-2);


                std::cout<<") step 3( ";
                /*
                for (auto const& i: arbre_pos) {
                    std::cout << i << " ";
                }
                std::cout<<")"<<std::endl;*/
                std::cout<<ntemp->arr_pere->lettre<<"(";
                for(int i=0;i<ntemp->arr_fils.size();i++){
                    std::cout<<ntemp->arr_fils[i]->lettre<<" ";
                }
                std::cout<<")"<<std::endl<<std::endl;


            } while(!arbre_pos.empty());
            std::cout<<" step 4"<<std::endl;
            for(int i=0;i<case_actu.list_possible.size();i++){
                    std::cout<<case_actu.list_possible[i].mot<<std::endl;
                }
            case_plateau.push_back(case_actu);
            std::string osef;std::cin>>osef;
        }
    }

}

void Gaddag::maj_info(Board b, std::string lettre_main){

    plateau = b;
    lettre_joueur = lettre_main;

}
