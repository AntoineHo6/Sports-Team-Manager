#include "Affichage.h"
#include "Traitement.h"
#include <iostream>
#include <iomanip>

// Affiche le menu principal.
void afficheMenu() {
	cout << "Veuillez choisir parmi les choix suivants: " << endl;
	cout << "1) Afficher la masse salariale des équipes" << endl;
	cout << "2) Afficher une équipe" << endl;
	cout << "3) Ajouter un joueur" << endl;
	cout << "4) Retirer un joueur" << endl;
	cout << "5) Quitter" << endl;
	cout << endl;
}


// Affiche le salaire cumulatif des joueurs d'une équipe.
void afficheMasseSalairiale(const ListeEquipe& listeEquipe) {
	cout << left << setw(20) << "équipe" << right << setw(10) << "Salaire" << "\n\n";

	int tailleLe = listeEquipe.getTaille();
	cout << setprecision(9);
	for (int i = 0; i < tailleLe; i++) {
		string nomEquipe = listeEquipe.obtenirEquipe(i).getNomEquipe();
		float masseSalairiale = calculerMasseSalairiale(listeEquipe.obtenirEquipe(i));

		cout << left << setw(20) << nomEquipe  << right << setw(10) << masseSalairiale << " $" << endl;
	}
	cout << endl;
}


// Affiche les équipes numérotées.
void afficheLesEquipes(const ListeEquipe& listeEquipe) {
	int tailleListe = listeEquipe.getTaille();
	for (int i = 0; i < tailleListe; i++) {
		cout << setw(3) << i + 1 << ")" << listeEquipe.obtenirEquipe(i).getNomEquipe() << endl;
	}
}


// Affiche les joueurs et leurs salaires d'une équipe
void afficheEquipe(const int& equipeChoisi, const ListeEquipe& listeEquipe) {
	ListeJoueur lj = listeEquipe.obtenirEquipe(equipeChoisi - 1).getListeJoueurs();

	cout << "Nom de l'équipe: " << listeEquipe.obtenirEquipe(equipeChoisi - 1).getNomEquipe() << "\n\n";

	cout << left << setw(30) << "Nom du joueur" << ' ' << right << setw(9) << "Salaire" << endl;
	cout << setprecision(9);

	lj.deplacerCurseurDebut();
	while (lj.elementCurseurValide()) {
		string nomJoueur = lj.obtenirCurseurElement().getNom();
		float salaireJoueur = lj.obtenirCurseurElement().getSalaire();
		cout << left << setw(30) << nomJoueur << " " << right << setw(9) << salaireJoueur << " $" << endl;
		lj.deplacerCurseurSuivant();
	}
	cout << endl;
}


// Affiche les noms des joueurs numérotés d'une équipe.
void afficheJoueurs(const int& equipeChoisi, const ListeEquipe& listeEquipe) {
	ListeJoueur lj = listeEquipe.obtenirEquipe(equipeChoisi - 1).getListeJoueurs();

	int compteur = 1;
	lj.deplacerCurseurDebut();
	while (lj.elementCurseurValide()) {
		cout << right << setw(2) << compteur << ") " << lj.obtenirCurseurElement().getNom() << endl;
		lj.deplacerCurseurSuivant();
		compteur++;
	}

	cout << endl;
}
