#include "Equipe.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Equipe::Equipe(const string& nom) {
	nomEquipe = nom;
}


Equipe::~Equipe() {
}


const Equipe& Equipe::operator=(const Equipe& equipe) {
	nomFichier = equipe.nomFichier;
	nomEquipe = equipe.nomEquipe;
	joueurs = equipe.getListeJoueurs();
	return *this;
}


const string& Equipe::getNomEquipe() const {
	return nomEquipe;
}


const ListeJoueur& Equipe::getListeJoueurs() const {
	return joueurs;
}


void Equipe::setNomfichier(const string& nouveauNomFichier) {
	nomFichier = nouveauNomFichier;
}


const string& Equipe::getNomfichier() const {
	return nomFichier;
}

void Equipe::ajouterJoueur(const Joueur& unJoueur) {
	float salaireJoueur = unJoueur.getSalaire();

	if (joueurs.getTaille() == 0) {
		joueurs.insererFin(unJoueur);
	}
	else {
		joueurs.deplacerCurseurDebut();
		while (joueurs.elementCurseurValide()) {
			float salaireCurseur = joueurs.obtenirCurseurElement().getSalaire();
			if (salaireCurseur < salaireJoueur) {
				joueurs.insererAvantCurseur(unJoueur);
				break;
			}
			joueurs.deplacerCurseurSuivant();
		}

		// Si aucun salaire est plus petit que le joueur a ajoute.
		// on l'ajoute a la fin de la liste
		if (!joueurs.elementCurseurValide()) {
			joueurs.insererFin(unJoueur);
		}
	}
}

void Equipe::retirerJoueur(const Joueur& joueurAChercher) {
	string nomJoueurEnlever = joueurAChercher.getNom();
	string nomJoueurPotentiel;
	Joueur joueurPotentiel;

	// Redeplace curseur au debut afin de pouvoir looper
	joueurs.deplacerCurseurDebut();
	while (joueurs.elementCurseurValide()) {
		joueurPotentiel = joueurs.obtenirCurseurElement();
		nomJoueurPotentiel = joueurPotentiel.getNom();

		if (nomJoueurEnlever == nomJoueurPotentiel) {
			joueurs.retirerCurseurElement();
			break;
		}
		joueurs.deplacerCurseurSuivant();
	}
}

void Equipe::sauvegarder() {
	ofstream fichier(nomFichier);
	bool debut = true;
	if (fichier.is_open()) {
		joueurs.deplacerCurseurDebut();
		while (joueurs.elementCurseurValide()) {
			if (debut) {
				fichier << nomEquipe << endl;
				debut = false;
			}
			fichier << left << setw(30) << joueurs.obtenirCurseurElement().getNom() + ";"
					<< setprecision(9) << right << setw(9)
					<< joueurs.obtenirCurseurElement().getSalaire() << endl;
			joueurs.deplacerCurseurSuivant();
		}
	}
	fichier.close();
}