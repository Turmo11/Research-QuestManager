#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Audio.h"
#include "j1Scene.h"
#include "j1Gui.h"
#include<iostream>



j1Gui::j1Gui() : j1Module()
{
	name = ("gui");

}

// Destructor
j1Gui::~j1Gui()
{}

// Called before the first frame
bool j1Gui::Start()
{
	
	score = 0;

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	
	

	return true;
}

bool j1Gui::Update()
{
	

	

	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{	

	

	

	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	

	return true;
}






