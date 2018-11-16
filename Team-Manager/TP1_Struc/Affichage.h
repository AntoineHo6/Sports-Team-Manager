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
	Affiche le salaire cumulatif des joueurs d'une équipe.

	@param listeEquipe La liste d'équipe manipulée afin d'accéder aux salaires.
	@return nothing.
*/
void afficheMasseSalairiale(const ListeEquipe& listeEquipe);

/**
	Affiche les équipes numérotées.

	@param listeEquipe La liste d'équipe manipulée afin d'accéder aux équipes.
	@return nothing.
*/
void afficheLesEquipes(const ListeEquipe& listeEquipe);

/**
	Affiche les joueurs et leurs salaires d'une équipe

	@param equipeChoisi Un int correspondant a l'indice d'une équipe quand on soustrait 1.
	@param listeEquipe La liste d'équipe manipulée afin d'accéder aux joueurs.
	@return nothing.
*/
void afficheEquipe(const int& equipeChoisi, const ListeEquipe& listeEquipe);

/**
	Affiche les noms des joueurs numérotés d'une équipe.

	@param equipeChoisi Est un int qui correspond a l'indice d'une équipe - 1
	@param listeEquipe La liste d'équipe manipulée afin d'accéder aux joueurs.
	@return nothing.
*/
void afficheJoueurs(const int& equipeChoisi, const ListeEquipe& listeEquipe);

#endif;