#include "Pokemon.h"

//Constructeurs
Pokemon::Pokemon(int ID, string name, double lvl, PokeType pokeType, double baseHP, double baseAtt, double baseDef, double baseSpeed, double mana, string sprite, Move* move1)
{
	setPokemonID(ID);
	setName(name);
	setLevel(lvl);
	setPokeType(pokeType);
	setBaseHP(baseHP);
	setBaseAtt(baseAtt);
	setBaseDef(baseDef);
	setBaseSpeed(baseSpeed);
	SetStatsForLevel();
	setMana(mana);
	setCurrentMana(mana);
	setSprite(sprite);
	setMoves(move1,NULL,NULL,NULL);
}

Pokemon::Pokemon(int ID, string name, double lvl, PokeType pokeType, double baseHP, double baseAtt, double baseDef, double baseSpeed, double mana, string sprite, Move* move1, Move* move2)
{
	setPokemonID(ID);
	setName(name);
	setLevel(lvl);
	setPokeType(pokeType);
	setBaseHP(baseHP);
	setBaseAtt(baseAtt);
	setBaseDef(baseDef);
	setBaseSpeed(baseSpeed);
	SetStatsForLevel();
	setMana(mana);
	setCurrentMana(mana);
	setSprite(sprite);
	setMoves(move1,move2,NULL,NULL);
}

Pokemon::Pokemon(int ID, string name, double lvl, PokeType pokeType, double baseHP, double baseAtt, double baseDef, double baseSpeed, double mana, string sprite, Move* move1, Move* move2, Move* move3)
{
	setPokemonID(ID);
	setName(name);
	setLevel(lvl);
	setPokeType(pokeType);
	setBaseHP(baseHP);
	setBaseAtt(baseAtt);
	setBaseDef(baseDef);
	setBaseSpeed(baseSpeed);
	SetStatsForLevel();
	setMana(mana);
	setCurrentMana(mana);
	setSprite(sprite);
	setMoves(move1, move2, move3,NULL);
}
Pokemon::Pokemon(int ID, string name, double lvl, PokeType pokeType, double baseHP, double baseAtt, double baseDef, double baseSpeed, double mana, string sprite, Move* move1, Move* move2, Move* move3, Move* move4)
{
	setPokemonID(ID);
	setName(name);
	setLevel(lvl);
	setPokeType(pokeType);
	setBaseHP(baseHP);
	setBaseAtt(baseAtt);
	setBaseDef(baseDef);
	setBaseSpeed(baseSpeed);
	SetStatsForLevel();
	setMana(mana);
	setCurrentMana(mana);
	setSprite(sprite);
	setMoves(move1, move2, move3, move4);
}

Pokemon::Pokemon()
{

}
Pokemon::~Pokemon()
{

}

//Mutateurs des variables de la classe

void Pokemon::setPokemonID(int ID)
{
	_pokemonID = ID;
}

void Pokemon::setName(string name)
{
	_name = name;
}

void Pokemon::setLevel(double lvl)
{
	if (lvl < 0)
		_lvl = 1;
	else if (lvl > 100)
		_lvl = 100;
	else
		_lvl = lvl;
}

void Pokemon::setPokeType(PokeType pokeType)
{
	_type = pokeType;
}

void Pokemon::setBaseHP(double baseHP)
{
	_baseHP = baseHP;
}

void Pokemon::setBaseAtt(double baseAtt)
{
	_baseAtt = baseAtt;
}

void Pokemon::setBaseDef(double baseDef)
{
	_baseDef = baseDef;
}

void Pokemon::setBaseSpeed(double baseSpeed)
{
	_baseSpeed = baseSpeed;
}

void Pokemon::SetStatsForLevel()
{
	setHP(ceil(2 * getBaseHP() + 31) * getLevel() / 100 + getLevel() + 10);
	setAtt(ceil(2 * getBaseAtt() + 31) * getLevel() / 100 + 5);
	setDef(ceil(2 * getBaseDef() + 31) * getLevel() / 100 + 5);
	setSpeed(ceil(2 * getBaseSpeed() + 31) * getLevel() / 100 + 5);

	setCurrentHP(getHP());
	setCurrentAtt(getAtt());
	setCurrentDef(getDef());
	setCurrentSpeed(getSpeed());
}

void Pokemon::setHP(double HP)
{
	_hp = HP;
}

void Pokemon::setAtt(double Att)
{
	_att = Att;
}

void Pokemon::setDef(double Def)
{
	_def = Def;
}

void Pokemon::setSpeed(double Speed)
{
	_speed = Speed;
}

void Pokemon::setMana(double Mana)
{
	_mana = Mana;
}

void Pokemon::setCurrentHP(double curHP)
{
	if (curHP < 0)
	{
		_curHP = 0;
		setIsAlive(false);
	}
	else if (curHP > getHP())
		_curHP = getHP();
	else
		_curHP = curHP;
}

void Pokemon::setCurrentAtt(double curAtt)
{
	_curAtt = curAtt;
}

void Pokemon::setCurrentDef(double curDef)
{
	_curDef = curDef;
}

void Pokemon::setCurrentSpeed(double curSpeed)
{
	_curSpeed = curSpeed;
}

void Pokemon::setCurrentMana(double curMana)
{
	if (curMana <= getMana())
		_curMana = curMana;
}

void Pokemon::setSprite(string sprite)
{
	_sprite = sprite;
}

void Pokemon::setMoves(Move* move1)
{
	_move1 = move1;
}

void Pokemon::setMoves(Move* move1, Move* move2)
{
	_move1 = move1;
	_move2 = move2;
}

void Pokemon::setMoves(Move* move1, Move* move2, Move* move3)
{
	_move1 = move1;
	_move2 = move2;
	_move3 = move3;
}

void Pokemon::setMoves(Move* move1, Move* move2, Move* move3, Move* move4)
{
	_move1 = move1;
	_move2 = move2;
	_move3 = move3;
	_move4 = move4;
}

void Pokemon::setIsAlive(bool IsAlive)
{
	_isAlive = IsAlive;
}


//Accesseurs des variables de la classe

int Pokemon::getPokemonID()
{
	return _pokemonID;
}

string Pokemon::getName()
{
	return _name;
}

double Pokemon::getLevel()
{
	return _lvl;
}

PokeType Pokemon::getPokeType()
{
	return _type;
}

double Pokemon::getBaseHP()
{
	return _baseHP;
}

double Pokemon::getBaseAtt()
{
	return _baseAtt;
}

double Pokemon::getBaseDef()
{
	return _baseDef;
}

double Pokemon::getBaseSpeed()
{
	return _baseSpeed;
}

double Pokemon::getHP()
{
	return _hp;
}

double Pokemon::getAtt()
{
	return _att;
}

double Pokemon::getDef()
{
	return _def;
}

double Pokemon::getSpeed()
{
	return _speed;
}

double Pokemon::getMana()
{
	return _mana;
}

double Pokemon::getCurrentHP()
{
	return _curHP;
}

double Pokemon::getCurrentAtt()
{
	return _curAtt;
}

double Pokemon::getCurrentDef()
{
	return _curDef;
}

double Pokemon::getCurrentSpeed()
{
	return _curSpeed;
}

double Pokemon::getCurrentMana()
{
	return _curMana;
}

string Pokemon::getSprite()
{
	return _sprite;
}

Move* Pokemon::getMove1()
{
	return _move1;
}

Move* Pokemon::getMove2()
{
	return _move2;
}

Move* Pokemon::getMove3()
{
	return _move3;
}

Move* Pokemon::getMove4()
{
	return _move4;
}

bool Pokemon::getIsAlive()
{
	return _isAlive;
}
