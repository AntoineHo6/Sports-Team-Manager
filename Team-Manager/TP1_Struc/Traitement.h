#ifndef TRAITEMENT
#define TRAITEMENT

#include "ListeEquipe.h"

using namespace std;

/**
	Lit le fichier equipes.txt, créé les équipes et les ajoute dans la liste d'équipe.

	@param listeEquipe La liste d'équipe manipulée afin d'ajouter des équipes.
	@return nothing.
*/
void lectureFichEquipes(ListeEquipe& listeEquipe, string cheminFichier);

/**
	Lit les fichiers des équipes, e.g., boston.txt, lasvegas.txt et rajoute les
	joueurs lus dans la liste de joueurs des équipes.

	@param listeEquipe La liste d'équipe manipulée afin d'ajouter des équipes.
	@return nothing.
*/
void creationListeJoueurs(ListeEquipe& listeEquipe, string delimiter);

/**
	Calcule la masse salairiale des joueurs dans une équipe.

	@param equipe L'équipe don't la somme des salaires va être calculer.
	@return nothing.
*/
float calculerMasseSalairiale(const Equipe& equipe);

/**
	Ajoute un nouveau joueur à une équipe.

	@param listeEquipe La liste d'équipe manipulée afin d'accéder à l'équipe.
	@param equipeChoisi Int correspondant a l'indice d'une équipe quand on soustrait 1.
	@param nom Le nom du joueur à ajouter.
	@param salaire Le salaire du joueur à ajouter.
	@return nothing.
*/
void ajouterJoueur(ListeEquipe& listeEquipe, const int& equipeChoisi, 
						const string& nom, const float& salaire);

/**
	Retire un joueur de son équipe.

	@param listeEquipe La liste d'équipe manipulée afin d'accéder au joueur.
	@param equipeChoisi Int correspondant a l'indice d'une équipe quand on soustrait 1.
	@param joueurChoisi Int correspondant a l'indice d'un joueur quand on soustrait 1.
	@return nothing.
*/
void enleverJoueur(ListeEquipe& listeEquipe, const int& equipeChoisi, const int& joueurChoisi);

/**
	Lit une chaine.

	@param message Un message qui apparait avant la demande de la chaine.
	@return La chaine entrée par l'utilisateur.
*/
string lireChaine(const string& message);

#endif;