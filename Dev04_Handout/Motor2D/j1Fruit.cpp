#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Audio.h"
#include "j1Textures.h"
#include "j1Player.h"
#include "j1Fruit.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Input.h"
#include "j1Collision.h"
#include <time.h>


j1Fruit::j1Fruit() : j1Module()
{}

j1Fruit::~j1Fruit()
{}

bool j1Fruit::Start()
{
	srand(time(NULL));

	type = static_cast<f_type>(rand() % MANGO);

	f_pos.x = ((rand() % 22) * 32) + 34;
	f_pos.y = ((rand() % 22) * 32) + 34;

	f_hitbox = { f_pos.x, f_pos.y, 28, 28 };


	f_col = App->collider->AddCollider(f_hitbox, COLLIDER_FRUIT, this);


	return true;
}

bool j1Fruit::PreUpdate()
{
	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN)
	{
		LOG("SPAWN");
		Spawn();
		//LOG("%s", type);
		App->player->is_dead = false;
	}
	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		
		LOG("REVIVE");

	}
	if (f_pos == App->player->getPos())
	{
		Eaten();
	}
	return true;
}

bool j1Fruit::Update(float dt)
{
	switch (type)
	{
	case CHERRY:
		points = 10;
		App->render->DrawQuad(f_hitbox, 150, 9, 21, 255);
		break;
	case BANANA:
		points = 20;
		App->render->DrawQuad(f_hitbox, 247, 225, 79, 255);
		break;
	case ORANGE:
		points = 30;
		App->render->DrawQuad(f_hitbox, 245, 105, 24, 255);
		break;
	case WATERMELON:
		points = 40;
		App->render->DrawQuad(f_hitbox, 235, 14, 14, 255);
		break;
	case MANGO:
		points = 50;
		App->render->DrawQuad(f_hitbox, 255, 215, 0, 255);
		break;
	
	}
	

	return true;
}

bool j1Fruit::PostUpdate()
{
	return true;
}

bool j1Fruit::CleanUp()
{
	return true;
}

void j1Fruit::Spawn() {

	type = static_cast<f_type>(rand() % MANGO);

	f_col->to_delete = true;

	f_pos.x = ((rand() % 22) * 32) + 34;
	f_pos.y = ((rand() % 22) * 32) + 34;

	f_hitbox = { f_pos.x, f_pos.y, 28, 28 };

	f_col = App->collider->AddCollider(f_hitbox, COLLIDER_FRUIT, this);
}

void j1Fruit::Eaten() {

	App->player->score += points;
	Spawn();
}