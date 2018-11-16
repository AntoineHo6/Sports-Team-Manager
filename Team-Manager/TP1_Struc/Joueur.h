#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
using namespace std;

class Joueur {
public:
	Joueur(const string& nom = "", float salaire = 0.0f);			// Constructeur par défaut.
	~Joueur();														// Destructeur.	

	// Pour copier un joueur.
	const Joueur& operator=(const Joueur& joueur);				

	// Retourne le nom.
	const string& getNom() const;

	// Retourne le salaire.
	float getSalaire() const;

	// Change le nom.
	void setNom(const string& nom);

	// Change le salaire
	void setSalaire(float salaire);

private:
	string nom;
	float salaire;
};

#endif