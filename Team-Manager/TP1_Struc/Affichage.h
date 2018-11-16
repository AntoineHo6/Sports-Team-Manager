#ifndef AFFICHAGE
#define AFFICHAGE

#include "ListeEquipe.h"

using namespace std;

/**
	Affiche le menu principal.

	@return nothing.
*/
void afficheMenu();

/**
	Affiche le salaire cumulatif des joueurs d'une �quipe.

	@param listeEquipe La liste d'�quipe manipul�e afin d'acc�der aux salaires.
	@return nothing.
*/
void afficheMasseSalairiale(const ListeEquipe& listeEquipe);

/**
	Affiche les �quipes num�rot�es.

	@param listeEquipe La liste d'�quipe manipul�e afin d'acc�der aux �quipes.
	@return nothing.
*/
void afficheLesEquipes(const ListeEquipe& listeEquipe);

/**
	Affiche les joueurs et leurs salaires d'une �quipe

	@param equipeChoisi Un int correspondant a l'indice d'une �quipe quand on soustrait 1.
	@param listeEquipe La liste d'�quipe manipul�e afin d'acc�der aux joueurs.
	@return nothing.
*/
void afficheEquipe(const int& equipeChoisi, const ListeEquipe& listeEquipe);

/**
	Affiche les noms des joueurs num�rot�s d'une �quipe.

	@param equipeChoisi Est un int qui correspond a l'indice d'une �quipe - 1
	@param listeEquipe La liste d'�quipe manipul�e afin d'acc�der aux joueurs.
	@return nothing.
*/
void afficheJoueurs(const int& equipeChoisi, const ListeEquipe& listeEquipe);

#endif;