#include "Item.h"


Item::Item(int ID, string name, int damage, int healing, float attack, float defense, float speed, int mana, string description)
{
	setItemID(ID);
	setName(name);
	setDamage(damage);
	setHealing(healing);
	setAttack(attack);
	setDefense(defense);
	setSpeed(speed);
	setMana(mana);
	setDescription(description);
}

Item::Item()
{

}

Item::~Item()
{

}

//Mutateurs des variables de la classe
void Item::setItemID(int ID)
{
	_itemID = ID;
}

void Item::setName(string name)
{
	_name = name;
}

void Item::setDamage(int dmg)
{
	_damage = dmg;
}

void Item::setHealing(int healing)
{
	_healing = healing;
}

void Item::setAttack(float att)
{
	_attack = att;
}

void Item::setDefense(float def)
{
	_defense = def;
}

void Item::setSpeed(float speed)
{
	_speed = speed;
}

void Item::setMana(int mana)
{
	_mana = mana;
}

void Item::setDescription(string desc)
{
	_description = desc;
}

//Accesseurs
int Item::getItemID()
{
	return _itemID;
}

string Item::getName()
{
	return _name;
}

int Item::getDamage()
{
	return _damage;
}

int Item::getHealing()
{
	return _healing;
}

float Item::getAttack()
{
	return _attack;
}

float Item::getDefense()
{
	return _defense;
}

float Item::getSpeed()
{
	return _speed;
}

int Item::getMana()
{
	return _mana;
}

string Item::getDescription()
{
	return _description;
}
