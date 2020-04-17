#include "Animation.h"

#include <iostream>

Animation::Animation(SDL_Texture* _source, SDL_Rect* location, int rows, int columns, int _delay, std::function<void()> _callback)
{
	source = _source;
	int frameWidth = location->w / columns;
	int frameHeight = location->h / rows;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			SDL_Rect frame;
			frame.x = location->x + j * frameWidth;
			frame.y = location->y + i * frameHeight;
			frame.w = frameWidth;
			frame.h = frameHeight;
			frames.push_back(frame);
		}
	}
	delay = _delay;
	callback = _callback;
}

Animation::~Animation()
{
}

void Animation::step() {
	if (!running) return;
	timer++;
	if (timer == delay) {
		timer = 0;
		currentFrame++;
		if (currentFrame == frames.size()) {
			currentFrame = 0;
			if (callback != nullptr) callback();
		}
	}
}

void Animation::play() {
	running = true;
}

void Animation::pause() {
	running = false;
}

SDL_Rect* Animation::getFrame() {
	return &frames[currentFrame];
}