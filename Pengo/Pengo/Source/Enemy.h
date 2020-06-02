#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

#include <random>
#include <stdlib.h> // used for random
#include <time.h> // used for random

struct SDL_Texture;
struct Collider;

class Enemy
{
public:
	// Constructor
	// Saves the spawn position for later movement calculations
	Enemy(int x, int y, int color);

	// Destructor
	virtual ~Enemy();

	// Called from inhering enemies' Udpate
	// Updates animation and collider position
	virtual void Update();

	// Called from ModuleEnemies' Update
	virtual void Draw();

	// Sets flag for deletion and for the collider aswell
	virtual void SetToDelete();

	void Pushed(int fromx, int fromy);

	void WallStunned(int wallID);

	void SetPosition(int x, int y);

	void GetNextTargetTile();

	void GetNextStepToTarget();

	enum class Directions {
		Up,
		CrushUp,
		Down,
		CrushDown,
		Left,
		CrushLeft,
		Right,
		CrushRight,
		Stopped,

	};

	Directions direction = Directions::Stopped;

public:
	// The current position in the world
	iPoint position;
	iPoint gridPosition;
	iPoint targetPosition;
	iPoint targetTile;

	// The enemy's texture
	SDL_Texture* texture = nullptr;

	// A flag for the enemy removal. Important! We do not delete objects instantly
	bool pendingToDelete = false;

	void destroy();

	bool stunned = false;

protected:
	// A ptr to the current animation
	Animation* currentAnim = nullptr;
	Animation spawnAnim;
	Animation walkDownAnim;
	Animation idleAnim;
	Animation crushUp;
	Animation crushDown;
	Animation crushLeft;
	Animation crushRight;
	Animation stunAnim;

private:
	int speed = 1;
	bool moving = false;
	std::random_device generator;

	float ABS(float x) {
		return x > 0 ? x : -x;
	}
};

#endif // __ENEMY_H__