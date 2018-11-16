#include "ListeEquipe.h"

ListeEquipe::ListeEquipe() {
	taille = 0;
	maximum = 2;
	lesEquipes = new Equipe[maximum];
}


ListeEquipe::~ListeEquipe() {
	delete[] lesEquipes;
}


const ListeEquipe& ListeEquipe::operator=(const ListeEquipe& le) {
	maximum = le.maximum;
	taille = le.taille;
	lesEquipes = le.lesEquipes;

	return *this;
}


void ListeEquipe::insererFin(const Equipe& equipe) {
	if (taille == maximum) {
		doublerMaximum();
	}
	lesEquipes[taille] = equipe;
	taille++;
}


const Equipe& ListeEquipe::obtenirEquipe(int indice) const {
	return lesEquipes[indice];
}


Equipe& ListeEquipe::obtenirEquipe(int indice) {
	return lesEquipes[indice];
}


int ListeEquipe::getTaille() const {
	return taille;
}


void ListeEquipe::doublerMaximum() {
	maximum = maximum * 2;
	Equipe *tmp = new Equipe[maximum];

	for (int i = 0; i < taille; i++) {
		tmp[i] = lesEquipes[i];
	}

	delete[] lesEquipes;
	lesEquipes = tmp;
}


