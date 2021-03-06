#ifndef _Animation_H
#define _Animation_H

#include "Texture.h"

class Animation : public Texture{
	private:
		unsigned int tilesX;
		unsigned int tilesY;
		unsigned int frameRate;

		unsigned int currentFrame;
		const unsigned int maxFrame;

		const float frameTime;
		float frameTimeLeft;

		bool isBackward;
		bool stopped;

	public:
		Animation(const char* filename, SDL_Surface *screen, unsigned int tilesX, unsigned int tilesY, unsigned int frameRate);

		virtual void update();
		//to rename to draw
		virtual void drawTexture(int x, int y);

		void runForward();
		void runBackward();
		void stop();
};

#endif