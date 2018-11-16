#include "Traitement.h"
#include <iostream>
#include <fstream>
#include <clocale>

// Lit le fichier equipes.txt, créer les équipes (sans listeJoueur) et les ajoute dans la liste d'équipe.
void lectureFichEquipes(ListeEquipe& listeEquipe, string cheminFichier) {
	ifstream fichLesEquipes(cheminFichier + "equipes.txt");
	string nomEquipe;
	string chaine;		// fichier d'une equipe

	while (!fichLesEquipes.eof()) {
		getline(fichLesEquipes, chaine);

		// Evite la derniere ligne vide dans le fichier
		if (chaine == "") {
			break;
		}

		ifstream fichEquipe(cheminFichier + chaine);
		// Premiere ligne du fichier d'equipe est le nom d'equipe
		getline(fichEquipe, nomEquipe);

		Equipe newEquipe(nomEquipe);
		newEquipe.setNomfichier(cheminFichier + chaine);
		listeEquipe.insererFin(newEquipe);
		
		fichEquipe.close();
	}
	fichLesEquipes.close();

}


// Lit les fichiers des équipes, e.g., boston.txt, lasvegas.txt et rajoute les
// joueurs lus dans la liste de joueurs des équipes.
void creationListeJoueurs(ListeEquipe& listeEquipe, string delimiter) {
	string chaine;
	bool debut;
	
	int tailleLe = listeEquipe.getTaille();

	for (int i = 0; i < tailleLe; i++) {
		string cheminFichEquipe = listeEquipe.obtenirEquipe(i).getNomfichier();
		ifstream fichEquipe(cheminFichEquipe);
		debut = true;

		if (fichEquipe.is_open()) {
			while (!fichEquipe.eof()) {
				getline(fichEquipe, chaine);
				// La premiere ligne(debut) du fichier est le nom de l'equipe.
				// La derniere ligne est vide.
				if (debut || chaine == "") {
					debut = false;
				}
				else {
					string tokenJoueur = chaine.substr(0, chaine.find(delimiter));
					// On enleve le nom du joueur de la chaine
					chaine.erase(0, chaine.find(delimiter));

					// Recherche de la position du salaire dans la chaine
					int pos = 0;
					for (char& c : chaine) {
						if (isdigit(c)) {
							break;
						}
						pos++;
					}

					string sTokenSalaire = chaine.substr(pos, chaine.length());
					float fTokenSalaire = atof(sTokenSalaire.c_str());

					Joueur newJoueur(tokenJoueur, fTokenSalaire);
					listeEquipe.obtenirEquipe(i).ajouterJoueur(newJoueur);
				}
			}
		}
		fichEquipe.close();
	}
}


// Calcule la masse salairiale des joueurs dans une équipe.
float calculerMasseSalairiale(const Equipe& equipe) {
	ListeJoueur lj = equipe.getListeJoueurs();
	float masseSalairiale = 0;

	lj.deplacerCurseurDebut();
	while (lj.elementCurseurValide()) {
		masseSalairiale += lj.obtenirCurseurElement().getSalaire();
		lj.deplacerCurseurSuivant();
	}

	return masseSalairiale;
}


// Ajoute un nouveau joueur à une équipe.
void ajouterJoueur(ListeEquipe& listeEquipe, const int& equipeChoisi, const string& nom, const float& salaire) {
	Joueur nouveau(nom, salaire);
	listeEquipe.obtenirEquipe(equipeChoisi - 1).ajouterJoueur(nouveau);
}


// Retire un joueur de son équipe.
void enleverJoueur(ListeEquipe& listeEquipe, const int& equipeChoisi, const int& joueurChoisi) {
	Joueur joueurEnlever = listeEquipe.obtenirEquipe(equipeChoisi - 1).getListeJoueurs()
		.obtenirElement(joueurChoisi - 1);

	listeEquipe.obtenirEquipe(equipeChoisi - 1).retirerJoueur(joueurEnlever);
}


// Lit une chaine.
string lireChaine(const string& message) {
	string chaine = "";

	while (chaine == "") {
		cout << message << ": ";
		getline(cin, chaine);

		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}
	cout << endl;

	return chaine;
}


