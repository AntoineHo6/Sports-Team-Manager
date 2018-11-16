/**
	420-P34-BB
	Main.cpp
	Utilit�: G�re des �quipes dans des fichiers .txt

	@auteur Antoine Ho (1767487)
	@date 5 novembre 2018
*/

#include <iostream>
#include <string>
#include <clocale>
#include "Affichage.h"
#include "ListeEquipe.h"
#include "UtilitairesES.h"
#include "Traitement.h"

using namespace std;

/**
	Demande de choisir une �quipe et ensuite il affichera ses joueurs.

	@param listeEquipe La liste d'�quipe manipul�e afin d'acc�der aux joueurs.
	@return nothing.
*/
void logicChoix2(const ListeEquipe& listeEquipe);

/**
	Ajoute un joueur a une �quipe selon le nom, salaire et �quipe choisi par l'utilisateur.

	@param listeEquipe La liste d'�quipe manipul�e afin d'ajout� un joueur.
	@return nothing.
*/
void logicChoix3(ListeEquipe& listeEquipe);

/**
	Affiche les joueurs d'une �quipe choisi et l'utilisateur va en choisir un a retirer.

	@param listeEquipe La liste d'�quipe manipul�e afin de retirer un joueur.
	@return nothing.
*/
void logicChoix4(ListeEquipe& listeEquipe);

/**
	Affiche les joueurs d'une �quipe choisi et l'utilisateur va en choisir un a retirer.

	@param listeEquipe La liste d'�quipe manipul�e afin de retirer un joueur.
	@return nothing.
*/
void logicChoix5(ListeEquipe& listeEquipe);


int main() {
	setlocale(LC_ALL, "");
	ListeEquipe listeEquipe;
	lectureFichEquipes(listeEquipe, "./Fichiers-TP1/");
	creationListeJoueurs(listeEquipe, ";");

	while (true) {
		afficheMenu();
		int choix = lireEntier("Entrez votre choix(entre 1 et 5)", 1, 5);

		switch (choix) {
			case 1:
				afficheMasseSalairiale(listeEquipe);
				break;
			case 2:
				logicChoix2(listeEquipe);
				break;
			case 3:
				logicChoix3(listeEquipe);
				break;
			case 4:
				logicChoix4(listeEquipe);
				break;
			case 5:
				logicChoix5(listeEquipe);
				break;
		}
	}
	return 0;
}


// Demande de choisir une �quipe et ensuite il affichera ses joueurs.
void logicChoix2(const ListeEquipe& listeEquipe) {
	afficheLesEquipes(listeEquipe);
	int equipeChoisi = lireEntier("Choisissez votre �quipe", 1, listeEquipe.getTaille());
	afficheEquipe(equipeChoisi, listeEquipe);
}


// Ajoute un joueur a une �quipe selon le nom, salaire et �quipe choisi par l'utilisateur.
void logicChoix3(ListeEquipe& listeEquipe) {
	cout << "Entrez le nom de l'�quipe du nouveau joueur" << endl;
	afficheLesEquipes(listeEquipe);

	int equipeChoisi = lireEntier("Choisissez votre �quipe", 1, listeEquipe.getTaille());
	string nom = lireChaine("Entrez le nom du joueur");
	float salaire = lireReel("Entrez le salaire du joueur", 0.0f, 99999999.0f);

	ajouterJoueur(listeEquipe, equipeChoisi, nom, salaire);
}


// Affiche les joueurs d'une �quipe choisi et l'utilisateur va en choisir un a retirer.
void logicChoix4(ListeEquipe& listeEquipe) {
	cout << "Entrez l'�quipe d'origine du joueur" << endl;
	afficheLesEquipes(listeEquipe);

	int equipeChoisi = lireEntier("Choisissez votre �quipe", 1, listeEquipe.getTaille());

	afficheJoueurs(equipeChoisi, listeEquipe);

	int tailleLe = listeEquipe.obtenirEquipe(equipeChoisi - 1).getListeJoueurs().getTaille();
	int joueurChoisi = lireEntier("Quel joueur voulez-vous retirer?", 1, tailleLe);

	enleverJoueur(listeEquipe, equipeChoisi, joueurChoisi);
}


// Affiche les joueurs d'une �quipe choisi et l'utilisateur va en choisir un a retirer.
void logicChoix5(ListeEquipe& listeEquipe) {
	int tailleLe = listeEquipe.getTaille();
	for (int i = 0; i < tailleLe; i++) {
		listeEquipe.obtenirEquipe(i).sauvegarder();
	}

	exit(0);
}
