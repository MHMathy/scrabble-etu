#include <vector>
using namespace std;

struct Cellule_lettre {
public:
	char lettre;
	int nb_lettre;
	int points;
	std::vector<Cellule_lettre> tableau_lettres(lettre, nb_lettre, points);
	
	Cellule_lettre(); //constructeur
	Cellule_lettre(int, int); //constructeur avec paramètres
	~Cellule_lettre(); //destructeur
}