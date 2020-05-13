#include "gaddag.hpp"
#include "board.hpp"
Dictionnaire* Gaddag::dico;
Board Gaddag::plateau;
std::string Gaddag::lettre_joueur;

Gaddag::Case_lettre Gaddag::calcul(){
    int var,pos_lettre;
    char sens = 'f';
    std::string lettre_main = lettre_joueur;
    std::string mot_actu = ""; // mot_actu contiendra le mot possible sur le plateau
    std::vector<Case_lettre> case_plateau; // case plateau contient mots possible pour chaque lettre du plateau
    std::vector<int> arbre_pos; // arbre pos va nous permettre de naviguer sur l'arbre

    Noeud* ntemp; // ntemp est égal au noeud sur lequel on se trouve dans le dictionnaire
    for(int i=0;i<235;i++){
        if(plateau.spots[i].letter==0){continue;} // si la case est vide on ne fais rien

        else{
            arbre_pos.clear(); // on réinitialise les variables
            arbre_pos.push_back((int)0);
            Case_lettre case_actu = {i,0,plateau.spots[i].letter}; // case_actu contient les mots possible de la case actuelle
            mot_actu=case_actu.lettre;
            lettre_main = lettre_joueur;


            // on commence dans le dico par la lettre sur laquel on se trouve sur le plateau
            ntemp = dico->Getracine_arbre()->get_arrete_lettre(case_actu.lettre)->fin;

            if(plateau.spots[i-1].letter==0 && plateau.spots[i+1].letter==0) sens = 'h';
            else if(plateau.spots[i-15].letter==0 && plateau.spots[i+15].letter==0) sens = 'v';
            else continue;

            do{
                var = arbre_pos.back(); // var representa la direction qu'on va prendre dans l'arbre
                arbre_pos.pop_back(); // on enlève l'instruction

                if(var<0){ // on retourne on arrière, vers le noeud précédent

                    if(var==-1){
                        if(ntemp->arr_pere->lettre!='+')lettre_main+=ntemp->arr_pere->lettre; // on ajoute la lettre du noeud à la main
                        mot_actu.pop_back(); // on enlève la dernière lettre
                    }

                    ntemp = ntemp->arr_pere->debut; // on change de noeud
                    continue;
                }


                ntemp = ntemp->arr_fils[var]->fin; // on se déplace vers le noeud indiqué par var
                pos_lettre = lettre_main.find(ntemp->arr_pere->lettre); // on cherche si la lettre du noeud est présent dans la main

                if(ntemp->arr_pere->lettre=='+')pos_lettre=0; // on compte comme si il s'agit d'une lettre possible

                if(pos_lettre>=0){ // si la lettre est dans la main
                    mot_actu+= ntemp->arr_pere->lettre; // on ajoute la lettre au mot actuel

                    if(ntemp->arr_pere->lettre!='+')lettre_main.erase(pos_lettre,1); // on enlève la lettre de la main si c'est pas un '+'

                    if(ntemp->terminal==true){
                        // si c'est une lettre terminale on l'ajoute aux mots possibles
                        case_actu.list_possible.push_back({sens,mot_actu,Dictionnaire::val_mot(mot_actu)});
                    }
                }

                if(var+1<ntemp->arr_pere->debut->arr_fils.size()){ // si le noeud père a d'autres fils à explorer
                    arbre_pos.push_back(var+1); // position de la lettre adjacente
                }

                else arbre_pos.push_back(-1); // sinon on retourne en arrière en avec l'ajout dans la main


                if(pos_lettre>=0){ // si la lettre actuelle est dans la main
                    if(!(ntemp->arr_fils.empty()))arbre_pos.push_back(0); // si le noeud a des fils on y accède avec l'instruction 0
                    else arbre_pos.push_back(-1); // sinon on fait retour complet avec -1
                }

                else arbre_pos.push_back(-2); // si ce n'est pas la bonne lettre on fait un retour simple avec -2

            } while(!arbre_pos.empty());
            /*
            for(Possible mottemp : case_actu.list_possible){
                    std::cout<<mottemp.mot<<" "<<mottemp.point<<std::endl;
                }*/
            case_actu.set_max_point();
            std::cout<<"case "<<case_actu.num_case<<std::endl;
            case_actu.tri_mot_possible();
            case_plateau.push_back(case_actu); // on ajoute les infos de la case actuelle

        }
    }
    return meilleur_choix(case_plateau);
}

Board Gaddag::jouer_meilleur(){
    Case_lettre coup = calcul();
    int var;

    int pos = coup.num_case;
    std::cout<<"pos "<<pos<<" mot "<<coup.list_possible[0].mot<<std::endl;

    if(coup.list_possible[0].sens=='h')var = -1;
    else if(coup.list_possible[0].sens=='v')var = -15;


    for(int i=0;i<coup.list_possible[0].mot.length();i++){
        if(coup.list_possible[0].mot[i]=='+'){
            var *=-1;
            pos +=(i+1)*var;

            continue;
        }

        plateau.spots[pos].letter = coup.list_possible[0].mot[i];
        pos += var;
    }

    return plateau;

}

Gaddag::Case_lettre Gaddag::meilleur_choix(std::vector<Case_lettre> c_plateau){
    Case_lettre meilleur = {0,0,'0'};
    for(auto c_l : c_plateau){
        if(c_l.max_point>meilleur.max_point){

            meilleur = c_l;
        }
    }

    return meilleur;
}

void Gaddag::maj_info(Board b, std::string lettre_main){

    plateau = b;
    lettre_joueur = lettre_main;

}

int Gaddag::Case_lettre::set_max_point(){
    for(auto possib : list_possible){
        if(possib.point>max_point)max_point = possib.point;
    }
}

void Gaddag::Case_lettre::tri_mot_possible(){
    std::vector<Possible> temp;
    for(auto possib : list_possible){
        if(possib.point==max_point)temp.push_back(possib);
        std::cout<<" mot "<<possib.mot<<std::endl;
    }

    list_possible = temp;
}
