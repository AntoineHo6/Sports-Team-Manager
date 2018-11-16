#ifndef TRAITEMENT
#define TRAITEMENT

#include "ListeEquipe.h"

using namespace std;

/**
	Lit le fichier equipes.txt, cr�� les �quipes et les ajoute dans la liste d'�quipe.

	@param listeEquipe La liste d'�quipe manipul�e afin d'ajouter des �quipes.
	@return nothing.
*/
void lectureFichEquipes(ListeEquipe& listeEquipe, string cheminFichier);

/**
	Lit les fichiers des �quipes, e.g., boston.txt, lasvegas.txt et rajoute les
	joueurs lus dans la liste de joueurs des �quipes.

	@param listeEquipe La liste d'�quipe manipul�e afin d'ajouter des �quipes.
	@return nothing.
*/
void creationListeJoueurs(ListeEquipe& listeEquipe, string delimiter);

/**
	Calcule la masse salairiale des joueurs dans une �quipe.

	@param equipe L'�quipe don't la somme des salaires va �tre calculer.
	@return nothing.
*/
float calculerMasseSalairiale(const Equipe& equipe);

/**
	Ajoute un nouveau joueur � une �quipe.

	@param listeEquipe La liste d'�quipe manipul�e afin d'acc�der � l'�quipe.
	@param equipeChoisi Int correspondant a l'indice d'une �quipe quand on soustrait 1.
	@param nom Le nom du joueur � ajouter.
	@param salaire Le salaire du joueur � ajouter.
	@return nothing.
*/
void ajouterJoueur(ListeEquipe& listeEquipe, const int& equipeChoisi, 
						const string& nom, const float& salaire);

/**
	Retire un joueur de son �quipe.

	@param listeEquipe La liste d'�quipe manipul�e afin d'acc�der au joueur.
	@param equipeChoisi Int correspondant a l'indice d'une �quipe quand on soustrait 1.
	@param joueurChoisi Int correspondant a l'indice d'un joueur quand on soustrait 1.
	@return nothing.
*/
void enleverJoueur(ListeEquipe& listeEquipe, const int& equipeChoisi, const int& joueurChoisi);

/**
	Lit une chaine.

	@param message Un message qui apparait avant la demande de la chaine.
	@return La chaine entr�e par l'utilisateur.
*/
string lireChaine(const string& message);

#endif;