#include "Animation.h"

Animation::Animation(const char* filename, SDL_Surface *screen, unsigned int tilesX, unsigned int tilesY, unsigned int frameRate)
: Texture(filename, screen), currentFrame(0), frameTime(1.0f / frameRate), frameTimeLeft(frameTime), maxFrame(tilesX * tilesY), isBackward(false), stopped(true)
{
	this->tilesX = tilesX;
	this->tilesY = tilesY;
	this->frameRate = frameRate;
}

void Animation::update(){
	static float lastTime = SDL_GetTicks() / 1000.0f;

	float timeSinceLastTime = (SDL_GetTicks() / 1000.0f) - lastTime;
	
	frameTimeLeft -= timeSinceLastTime;

	if (!stopped) {
		if (frameTimeLeft <= 0.0f){
			if (!isBackward) {
				if (currentFrame == maxFrame - 1){
					currentFrame = 0;
				}else{
					currentFrame++;
				}
			}
			else {
				if (currentFrame == 0){
					currentFrame = maxFrame-1;
				}else{
					currentFrame--;
				}
			}
			frameTimeLeft = frameTime;
		}
	}

	lastTime = SDL_GetTicks() / 1000.0f;
}

void Animation::drawTexture(int x, int y){
	SDL_Rect destRect;
	destRect.x = x;
	destRect.y = y;

	SDL_Rect frameRect;
	frameRect.w = width / tilesX;
	frameRect.h = height / tilesY;
	frameRect.x = currentFrame % tilesX * frameRect.w;
	frameRect.y = currentFrame / tilesX * frameRect.h;

	SDL_BlitSurface(surface, &frameRect, displaySurface, &destRect);
}

void Animation::runForward() {
	isBackward = false;
}

void Animation::runBackward() {
	isBackward = true;
}

void Animation::stop() {
	stopped = true;
}