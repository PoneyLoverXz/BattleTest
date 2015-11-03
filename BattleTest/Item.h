#pragma once
#include <string>
using namespace std;

class Item
{
	/***********/
	/*Variables*/
	/***********/

	int _itemID;	//ID d'item dans la BD.
	string _name;	//Nom de l' item.

	int _damage;	//Le dommage d'item.
	int _healing;	//La quantité de vie que l'item regénère.
	float _attack;	//Le nombre de "stages" que l'item fait augmenter l'attaque.
	float _defense;	//Le nombre de "stages" que l'item fait augmenter la defense.
	float _speed;		//Le nombre de "stages" que l'item fait augmenter la vitesse.
	int _mana;		//Le nombre de mana que l'item coute

	string _description;	//La description de l'item.

public:


	/***************/
	/*Constructeurs*/
	/***************/

	//Instancier un item en indiquant son ID, nom, type, dommage, vie restauré, attaque, défense et vitesse augmenté et sa description.
	Item(int ID, string name, int damage, int healing, float attack, float defense, float speed, int mana, string description);
	//Constructeur par défaut
	Item();
	//Destructeur
	~Item();



	/**************************************/
	/*Mutateurs des variables de la classe*/
	/**************************************/

	//Fixer l'ID de l' item
	void setItemID(int ID);
	//Fixer le nom de l' item
	void setName(string name);

	//Fixer le dommage de l' item
	void setDamage(int dmg);
	//Fixer la vie restaurée par le item
	void setHealing(int healing);
	//Fixer le changement à l'attaque de l' item.
	void setAttack(float att);
	//Fixer le changement à la défense de l' item.
	void setDefense(float def);
	//Fixer le changement à la vitesse de l' item.
	void setSpeed(float speed);
	//Fixer la mana
	void setMana(int mana);

	//Fixer la description de l' item.
	void setDescription(string desc);


	/***************************************/
	/*Accesseurs des variables de la classe*/
	/***************************************/

	//Obtenir l'ID de l' item
	int getItemID();
	//
	string getName();

	int getDamage();
	int getHealing();
	float getAttack();
	float getDefense();
	float getSpeed();
	int getMana();

	string getDescription();
};