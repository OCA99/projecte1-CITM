#ifndef __SCENE_LEVEL12_H__
#define __SCENE_LEVEL12_H__

#include "SceneLevel.h"
#include "Animation.h"

struct SDL_Texture;

class SceneLevel12 : public SceneLevel
{
public:
	//Constructor
	SceneLevel12(bool startEnabled);

	//Destructor
	~SceneLevel12();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;


	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate() override;

	// Disables the player and the enemies
	bool CleanUp();

	bool win = false;

public:
};

#endif