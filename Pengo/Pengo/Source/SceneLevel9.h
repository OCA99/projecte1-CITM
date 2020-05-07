#ifndef __SCENE_LEVEL9_H__
#define __SCENE_LEVEL9_H__

#include "SceneLevel.h"
#include "Animation.h"

struct SDL_Texture;

class SceneLevel9 : public SceneLevel
{
public:
	//Constructor
	SceneLevel9(bool startEnabled);

	//Destructor
	~SceneLevel9();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate() override;

	// Disables the player and the enemies
	bool CleanUp();

public:
};

#endif