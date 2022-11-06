#pragma once
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include "Personnage.h"
using namespace std; 


class Heros : virtual public Personnage {
public:
	Heros() = default;
	Heros(const string& nom, const string& parution, string ennemi, vector<string>& alliees) :
		Personnage(nom, parution),
		ennemi_(ennemi),
		alliees_(alliees)
		{}

	string getEnnemi() {
		return ennemi_;
	}

	vector<string>getAlliees() {
		return alliees_;
	}

	void afficher(ostream& os);
private:
	string ennemi_;
	vector<string>alliees_;
};