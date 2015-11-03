#include "Battle.h"
#include <iostream>
#include <vector>
using namespace std;
/***************/
/*Constructeurs*/
/***************/

Battle::Battle(Pokemon * pp1, Pokemon * pp2, Pokemon * pp3, Pokemon * ap1, Pokemon * ap2, Pokemon * ap3)
{
	PlayerPokemon1 = pp1;
	PlayerPokemon2 = pp2;
	PlayerPokemon3 = pp3;

	AIPokemon1 = ap1;
	AIPokemon2 = ap2;
	AIPokemon3 = ap3;
}


Battle::~Battle()
{
}

/**************************************/
/*Mutateurs des variables de la classe*/
/**************************************/



/***************************************/
/*Accesseurs des variables de la classe*/
/***************************************/



/*****************/
/*Autres méthodes*/
/*****************/

//Permet au combat de débuter
void Battle::StartBattle(Pokemon *pkmnplaying, Pokemon *aiplaying)
{
	_isStarted = true;
	PokemonPlaying = pkmnplaying;
	AIPlaying = aiplaying;
}

//Termine le combat
void Battle::EndBattle()
{
	_isStarted = false;
}

double Battle::useMove(Move *move, Pokemon *attacker, Pokemon *defender)
{
	cout << attacker->getName() << " used " << move->getName() << "!" << endl;

	double dmg = ceil(damage(move, attacker, defender));
	defender->setCurrentHP(defender->getCurrentHP() - dmg);

	cout << attacker->getName() << " did " << dmg << " damage to " + defender->getName() << endl;

	if (move->getHealing() > 0)
	{
		attacker->setCurrentHP(ceil(attacker->getCurrentHP() * move->getHealing())); //AFFICHER ET VERIFIER***********************
		cout << attacker->getName() << " healed himself for " << move->getHealing() << endl;
	}

	if (move->getAttack() > 0)
	{
		attacker->setCurrentAtt(ceil(attacker->getCurrentAtt() * move->getAttack())); //AFFICHER ET VERIFIER***********************
		cout << attacker->getName() << "'s attack rose " << move->getAttack() << " times" << endl;
	}
	if (move->getAttack() < 0)
	{
		defender->setCurrentAtt(ceil(defender->getCurrentAtt() * move->getAttack())); //AFFICHER ET VERIFIER***********************
		cout << defender->getName() << "'s attack fell " << move->getAttack() << " times" << endl;
	}

	if (move->getDefense() > 0)
	{
		attacker->setCurrentDef(ceil(attacker->getCurrentDef() * move->getDefense())); //AFFICHER ET VERIFIER***********************
		cout << attacker->getName() << "'s defense rose " << move->getDefense() << " times" << endl;
	}
	if (move->getDefense() < 0)
	{
		defender->setCurrentDef(ceil(defender->getCurrentDef() * move->getDefense())); //AFFICHER ET VERIFIER***********************
		cout << defender->getName() << "'s defense fell " << move->getDefense() << " times" << endl;
	}

	if (move->getSpeed() > 0)
	{
		attacker->setCurrentSpeed(ceil(attacker->getCurrentSpeed() * move->getSpeed())); //AFFICHER ET VERIFIER***********************
		cout << attacker->getName() << "'s speed rose " << move->getSpeed() << " times" << endl;
	}
	if (move->getSpeed() < 0)
	{
		defender->setCurrentSpeed(ceil(defender->getCurrentSpeed() * move->getSpeed())); //AFFICHER ET VERIFIER***********************
		cout << defender->getName() << "'s speed fell " << move->getSpeed() << " times" << endl;
	}
	return dmg;
}

float Battle::damage(Move* move, Pokemon * attacker, Pokemon * defender)
{
	float ye = (2.0f * attacker->getLevel() + 10.0f) / 250.0f;
	float a = attacker->getCurrentAtt();
	float d = defender->getCurrentDef();
	float wahoo = a / d;
	float damn = move->getDamage() * isStab(move, attacker) * IsEffective(move, defender);
	return ye * wahoo * damn;
}

float Battle::isStab(Move* move, Pokemon * pkmn)
{
	if (move->getPokeType() == pkmn->getPokeType())
	{
		return 1.5f;
	}
	else
	{
		return 1;
	}
}

float Battle::IsEffective(Move* move, Pokemon* pkmn)
{
	PokeType MoveType = move->getPokeType();
	PokeType PkmnType = pkmn->getPokeType();

	float Effectiveness = 1;
	if (PkmnType == NORMAL)
	{
		if (MoveType == FIGHT)
		{
			Effectiveness = 2;
		}
		else if (MoveType == GHOST)
		{
			Effectiveness = 0;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == FIGHT)
	{
		if (MoveType == FLYING || MoveType == PSYCHIC || MoveType == FAIRY)
		{
			Effectiveness = 2;
		}
		else if (MoveType == BUG || MoveType == ROCK || MoveType == DARK)
		{
			Effectiveness = 0.5f;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == FLYING)
	{
		if (MoveType == ELECTRIC || MoveType == ICE || MoveType == ROCK)
		{
			Effectiveness = 2;
		}
		else if (MoveType == GRASS || MoveType == FIGHT || MoveType == BUG)
		{
			Effectiveness = 0.5f;
		}
		else if (MoveType == GROUND)
		{
			Effectiveness = 0;
		}
		else 
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == POISON)
	{
		if (MoveType == GROUND || MoveType == PSYCHIC)
		{
			Effectiveness = 2;
		}
		else if (MoveType == GRASS || MoveType == FIGHT || MoveType == POISON || MoveType == FAIRY)
		{
			Effectiveness = 0.5f;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == GROUND)
	{
		if (MoveType == WATER || MoveType == GRASS || MoveType == ICE)
		{
			Effectiveness = 2;
		}
		else if (MoveType == POISON || MoveType == ROCK )
		{
			Effectiveness = 0.5f;
		}
		else if (MoveType == ELECTRIC)
		{
			Effectiveness = 0;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == ROCK)
	{
		if (MoveType == WATER || MoveType == GRASS || MoveType == GROUND)
		{
			Effectiveness = 2;
		}
		else if (MoveType == NORMAL || MoveType == FIRE || MoveType == POISON || MoveType == FLYING)
		{
			Effectiveness = 0.5f;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == BUG)
	{
		if (MoveType == FIRE || MoveType == FLYING || MoveType == ROCK)
		{
			Effectiveness = 2;
		}
		else if (MoveType == GRASS || MoveType == FIGHT || MoveType == GROUND)
		{
			Effectiveness = 0.5f;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == GHOST)
	{
		if (MoveType == GHOST || MoveType == DARK)
		{
			Effectiveness = 2;
		}
		else if (MoveType == POISON || MoveType == BUG)
		{
			Effectiveness = 0.5f;
		}
		else if (MoveType == NORMAL || MoveType == FIGHT)
		{
			Effectiveness = 0;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == STEEL)
	{
		if (MoveType == FIRE || MoveType == FIGHT || MoveType == GROUND)
		{
			Effectiveness = 2;
		}
		else if	(MoveType == NORMAL || MoveType == GRASS || MoveType == ICE
				|| MoveType == FLYING || MoveType == PSYCHIC || MoveType == BUG
				|| MoveType == ROCK || MoveType == DRAGON || MoveType == STEEL
				|| MoveType == FAIRY)
		{
			Effectiveness = 0.5f;
		}
		else if (MoveType == POISON)
		{
			Effectiveness = 0;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == FIRE)
	{
		if (MoveType == FIRE || MoveType == GRASS || MoveType == ICE || 
			MoveType == BUG || MoveType == STEEL || MoveType == FAIRY)
		{
			Effectiveness = 0.5f;
		}
		else if (MoveType == WATER || MoveType == GROUND || MoveType == ROCK)
		{
			Effectiveness = 2;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == WATER)
	{
		if (MoveType == FIRE || MoveType == WATER || MoveType == ICE || MoveType == STEEL)
		{
			Effectiveness = 0.5f;
		}
		else if (MoveType == GRASS || MoveType == ELECTRIC)
		{
			Effectiveness = 2;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == GRASS)
	{
		if (MoveType == FIRE || MoveType == ICE || MoveType == POISON || MoveType == FLYING || MoveType == BUG)
		{
			Effectiveness = 2;
		}
		else if (MoveType == WATER || MoveType == GRASS || MoveType == ELECTRIC || MoveType == GROUND)
		{
			Effectiveness = 0.5f;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == ELECTRIC)
	{
		if (MoveType == GROUND)
		{
			Effectiveness = 2;
		}
		else if (MoveType == ELECTRIC || MoveType == FLYING || MoveType == STEEL)
		{
			Effectiveness = 0.5f;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == PSYCHIC)
	{
		if (MoveType == BUG || MoveType == DARK || MoveType == GHOST)
		{
			Effectiveness = 2;
		}
		else if (MoveType == FIGHT || MoveType == PSYCHIC)
		{
			Effectiveness = 0.5f;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == ICE)
	{
		if (MoveType == FIRE || MoveType == FIGHT || MoveType == ROCK || MoveType == STEEL)
		{
			Effectiveness = 2;
		}
		else if (MoveType == ICE)
		{
			Effectiveness = 0.5f;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == DRAGON)
	{
		if (MoveType == ICE || MoveType == DRAGON || MoveType == FAIRY)
		{
			Effectiveness = 2;
		}
		else if (MoveType == FIRE || MoveType == WATER || MoveType == GRASS || MoveType == ELECTRIC)
		{
			Effectiveness = 0.5f;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == DARK)
	{
		if (MoveType == FIGHT || MoveType == BUG || MoveType == FAIRY)
		{
			Effectiveness = 2;
		}
		else if (MoveType == GHOST || MoveType == DARK)
		{
			Effectiveness = 0.5f;
		}
		else if (MoveType == PSYCHIC)
		{
			Effectiveness = 0;
		}
		else
		{
			Effectiveness = 1;
		}
	}
	else if (PkmnType == FAIRY)
	{
		if (MoveType == POISON || MoveType == STEEL)
		{
			Effectiveness = 2;
		}
		else if (MoveType == FIGHT || MoveType == BUG || MoveType == DARK)
		{
			Effectiveness = 0.5f;
		}
		else if (MoveType == DRAGON)
		{
			Effectiveness = 0;
		}
		else
		{
			Effectiveness = 1;
		}
	}

	/*if (Effectiveness > 1)
		cout << "IT'S SUPER EFFECTIVE!" << endl;
	else if (Effectiveness < 1)
		cout << "It's not very effective." << endl;
   else if (Effectiveness == 0)
		cout << "It failed." << endl;*/

	return Effectiveness;
}

void Battle::useItem(Item *item, Pokemon &attacker, Pokemon &defender)
{
	defender.setCurrentHP(defender.getCurrentHP() - item->getDamage());
	attacker.setCurrentHP(attacker.getCurrentHP() + item->getHealing());

	if (item->getAttack() > 0)
	{
		attacker.setCurrentAtt(ceil(attacker.getCurrentAtt() * item->getAttack())); //AFFICHER ET VERIFIER***********************
	}
	if (item->getAttack() < 0)
	{
		defender.setCurrentAtt(ceil(defender.getCurrentAtt() * item->getAttack())); //AFFICHER ET VERIFIER***********************
	}

	if (item->getDefense() > 0)
	{
		attacker.setCurrentDef(ceil(attacker.getCurrentDef() * item->getDefense())); //AFFICHER ET VERIFIER***********************
	}
	if (item->getDefense() < 0)
	{
		defender.setCurrentDef(ceil(defender.getCurrentDef() * item->getDefense())); //AFFICHER ET VERIFIER***********************
	}

	if (item->getSpeed() > 0)
	{
		attacker.setCurrentSpeed(ceil(attacker.getCurrentSpeed() * item->getSpeed())); //AFFICHER ET VERIFIER***********************
	}
	if (item->getSpeed() < 0)
	{
		defender.setCurrentSpeed(ceil(defender.getCurrentSpeed() * item->getSpeed())); //AFFICHER ET VERIFIER***********************
	}
}

void Battle::AITurn()
{
	bool MoveUsed = false;
	double curHPpercent = AIPlaying->getCurrentHP() / AIPlaying->getHP();

	if (AIPlaying->getCurrentSpeed() >= PokemonPlaying->getCurrentSpeed())
	{
		if (isPokemonEffective(AIPlaying, PokemonPlaying) > 1)
		{
			AIMove(AIPlaying, PokemonPlaying);
		}
		else
		{
			if (!ShouldAISwitch(AIPlaying))
			{
				if (HasHealingMove(AIPlaying) && curHPpercent < 0.5)
				{
					AIHeal(AIPlaying);
				}
				else
				{
					AIMove(AIPlaying, PokemonPlaying);
				}
			}
		}
	}
	else
	{
		if (isPokemonEffective(PokemonPlaying, AIPlaying) > 1)
		{
			if (!ShouldAISwitch(AIPlaying))
			{
				if (HasHealingMove(AIPlaying) && curHPpercent < 0.5)
				{
					AIHeal(AIPlaying);
				}
				else
				{
					AIMove(AIPlaying, PokemonPlaying);
				}
			}
		}
		else
		{
			if (isPokemonEffective(AIPlaying, PokemonPlaying) > 1)
			{
				AIMove(AIPlaying, PokemonPlaying);
			}
			else
			{
				if (!ShouldAISwitch(AIPlaying))
				{
					if (HasHealingMove(AIPlaying) && curHPpercent < 0.5)
					{
						AIHeal(AIPlaying);
					}
					else
					{
						AIMove(AIPlaying, PokemonPlaying);
					}
				}
			}
		}
	}
}

bool Battle::AIMove(Pokemon *ai, Pokemon *pkmn)
{
   if (isPokemonEffective(AIPlaying, PokemonPlaying) < 1 && HasStatMove(AIPlaying))
   {      
      return AIStatMove();
   }
   else
   {	   
      return AIDamagingMove();
   }
}

double Battle::HasHealingMove(Pokemon * ai)
{
	if (ai->getMove1()->getHealing() > 0)
	{
		return ai->getMove1()->getHealing();
	}
	if (ai->getMove2()->getHealing() > 0)
	{
		return ai->getMove2()->getHealing();
	}
	if (ai->getMove3()->getHealing() > 0)
	{
		return ai->getMove3()->getHealing();
	}
	if (ai->getMove4()->getHealing() > 0)
	{
		return ai->getMove4()->getHealing();
	}
}

bool Battle::AIHeal(Pokemon * ai)
{
	double m1heal = 0, m2heal = 0, m3heal = 0, m4heal = 0, maxheal = 0;
	if (ai->getMove1())
	{
		m1heal = ai->getMove1()->getHealing();
	}
	if (ai->getMove2())
	{
		m2heal = ai->getMove2()->getHealing();
	}
	if (ai->getMove3())
	{
		m3heal = ai->getMove3()->getHealing();
	}
	if (ai->getMove4())
	{
		m4heal = ai->getMove4()->getHealing();
	}

	if (m1heal > m2heal && m1heal > m3heal && m1heal > m4heal)
	{
		ai->setCurrentHP(ceil(ai->getCurrentHP() * ai->getMove1()->getHealing()));
		return true;
	}
	else if (m2heal > m1heal && m2heal > m3heal && m2heal > m4heal)
	{
		ai->setCurrentHP(ceil(ai->getCurrentHP() * ai->getMove2()->getHealing()));
	}
	else if (m3heal > m1heal && m3heal > m2heal && m3heal > m4heal)
	{
		ai->setCurrentHP(ceil(ai->getCurrentHP() * ai->getMove3()->getHealing()));
		return true;
	}
	else if (m4heal > m1heal && m4heal > m2heal && m4heal > m3heal)
	{
		ai->setCurrentHP(ceil(ai->getCurrentHP() * ai->getMove4()->getHealing()));
		return true;
	}
	return false;
}

double Battle::isPokemonEffective(Pokemon * attacker, Pokemon * defender)
{
	double maxdamage = 0;
	if (attacker->getMove1())
	{
		if (IsEffective(attacker->getMove1(), defender) * isStab(attacker->getMove1(), defender) > 1)
			return IsEffective(attacker->getMove1(), defender) * isStab(attacker->getMove1(), defender);
	}
	if (attacker->getMove2())
	{
		if (IsEffective(attacker->getMove2(), defender) * isStab(attacker->getMove2(), defender) > 1)
			return IsEffective(attacker->getMove2(), defender) * isStab(attacker->getMove2(), defender);
	}
	if (attacker->getMove3())
	{
		if (IsEffective(attacker->getMove3(), defender) * isStab(attacker->getMove3(), defender) > 1)
			return IsEffective(attacker->getMove3(), defender) * isStab(attacker->getMove3(), defender);
	}
	if (attacker->getMove4())
	{
		if (IsEffective(attacker->getMove4(), defender) * isStab(attacker->getMove4(), defender) > 1)
			return IsEffective(attacker->getMove4(), defender) * isStab(attacker->getMove4(), defender);
	}
	return 1;
}

bool Battle::ShouldAISwitch(Pokemon *ai)
{
	double one = 0, two = 0, three = 0;
	if (AIPokemon1 != AIPlaying)
	{
		one = isPokemonEffective(AIPokemon1, PokemonPlaying);
	}
	if (AIPokemon2 != AIPlaying)
	{
		two = isPokemonEffective(AIPokemon2, PokemonPlaying);
	}
	if (AIPokemon3 != AIPlaying)
	{
		three = isPokemonEffective(AIPokemon3, PokemonPlaying);
	}

	if (one > two && one > three)
	{
		return AISwitchPokemon(1);
	}
	if (two > one && two > three)
	{
		return AISwitchPokemon(2);
	}
	if (three > one && three > two)
	{
		return AISwitchPokemon(3);
	}
	return false;
}

bool Battle::AISwitchPokemon(int choice)
{
	switch (choice)
	{
		case 1: AIPlaying = AIPokemon1; return true;
		case 2: AIPlaying = AIPokemon2; return true;
		case 3: AIPlaying = AIPokemon3; return true;
		default: return false;
	}
}

bool Battle::AIDamagingMove()
{
	int m1damage = 0, m2damage = 0, m3damage = 0, m4damage = 0;
	if (AIPlaying->getMove1())
	{
		m1damage = ceil(damage(AIPlaying->getMove1(), AIPlaying, PokemonPlaying));
	}
	if (AIPlaying->getMove2())
	{
		m2damage = ceil(damage(AIPlaying->getMove2(), AIPlaying, PokemonPlaying));
	}
	if (AIPlaying->getMove3())
	{
		m3damage = ceil(damage(AIPlaying->getMove3(), AIPlaying, PokemonPlaying));
	}
	if (AIPlaying->getMove4())
	{
		m4damage = ceil(damage(AIPlaying->getMove4(), AIPlaying, PokemonPlaying));
	}

	if (m1damage > m2damage && m1damage > m3damage && m1damage > m4damage)
	{
		useMove(AIPlaying->getMove1(), AIPlaying, PokemonPlaying);
		return true;
	}
	else if (m2damage > m1damage && m2damage > m3damage && m2damage > m4damage)
	{
		useMove(AIPlaying->getMove2(), AIPlaying, PokemonPlaying);
		return true;
	}
	else if (m3damage > m1damage && m3damage > m2damage && m3damage > m4damage)
	{
		useMove(AIPlaying->getMove3(), AIPlaying, PokemonPlaying);
		return true;
	}
	else if (m4damage > m1damage && m4damage > m2damage && m4damage > m3damage)
	{
		useMove(AIPlaying->getMove4(), AIPlaying, PokemonPlaying);
		return true;
	}
	else
	{
      /*********************JE DOIS UTILISER UNE ATTAQUE AU HASARD******************/
		return false;
	}
}

bool Battle::isStatMove(Move * move)
{
   if (move)
   {
      if (move->getAttack() > 1 || move->getDefense() > 1 || move->getSpeed() > 1)
      {
         return true;
      }
   }
   return false;
}

bool Battle::HasStatMove(Pokemon * pkmn)
{
   if (isStatMove(pkmn->getMove1()))
   {
      return true;
   }
   if (isStatMove(pkmn->getMove2()))
   {
      return true;
   }
   if (isStatMove(pkmn->getMove3()))
   {
      return true;
   }
   if (isStatMove(pkmn->getMove4()))
   {
      return true;
   }
   return false;
}

bool Battle::AIStatMove()
{   
   bool MoveUsed = false,
      Move1 = false,
      Move2 = false,
      Move3 = false,
      Move4 = false;

   Move1 = isStatMove(AIPlaying->getMove1());
   Move2 = isStatMove(AIPlaying->getMove2());
   Move3 = isStatMove(AIPlaying->getMove3());
   Move4 = isStatMove(AIPlaying->getMove4());

   vector<int> moves;
   if (Move1)
   {
      moves.push_back(1);
   }
   if (Move2)
   {
      moves.push_back(2);
   }
   if (Move3)
   {
      moves.push_back(3);
   }
   if (Move4)
   {
      moves.push_back(4);
   }

   int random = rand() % moves.size();

   switch (moves.at(random))
   {
   case 1:
      useMove(AIPlaying->getMove1(), AIPlaying, PokemonPlaying);
      return true;
   case 2:
      useMove(AIPlaying->getMove2(), AIPlaying, PokemonPlaying);
      return true;
   case 3:
      useMove(AIPlaying->getMove3(), AIPlaying, PokemonPlaying);
      return true;
   case 4:
      useMove(AIPlaying->getMove4(), AIPlaying, PokemonPlaying);
      return true;
   }
   return false;
}