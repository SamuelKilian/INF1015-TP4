#pragma once
#include <iostream>
#include <vector>
#pragma once
#include <string>
#include <ostream>
#include "Affichable.h"

using namespace std;


class Personnage : public Affichable {
public:
	Personnage() = default;
	Personnage(const string& nom, const string& parution) :
		nom_(nom),
		parution_(parution)
	{}
	
	void changerCouleur(ostream& os, int couleur) override;
	void afficher(ostream& os) override;
	
	string getNom() {
		return nom_;
	}

	string getParution() {
		return parution_;
	}

private:
	string nom_;
	string parution_;
};

