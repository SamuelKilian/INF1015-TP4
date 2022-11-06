#pragma once
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include "Vilain.h"
#include "Heros.h"

using namespace std; 

class VilainHeros : public Vilain, public Heros {
public:
	VilainHeros() = default;
	VilainHeros(Vilain& vilain, Heros& heros);
	void afficher(ostream& os);


private:

	string nom_;
	string parution_;
	string objectif_;
	string ennemi_;
	string missionSpeciale_;
	vector<string>alliees_;
};
