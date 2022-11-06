#pragma once
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include "Personnage.h"
using namespace std;


class Vilain : virtual public Personnage {
public:
	Vilain() = default;
	Vilain(const string& nom, const string& parution, string objectif) :
		Personnage(nom, parution),
		objectif_(objectif)
	{}

	string getObjectif() {
		return objectif_;
	}


	void afficher(ostream& os);
private:
	string objectif_;
};


