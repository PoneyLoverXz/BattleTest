#include "Move.h"


Move::Move(int ID, string name, PokeType pokeType, double damage, double healing, double attack, double defense, double speed, double mana, string description)
{
	setMoveID(ID);
	setName(name);
	setPokeType(pokeType);
	setDamage(damage);
	setHealing(healing);
	setAttack(attack);
	setDefense(defense);
	setSpeed(speed);
	setMana(mana);
	setDescription(description);
}

Move::Move()
{

}

Move::~Move()
{

}

//Mutateurs des variables de la classe
void Move::setMoveID(int ID)
{
	_moveID = ID;
}

void Move::setName(string name)
{
	_name = name;
}

void Move::setPokeType(PokeType type)
{
	_type = type;
}

void Move::setDamage(double dmg)
{
	_damage = dmg;
}

void Move::setHealing(double healing)
{
	_healing = healing;
}

void Move::setAttack(double att)
{
	_attack = att;
}

void Move::setDefense(double def)
{
	_defense = def;
}

void Move::setSpeed(double speed)
{
	_speed = speed;
}

void Move::setMana(double mana)
{
	_mana = mana;
}

void Move::setDescription(string desc)
{
	_description = desc;
}

//Accesseurs
int Move::getMoveID()
{
	return _moveID;
}

string Move::getName()
{
	return _name;
}

PokeType Move::getPokeType()
{
	return _type;
}

double Move::getDamage()
{
	return _damage;
}

double Move::getHealing()
{
	return _healing;
}

double Move::getAttack()
{
	return _attack;
}

double Move::getDefense()
{
	return _defense;
}

double Move::getSpeed()
{
	return _speed;
}

double Move::getMana()
{
	return _mana;
}

string Move::getDescription()
{
	return _description;
}