#include "BattleArena.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

BattleArena::BattleArena(): Building('A', 0, Point2D(0,0))
{
	pokemon_count = 0;
	max_num_rivals = 3;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = 4;
	stamina_cost_per_fight = 3;
	state = RIVALS_AVAILABLE;
	cout << "BattleArena default constructed. " << endl;
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc): Building ('A', in_Id, in_loc)
{
	pokemon_count = 0;
	max_num_rivals = max_rivals;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = dollar_cost;
	stamina_cost_per_fight = stamina_cost;
	state = RIVALS_AVAILABLE;
	cout << "BattleArena constructed. " << endl;
}

unsigned int BattleArena::GetNumRivalsRemaining()
{
	return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals()
{
	if (num_rivals_remaining >= 1)
		return true;
	else
		return false;
}

double BattleArena::GetDollarCost()
{
	return dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost()
{
	return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight( double budget, unsigned int stamina)
{
	if (budget >= dollar_cost_per_fight && stamina >= stamina_cost_per_fight)
		return true;
	else
		return false;
}

bool BattleArena::Update()
{
	if (HasEnoughRivals() == false && !IsBeaten())
	{
		display_code = 'a';
        cout << display_code << GetId() << " has been beaten" << endl;
		state = NO_RIVALS_AVAILABLE;
		return true;
	}
	else
		return false;
}

bool BattleArena::IsBeaten()
{
	if (num_rivals_remaining == 0)
		return true;
	else
		return false;
}

void BattleArena::ShowStatus()
{
	GameObject::ShowStatus();
	cout << pokemon_count << " is in this building" << endl;
	cout << "Stamina cost per fight: " << stamina_cost_per_fight << endl;
	cout << "Pokemon dollar cost per fight: " << dollar_cost_per_fight << endl;
	cout << num_rivals_remaining << " rival(s) remaining for this arena " << endl;

}

void BattleArena::AddPokemon()
{
	pokemon_count++;
}

void BattleArena::RemoveOnePokemon()
{
	pokemon_count--;
}
