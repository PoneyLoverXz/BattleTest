#include "Pokemon.h"
#include "Item.h"
#include "Battle.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//MÉTHODES
Pokemon InstancierPokemon(int id);
PokeType assignerType(string type);

//Variables
Move Tackle = Move(1, "Tackle", NORMAL, 40, 0, 0, 0, 0, 10, "Pokemon tackles enemy");
Move RazorLeaf = Move(2, "Razor Leaf", GRASS, 40, 0, 0, 0, 0, 10, "RAZOR LEAF THE SHITSSSS");
Move SwordDance = Move(3, "Swords Dance", NORMAL, 0, 0, 1.6, 0, 0, 10, "Raises user's attack");
Move WaterGun = Move(4, "Water Gun", WATER, 40, 0, 0, 0, 0, 10, "BLOUPBLOUP");
Move Ember = Move(5, "Ember", FIRE, 40, 0, 0, 0, 0, 10, "FEUUUU");
Move Recover = Move(6, "Recover", NORMAL, 0, 0.4, 0, 0, 0, 10, "Recovers 40 hp");
string MonsterTxt = "../Monsters.txt";
ifstream Fichier(MonsterTxt);


int main()
{
	//CRÉER UN MOVE
	cout << "***MOVE***" << endl;
	cout << "ID: " << Tackle.getMoveID() << ", Name: " << Tackle.getName() << ", Type: " << Tackle.getPokeType()
		<< "Damage: " << Tackle.getDamage() << ", Description: " << Tackle.getDescription() << endl;

	//INSTANCIER UN POKEMON	
	Pokemon Bulbasaur;
	Pokemon Squirtle;
	Pokemon Charmander;
	if (Fichier)
	{
		Bulbasaur = Pokemon(1, "Bulbasaur", 5, GRASS, 60, 60, 60, 50, 0, "yeah", &Tackle, &RazorLeaf, &Recover);
		Squirtle = Pokemon(2, "Squirtle", 5, WATER, 70, 50, 70, 51, 0, "yeah", &Tackle, &WaterGun, &Recover);
		Charmander = Pokemon(3, "Charmander", 5, FIRE, 50, 70, 50, 60, 0, "yeah", &Tackle, &Ember, &Recover);
	}
	else
	{
		cout << "IMPOSSIBLE DE LIRE LE FICHIER \"" << MonsterTxt << "\"" << endl;
	}

	

	//INSTANCIER UN ITEM
	Item potion = Item(1, "Potion", 0, 0.4, 0, 0, 0, 1, "Heals Pokémon for 20HP");
	Item powerUp = Item(2, "PowerUp", 0, 0, 1.3, 0, 0, 1, "Makes Pokémon's attack better");

	//Instancier le joueur
	Pokemon PlayerPokemon1 = Bulbasaur;
	Pokemon PlayerPokemon2 = Squirtle;
	Pokemon PlayerPokemon3 = Charmander;

	Pokemon AIPokemon1 = Bulbasaur;
	Pokemon AIPokemon2 = Bulbasaur;
	Pokemon AIPokemon3 = Bulbasaur;

	
	Battle battle = Battle(&PlayerPokemon1, &PlayerPokemon2, &PlayerPokemon3, &AIPokemon1, &AIPokemon2, &AIPokemon3);

	battle.StartBattle(&PlayerPokemon1, &AIPokemon2);
	battle.useMove(PlayerPokemon1.getMove1(), &PlayerPokemon1, &AIPokemon1);
	battle.useMove(PlayerPokemon1.getMove1(), &PlayerPokemon1, &AIPokemon1);
	battle.useMove(PlayerPokemon1.getMove1(), &PlayerPokemon1, &AIPokemon1);
	battle.useMove(PlayerPokemon1.getMove1(), &PlayerPokemon1, &AIPokemon1);

	battle.AITurn();
	battle.AITurn();
	battle.PokemonPlaying = &PlayerPokemon2;
	battle.AITurn();

}

Pokemon InstancierPokemon(int id)
{
	Pokemon pkmn;
	//Variable qui dit que le pokemon est trouvé
	bool Trouve = false;

	// Rechercher les informations dans le fichier
	while (!Trouve || !Fichier.eof())
	{
		// Vérifier si c'est le bon Pokémon
		string IdLecture;
		getline(Fichier, IdLecture, '+');

		if (to_string(id) == IdLecture.c_str())
		{
			//Le pokemon est trouvé
			Trouve = true;

			// Mettre les stats dans l'array
			string stat = IdLecture;
			getline(Fichier, stat, '+');				//Nom
			string nom = stat;
			getline(Fichier, stat, '+');				//Type
			PokeType poketype = assignerType(stat);
			getline(Fichier, stat, '+');				//HP
			int hp = atoi(stat.c_str());
			getline(Fichier, stat, '+');				//Attaque
			int att = atoi(stat.c_str());
			getline(Fichier, stat, '+');				//Defense
			int def = atoi(stat.c_str());
			getline(Fichier, stat, '+');				//Vitesse
			int spd = atoi(stat.c_str());
			getline(Fichier, stat, '+');				//Mana
			int mana = atoi(stat.c_str());
			getline(Fichier, stat, '+');				//Move Defaut
			/* IL FAUT POGNER LE ID DU MOVE */
			getline(Fichier, stat, '+');				//Prix
			getline(Fichier, stat, '\n');				// Image
			string sprite = stat;

			pkmn = Pokemon(id, nom, 5, poketype, hp, att, def, spd, mana, sprite, &RazorLeaf,&Recover,&WaterGun,&Ember);
			return pkmn;
		}
		else
		{
			getline(Fichier, IdLecture, '\n');
		}
	}
	return pkmn;
}

PokeType assignerType(string type)
{
	if (type == "NORMAL")
		return NORMAL;
	else if (type == "FIGHT")
		return FIGHT;
	else if (type == "FLYING")
		return FLYING;
	else if (type == "POISON")
		return POISON;
	else if (type == "GROUND")
		return GROUND;
	else if (type == "ROCK")
		return ROCK;
	else if (type == "BUG")
		return BUG;
	else if (type == "GHOST")
		return GHOST;
	else if (type == "STEEL")
		return STEEL;
	else if (type == "FIRE")
		return FIRE;
	else if (type == "WATER")
		return WATER;
	else if (type == "GRASS")
		return GRASS;
	else if (type == "ELECTRIC")
		return ELECTRIC;
	else if (type == "PSYCHIC")
		return PSYCHIC;
	else if (type == "ICE")
		return ICE;
	else if (type == "DRAGON")
		return DRAGON;
	else if (type == "DARK")
		return DARK;
	else if (type == "FAIRY")
		return FAIRY;
	else
		return NORMAL;
}