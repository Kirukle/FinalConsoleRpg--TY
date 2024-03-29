#include "Character.h"


Character::Character()
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	 this->name = "NONE";
	 this->level = 1;
	 this->exp = 0;
	 this->expNext = 0;

	 this->strength = 0;
	 this->constitution = 0;
	 this->dexterity = 0;
	 this->intelligence = 0;

	 this->hp = 0;
	 this->hpMax = 0;
	 this->stamina = 0;
	 this->staminaMax = 0;
	 this->damageMin = 0;
	 this->damageMax = 0;
	 this->defence = 0;
	 this->luck = 0;

	 this->statPoints = 0;
	 this->skillPoints = 0;
}


Character::~Character()
{

}

void Character::initialize(std::string name)
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = 1;

	this->strength = 5;
	this->constitution = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	

	this->hpMax = (this->constitution * 2) + (this->strength/2);
	this->hp = this->hpMax;
	this->staminaMax = this->constitution + (this->strength / 2) + (this->dexterity);
	this->stamina = this->staminaMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->defence = this->dexterity + (this->intelligence/2);
	this->luck = this->intelligence;


	this-> statPoints = 0;
	this-> skillPoints = 0;
}

void Character::printStats() const
{
	std::cout << "= Character Sheet =" << std::endl;
	std::cout << "= Name: " << this->name << std::endl;
	std::cout << "= Level: " << this->level << std::endl;
	std::cout << "= Exp: " << this->exp << std::endl;
	std::cout << "= Exp to Level Up: " << this->expNext << std::endl;
	std::cout << std::endl;
	std::cout << "= Strength: " << this->strength << std::endl;
	std::cout << "= Constitution: " << this->constitution << std::endl;
	std::cout << "= Dexterity: " << this->dexterity << std::endl;
	std::cout << "= Intelligence: " << this->intelligence << std::endl;
	std::cout << std::endl;
	std::cout << "= HP: " << this->hp << " / " << this->hpMax << std::endl;
	std::cout << "= Stamina: " << this->stamina << " / " << this->staminaMax << std::endl;
	std::cout << "= Damage: " << this->damageMin << " - " << this->damageMax << std::endl;
	std::cout << "= Defense: " << this->defence << std::endl;
	std::cout << "= Luck: " << this->luck << std::endl;
	std::cout << std::endl;
}

void Character::updateStats()
{
	this->hpMax = (this->constitution * 2) + (this->strength / 2);
	this->staminaMax = this->constitution + (this->strength / 2) + (this->dexterity);
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->defence = this->dexterity + (this->intelligence / 2);
	this->luck = this->intelligence;
}

void Character::levelUp()
{
	if (this->exp >= this->expNext)
	{
		this->exp -= this->expNext;
		this->level++;
		this->expNext = (level * 20);

		this->statPoints++;
		this->skillPoints++;

		std::cout << "YOU ARE NOW LEVEL " << this->level << "!" << "\n\n";

		int i = rand() % this->nrOfEvents;

		
			this->constitution++;
			this->strength++;
			this->dexterity++;
			this->intelligence++;
			this->luck++;
			this->luck++;
			
	}
	else
	{
		std::cout << "NOT ENOUGH EXP!" << "\n\n";
	}
}

std::string Character::getAsString() const
{
	return std::to_string(xPos) + " " +
		std::to_string(yPos) + " " +
		name + " " +
		std::to_string(level) + " " +
		std::to_string(exp) + " " +
		std::to_string(strength) + " " +
		std::to_string(constitution) + " " +
		std::to_string(dexterity) + " " +
		std::to_string(intelligence) + " " +
		std::to_string(hp) + " " +
		std::to_string(stamina) + " " +
		std::to_string(statPoints) + " " +
		std::to_string(skillPoints) + " ";
}