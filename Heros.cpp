#pragma once
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include "Heros.h"

using namespace std;

void Heros::afficher(ostream& os)
{
	Personnage::changerCouleur(os, 0);
	Personnage::afficher(os);
	os << " Ennemi : " << ennemi_ << endl;
	os << " Alliees : " << endl;
	for (auto&& alliees : alliees_)
		os << " " << alliees << endl;

	Personnage::changerCouleur(os, 3);
}
