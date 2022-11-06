#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include "Personnage.h"
#include "Vilain.h"

using namespace std;

void Vilain::afficher(ostream& os)
{
	Personnage::changerCouleur(os, 1);
	Personnage::afficher(os);
	os << " Objectif : " << objectif_ << endl;

	Personnage::changerCouleur(os, 3);
}
