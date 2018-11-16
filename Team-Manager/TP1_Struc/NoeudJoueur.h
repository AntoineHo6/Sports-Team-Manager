#ifndef NOEUDJOUEUR_H
#define NOEUDJOUEUR_H

#include "Joueur.h"

class NoeudJoueur {
public:
	NoeudJoueur();								// Constructeur par défaut.
	NoeudJoueur(const NoeudJoueur& ne);			// Constructeur par copie.
	~NoeudJoueur();								// Destructeur

	// Copie d'un noeudJoueur.
	const NoeudJoueur& operator=(const NoeudJoueur& noeud);

	// Retourne le joueur const.
	const Joueur& getJoueur() const;
	
	// Retourne le joueur.
	Joueur& getJoueur();

	// Retourne le noeud suivant.
	NoeudJoueur* getSuivant() const;

	// Ajoute ou change un joueur.
	void setJoueur(const Joueur& joueur);

	// Ajoute ou change le noeud suivant.
	void setSuivant(NoeudJoueur* n);

private:
	NoeudJoueur* suivant;
	Joueur leJoueur;
};

#endif