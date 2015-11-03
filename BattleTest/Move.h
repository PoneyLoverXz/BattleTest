#pragma once
#include "PokeType.h"
#include <string>
using namespace std;
class Move
{
	  /***********/
	 /*Variables*/
	/***********/

	int _moveID;	//ID du move dans la BD.
	string _name;	//Nom du move.
	PokeType _type;	//Type du move. ie: Feu, Eau, etc... 

	double _damage;	//Le dommage du move.
	double _healing;	//La quantité de vie que l'attaque regénère.
	double _attack;	//Le nombre de "stages" que le move fait augmenter l'attaque.
	double _defense;	//Le nombre de "stages" que le move fait augmenter la defense.
	double _speed;		//Le nombre de "stages" que le move fait augmenter la vitesse.
	double _mana;		//Le nombre de mana que le move coute.

	string _description;	//La description du move.

public:


	  /***************/
	 /*Constructeurs*/
	/***************/

	//Instancier un move en indiquant son ID, nom, type, dommage, vie restauré, attaque, défense et vitesse augmenté et sa description.
	Move(int ID, string name, PokeType pokeType, double damage, double healing, double attack, double defense, double speed, double mana, string description);
	//Constructeur par défaut
	Move();
	//Destructeur
	~Move();



	  /**************************************/
	 /*Mutateurs des variables de la classe*/
	/**************************************/

	//Fixer l'ID du move
	void setMoveID(int ID);
	//Fixer le nom du move
	void setName(string name);
	//Fixer le type du move
	void setPokeType(PokeType type);
	
	//Fixer le dommage du move
	void setDamage(double dmg);
	//Fixer la vie restaurée par le move
	void setHealing(double healing);
	//Fixer le changement à l'attaque du move.
	void setAttack(double att);
	//Fixer le changement à la défense du move.
	void setDefense(double def);
	//Fixer le changement à la vitesse du move.
	void setSpeed(double speed);

	//Fixer le cout de mana
	void setMana(double mana);
	//Fixer la description du move.
	void setDescription(string desc);


	  /***************************************/
	 /*Accesseurs des variables de la classe*/
	/***************************************/

	//Obtenir l'ID du move
	int getMoveID();
	//
	string getName();
	PokeType getPokeType();

	double getDamage();
	double getHealing();
	double getAttack();
	double getDefense();
	double getSpeed();

	double getMana();
	string getDescription();

	/*****************/
	/*Autres méthodes*/
	/*****************/

	
};

