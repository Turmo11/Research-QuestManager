#include "j1QuestManager.h"
#include "j1Module.h"
#include "p2Point.h"
#include "p2Log.h"
#include <vector>
#include "j1App.h"


j1QuestManager::j1QuestManager() {}


j1QuestManager::~j1QuestManager() 
{
	for (std::list <Quest*>::iterator it = loaded_quests.begin(); it != loaded_quests.end(); it++) 
	{
		loaded_quests.erase(it);
	}		
	for (std::list <Quest*>::iterator it = active_quests.begin(); it != active_quests.end(); it++) 
	{
		active_quests.erase(it);
	}
	for (std::list <Quest*>::iterator it = finished_quests.begin(); it != finished_quests.end(); it++) 
	{
		finished_quests.erase(it);
	}	
}


bool j1QuestManager::Awake(pugi::xml_node& config) 
{
	LOG("STARTING QUEST_MANAGER");
	

	//TODO 3: Now that we have the XML loaded, we'll begin loading all of the info into our Quest Manager. 
	//Remember to use the LoadQuest function we just created and to use the proper syntax. 
	//We will code a loop that creates a new_quest and loads all of its info for every quest on the XML

	

		//TODO 4: Right now, we are creating the Quests but we are not storing them properly, 
		//therefore after every loop we will push them into the loaded_quests list, 
		//however if a quest's trigger is equal to 1 (meaning that is always active) we will directly put those into the active_quests list

	

	return true;
}


bool j1QuestManager::Start() 
{


	return true;

}



