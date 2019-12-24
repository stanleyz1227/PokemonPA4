#include "Rival.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

Rival::Rival(string name, double speed, double hp, double phys_dmg,double magic_dmg, double def, int id, Point2D in_loc): GameObject(in_loc, id, 'R')
{
	this->name = name;
	this->speed = speed;
	health = hp;
	this->physical_damage = phys_dmg;
	this->magical_damage = magic_dmg;
	this->defense = def;
	state = ALIVE_RIVAL;
}

void Rival::TakeHit(double physical_damage, double magical_damage, double defense)
{
	//random integer 0 represents physical
	//random integer 1 represents magical
	if ((rand() % 2) == 0)
	{
	    double damage = (100.0 - defense) / 100 * physical_damage;
	    this->health -= damage;
	} 
	else
	{
	    double damage = (100.0 - defense) / 100 * magical_damage;
	    this->health -= damage;
	}
}


double Rival::get_phys_dmg()
{
	return this->physical_damage;
}

double Rival::get_magic_dmg()
{
	return this->magical_damage;
}

double Rival::get_defense()
{
	return this->defense;
}

double Rival::get_health()
{
	return this->health;
}

bool Rival::Update()
{
	switch (state)
	{
		case ALIVE_RIVAL:
			return false;
		case FAINTED_RIVAL:
			return true;
	}
}

void Rival::ShowStatus()
{
	cout << name << " status: ";
	GameObject::ShowStatus();
	switch (state)
	{
		case ALIVE_RIVAL:
			cout << " alive " << endl;
			break;
		case FAINTED_RIVAL:
			cout << " dead, RIP..." << endl;
			break;
		default:
			break;
	}
	//print stats
	cout << "\tHealth:  " << this->health << endl;
    cout << "\tPhysical Damage:  " << this->physical_damage << endl;
    cout << "\tMagical Damage:  " << this->magical_damage << endl;
    cout << "\tDefense:  " << this->defense << endl;
}

bool Rival::IsAlive()
{
	if (this->health > 0)
	{
		state = ALIVE_RIVAL;
		return true;
	}
	else
	{
		state = FAINTED_RIVAL;
		return false;
	}
}

string Rival::GetName()
{
	return name;
}

bool Rival::ShouldBeVisible()
{
	return true;
}