#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include "Personnage.h"

using namespace std;

void Personnage::changerCouleur(ostream& os, int couleur)
{
	if (couleur == 0)
		os << "\n\033[91m";
	else if (couleur == 1)
		os << "\n\033[96m";
	else if (couleur == 2)
		os << "\n\033[93m";
	else if (couleur == 3)
		os << "\n\033[97m";
}

void Personnage::afficher(ostream& os)
{
	os << " Nom : " << nom_ << endl;
	os << " Parution : " << parution_ << endl;
}
