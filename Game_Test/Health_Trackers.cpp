#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int itemUsed1(string weapon, int health)
{
	int playerHealth = health;
	srand(static_cast<unsigned int>(time(0)));
	if(weapon == "Healing Potion(30)")
	{
		for(int i = 0; i<30; i++)
		{
			if(playerHealth < 100)
			{
				playerHealth++;
			}
		}
	}
	else if(weapon == "Healing Potion(50)")
	{
		for(int i = 0; i<50; i++)
		{
			if(playerHealth < 100)
			{
				playerHealth++;
			}
		}
	}
	else
	{
		playerHealth = health;
	}
	return playerHealth;
}

int damageMilitiaSkeleton()
{
	int damage = 0;
	srand(static_cast<unsigned int>(time(0)));
	damage = (rand() % 6) + 5;
	return damage;
}

int militiaSkeletonHealth(string weapon, int health)
{
	int militiaSkeletonHealth = health;
	srand(static_cast<unsigned int>(time(0)));
	if(weapon == "Bamboo Stick")
	{
		militiaSkeletonHealth = militiaSkeletonHealth - ((rand() % 50) + 25);
	}
	else if(weapon == "Qiang Spear")
	{
		militiaSkeletonHealth = militiaSkeletonHealth - ((rand() % 50) + 30);
	}
	else if(weapon == "Jian Sword")
	{
		militiaSkeletonHealth = militiaSkeletonHealth - ((rand() % 40) + 20);
	}
	else if(weapon == "Nu Crossbow")
	{
		militiaSkeletonHealth = militiaSkeletonHealth - ((rand() % 50) + 35);
	}
	return militiaSkeletonHealth;
}

int damageStatueWarrior()
{
	int damage = 0;
	srand(static_cast<unsigned int>(time(0)));
	damage = (rand() % 20) + 20;
	return damage;
}

int statueWarriorHealth(string weapon, int health)
{
	int statueHealth = health;
	srand(static_cast<unsigned int>(time(0)));
	if(weapon == "Bamboo Stick")
	{
		statueHealth = statueHealth - ((rand() % 26) + 20);
	}
	else if(weapon == "Qiang Spear")
	{
		statueHealth = statueHealth - ((rand() % 26) + 20);
	}
	else if(weapon == "Jian Sword")
	{
		statueHealth = statueHealth - ((rand() % 16) + 10);
	}
	else if(weapon == "Nu Crossbow")
	{
		statueHealth = statueHealth - ((rand() % 11) + 5);
	}
	return statueHealth;
}