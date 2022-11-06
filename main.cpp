#pragma once
#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include "bibliotheque_cours.hpp"
#include "iostream"
#include "Heros.h"
#include "Vilain.h"
#include "VilainHeros.h"

using namespace std;

ifstream ouvrirFichierBinaire(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	return fichier;
}

void testsPourCouvertureLectureBinaire()
{
	istringstream iss("\xA0\x12\xA1\x21\x43\xA2\x98\xBA\xDC\xFE");
	assert(lireUintTailleVariable(iss) == 0x12);
	assert(lireUintTailleVariable(iss) == 0x4321);
	assert(lireUintTailleVariable(iss) == 0xFEDCBA98);
}

int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	testsPourCouvertureLectureBinaire();

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros = ouvrirFichierBinaire("heros.bin");
	ifstream fichierVilains = ouvrirFichierBinaire("vilains.bin");

	//TODO: Votre code pour le main commence ici (mais vous pouvez aussi ajouter/modifier du code avant si nécessaire)
	
	/*cout << lireUintTailleVariable(fichierHeros) << endl;
	for (int i = 0; i < 9; i++) {
		cout <<" heros : " << i << "  " << lireString(fichierHeros) << endl;
		
		cout << lireString(fichierHeros) << endl;
		cout << lireString(fichierHeros) << endl;
		
		int nb_alliees = lireUintTailleVariable(fichierHeros);
		for (int j = 0; j < nb_alliees; j++)
			cout << lireString(fichierHeros) << endl;
		cout << trait << endl;
		}*/
	
	vector<shared_ptr<Heros>> heros;
	vector<shared_ptr<Vilain>> vilains;
	vector<shared_ptr<Personnage>> personnage; 


	int h = lireUintTailleVariable(fichierHeros);
	int v = lireUintTailleVariable(fichierVilains);

	for (int a = 0; a < h ; a++) {
		string nom = lireString(fichierHeros);
		string parution = lireString(fichierHeros);
		string ennemi = lireString(fichierHeros);
		vector<string> alliees;

		int j = lireUintTailleVariable(fichierHeros);
		for (int i = 0; i < j; i++) {
			alliees.push_back(lireString(fichierHeros));
		}
		
		Heros heros1(nom, parution, ennemi, alliees);
		heros.push_back(make_shared<Heros>(heros1));
	}

	for (auto&& hero : heros) {
		hero->afficher(cout);
		cout << trait << endl;
	}

	for (int b = 0; b < v; b++) {
		string nom = lireString(fichierVilains);
		string parution = lireString(fichierVilains);
		string objectif = lireString(fichierVilains);

		Vilain vilain1(nom, parution, objectif);
		vilains.push_back(make_shared<Vilain>(vilain1)); 

	}

	for (auto&& vilain : vilains) {
		vilain->afficher(cout);
		cout << trait << endl;
	}
	

	for (auto&& elment : heros) {
		personnage.push_back(elment);

	}

	for (auto&& element : vilains) {
		personnage.push_back(element);

	}

	for (auto&& personnages : personnage) {
		personnages->afficher(cout);
		cout << trait << endl;
	}

	VilainHeros vilainhero(*vilains[0], *heros[0]);
	vilainhero.afficher(cout);

	personnage.push_back(make_shared<VilainHeros>(vilainhero));


	for (auto&& personnages : personnage) {
		personnages->afficher(cout);
		cout << trait << endl;
	}
	
	
	
	

	

}
