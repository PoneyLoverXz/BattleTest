#pragma once
#include "PokeType.h"
#include "Move.h"
#include <string>
using namespace std;
class Pokemon
{
	/***********/
	/*Variables*/
	/***********/

	int _pokemonID;	//ID du monstre
	string _name;		//Nom du monstre
	double _lvl;			//Niveau du monstre
	PokeType _type;		//Type du monstre

	double _baseHP;		//Vie de base du monstre
	double _baseAtt;		//Attaque de base du monstre
	double _baseDef;		//Defense de base du monstre
	double _baseSpeed;		//Vitesse de base du monstre

	double _hp;			//Vie pour son niveau
	double _att;			//Attaque pour son niveau
	double _def;			//Defense pour son niveau
	double _speed;			//Vitesse pour son niveau
	double _mana;			//Mana

	double _curHP;			//Vie courante
	double _curAtt;		//Attaque courante
	double _curDef;		//Defense courante
	double _curSpeed;		//Vitesse courante
	double _curMana;		//Mana courante

	string _sprite;		//Path de son sprite

	Move *_move1;		//Premier move.
	Move *_move2;		//Deuxième move.
	Move *_move3;		//Troisième move.
	Move *_move4;		//Quatrième move.

	bool _isAlive = true;

public:
	/***************/
	/*Constructeurs*/
	/***************/

	//Instancier un monstre avec son ID, son nom, son type, ses stastiques de base, son sprite et ses moves.
	Pokemon(int ID, string name, double lvl, PokeType pokeType, double baseHP, double baseAtt, double baseDef, double baseSpeed, double mana, string sprite, Move *move1);
	Pokemon(int ID, string name, double lvl, PokeType pokeType, double baseHP, double baseAtt, double baseDef, double baseSpeed, double mana, string sprite, Move *move1, Move *move2);
	Pokemon(int ID, string name, double lvl, PokeType pokeType, double baseHP, double baseAtt, double baseDef, double baseSpeed, double mana, string sprite, Move* move1, Move *move2, Move *move3);
	Pokemon(int ID, string name, double lvl, PokeType pokeType, double baseHP, double baseAtt, double baseDef, double baseSpeed, double mana, string sprite, Move *move1, Move *move2, Move* move3, Move *move4);
	Pokemon();
	~Pokemon();


	/**************************************/
	/*Mutateurs des variables de la classe*/
	/**************************************/

	void setPokemonID(int ID);
	void setName(string name);
	void setLevel(double lvl);
	void setPokeType(PokeType pokeType);
	
	void setBaseHP(double baseHP);
	void setBaseAtt(double baseAtt);
	void setBaseDef(double baseDef);
	void setBaseSpeed(double baseSpeed);

	void SetStatsForLevel();
	void setHP(double HP);
	void setAtt(double Att);
	void setDef(double Def);
	void setSpeed(double Speed);
	void setMana(double Mana);

	void setCurrentHP(double curHP);
	void setCurrentAtt(double curAtt);
	void setCurrentDef(double curDef);
	void setCurrentSpeed(double curSpeed);
	void setCurrentMana(double curMana);

	void setSprite(string sprite);
	void setMoves(Move *move1);
	void setMoves(Move *move1, Move *move2);
	void setMoves(Move *move1, Move *move2, Move *move3);
	void setMoves(Move *move1, Move *move2, Move* move3, Move *move4);

	void setIsAlive(bool IsAlive);

	/***************************************/
	/*Accesseurs des variables de la classe*/
	/***************************************/

	int getPokemonID();
	string getName();
	double getLevel();
	PokeType getPokeType();

	double getBaseHP();
	double getBaseAtt();
	double getBaseDef();
	double getBaseSpeed();

	double getHP();
	double getAtt();
	double getDef();
	double getSpeed();
	double getMana();

	double getCurrentHP();
	double getCurrentAtt();
	double getCurrentDef();
	double getCurrentSpeed();
	double getCurrentMana();

	string getSprite();
	Move* getMove1();
	Move* getMove2();
	Move* getMove3();
	Move* getMove4();

	bool getIsAlive();
};

