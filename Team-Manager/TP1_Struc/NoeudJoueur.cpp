#include "NoeudJoueur.h"

// Constructeur par défaut.
NoeudJoueur::NoeudJoueur() {
}


// Constructeur par copie.
NoeudJoueur::NoeudJoueur(const NoeudJoueur& ne) {
	*this = ne;
}


// Destructeur
NoeudJoueur::~NoeudJoueur() {
}


// Copie d'un noeudJoueur.
const NoeudJoueur& NoeudJoueur::operator=(const NoeudJoueur& noeud) {

	suivant = noeud.getSuivant();
	leJoueur = noeud.getJoueur();

	return *this;
}


// Retourne le joueur const.
const Joueur& NoeudJoueur::getJoueur() const {
	return leJoueur;
}

// Retourne le joueur.
Joueur& NoeudJoueur::getJoueur() {
	return leJoueur;
}

// Retourne le noeud suivant.
NoeudJoueur* NoeudJoueur::getSuivant() const {
	return suivant;
}


// Ajoute ou change un joueur.
void NoeudJoueur::setJoueur(const Joueur& joueur) {
	leJoueur = joueur;
}


// Ajoute ou change le noeud suivant.  
void NoeudJoueur::setSuivant(NoeudJoueur* n) {
	suivant = n;
}
