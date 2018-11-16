#include "ListeJoueur.h"

ListeJoueur::ListeJoueur() {
	tete = nullptr;
	fin = nullptr;
	// curseur = nullptr;
	taille = 0;
}


ListeJoueur::ListeJoueur(const ListeJoueur& uneListeJoueur) {
	*this = uneListeJoueur;
}


ListeJoueur::~ListeJoueur() {
	viderListe();
}


const ListeJoueur& ListeJoueur::operator=(const ListeJoueur& uneListeJoueur) {
	NoeudJoueur *tmp = uneListeJoueur.tete;
	while (tmp != nullptr) {
		insererFin(tmp->getJoueur());
		tmp = tmp->getSuivant();
	}

	delete tmp;
	return *this;
}


void ListeJoueur::deplacerCurseurDebut() const {
	curseur = tete;
}


void ListeJoueur::deplacerCurseurSuivant() const {
	curseur = curseur->getSuivant();
}


void ListeJoueur::retirerCurseurElement() {
	NoeudJoueur *tmp = curseur;

	// taille == 0
	if (tete == fin) {
		viderListe();
	}
	else if (curseur == tete) {
		tete = tete->getSuivant();
		curseur = curseur->getSuivant();
	}
	else if (curseur == fin) {
		string nomJoueurEnlever = tmp->getJoueur().getNom();
		string nomJoueurPotentiel;

		deplacerCurseurDebut();
		while (true) {
			nomJoueurPotentiel = curseur->getSuivant()->getJoueur().getNom();
			if (nomJoueurPotentiel == nomJoueurEnlever) {
				break;
			}
			curseur = curseur->getSuivant();
		}

		// curseur est devenu le joueur avant le noeud fin
		fin = curseur;
		curseur->setSuivant(nullptr);
	}
	else {
		string nomJoueurEnlever = tmp->getJoueur().getNom();
		string nomJoueurPotentiel;

		deplacerCurseurDebut();
		while (true) {
			
			nomJoueurPotentiel = curseur->getSuivant()->getJoueur().getNom();
			if (nomJoueurPotentiel == nomJoueurEnlever) {
				break;
			}
			curseur = curseur->getSuivant();
		}
		// curseur maintenant pointe le noeud avant tmp
		curseur->setSuivant(tmp->getSuivant());
	}
	
	delete tmp;
	taille--;
}


bool ListeJoueur::elementCurseurValide() const {
	if (curseur == nullptr) {
		return false;
	}

	return true;
}


void ListeJoueur::insererAvantCurseur(const Joueur& unJoueur) {
	NoeudJoueur *nouveau = new NoeudJoueur();
	if (curseur == tete) {
		nouveau->setJoueur(unJoueur);

		nouveau->setSuivant(tete);
		tete = nouveau;

		curseur = curseur->getSuivant();
	} else {
		string nomJoueurCurseur = curseur->getJoueur().getNom();

		deplacerCurseurDebut();
		// Recherche du joueur qui se trouvent just avant le tmp
		while (true) {
			string nomJoueurProchain = curseur->getSuivant()->getJoueur().getNom();

			if (nomJoueurProchain == nomJoueurCurseur) {
				break;
			}
			curseur = curseur->getSuivant();
		}
		// curseur maintenant pointe le noeud avant tmp
		nouveau->setJoueur(unJoueur);
		nouveau->setSuivant(curseur->getSuivant());
		curseur->setSuivant(nouveau);
	}
	taille++;
}


const Joueur& ListeJoueur::obtenirCurseurElement() const{
	return curseur->getJoueur();
}


const Joueur& ListeJoueur::obtenirElement(int element) const{
	deplacerCurseurDebut();
	int compteur = 0;

	while (compteur < element) {
		curseur = curseur->getSuivant();
		compteur++;
	}

	return curseur->getJoueur();
}


void ListeJoueur::insererFin(const Joueur& unJoueur){
	NoeudJoueur *nouveau = new NoeudJoueur();
	nouveau->setJoueur(unJoueur);

	if (tete == nullptr) {
		tete = nouveau;
	} else {
		fin->setSuivant(nouveau);
	}

	fin = nouveau;
	taille++;
}


bool ListeJoueur::estVide() const{
	if (tete == nullptr && fin == nullptr) {
		return true;
	}

	return false;
}


int ListeJoueur::getTaille() const {
	return taille;
}


void ListeJoueur::viderListe() {
	deplacerCurseurDebut();
	NoeudJoueur *tmp;

	while (curseur != nullptr) {
		tmp = curseur;
		curseur = curseur->getSuivant();
		delete tmp;
	}

	tete = nullptr;
	fin = nullptr;
	taille = 0;
}