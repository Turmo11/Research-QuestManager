#include "j1Module.h"
#include "p2Point.h"
#include <vector>
#include <list>
#include "SDL/include/SDL_rect.h"

/*TODO 0:
Look at the structure mentioned above presented by the Quests, Events and the Quest Manager.
*/


class Quest
{
public:

	Quest() {};
	~Quest() ;
	
	int id; 
	int trigger;
	int reward;
	int requisites;
	int type;

	std::string title;
	std::string description;

	bool completed = false;
};


class j1QuestManager : public j1Module 
{

public:

	j1QuestManager();
	~j1QuestManager();

	bool Awake(pugi::xml_node& file);
	bool Start();
	


	pugi::xml_document quest_data;

	std::list<Quest*> loaded_quests;
	std::list<Quest*> active_quests;
	std::list<Quest*> finished_quests;
};


