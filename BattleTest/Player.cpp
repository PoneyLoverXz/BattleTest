#include "Player.h"


Player::Player(vector<Pokemon> party, vector<Pokemon> pokemonBag, vector<Item> itemBag)
{
	setParty(party);
	setPokemonBag(pokemonBag);
	setItemBag(itemBag);
}

Player::Player()
{
}

Player::~Player()
{

}

/**************************************/
/*Mutateurs des variables de la classe*/
/**************************************/

void  Player::setParty(vector<Pokemon> party)
{
	_party = party;
}

void  Player::setPokemonBag(vector<Pokemon> pokemonBag)
{
	_pokemonBag = pokemonBag;
}

void  Player::setItemBag(vector<Item> itemBag)
{
	_itemBag = itemBag;
}

/***************************************/
/*Accesseurs des variables de la classe*/
/***************************************/

vector<Pokemon> Player::getParty()
{
	return _party;
}

vector<Pokemon>  Player::getPokemonBag()
{
	return _pokemonBag;
}

vector<Item>  Player::getItemBag()
{
	return _itemBag;
}