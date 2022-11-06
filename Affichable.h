#pragma once
#include <ostream>
#include <gsl/span>
#include <gsl/pointers>
#include <cppitertools/range.hpp>

using namespace std;


class Affichable {
public:
	//virtual ~Affichable() = default;
	virtual void afficher(ostream& os) = 0;
	virtual void changerCouleur(ostream& os, int couleur) = 0;
};