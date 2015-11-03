#pragma once
#include "Pokemon.h"
#include "Item.h"
#include "Player.h"
class Battle
{
	/***********/
	/*Variables*/
	/***********/
	bool _isStarted = false;

	Pokemon _playerPokemon;
	Pokemon _AIPokemon;
	
public:
	/***************/
	/*Constructeurs*/
	/***************/	
	Battle(Pokemon * pp1, Pokemon * pp2, Pokemon * pp3, Pokemon * ap1, Pokemon * ap2, Pokemon * ap3);
	//Destructeurs
	~Battle();

	Pokemon *PokemonPlaying;
	Pokemon *AIPlaying;

	Pokemon *PlayerPokemon1;
	Pokemon *PlayerPokemon2;
	Pokemon *PlayerPokemon3;

	Pokemon *AIPokemon1;
	Pokemon *AIPokemon2;
	Pokemon *AIPokemon3;

	/**************************************/
	/*Mutateurs des variables de la classe*/
	/**************************************/
public:


	/***************************************/
	/*Accesseurs des variables de la classe*/
	/***************************************/
	
	/*****************/
	/*Autres méthodes*/
	/*****************/

	//Permet au combat de débuter
	void StartBattle(Pokemon *pkmnplaying, Pokemon *aiplaying);
	//Termine le combat
	void EndBattle();

	double useMove(Move *move, Pokemon *attacker, Pokemon *defender);
	float damage(Move *move, Pokemon *attacker, Pokemon *defender);
	float isStab(Move *move, Pokemon *pkmn);
	float IsEffective(Move *move, Pokemon *pkmn);

	void useItem(Item *item, Pokemon &attacker, Pokemon &defender);


	/********/
	/*  AI  */
	/********/

	void AITurn();
	bool AIMove(Pokemon *ai, Pokemon *pkmn);
	double HasHealingMove(Pokemon * ai);
	bool AIHeal(Pokemon * ai);
	double isPokemonEffective(Pokemon * attacker, Pokemon * defender);
	bool ShouldAISwitch(Pokemon *ai);
	bool AISwitchPokemon(int choice);
	bool AIDamagingMove();
};

