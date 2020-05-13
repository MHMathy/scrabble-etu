#include "board.hpp"
#include "gaddag.hpp"

#include <iostream>
#include <sstream>
/*
int main() {
  Board b ;

  //std::cout << b << std::endl ;

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

  //std::cout << b << std::endl ;

  return 0 ;
}
*/

int main() {
    //std::string plat = "BLATTE";
    std::string main = "BAEAU";
    Dictionnaire dico;
    dico.init_dictionnaire();

    Board b ;

    //std::cout << b << std::endl ;

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
    std::cout <<"lettre:"<< b.spots[128] << std::endl ;
    Gaddag::dico = &dico;
    Gaddag::maj_info(b,main);
    b = Gaddag::jouer_meilleur();
    std::cout << b << std::endl ;
    //delete &dico;
    return 0;
  }
