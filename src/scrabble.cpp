#include "scrabble.hpp"
#include "sac_de_lettres.hpp"

scrabble::scrabble()
{std::cout<<"HERE 5";}
void scrabble::init(){
    std::cout<<"HERE 1";
    Dictionnaire dico;
    dico.init_dictionnaire();
    std::cout<<"HERE 2";
    sac_de_lettres::init();
    Board b ;

    Joueur j1(1);
    Joueur j2(2);
    Gaddag::dico = &dico;

    std::stringstream ss ;
    ss << "..............." << std::endl ;
    ss << "..............." << std::endl ;
    ss << "..............." << std::endl ;
    ss << "..............." << std::endl ;
    ss << "..............." << std::endl ;
    ss << "..............." << std::endl ;
    ss << "..............." << std::endl ;
    ss << "....PROJET....." << std::endl ;
    ss << ".......O......." << std::endl ;
    ss << ".......U......." << std::endl ;
    ss << ".......E......." << std::endl ;
    ss << ".......U......." << std::endl ;
    ss << ".....SCRABBLE.." << std::endl ;
    ss << "..............." << std::endl ;
    ss << "..............." << std::endl ;

    b.load(ss) ;

    std::cout << b << std::endl ;
    b = Board();
}


scrabble::~scrabble()
{
    //dtor
}

scrabble::Joueur::Joueur(){
    num_joueur = 0;
    score =0;
    lettres_joueur lettres_main();
}

scrabble::Joueur::Joueur(int n){
    num_joueur = n;
}

scrabble::Joueur::~Joueur(){
}

void scrabble::joue_partie(){
    std::cout<<" Partie Commence"<<std::endl;
    int numj=1;
    bool t1 = true;
    while(sac_de_lettres::nb_lettres_total>0){

        t1 = false;
        if(numj==1){
            tour_joueur(j1,t1);
            std::cout << b << std::endl ;
            numj=2;
            }
        else {
            tour_joueur(j2,t1);
            std::cout << b << std::endl ;
            numj=1;
            }

    }
    std::cout<<" Partie Terminé"<<std::endl;
}
void scrabble::tour_joueur(Joueur j,bool t1){
    j.lettre_main.recharger();
    std::cout << "LETER" <<j.lettre_main.str_lettres_joueur.back()<< std::endl ;
    if(t1==true){
        b.spots[114].letter = j.lettre_main.str_lettres_joueur.back();
        j.lettre_main.str_lettres_joueur.pop_back();
    }
    //std::cout << b << std::endl ;
    Gaddag::maj_info(b,j.lettre_main.str_lettres_joueur);
    b = Gaddag::jouer_meilleur();
    std::cout << b << std::endl ;
}

