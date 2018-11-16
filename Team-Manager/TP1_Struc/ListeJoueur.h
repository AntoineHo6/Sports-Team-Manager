#ifndef LISTE_JOUEUR_H
#define LISTE_JOUEUR_H

#include "NoeudJoueur.h"

class ListeJoueur {
public:
	ListeJoueur();										// Constructeur par défaut.
	ListeJoueur(const ListeJoueur& uneListeJoueur);		// Constructeur par copie.
	~ListeJoueur();										// Destructeur.

	// Pour copier une ListeJoueur
	const ListeJoueur& operator=(const ListeJoueur& uneListeJoueur);

	// Fonctions d'utilisation du curseur
	void deplacerCurseurDebut() const;
	void deplacerCurseurSuivant() const;
	void retirerCurseurElement();
	bool elementCurseurValide() const;
	void insererAvantCurseur(const Joueur& unJoueur);
	const Joueur& obtenirCurseurElement() const;
	
	// Retourne un joueur au x'ième indice de la liste chainée.
	const Joueur& obtenirElement(int element) const;

	// Ajoute un joueur à la fin de la liste.
	void insererFin(const Joueur& unJoueur);

	bool estVide() const;
	int getTaille() const;

private:
	void viderListe();
	mutable NoeudJoueur* curseur; 
	NoeudJoueur* tete;
	NoeudJoueur* fin;
	int taille;
};

#endif
