#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	App->map->Load("map.tmx");
	graphics = App->tex->Load("textures/quests/logo.png");
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame();

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame();

	

	DrawTest();
	DrawRay();
	DrawQ3();
	DrawQ4();
	DrawQ5();

	App->map->Draw();

	p2SString title("Map:%dx%d Tiles:%dx%d Tilesets:%d",
					App->map->data.width, App->map->data.height,
					App->map->data.tile_width, App->map->data.tile_height,
					App->map->data.tilesets.count());

	App->win->SetTitle(title.GetString());
	App->render->Blit(graphics, 968, 160, &testo, 1.0f, false);
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;
	/*App->render->Blit(graphics, 928, 160, &test, 0.1f, false);*/
	

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;


}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");
	App->tex->UnLoad(graphics);

	return true;
}

void j1Scene::DrawTest()
{
	App->render->DrawQuad(test, 255, 0, 0, 100);
	App->render->DrawQuad(test2, 255, 127, 0, 100);
	App->render->DrawQuad(test3, 255, 255, 0, 100);
	App->render->DrawQuad(test4, 0, 255, 0, 100);
	App->render->DrawQuad(test5, 0, 0, 255, 100);
	App->render->DrawQuad(test6, 75, 0, 130, 100);
	App->render->DrawQuad(test7, 143, 0, 255, 100);
}

void j1Scene::DrawRay()
{
	App->render->DrawQuad(ray, 255, 0, 0, 200);
	App->render->DrawQuad(ray2, 255, 127, 0, 200);
	App->render->DrawQuad(ray3, 255, 255, 0, 200);
	App->render->DrawQuad(ray4, 0, 255, 0, 200);
	App->render->DrawQuad(ray5, 0, 0, 255, 200);
	App->render->DrawQuad(ray6, 75, 0, 130, 200);
	App->render->DrawQuad(ray7, 143, 0, 255, 200);
	
}

void j1Scene::DrawQ3()
{
	App->render->DrawCircle(1008, 176, 2, 255, 0, 0, 200);
	App->render->DrawCircle(1008, 176, 4, 255, 127, 0, 200);
	App->render->DrawCircle(1008, 176, 6, 255, 255, 0, 200);
	App->render->DrawCircle(1008, 176, 10, 0, 255, 0, 200);
	App->render->DrawCircle(1008, 176, 12, 0, 255, 200);
	App->render->DrawCircle(1008, 176, 14, 75, 0, 130, 200);
	App->render->DrawCircle(1008, 176, 16, 143, 0, 255, 200);


}

void j1Scene::DrawQ4()
{
	App->render->DrawCircle(1032, 168, 4, 150, 9, 21, 255);
	App->render->DrawCircle(1048, 168, 4, 247, 225, 79, 255);
	App->render->DrawCircle(1040, 176, 4, 245, 105, 24, 255);
	App->render->DrawCircle(1032, 184, 4, 235, 14, 14, 255);
	App->render->DrawCircle(1048, 184, 4, 255, 215, 0, 255);
}

void j1Scene::DrawQ5()
{
	App->render->DrawLine(1064, 168, 1080, 184, 150, 9, 21, 255);
	App->render->DrawLine(1064, 168, 1080, 184, 150, 9, 21, 255);
}
