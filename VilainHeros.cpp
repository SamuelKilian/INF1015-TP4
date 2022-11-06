#pragma once
#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include "VilainHeros.h"

using namespace std;

VilainHeros::VilainHeros(Vilain& vilain, Heros& heros) :

		nom_(vilain.getNom() + "-" + heros.getNom()),
		parution_(vilain.getParution() + "-" + heros.getParution()),
		objectif_(vilain.getObjectif()),
		ennemi_(heros.getEnnemi()),
		alliees_(heros.getAlliees()),
		missionSpeciale_(vilain.getObjectif() + " dans le monde de " + heros.getParution())
		{}




void VilainHeros::afficher(ostream& os)
{
	Personnage::changerCouleur(os, 2);
	os << " Nom : " << nom_;
	os << " Parution : " << parution_;	
	os << " Objectif : " << objectif_ << endl;
	os << " Ennemi : " << ennemi_ << endl;
	os << " Alliees : " << endl;
	for (auto&& alliees : alliees_)
		os << " " << alliees << endl;
	os << " Mission spéciale : " << missionSpeciale_ << endl;

	Personnage::changerCouleur(os, 3);
}
