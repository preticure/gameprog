#pragma once

#include <vector>
#include <SDL3/SDL.h>

#include "sprite_component.h"

class AnimSpriteComponent : public SpriteComponent
{
public:
	AnimSpriteComponent(class Actor *owner, int drawOrder = 100);

	// Update animation every frame (overridden from component)
	void Update(float deltaTime) override;
	// Set the textures used from animation
	void SetAnimTextures(const std::vector<SDL_Texture *> &textures);

	// Set/get animation FPS
	void SetAnimFPS(float animFPS)
	{
		mAnimFPS = animFPS;
	}
	float GetAnimFPS() const
	{
		return mAnimFPS;
	}
private:
	// all textures in the animation
	std::vector<SDL_Texture *> mAnimTextures;
	// Current frame displayed
	float mCurrFrame;
	// Animation frame rate
	float mAnimFPS;
};