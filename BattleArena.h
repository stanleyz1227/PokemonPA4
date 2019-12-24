#ifndef BATTLEARENA_H
#define BATTLEARENA_H
#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "Building.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include <string>

enum BattleArenaStates {
	RIVALS_AVAILABLE = 0,
	NO_RIVALS_AVAILABLE = 1
};


class BattleArena: public Building
{
	private:
		unsigned int max_num_rivals;
		unsigned int num_rivals_remaining;
		double dollar_cost_per_fight;
		unsigned int stamina_cost_per_fight;
		unsigned int pokemon_count;

	public:
		BattleArena();
		BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc);
		unsigned int GetNumRivalsRemaining();
		bool HasEnoughRivals();
		double GetDollarCost();
		unsigned int GetStaminaCost();
		bool IsAbleToFight( double budget, unsigned int stamina);
		bool Update();
		bool IsBeaten();
		void ShowStatus();
		void AddPokemon();
		void RemoveOnePokemon();


};

#endif