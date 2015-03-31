#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int smallRandomGenerator(); //Random number generator from 1 - 3
int bigRandomGenerator();   //Random number generator from 1 - 6

int itemUsed1(string weapon, int health); //Method used to use potions (does not use weapons)

int damageMilitiaSkeleton(); //Random damage generator based on weapon used
int militiaSkeletonHealth(string weapon, int health); //Returns health of militiaSkeleton

int damageStatueWarrior(); //Random damage generator based on weapon used for statueBoss
int statueWarriorHealth(string weapon, int health); //Returns health of statueBoss

void textMilitiaSkeleton(); //Displays message showing battle

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int health = 100;
	int choice = 0;

	int militiaSkelHealth = 100;	//MilitiaSkeleton health tracker (used for loops when fighting)
	int statueBossHealth = 100;		//StatueWarrior health tracker (used for loop when fighting)

	string startGame;
	string endGame;
	string answer;
	string answerCamp;
	string answerChest;
	string answerLever;
	string answerHallOfRooms;
	string answerPath;
	string answerPuzzle;

	int answerWeapon = 0;
	int roomCycle = 5;
	int keyHoles = 4;
	int puzzlePieceChoice = 0;  //The choice of which puzzle piece player wants to discard

	vector<string> inventory;

	vector<string> chest1;
	chest1.push_back("Qiang Spear");
	chest1.push_back("Jian Sword");
	chest1.push_back("Nu Crossbow");

	vector<string> chest2;
	chest2.push_back("Healing Potion(30)");

	vector<string> chest3;
	chest3.push_back("Healing Potion(50)");

	vector<string> puzzleInventory;  

	cout<<"\n\n           ''''''''''''''''''                                       "<<endl;
	cout<<"         ''''''''''''''''''''''              ________________       "<<endl;
	cout<<"        ''''''''''''''''''''''''            (______    ______)      "<<endl;
	cout<<"       ''''''''''''''''''''''''''                  |  |              "<<endl;
	cout<<"      ''''''''''''''''''''''''''''            _____|  |_____        "<<endl;
	cout<<"     ''''''''''''''''''''''''''''''          (______   _____)       "<<endl;
	cout<<"    '''''''''''''       ''''''''''''               |  |              "<<endl;
	cout<<"    ''''''''''''          ''''''''''         ______|  |______      "<<endl;
	cout<<"    '''''''''' _____  _____ ''''''''        (________________)     "<<endl;
	cout<<"     '''''''''              '''''''          __      __             "<<endl;
	cout<<"      '''''''        ^      ''''''          /  )____(  )_______     "<<endl;
	cout<<"       '''''''\\           / '''''          /  ______    _______)   "<<endl;
	cout<<"        '''''  \\   ___   /  ''''          /__/______|  |______     "<<endl;
	cout<<"         ''''   \\       /   '''              (___          ___)    "<<endl;
	cout<<"          '''    \\_____/    ''                  /  /|  |\\  \\     "<<endl;
	cout<<"           ''               ''                 /  / |  | \\  \\     "<<endl;
	cout<<"                                              /__/  |__|  \\__\\    "<<endl;

	cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~ CHU: DAWN OF A NEW DYNASTY ~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	cout<<"1) If you wish to end the game, just simply type in 'quit' when"<<endl;
	cout<<"   prompted to answer any question except when battling."<<endl;
	cout<<"2) Game is best enjoyed in large screen view."<<endl;
	cout<<"3) Type in 'start' when you're ready to start the game.\n\nInput: ";
	cin>>startGame;
	while(startGame != "start" && startGame != "quit")
	{
		cout<<"Type in start when you're ready to start the game.\n\nInput: ";
		cin>>startGame;
	}
	if(startGame == "quit")
	{
		choice = 6;
		health = 0;
	}

	switch(choice)
	{
	case 0:
		cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~ PROLOGUE: A NEW BEGINNING! ~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
		cout<<"The year is 1368. You, Wan, are the last remaining descendant"<<endl;
		cout<<"of the legendary Chu warriors. It is time for you to"<<endl;
		cout<<"embark on your quest to redeem your family name and bring honor back"<<endl;
		cout<<"to your country by slaying the mighty Huns!"<<endl;
		cout<<"\nType in ready when you're ready.\n\nInput: ";
		cin>>answer;
		while(answer != "ready" && answer != "quit")
		{
			cout<<"Type in ready when you're ready.\n\nInput: ";
			cin>>answer;
		}
		if(answer == "quit")
		{
			health = 0;
			break;
		}
	case 1:
		cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~ CHAPTER 1: GEARING UP! ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<"\nYou head to the armory to choose your weapon."<<endl;
		cout<<"As you search the armory, you trip over something hard near the haystack."<<endl;
		cout<<"You clear the hay away to find a dusty old bamboo stick."<<endl;
		cout<<"It seems to be imbued with some sort of mystical energy."<<endl;
		cout<<"\n\n   **    ________________   ** "<<endl;
		cout<<"        (__(__(__(__(__(_)   "<<endl;
		cout<<"                   "<<"\n\n";

		cout<<"You take the stick and head out on your quest.\n\n";
		inventory.push_back("Bamboo Stick");
		cout<<"Your items are now:"<<endl;
		for(int i = 0; i<inventory.size(); i++)
		{
			cout<<"[ "<<inventory[i]<<" ]"<<endl;
		}
		cout<<"\nType in ready when you're ready.\nInput: ";
		cin>>answer;
		while(answer != "ready" && answer != "quit")
		{
			cout<<"\nType in ready when you're ready.\nInput: ";
			cin>>answer;
		}
		if(answer == "quit")
		{
			health = 0;
			break;
		}
		choice = 2;
	case 2:
		cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~ CHAPTER 2: THE ROAD LESS TRAVELED! ~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<"The road ahead is one better to not be taken but you have a destiny to fulfill  so you head on. "<<endl;
		textMilitiaSkeleton();
		cout<<"Your health is: "<<health<<endl;
		while(militiaSkelHealth > 0)
		{
			cout<<"\nYour items are:"<<endl;			//Displays items in inventory to use in battle
			for(int i = 0; i<inventory.size(); i++)
			{
				cout<<i<<". "<<inventory[i]<<endl;
			}
			cout<<"\nType in the index number of the weapon you wish to use: ";
			cin>>answerWeapon;
			while(answerWeapon > (inventory.size() - 1))	//While index number is invalid, repeats question
			{
				cout<<"\nType in the index number of the weapon you wish to use: ";
				cin>>answerWeapon;
			}
			cout<<"You choose to use your "<<inventory[answerWeapon]<<"."<<endl;
			if(bigRandomGenerator() != 4)				//Uses random number generator to attack militia skeleton
			{
				cout<<"You attack the Militia Skeletons and deal "<<(militiaSkelHealth - (militiaSkeletonHealth(inventory[answerWeapon], militiaSkelHealth)))<<" to them."<<endl;
				militiaSkelHealth = militiaSkeletonHealth(inventory[answerWeapon], militiaSkelHealth);		//Updates health of militia skeleton after they've taken damage
				if(militiaSkelHealth > 0)
				{
					cout<<"The Militia Skeletons have "<<militiaSkelHealth<<" health left."<<endl;		//Displays Militia Skeleton current health
				}
			}
			//
			else
			{
				cout<<"You attack the Militia Skeletons but miss!!!"<<endl;		//If random number generator = 4, your attack misses and militia skeletons take no damage
			}
			if(militiaSkelHealth <= 0)			//Ends loop if militia skeletons have no health left
			{
				break;
			}
			if(bigRandomGenerator() != 3)		//Uses random number generator to attack player
			{
				cout<<"\nThe Militia Skeletons attack and deal "<<damageMilitiaSkeleton()<<" to you."<<endl;
				health = health - damageMilitiaSkeleton();
				if(health > 0)
				{
					cout<<"Your health is: "<<health<<endl;
				}
			}
			else
			{
				cout<<"\nThe Militia Skeletons attack but miss!!!"<<endl;
			}
			if(health <= 0)
			{
				cout<<"You fought valiantly but have been slain in battle."<<endl;
				break;
			}
		}
		if(health <= 0)					//If player health reaches 0 or lower, game ends
		{
			break;
		}
		if(militiaSkelHealth <= 0 && health > 0)			//Displays victory message if player is alive and militia
		{													//skeletons are dead
			cout<<"\nYou have defeated the Militia Skeletons!!!"<<endl;
			cout<<"Your health is: "<<health<<".\n\n";
		}

		cout<<"\nType in ready when you're ready.\nInput: ";
		cin>>answer;
		while(answer != "ready" && answer != "quit")
		{
			cout<<"\nType in ready when you're ready.\nInput: ";
			cin>>answer;
		}
		if(answer == "quit")
		{
			health = 0;
			break;
		}
		choice = 3;
	case 3:
		cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~ CHAPTER 3: SCARRED PLAGUELANDS! ~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<"    ~  ~  ~              /        /   ~  ~  ~     "<<endl;
		cout<<"   {  { }  }           /        /    {  { }  }    "<<endl;
		cout<<"  {  {   }  }        /        /     {  {   }  }   "<<endl;
		cout<<" {__{_____}__}     /        /      {__{_____}__}  "<<endl;
		cout<<"     |   |       /        /            |   |      "<<endl;
		cout<<"     |   |     /        /              |   |      "<<endl;
		cout<<"\n\nYour health: "<<health<<"\n\n";
		cout<<"You find a chest under a tree."<<endl;
		cout<<"Open the chest (yes/no)? ";
		cin>>answerChest;
		while(answerChest != "yes" && answerChest != "no" && answerChest != "quit")		//Prompts player to answer until valid answer is given
		{
			cout<<"\nInvalid answer!"<<endl;
			cout<<"Open the chest (yes/no)?  ";
			cin>>answerChest;
		}
		if(answerChest == "yes")				//If answer = yes, for loop shows inventory adding contents of chest
		{
			cout<<"\n\n";
			cout<<"             _____________ "<<endl;
			cout<<"           /             /)   "<<endl;
			cout<<"          /             //    "<<endl;
			cout<<"         /____________ //     "<<endl;
			cout<<"        /             /|      "<<endl;
			cout<<"       /_____________/ |   "<<endl;
			cout<<"       |             | |    "<<endl;
			cout<<" ______|             | |______"<<endl;
			cout<<"       |_____________|/     "<<endl;
			cout<<"\n\nThe chest contains:\n\n";
			for(int i = 0; i<chest1.size(); i++)
			{
				cout<<"[ "<<chest1[i]<<" ]"<<endl;
			}
			cout<<"\nYou put the item(s) in your inventory.";
			for(int i = 0; i<chest1.size(); i++)
			{
				inventory.push_back(chest1[i]);
			}
			cout<<"\nYour items are now:\n\n";
			for(int i = 0; i<inventory.size(); i++)
			{
				cout<<"[ "<<inventory[i]<<" ]"<<endl;
			}
		}
		else if(answerChest == "no")
		{
			cout<<"\nYou continue on your way and disregard the chest."<<endl;
		}
		else if(answerChest == "quit")
		{
			health = 0;
			break;
		}
		cout<<"\nYou see a castle in the far distance but the sun is setting."<<endl;
		cout<<"Do you wish to continue, or set up camp here and rest (rest/continue)? ";
		cin>>answerCamp;
		while(answerCamp != "rest" && answerCamp != "continue" && answerCamp != "quit")
		{
			cout<<"\nInvalid answer!"<<endl;
			cout<<"Do you wish to continue, or set up camp here and rest (rest/continue)? ";
			cin>>answerCamp;
		}
		if(answerCamp == "rest")
		{
			cout<<"\n\n";
			cout<<"          _______________    "<<endl;
			cout<<"         /              /\\  "<<endl;
			cout<<"        /              /  \\  "<<endl;
			cout<<"       /              /    \\ "<<endl;
			cout<<" _____/______________/______\\____"<<endl;
			if(smallRandomGenerator() == 2)
			{
				cout<<"\n\nYou set up camp and rest up."<<endl;		//Miltia skeleton code is the same at all times
				textMilitiaSkeleton();
				militiaSkelHealth = 100;
				cout<<"Your health is: "<<health<<endl;
				while(militiaSkelHealth > 0)
				{
					cout<<"\nYour items are:"<<endl;
					for(int i = 0; i<inventory.size(); i++)
					{
						cout<<i<<". "<<inventory[i]<<endl;
					}
					cout<<"\nType in the index number of the weapon you wish to use: ";
					cin>>answerWeapon;
					while(answerWeapon > (inventory.size() - 1))
					{
						cout<<"\nType in the index number of the weapon you wish to use: ";
						cin>>answerWeapon;
					}
					cout<<"You choose to use your "<<inventory[answerWeapon]<<"."<<endl;
					if(bigRandomGenerator() != 4)
					{
						cout<<"You attack the Militia Skeletons and deal "<<(militiaSkelHealth - (militiaSkeletonHealth(inventory[answerWeapon], militiaSkelHealth)))<<" to them."<<endl;
						militiaSkelHealth = militiaSkeletonHealth(inventory[answerWeapon], militiaSkelHealth);
						if(militiaSkelHealth > 0)
						{
							cout<<"The Militia Skeletons have "<<militiaSkelHealth<<" health left."<<endl;
						}
					}
					//
					else
					{
						cout<<"You attack the Militia Skeletons but miss!!!"<<endl;
					}
					if(militiaSkelHealth <= 0)
					{
						break;
					}
					if(bigRandomGenerator() != 3)
					{
						cout<<"\nThe Militia Skeletons attack and deal "<<damageMilitiaSkeleton()<<" to you."<<endl;
						health = health - damageMilitiaSkeleton();
						if(health > 0)
						{
							cout<<"Your health is: "<<health<<endl;
						}
					}
					else
					{
						cout<<"\nThe Militia Skeletons attack but miss!!!"<<endl;
					}
					if(health <= 0)
					{
						cout<<"You fought valiantly but have been slain in battle."<<endl;
						break;
					}
				}
				if(health <= 0)
				{
					break;
				}
				if(militiaSkelHealth <= 0 && health > 0)
				{
					cout<<"\nYou have defeated the Militia Skeletons!!!"<<endl;
					cout<<"Your health is: "<<health<<".\n\n";
				}
			}
			else
			{
				cout<<"\nYou set up camp and rest up."<<endl;
				cout<<"You heal back to full health."<<endl;
				health = 100;
			}
		}
		if(answerCamp == "continue")
		{
			cout<<"\nYou are not afraid of the dark and continue your journey."<<endl;
			if(smallRandomGenerator() == 3)
			{
				cout<<"You collapse from fatigue and faint."<<endl;
				cout<<"You are killed by militia skeleton passing by."<<endl;
				health = 0;
				cout<<"Your journey has ended short.\n\n";
				break;
			}
			else
			{
				cout<<"You feel weary but have finally made it to the castle."<<endl;
			}
		}
		if(answerCamp == "quit")
		{
			health = 0;
			break;
		}
		cout<<"\nType in ready when you're ready.\nInput: ";
		cin>>answer;
		while(answer != "ready" && answer != "quit")
		{
			cout<<"\nType in ready when you're ready.\nInput: ";
			cin>>answer;
		}
		if(answer == "quit")
		{
			health = 0;
			break;
		}

	case 4:
		cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CHAPTER 4: THE CASTLE! ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<"                      ______________________                "<<endl;
		cout<<"                     /______________________\\              "<<endl;
		cout<<"                    /________________________\\             "<<endl;
		cout<<"                   /__________________________\\            "<<endl;
		cout<<"                    |        ________        |             "<<endl;
		cout<<"                    |       |        |       |             "<<endl;
		cout<<"                 /\\ |      /\\        /\\      | /\\         "<<endl;
		cout<<"                /  \\|     /  \\______/  \\     |/  \\        "<<endl;
		cout<<"               /    \\    /    \\    /    \\    /    \\       "<<endl; 
		cout<<"              /______\\  /______\\  /______\\  /______\\      "<<endl;
		cout<<"              |  __  |  |  __  |  |  __  |  |  __  |      "<<endl;
		cout<<"          ____| |__| |__| |__| |__| |__| |__| |__| |___   "<<endl;
		cout<<"         |                                             |  "<<endl;
		cout<<"         |                                             |  "<<endl;
		cout<<"         |                _____________                |  "<<endl;
		cout<<"         |               |      |      |               |  "<<endl;
		cout<<"         |               |      |      |               |  "<<endl;
		cout<<"  _______|_______________|______|______|_______________|_______ "<<endl;
		cout<<"\nYour health: "<<health<<"\n\n";
		cout<<"The gates to the castle are sealed. You spot a lever by the corner."<<endl;
		cout<<"Pull the lever (yes/no)? ";
		cin>>answerLever;
		while(answerLever != "yes" && answerLever != "no" && answerLever != "quit")
		{
			cout<<"Pull the lever (yes/no)? ";
			cin>>answerLever;
		}
		if(answerLever == "yes")				//Uses random number generator to see what happens to player
		{
			if(bigRandomGenerator() != 3)		//If random number != 3, player lives and attempts to vault over to other side
			{
				cout<<"\nYou pull the lever and the floor beneath you creaks."<<endl;
				cout<<"You see a crack on the bottom of the gate big enough for you to go through."<<endl;
				cout<<"You attempt to vault over using your bamboo stick."<<endl;
				if(bigRandomGenerator() == 4)			//If random number equals 4, player doesn't vault over and dies
				{
					cout<<"\nYou attempt to vault over but fall short and plunge to your death."<<endl;
					cout<<"Your journey has ended short.\n\n";
					health = 0;
					break;
				}
				else
				{
					cout<<"\nYou vault across safely and fall through the hole."<<endl;
				}
			}
			else			//If random number equals 3, player falls to death
			{
				cout<<"\n\nYou pull the lever."<<endl;
				cout<<"\n\n        _________            ___________  "<<endl;
				cout<<"    __________    \\\\    ___________       "<<endl;
				cout<<"               \\\\  \\\\                   "<<endl;
				cout<<"                \\\\   O__/                 "<<endl;
				cout<<"                 \\\\     \\                "<<endl;
				cout<<"The space beneath you opens and you fall to your death."<<endl;
				cout<<"Your journey has ended short.\n\n";
				health = 0;
				break;
			}
		}
		if(answerLever == "no")
		{
			cout<<"\nThe lever does look suspicious. You leave it alone."<<endl;
			cout<<"You see a crack on the bottom of the gate big enough for you to go through."<<endl;
			cout<<"You attempt to vault over using your bamboo stick."<<endl;
			if(bigRandomGenerator() != 4)
			{
				cout<<"You vault across safely and fall through the hole onto a platform."<<endl;
			}
			else
			{
				cout<<"You fall short and plunge to your death"<<endl;
				cout<<"Your journey has ended short.\n\n";
				health = 0;
				break;
			}
		}
		if(answerLever == "quit")
		{
			health = 0;
			break;
		}
		cout<<"You walk across the platform and it leads you into a hall."<<endl;
		cout<<"The hall resemble that of a cathedral almost except"<<endl;
		cout<<"that they are filled with statues of warriors."<<endl;
		cout<<"As you walk down the hall, you feel as if the statues are looking at you."<<endl;
		cout<<"As you are about to pass the hall, a statue swings its sword at you!"<<endl;
		cout<<"This enemy doesn't seem like the ones you've previously encountered."<<endl;
		cout<<"You proceed to fight the statue."<<endl;
		cout<<"                      _____"<<endl;
		cout<<"    _O_          |   |_0.0_|  ___"<<endl;
		cout<<"  (|   |~-+---   |   |     | |   |"<<endl;
		cout<<"    \\_/        --+--~~\\___/~~|___|"<<endl;
		cout<<"___ /_\\_______________| _ |________"<<"\n\n";
		cout<<"\nYour health: "<<health<<"\n\n";

		while(statueBossHealth > 0)		//While loop for boss fight, similar to militia skeleton code
		{
			cout<<"\nYour items are:"<<endl;
			for(int i = 0; i<inventory.size(); i++)
			{
				cout<<i<<". "<<inventory[i]<<endl;
			}
			cout<<"\nType in the index number of the weapon you wish to use: ";
			cin>>answerWeapon;
			while(answerWeapon > (inventory.size() - 1))
			{
				cout<<"\nType in the index number of the weapon you wish to use: ";
				cin>>answerWeapon;
			}
			cout<<"\nYou choose to use your "<<inventory[answerWeapon]<<"."<<endl;
			if(bigRandomGenerator() != 4)
			{
				cout<<"You attack the Statue Warrior and deal "<<(statueBossHealth - (statueWarriorHealth(inventory[answerWeapon], statueBossHealth)))<<" to it."<<endl;
				statueBossHealth = statueWarriorHealth(inventory[answerWeapon], statueBossHealth);
				if(statueBossHealth > 0)
				{
					cout<<"The STATUE WARRIOR has "<<statueBossHealth<<" health left."<<endl;
				}
			}
			else
			{
				cout<<"You attack the Statue Warrior but miss!!!"<<endl;
			}
			if(statueBossHealth <= 0)
			{
				break;
			}
			if(bigRandomGenerator() != 3)
			{
				cout<<"\nThe Statue Warrior attacks and deals "<<damageStatueWarrior()<<" to you."<<endl;
				health = health - damageStatueWarrior();
			}
			else
			{
				cout<<"\nThe Statue Warrior attacks but misses!!!"<<endl;
			}
			if(health <= 0)
			{
				cout<<"You fought valiantly but have been slain in battle."<<endl;
				break;
			}
			cout<<"YOUR health is now: "<<health<<endl;
		}
		if(health <= 0)
		{
			break;
		}
		if(statueBossHealth <= 0 && health > 0)
		{
			cout<<"\nYou have defeated the Statue Boss!!!"<<endl;
			cout<<"Your health is now: "<<health<<".\n\n";
		}
		//Boss fight with Statue Warrior ends

		cout<<"That was a close encounter!"<<endl;
		cout<<"Your health is getting low, best to try and find some health potions."<<endl;
		cout<<"You pass through the hall to find another hall filled with rooms."<<endl;
		cout<<"Maybe one of these rooms will have health potions or even weapons."<<endl;
		cout<<"Check the rooms or continue on your way (yes/no)? ";
		cin>>answerHallOfRooms;
		while(answerHallOfRooms != "yes" && answerHallOfRooms != "no" && answerHallOfRooms != "quit")
		{
			cout<<"\nCheck the rooms or continue on your way (yes/no)? ";
			cin>>answerHallOfRooms;
		}
		if(answerHallOfRooms == "yes")
		{
			cout<<"        ______   ______   ______   ______   ______   "<<endl;
			cout<<"       |      | |      | |      | |      | |      |   "<<endl;
			cout<<"       |      | |      | |      | |      | |      |   "<<endl;
			cout<<"       |      | |      | |      | |      | |      |   "<<endl;
			cout<<"       |     o| |     o| |     o| |     o| |     o|   "<<endl;
			cout<<"       |      | |      | |      | |      | |      |   "<<endl;
			cout<<"  _____|______|_|______|_|______|_|______|_|______|_____"<<endl;

			for(int i = 0; i<roomCycle; i++)	//Let's you check up to 5 rooms   //Can be broken out of anytime
			{
				int roomChance = smallRandomGenerator();
				cout<<"\nCheck a room or leave the hall (check/leave)? ";	//Asks if player wants to continue checking rooms
				cin>>answerHallOfRooms;
				if(answerHallOfRooms == "check")
				{
					cout<<"THIS IS THE CURRENT COUNT: "<<i;
					cout<<"\n\nYou check a room."<<endl;
					if(roomChance == 1)
					{
						textMilitiaSkeleton();
						militiaSkelHealth = 100;
						while(militiaSkelHealth > 0)
						{
							cout<<"\nYour items are:"<<endl;
							for(int i = 0; i<inventory.size(); i++)
							{
								cout<<i<<". "<<inventory[i]<<endl;
							}
							cout<<"\nType in the index number of the weapon you wish to use: ";
							cin>>answerWeapon;
							while(answerWeapon > (inventory.size() - 1))
							{
								cout<<"\nType in the index number of the weapon you wish to use: ";
								cin>>answerWeapon;
							}
							if(inventory[answerWeapon].find("Potion") != string::npos)
							{
								cout<<"You use your "<<inventory[answerWeapon]<<"."<<endl;
								cout<<"Your health is now: "<<itemUsed1(inventory[answerWeapon], health)<<"."<<endl;
								health = itemUsed1(inventory[answerWeapon], health);
								for(int i = 0; i<inventory.size(); i++)
								{
									if(inventory[i] == inventory[answerWeapon])
									{
										inventory.erase(inventory.begin() + i);
									}
								}
								if(bigRandomGenerator() != 3)
								{
									cout<<"\nThe Militia Skeletons attack and deal "<<damageMilitiaSkeleton()<<" to you."<<endl;
									health = health - damageMilitiaSkeleton();
									if(health > 0)
									{
										cout<<"Your health is: "<<health<<endl;
									}
								}
								else
								{
									cout<<"\nThe Militia Skeletons attack but miss!!!"<<endl;
								}
							}
							else
							{
								cout<<"You choose to use your "<<inventory[answerWeapon]<<"."<<endl;
								if(bigRandomGenerator() != 4)
								{
									cout<<"You attack the Militia Skeletons and deal "<<(militiaSkelHealth - (militiaSkeletonHealth(inventory[answerWeapon], militiaSkelHealth)))<<" to them."<<endl;
									militiaSkelHealth = militiaSkeletonHealth(inventory[answerWeapon], militiaSkelHealth);
									if(militiaSkelHealth > 0)
									{
										cout<<"The Militia Skeletons have "<<militiaSkelHealth<<" health left."<<endl;
									}
								}
								else
								{
									cout<<"You attack the Militia Skeletons but miss!!!"<<endl;
								}
								if(militiaSkelHealth < 0)
								{
									break;
								}
								if(bigRandomGenerator() != 3)
								{
									cout<<"\nThe Militia Skeletons attack and deal "<<damageMilitiaSkeleton()<<" to you."<<endl;
									health = health - damageMilitiaSkeleton();
									if(health > 0)
									{
										cout<<"Your health is: "<<health<<endl;
									}
								}
								else
								{
									cout<<"\nThe Militia Skeletons attack but miss!!!"<<endl;
								}
							}
							if(health <= 0)
							{
								cout<<"\nYou fought valiantly but have been slain in battle."<<endl;
								cout<<"Your journey has ended short.\n\n";
								break;
							}
						}
						if(health <= 0)
						{
							break;
						}
						if(militiaSkelHealth <= 0 && health > 0)
						{
							cout<<"\nYou have defeated the Militia Skeletons!!!"<<endl;
							cout<<"Your health is: "<<health<<".\n\n";
						}
					}
					else if(roomChance == 2)
					{
						cout<<"This room appears to be empty. You leave the room."<<endl;
					}
					else if(roomChance == 3)
					{
						cout<<"There appears to be a chest at the end of the room."<<endl;
						cout<<"Open the chest (yes/no)? ";
						cin>>answerChest;
						while(answerChest != "yes" && answerChest != "no" && answerChest != "quit")
						{
							cout<<"\n\nOpen the chest (yes/no)? ";
							cin>>answerChest;
						}
						if(answerChest == "yes")
						{
							cout<<"\n\n";
							cout<<"             _____________ "<<endl;
							cout<<"           /             /)   "<<endl;
							cout<<"          /             //    "<<endl;
							cout<<"         /____________ //     "<<endl;
							cout<<"        /             /|      "<<endl;
							cout<<"       /_____________/ |   "<<endl;
							cout<<"       |             | |    "<<endl;
							cout<<" ______|             | |______"<<endl;
							cout<<"       |_____________|/     "<<endl;
							int chestTracker = smallRandomGenerator();
							if(chestTracker == 1)
							{
								cout<<"\n\nThe chest contains:"<<endl;
								for(int i = 0; i<chest2.size(); i++)
								{
									cout<<chest2[i]<<endl;
								}
								cout<<"\nYou put the item(s) in your inventory."<<endl;
								for(int i = 0; i<chest2.size(); i++)
								{
									inventory.push_back(chest2[i]);
								}
								cout<<"\nYour items are now:"<<endl;
								for(int i = 0; i<inventory.size(); i++)
								{
									cout<<"[ "<<inventory[i]<<" ]"<<endl;
								}
							}
							else if(chestTracker == 2)
							{
								cout<<"\n\nThe chest contains:"<<endl;
								for(int i = 0; i<chest3.size(); i++)
								{
									cout<<chest3[i]<<endl;
								}
								cout<<"\nYou put the item(s) in your inventory."<<endl;
								for(int i = 0; i<chest3.size(); i++)
								{
									inventory.push_back(chest3[i]);
								}
								cout<<"\nYour items are now:"<<endl;
								for(int i = 0; i<inventory.size(); i++)
								{
									cout<<"[ "<<inventory[i]<<" ]"<<endl;
								}
							}
							else if(chestTracker == 3)
							{
								cout<<"\nThe chest is empty."<<endl;
							}
						}
						else if(answerChest == "no")
						{
							cout<<"You disregard the chest and leave the room."<<endl;
						}
						else if(answerChest == "quit")
						{
							break;
						}
					}
				}
				else if(answerHallOfRooms == "leave")
				{
					break;
				}
				else if(answerHallOfRooms == "quit")
				{
					health = 0;
					break;
				}
			}
			if(health <= 0)
			{
				break;
			}
			else
			{
				cout<<"\nThere's no more time to check these rooms. Honor waits for no one!"<<endl;
			}
		}
		if(answerHallOfRooms == "no")
		{
			cout<<"\nThere's no time to check these rooms. Honor waits for no one!"<<endl;
		}
		if(answerHallOfRooms == "quit")
		{
			health = 0;
			break;
		}
		cout<<"\nType in ready when you're ready.\nInput: ";
		cin>>answer;
		while(answer != "ready" && answer != "quit")
		{
			cout<<"\nType in ready when you're ready.\nInput: ";
			cin>>answer;
		}
		if(answer == "quit")
		{
			health = 0;
			break;
		}

		cout<<"\n\n        _______               _______      "<<endl;
		cout<<"       |~~~~~~~|             |~~~~~~~|     "<<endl;
		cout<<"       |~~~~~~~|             |~~~~~~~|     "<<endl;
		cout<<"       |~~~~~~~|             |~~~~~~~|     "<<endl;
		cout<<"       |~~~~~~~|             |~~~~~~~|     "<<endl;
		cout<<"       -_      -_           _-      _-     "<<endl;
		cout<<"         -_      -_       _-      _-       "<<endl;
		cout<<"           -_      -_   _-      _-         "<<endl;
		cout<<"             -_      -_-      _-           "<<endl; 
		cout<<"               -_     -     _-             "<<endl;
		cout<<"                 -         -               "<<endl;
		cout<<"                 |         |               "<<endl;
		cout<<"                 |         |               "<<endl;

		cout<<"\nYou leave the hall of rooms and continue on."<<endl;
		cout<<"You come across a path that splits to the right and to the left."<<endl;
		cout<<"Take the right or left path? (right/left) ";
		cin>>answerPath;
		if(answerPath == "right")
		{
			cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ THE DUNGEONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			cout<<"\t            |                                     "<<endl;
			cout<<"\t         ~~~|~~~~~~~~                    | ~~~~   "<<endl;
			cout<<"\t         ___|___               ~~~~~     |        "<<endl;
			cout<<"\t        |_|O|_|_|    ~~~~~~~~~        ___|___     "<<endl;
			cout<<"\t        |_~|~_|_|          |  ~~~    |_|_|_|_|    "<<endl;
			cout<<"\t        |_|||_|_|~~~~~~    |         |_|_|_|_|~~  "<<endl;
			cout<<"\t        |_|_|_|_|       ___|___  ~~~~|_|_|_|_|    "<<endl;
			cout<<"\t                       |_|_|O|_|     |_|_|_|_|    "<<endl;
			cout<<"\t   ~~~~                |_|_~|~_|                  "<<endl;
			cout<<"\t                ~~~~   |_|_|||_| ~~~~~  ~~        "<<endl;
			cout<<"\t         ~~~~~~~       |_|_|_|_|                  "<<endl;
			cout<<"\t                                                  "<<endl;
			cout<<"\t  _______________________________________________ "<<endl;

			cout<<"\n\nYou choose the right path and come across a large open gate."<<endl;
			cout<<"The gate appears to lead into some sort of dungeon. You walk in."<<endl;
			cout<<"As you pass through, the gate shuts!"<<endl;
			textMilitiaSkeleton();
			militiaSkelHealth = 100;
			while(militiaSkelHealth > 0)
			{
				cout<<"\nYour items are:"<<endl;
				for(int i = 0; i<inventory.size(); i++)
				{
					cout<<i<<". "<<inventory[i]<<endl;
				}
				cout<<"\nType in the index number of the weapon you wish to use: ";
				cin>>answerWeapon;
				while(answerWeapon > (inventory.size() - 1))
				{
					cout<<"\nType in the index number of the weapon you wish to use: ";
					cin>>answerWeapon;
				}
				if(inventory[answerWeapon].find("Potion") != string::npos)
				{
					cout<<"You use your "<<inventory[answerWeapon]<<"."<<endl;
					cout<<"Your health is now: "<<itemUsed1(inventory[answerWeapon], health)<<"."<<endl;
					health = itemUsed1(inventory[answerWeapon], health);
					for(int i = 0; i<inventory.size(); i++)
					{
						if(inventory[i] == inventory[answerWeapon])
						{
							inventory.erase(inventory.begin() + i);
						}
					}
					if(bigRandomGenerator() != 3)
					{
						cout<<"\nThe Militia Skeletons attack and deal "<<damageMilitiaSkeleton()<<" to you."<<endl;
						health = health - damageMilitiaSkeleton();
						if(health > 0)
						{
							cout<<"Your health is: "<<health<<endl;
						}
					}
					else
					{
						cout<<"\nThe Militia Skeletons attack but miss!!!"<<endl;
					}
				}
				else
				{
					cout<<"You choose to use your "<<inventory[answerWeapon]<<"."<<endl;
					if(bigRandomGenerator() != 4)
					{
						cout<<"You attack the Militia Skeletons and deal "<<(militiaSkelHealth - (militiaSkeletonHealth(inventory[answerWeapon], militiaSkelHealth)))<<" to them."<<endl;
						militiaSkelHealth = militiaSkeletonHealth(inventory[answerWeapon], militiaSkelHealth);
						if(militiaSkelHealth > 0)
						{
							cout<<"The Militia Skeletons have "<<militiaSkelHealth<<" health left."<<endl;
						}
					}
					else
					{
						cout<<"You attack the Militia Skeletons but miss!!!"<<endl;
					}
					if(militiaSkelHealth < 0)
					{
						break;
					}
					if(bigRandomGenerator() != 3)
					{
						cout<<"\nThe Militia Skeletons attack and deal "<<damageMilitiaSkeleton()<<" to you."<<endl;
						health = health - damageMilitiaSkeleton();
						if(health > 0)
						{
							cout<<"Your health is: "<<health<<endl;
						}
					}
					else
					{
						cout<<"\nThe Militia Skeletons attack but miss!!!"<<endl;
					}
				}
				if(health <= 0)
				{
					cout<<"\nYou fought valiantly but have been slain in battle."<<endl;
					cout<<"Your journey has ended short.\n\n";
					break;
				}
			}
			if(health <= 0)
			{
				break;
			}
			if(militiaSkelHealth <= 0 && health > 0)
			{
				cout<<"\nYou have defeated the Militia Skeletons!!!"<<endl;
				cout<<"Your health is: "<<health<<".\n\n";
			}

			cout<<"\nType in ready when you're ready.\nInput: ";
			cin>>answer;
			while(answer != "ready" && answer != "quit")
			{
				cout<<"\nType in ready when you're ready.\nInput: ";
				cin>>answer;
			}
			if(answer == "quit")
			{
				health = 0;
				break;
			}

			cout<<"\n\n          _________________          "<<endl;
			cout<<"         /                 \\        "<<endl;
			cout<<"        /         _         \\       "<<endl;
			cout<<"        |        |_|        |        "<<endl;
			cout<<"        |                   |        "<<endl;
			cout<<"        |  _      _      _  |        "<<endl;
			cout<<"        | / \\    / \\    / \\ |     "<<endl;
			cout<<"        | \\_/    \\_/    \\_/ |     "<<endl;
			cout<<"        |                   |        "<<endl;
			cout<<"  ______|___________________|________"<<endl;

			cout<<"\nThe gates to the other side seem to be shut."<<endl;
			cout<<"As you walk up to the gates you spot what seems to be a"<<endl;
			cout<<"switch of some sort on the gate."<<endl;
			cout<<"You spot an inscription on the wall near the gate."<<endl;
			cout<<"You read the inscription."<<endl;
			cout<<"\n\t'The gates of wrath have sealed me in. I feel as I've been"<<endl;
			cout<<"\t locked in here for ages. All attempts at trying to open the"<<endl;
			cout<<"\t gate have been futile. Perhaps the drawing on the wall contains"<<endl;
			cout<<"\t the clue to figuring it out.'"<<endl;
			cout<<"\nThe message seems to end there..."<<endl;
			cout<<"Time to figure out this switch and get out of this dungeon."<<endl;

			cout<<"\nType in ready when you're ready.\nInput: ";
			cin>>answer;
			while(answer != "ready" && answer != "quit")
			{
				cout<<"\nType in ready when you're ready.\nInput: ";
				cin>>answer;
			}
			if(answer == "quit")
			{
				health = 0;
				break;
			}
			cout<<"\n\nYou look at the drawing."<<endl;
			cout<<"\t                                     "<<endl;
			cout<<"\t            _____  _                 "<<endl;
			cout<<"\t           |        |                "<<endl;
			cout<<"\t           |  __    |                "<<endl;
			cout<<"\t           | /  \\ /________         "<<endl;
			cout<<"\t             \\__/ \\ |              "<<endl;
			cout<<"\t           |______ _|                "<<endl;
			cout<<"\t                                     "<<endl;
			cout<<"\nSeems like we have to insert something into the hole in the gate to open it."<<endl;
			cout<<"It looks like the bamboo stick will fit in it."<<endl;
			cout<<"The gate appears to have multiple holes."<<endl;
			cout<<"Guess we'll have to try each one until it opens."<<endl;
			int rightChoice = (rand() % 3) + 1;
			int badLuck = smallRandomGenerator();
			while(rightChoice == badLuck)
			{
				badLuck = smallRandomGenerator();
			}
			int holeChoice = 0;
			while(holeChoice != rightChoice && holeChoice != badLuck)
			{
				cout<<"\nWhich hole do you want to try first? ('1'/'2'/'3') ";
				cin>>holeChoice;
				if(holeChoice == 1)
				{
					cout<<"You stick the bamboo stick into the first hole."<<endl;
				}
				else if(holeChoice == 2)
				{
					cout<<"You stick the bamboo stick into the second hole."<<endl;
				}
				else if(holeChoice == 3)
				{
					cout<<"You stick the bamboo stick into the third hole."<<endl;
				}

				if(holeChoice == badLuck)
				{
					cout<<"\nWater pours in from the walls and you drown."<<endl;
					cout<<"Your journey has ended short."<<endl;
					health = 0;
					break;
				}
				else if(holeChoice == rightChoice)
				{
					cout<<"\nThe switch clicks and the gate unlocks."<<endl;
					choice = 5;
					break;
				}
				else
				{
					cout<<"\nNothing happens. Try again."<<endl;
				}
			}		
		}
		else if(answerPath == "left")
		{
			cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~ JESTER'S PLAYROOM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"<<endl;
			cout<<"       _______          /              /             "<<endl;
			cout<<"      (0 ___ 0)        /              /              "<<endl;
			cout<<"       (|___|)        /              /               "<<endl;
			cout<<"          |          /              /                "<<endl;
			cout<<"        __|___      /      O       /                 "<<endl;
			cout<<"       /__|__/|    /      -|-     /     _________     "<<endl;
			cout<<"       |_____|/   /       / \\    /     /        /|    "<<endl;
			cout<<"          _________             /     /________/ |    "<<endl;
			cout<<"         /________/|           /     |  O _  O|  |    "<<endl;
			cout<<"         | X    O |/          /      |   |_|  | /     "<<endl;
			cout<<"          \\__()__/           /       |>______<|/      \n\n"<<endl;

			cout<<"You choose the left path and come across a large gate that leads"<<endl;
			cout<<"to a playroom filled with toys and boxes that seem to tower you."<<endl;
			cout<<"Wonder who plays with these..."<<endl;
			cout<<"As you walk down the room, the gates on both sides shut."<<endl;
			cout<<"You try to open the gate but it won't even budge."<<endl;
			cout<<"You spot an inscription on the wall near the gate."<<endl;
			cout<<"You read the inscription."<<endl;
			cout<<"\n\t'A puzzle for all, a puzzle for you! Here are your clues"<<endl;
			cout<<"\t in hopes that you do..."<<endl;
			cout<<"\t do get out of this dreadful place cause it's dreadful~~~"<<endl;
			cout<<"\t The pieces on the floor will combine to open the door"<<endl;
			cout<<"\t hehehehehe..."<<endl;
			cout<<"\nThe message seems to end there..."<<endl;
			cout<<"Time to figure out this puzzle and get out of this dungeon."<<endl;

			cout<<"\nType in ready when you're ready.\nInput: ";
			cin>>answer;
			while(answer != "ready" && answer != "quit")
			{
				cout<<"\nType in ready when you're ready.\nInput: ";
				cin>>answer;
			}
			if(answer == "quit")
			{
				health = 0;
				break;
			}
			cout<<"\n\n       ______                       "<<endl;
			cout<<"      |      |         _____       "<<endl;
			cout<<"      |      |        |     |      "<<endl;
			cout<<"       \\     \\        |     |      "<<endl;
			cout<<"        \\     \\_______|     |      "<<endl;
			cout<<"         \\                  |      "<<endl;
			cout<<"          \\        _________|      "<<endl;
			cout<<"           |      |                 "<<endl;
			cout<<"           |      |________         "<<endl;
			cout<<"           |               |        "<<endl;
			cout<<"           |_______________|        "<<endl;

			cout<<"\nThere is a hole on the gate in this shape."<<endl;
			cout<<"Guess we have to fill in the holes on the gate to unlock it."<<endl;
			cout<<"There are pieces lying all over the floor."<<endl;
			cout<<"Unfortunately our pouch can only hold 3 pieces at a time so"<<endl;
			cout<<"it seems we'll have to pick up the exact 3 pieces"<<endl;

			for(int i = 0; i<500; i++)	//Loops till player decides he has the correct 3 puzzle pieces
			{
				if(answer == "quit")
				{
					health = 0;
					break;
				}
				int randomPuzzlePiece = bigRandomGenerator();
				cout<<"\nTHIS IS THE RANDOM NUMBER: "<<randomPuzzlePiece<<endl;		
				if(randomPuzzlePiece == 1)						//Displays the puzzle piece if number = 1
				{
					cout<<"\n\n  ____            "<<endl;
					cout<<" |    |           "<<endl;
					cout<<" |    |           "<<endl;
					cout<<"  \\    \\        "<<endl;
					cout<<"   \\    \\       "<<endl;
					cout<<"    \\   /        "<<endl;
					cout<<"     \\/          "<<endl;
					cout<<"\n\nYou come across a piece that looks like this:"<<endl;
					cout<<"Pick it up (yes/no)? ";
					cin>>answer;
					if(answer == "yes" && puzzleInventory.size() < 3)
					{
						cout<<"\nYou pick it up."<<endl;
						puzzleInventory.push_back("PuzzlePiece1");
					}
					else if(answer == "yes" && puzzleInventory.size() >= 3)			//If puzzle bag is full, asks player to drop something first
					{
						cout<<"\nYour pouch is full. You'll have to dump something out."<<endl;
						cout<<"Puzzle bag inventory:\n\n";
						for(int i = 0; i<puzzleInventory.size(); i++)
						{
							cout<<i<<". "<<puzzleInventory[i]<<endl;		//Displays puzzle bag contents
						}
						cout<<"\nEnter the index number of the piece you wish to dump or type in '9'"<<endl;
						cout<<"if you wish to discard none."<<endl;
						cout<<"Which piece do you wish to dump? ";
						cin>>puzzlePieceChoice;							//Removes puzzle piece player wishes to remove
						if(puzzlePieceChoice == 0)
						{
							puzzleInventory.erase(puzzleInventory.begin());
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece1");
						}
						else if(puzzlePieceChoice == 1)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 1);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece1");
						}
						else if(puzzlePieceChoice == 2)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 2);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece1");
						}
						else if(puzzlePieceChoice == 9)					//Player can choose not to remove any pieces
						{
							cout<<"You decide to keep your beloved pieces and move on."<<endl;
						}
					}
					else if(answer == "no")
					{
						cout<<"\nYou leave it on the ground and search for others."<<endl;
					}
				}
				if(randomPuzzlePiece == 2)
				{
					cout<<"\n\n            ____   "<<endl;
					cout<<"           |    |  "<<endl;
					cout<<"           |    |  "<<endl;
					cout<<"     ______|    |  "<<endl;
					cout<<"    /           |  "<<endl;
					cout<<"   /____________|  "<<endl;
					cout<<"\n\nYou come across a piece that looks like this:"<<endl;
					cout<<"Pick it up (yes/no)? ";
					cin>>answer;
					if(answer == "yes" && puzzleInventory.size() < 3)
					{
						cout<<"\nYou pick it up."<<endl;
						puzzleInventory.push_back("PuzzlePiece2");
					}
					else if(answer == "yes" && puzzleInventory.size() >= 3)
					{
						cout<<"\nYour pouch is full. You'll have to dump something out."<<endl;
						cout<<"Puzzle bag inventory:\n\n";
						for(int i = 0; i<puzzleInventory.size(); i++)
						{
							cout<<i<<". "<<puzzleInventory[i]<<endl;
						}
						cout<<"\nEnter the index number of the piece you wish to dump or type in '9'"<<endl;
						cout<<"if you wish to discard none."<<endl;
						cout<<"Which piece do you wish to dump? ";
						cin>>puzzlePieceChoice;
						if(puzzlePieceChoice == 0)
						{
							puzzleInventory.erase(puzzleInventory.begin());
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece2");
						}
						else if(puzzlePieceChoice == 1)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 1);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece2");
						}
						else if(puzzlePieceChoice == 2)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 2);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece2");
						}
						else if(puzzlePieceChoice == 9)
						{
							cout<<"You decide to keep your beloved pieces and move on."<<endl;
						}
					}
					else if(answer == "no")
					{
						cout<<"\nYou leave it on the ground and search for others."<<endl;
					}
				}
				if(randomPuzzlePiece == 3)
				{
					cout<<"\n\n            ____   "<<endl;
					cout<<"           |    |  "<<endl;
					cout<<"           |    |  "<<endl;
					cout<<"   ________|    |  "<<endl;
					cout<<"   \\            | "<<endl;
					cout<<"    \\___________| "<<endl;
					cout<<"\n\nYou come across a piece that looks like this:"<<endl;
					cout<<"Pick it up (yes/no)? ";
					cin>>answer;
					if(answer == "yes" && puzzleInventory.size() < 3)
					{
						cout<<"\nYou pick it up."<<endl;
						puzzleInventory.push_back("PuzzlePiece3");
					}
					else if(answer == "yes" && puzzleInventory.size() >= 3)
					{
						cout<<"\nYour pouch is full. You'll have to dump something out."<<endl;
						cout<<"Puzzle bag inventory:\n\n";
						for(int i = 0; i<puzzleInventory.size(); i++)
						{
							cout<<i<<". "<<puzzleInventory[i]<<endl;
						}
						cout<<"\nEnter the index number of the piece you wish to dump or type in '9'"<<endl;
						cout<<"if you wish to discard none."<<endl;
						cout<<"Which piece do you wish to dump? ";
						cin>>puzzlePieceChoice;
						if(puzzlePieceChoice == 0)
						{
							puzzleInventory.erase(puzzleInventory.begin());
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece3");
						}
						else if(puzzlePieceChoice == 1)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 1);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece3");
						}
						else if(puzzlePieceChoice == 2)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 2);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece3");
						}
						else if(puzzlePieceChoice == 9)
						{
							cout<<"You decide to keep your beloved pieces and move on."<<endl;
						}
					}
					else if(answer == "no")
					{
						cout<<"\nYou leave it on the ground and search for others."<<endl;
					}
				}
				if(randomPuzzlePiece == 4)
				{
					cout<<"\n\n   ____            "<<endl;
					cout<<"  |    |           "<<endl;
					cout<<"  |    |_______    "<<endl;
					cout<<"  |            |   "<<endl;
					cout<<"  |____________|   "<<endl;
					cout<<"\n\nYou come across a piece that looks like this:"<<endl;
					cout<<"Pick it up (yes/no)? ";
					cin>>answer;
					if(answer == "yes" && puzzleInventory.size() < 3)
					{
						cout<<"\nYou pick it up."<<endl;
						puzzleInventory.push_back("PuzzlePiece4");
					}
					else if(answer == "yes" && puzzleInventory.size() >= 3)
					{
						cout<<"\nYour pouch is full. You'll have to dump something out."<<endl;
						cout<<"Puzzle bag inventory:\n\n";
						for(int i = 0; i<puzzleInventory.size(); i++)
						{
							cout<<i<<". "<<puzzleInventory[i]<<endl;
						}
						cout<<"\nEnter the index number of the piece you wish to dump or type in '9'"<<endl;
						cout<<"if you wish to discard none."<<endl;
						cout<<"Which piece do you wish to dump? ";
						cin>>puzzlePieceChoice;
						if(puzzlePieceChoice == 0)
						{
							puzzleInventory.erase(puzzleInventory.begin());
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece4");
						}
						else if(puzzlePieceChoice == 1)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 1);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece4");
						}
						else if(puzzlePieceChoice == 2)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 2);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece4");
						}
						else if(puzzlePieceChoice == 9)
						{
							cout<<"You decide to keep your beloved pieces and move on."<<endl;
						}
					}
					else if(answer == "no")
					{
						cout<<"\nYou leave it on the ground and search for others."<<endl;
					}
				}
				if(randomPuzzlePiece == 5)
				{
					cout<<"\n\n       /|          "<<endl;
					cout<<"      / |          "<<endl;
					cout<<"     /  |          "<<endl;
					cout<<"    /   |          "<<endl;
					cout<<"   |    |          "<<endl;
					cout<<"   |    |_______   "<<endl;
					cout<<"   |            |  "<<endl;
					cout<<"   |____________|  "<<endl;
					cout<<"\n\nYou come across a piece that looks like this:"<<endl;
					cout<<"Pick it up (yes/no)? ";
					cin>>answer;
					if(answer == "yes" && puzzleInventory.size() < 3)
					{
						cout<<"\nYou pick it up."<<endl;
						puzzleInventory.push_back("PuzzlePiece5");
					}
					else if(answer == "yes" && puzzleInventory.size() >= 3)
					{
						cout<<"\nYour pouch is full. You'll have to dump something out."<<endl;
						cout<<"Puzzle bag inventory:\n\n";
						for(int i = 0; i<puzzleInventory.size(); i++)
						{
							cout<<i<<". "<<puzzleInventory[i]<<endl;
						}
						cout<<"\nEnter the index number of the piece you wish to dump or type in '9'"<<endl;
						cout<<"if you wish to discard none."<<endl;
						cout<<"Which piece do you wish to dump? ";
						cin>>puzzlePieceChoice;
						if(puzzlePieceChoice == 0)
						{
							puzzleInventory.erase(puzzleInventory.begin());
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece5");
						}
						else if(puzzlePieceChoice == 1)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 1);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece5");
						}
						else if(puzzlePieceChoice == 2)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 2);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece5");
						}
						else if(puzzlePieceChoice == 9)
						{
							cout<<"You decide to keep your beloved pieces and move on."<<endl;
						}
					}
					else if(answer == "no")
					{
						cout<<"\nYou leave it on the ground and search for others."<<endl;
					}
				}
				if(randomPuzzlePiece == 6)
				{
					cout<<"\n\n         /\\       "<<endl;
					cout<<"        /  \\      "<<endl;
					cout<<"       /    \\     "<<endl;
					cout<<"      /      \\    "<<endl;
					cout<<"     /        \\   "<<endl;
					cout<<"    /__________\\  "<<endl;
					cout<<"\n\nYou come across a piece that looks like this:"<<endl;
					cout<<"Pick it up (yes/no)? ";
					cin>>answer;
					if(answer == "yes" && puzzleInventory.size() < 3)
					{
						cout<<"\nYou pick it up."<<endl;
						puzzleInventory.push_back("PuzzlePiece6");
					}
					else if(answer == "yes" && puzzleInventory.size() >= 3)
					{
						cout<<"\nYour pouch is full. You'll have to dump something out."<<endl;
						cout<<"Puzzle bag inventory:\n\n";
						for(int i = 0; i<puzzleInventory.size(); i++)
						{
							cout<<i<<". "<<puzzleInventory[i]<<endl;
						}
						cout<<"\nEnter the index number of the piece you wish to dump or type in '9'"<<endl;
						cout<<"if you wish to discard none."<<endl;
						cout<<"Which piece do you wish to dump? ";
						cin>>puzzlePieceChoice;
						if(puzzlePieceChoice == 0)
						{
							puzzleInventory.erase(puzzleInventory.begin());
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece6");
						}
						else if(puzzlePieceChoice == 1)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 1);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece6");
						}
						else if(puzzlePieceChoice == 2)
						{
							puzzleInventory.erase(puzzleInventory.begin() + 2);
							cout<<"\nYou pick it up."<<endl;
							puzzleInventory.push_back("PuzzlePiece6");
						}
						else if(puzzlePieceChoice == 9)
						{
							cout<<"You decide to keep your beloved pieces and move on."<<endl;
						}
					}
					else if(answer == "no")
					{
						cout<<"\nYou leave it on the ground and search for others."<<endl;
					}
				}
				if(puzzleInventory.size() == 3)
				{
					cout<<"\n\nDo you want to try to fit the pieces you have into the hole (yes/no)? ";
					cin>>answerPuzzle;
					if(answerPuzzle == "yes")
					{
						int puzzleTracker = 0;		//Keeps track of the correct puzzle pieces inside of bag
						for(int i = 0; i<puzzleInventory.size(); i++)	//Loops through bag contents
						{
							if(puzzleInventory[i].find("1") != string::npos)
							{
								if(i == 0)
								{
									if(puzzleInventory[i] != puzzleInventory[1] && puzzleInventory[i] != puzzleInventory[2])
									{
										puzzleTracker++;	//If bag contains the 1st right piece, increment correct piece count
									}
								}
								else if(i == 1)
								{
									if(puzzleInventory[i] != puzzleInventory[0] && puzzleInventory[i] != puzzleInventory[2])
									{
										puzzleTracker++;
									}
								}
								else if(i == 2)
								{
									if(puzzleInventory[i] != puzzleInventory[0] && puzzleInventory[i] != puzzleInventory[1])
									{
										puzzleTracker++;
									}
								}
							}
							if(puzzleInventory[i].find("2") != string::npos)
							{
								if(i == 0)
								{
									if(puzzleInventory[i] != puzzleInventory[1] && puzzleInventory[i] != puzzleInventory[2])
									{
										puzzleTracker++;	//If bag contains the 2nd right piece, increment correct piece count
									}
								}
								else if(i == 1)
								{
									if(puzzleInventory[i] != puzzleInventory[0] && puzzleInventory[i] != puzzleInventory[2])
									{
										puzzleTracker++;
									}
								}
								else if(i == 2)
								{
									if(puzzleInventory[i] != puzzleInventory[0] && puzzleInventory[i] != puzzleInventory[1])
									{
										puzzleTracker++;
									}
								}
							}
							if(puzzleInventory[i].find("4") != string::npos)
							{
								if(i == 0)
								{
									if(puzzleInventory[i] != puzzleInventory[1] && puzzleInventory[i] != puzzleInventory[2])
									{
										puzzleTracker++;	//If bag contains the 3rd right piece, increment correct piece count
									}
								}
								else if(i == 1)
								{
									if(puzzleInventory[i] != puzzleInventory[0] && puzzleInventory[i] != puzzleInventory[2])
									{
										puzzleTracker++;
									}
								}
								else if(i == 2)
								{
									if(puzzleInventory[i] != puzzleInventory[0] && puzzleInventory[i] != puzzleInventory[1])
									{
										puzzleTracker++;
									}
								}
							}
						}
						if(puzzleTracker == 3)		//If all 3 pieces are correct, player exits phase and moves to next one
						{
							cout<<"\n              ____________   "<<endl;
							cout<<"             /___________/|  "<<endl;
							cout<<"            |____________|/  "<<endl;
							cout<<"           /____________/|   "<<endl;
							cout<<"          |_____________|/   "<<endl;
							cout<<"         /_____________/|    "<<endl;
							cout<<"        |_____________|/     "<<endl;
							cout<<"       /_____________/|      "<<endl;
							cout<<"      |_____________|/       "<<endl;
							cout<<"     /_____________/|        "<<endl;
							cout<<"    |______________|/        "<<endl;
							cout<<"\nThe pieces fit perfectly and the gate unlocks to reveal a staircase"<<endl;
							cout<<"leading upwards. You take one last look back at this room and once again"<<endl;
							cout<<"wonder who this room belongs to..."<<endl;
							break;
						}
						else			//Else if the pieces aren't the correct 3, player stays in same phase and keeps trying
						{
							cout<<"\nThe pieces don't even fit inside."<<endl;
							cout<<"Guess we'll have to keep looking."<<endl;
							continue;
						}
					}

					else if(answerPuzzle == "no")
					{
						continue;
					}
					else if(answerPuzzle == "quit")
					{
						health = 0;
						break;
					}
				}
			}
		}
		else if(answerPath == "quit")
		{
			health = 0;
			break;
		}
	}
	if(health > 0)
	{
		cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~ YOU'VE BEAT THE GAME!!! ~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~ THANK YOU FOR PLAYING!!! ~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cin>>endGame;		//Used to stall game from immediately exiting in .exe mode
	}
	else
	{
		cout<<"\n\n";
		cout<<"\t\t\t\t      _______   "<<endl;
		cout<<"\t\t\t\t     |       |    "<<endl;
		cout<<"\t\t\t\t     | X . X |    "<<endl;
		cout<<"\t\t\t\t     (   _   )    "<<endl;
		cout<<"\t\t\t\t      \\     /     "<<endl;
		cout<<"\t\t\t\t       \\___/     "<<endl;
		cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GAME OVER!!! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~ THANK YOU FOR PLAYING!!! ~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cin>>endGame;		//Used to stall game from immediately exiting in .exe mode
	}
	return 0;
}

int bigRandomGenerator()
{
	int random;
	srand(static_cast<unsigned int>(time(0)));
	random = (rand() % 6) + 1;
	return random;
}

int smallRandomGenerator()
{
	int random;
	srand(static_cast<unsigned int>(time(0)));
	random = (rand() % 3) + 1;
	return random;
}