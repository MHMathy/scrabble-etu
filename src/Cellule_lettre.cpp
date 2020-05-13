#include "Cellule_lettre.hpp"
#include <vector>
using namespace std;

Cellule_lettre::Cellule_lettre() {

}

Cellule_lettre::Cellule_lettre(char c ,int i, int p){
    lettre = c;
    nb_lettre= i;
    points = p;
}

Cellule_lettre::~Cellule_lettre(){}
