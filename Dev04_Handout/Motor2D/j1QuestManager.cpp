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
	/*TODO 2:
	We will need to read in the QuestManager Start the own xml file that will contain all the necessary data
	for quests and events. As in config.xml, a specific myApp function has been created for read this file.
	The function is called LoadQuests.
	*/
	pugi::xml_node quest_node;
	quest_node = App->LoadQuests(quest_data);  //Loads the xml file that you pass in the "xmlfile" and returns a node

	if (quest_node == NULL)
	{
		LOG("Could not load quests_file.xml");
	}

	for (quest_node = quest_node.child("quest"); quest_node; quest_node = quest_node.next_sibling("quest"))
	{
		/*TODO 3:
		Respecting the structure that has been seen in the xml in TODO 1, all the data will have to be read and equaled
		with those of a new Quest that we will create.
		To do this, we will create a loop that goes through all the quests in the questData file. Inside the loop, a new
		quest will be created (with the class that was created previously) and its DNI and reward will be taken from the xml file.
		*/

		Quest* new_quest = new Quest();

		new_quest->id = quest_node.attribute("id").as_int();
		new_quest->title = quest_node.attribute("title").as_string();
		new_quest->type = quest_node.attribute("type").as_int();
		new_quest->trigger = quest_node.attribute("trigger").as_int();
		new_quest->description = quest_node.attribute("description").as_string();
		new_quest->reward = quest_node.attribute("reward").as_int();
		new_quest->requisites = quest_node.attribute("requisites").as_int();

		/*TODO 5:
		Now the function seen in the last TODO is applied. As you can see, it is matched with the activationEvent of the quest. Now you have
		to do the same but with all the subEvent presented by the quests, so you will have to create a for going through all the subEvent
		and entering them in the list of subMissions within the quest itself.
		To introduce them we can use the push_back() function and pass it as parameter the new event (created with the createEvent function).
		*/
		if (new_quest->trigger == 1)
		{
			active_quests.push_back(new_quest);
		}
		else 
		{
			loaded_quests.push_back(new_quest);
		}
		
	}

	return true;
}


bool j1QuestManager::Start() 
{


	return true;

}



