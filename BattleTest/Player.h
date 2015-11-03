#pragma once

#include "Pokemon.h"
#include "Item.h"
#include <vector>

class Player
{
	/***********/
	/*Variables*/
	/***********/

	vector<Pokemon> _party;		//Party du joueur
	vector<Pokemon> _pokemonBag; //Les Pokémons du joueur qui ne sont pas dans notre party
	vector<Item> _itemBag;		//Les items du joueur

public:
	
	/***************/
	/*Constructeurs*/
	/***************/
	Player(vector<Pokemon> party, vector<Pokemon> pokemonBag, vector<Item> itemBag);
	Player();
	~Player();

	/**************************************/
	/*Mutateurs des variables de la classe*/
	/**************************************/

	void setParty(vector<Pokemon> party);
	void setPokemonBag(vector<Pokemon> pokemonBag);
	void setItemBag(vector<Item> itemBag);

	/***************************************/
	/*Accesseurs des variables de la classe*/
	/***************************************/

	vector<Pokemon> getParty();
	vector<Pokemon> getPokemonBag();
	vector<Item> getItemBag();
};

