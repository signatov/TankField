#include "Object.h"

Object::Object(Texture *texture)
	: velocity(0,0), speed(500) {
	this->texture = texture;
	this->position.x = 500;
	this->position.y = 200;
}


void Object::moveUp(){
	velocity = Vector2D(0, -1) * speed;
}

void Object::moveDown(){
	velocity = Vector2D(0, 1) * speed;
}

void Object::moveLeft(){
	velocity = Vector2D(-1, 0) * speed;
}

void Object::moveRight(){
	velocity = Vector2D(1, 0) * speed;
}

void Object::stop(){
	velocity = Vector2D(0, 0);
}

void Object::update(){
	static float lastTime = SDL_GetTicks() / 1000.0f;

	float timeSinceLastTime = (SDL_GetTicks() / 1000.0f) - lastTime;

	position += velocity * timeSinceLastTime;

	texture->update();

	lastTime = SDL_GetTicks() / 1000.0f;
}

void Object::render(){
	texture->drawTexture((int)this->position.x,(int)this->position.y);
}

