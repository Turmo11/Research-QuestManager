#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

struct SDL_Texture;
struct Collider;

enum f_type {

	CHERRY = 0,
	BANANA,
	ORANGE,
	WATERMELON,
	MANGO
};

class j1Fruit : public j1Module 
{
public:

	//Constructor
	j1Fruit();

	// Destructor
	virtual ~j1Fruit();

	//Called at first
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	// Called before render is available

	//bool Awake(pugi::xml_node& conf);

	void Spawn();
	void Eaten();

	// Called before quitting
	bool CleanUp();


private:

	p2Point<int> f_pos;
	SDL_Rect f_hitbox = {};

	SDL_Texture* graphics;

	Collider* f_col;

	int points;
	f_type type;



};
