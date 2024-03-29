#pragma once

#include<iostream>
#include<iomanip>
#include<string>

#include"Inventory.h"


class Character
{
public:
	Character();
	virtual ~Character();


	void initialize(std::string name);
	void printStats() const;
	void levelUp();
	std::string getAsString()const;
	void updateStats();

	inline const double& getX() const { return this->xPos; }
	inline const double& getY() const { return this->yPos; }

	inline const std::string& getName() const { return this->name; }
	inline const int getLevel() const { return this->level; }
	inline const int getExp() const { return this->exp; }
	inline const int getExpNext() const { return this->expNext; }
	inline const int getHp() const { return this->hp; }
	inline const int getHpMax() const { return this->hpMax; }
	inline const int getStamina() const { return this->stamina; }
	inline const int getStaminaMax() const { return this->staminaMax; }
	inline const int getDamageMin() const { return this->damageMin; }
	inline const int getDamageMax() const { return this->damageMax; }
	inline const int getDefense() const { return this->defence; }
	inline const int getLuck() const { return this->luck; }

	inline void gainExp(const int& exp) { this->exp += exp; }
private:
	double xPos;
	double yPos;
	int nrOfEvents;

	Inventory inventory;
	Weapon weapon;
	Armor  armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;


	std::string name;
	int level;
	int exp;
	int expNext;
	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	int defence;
	int luck;

	int statPoints;
	int skillPoints;

	int strength;
	int constitution;
	int dexterity;
	int intelligence;
};

