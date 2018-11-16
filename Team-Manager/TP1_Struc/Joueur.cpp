#include "Joueur.h"

// Constructeur par défaut.
Joueur::Joueur(const string& nom, float salaire) {
	this->nom = nom;
	this->salaire = salaire;
}


// Destructeur.	
Joueur::~Joueur() {
}


// Pour copier un joueur.
const Joueur& Joueur::operator=(const Joueur& unJoueur) {
	nom = unJoueur.nom;
	salaire = unJoueur.salaire;
	return *this;
}


// Retourne le nom.
const string& Joueur::getNom() const {
	return nom;
}


// Retourne le salaire.
float Joueur::getSalaire() const {
	return salaire;
}


// Change le nom.
void Joueur::setNom(const string& nom) {
	this->nom = nom;
}


// Change le salaire
void Joueur::setSalaire(float salaire) {
	this->salaire = salaire;
}