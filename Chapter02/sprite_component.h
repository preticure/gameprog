#pragma once

#include <SDL3/SDL.h>

#include "component.h"

class SpriteComponent : public Component
{
public:
	// (Lower draw order corresponds to farther back)
	SpriteComponent(class Actor *owner, int drawOrder = 100);
	~SpriteComponent();

	virtual void Draw(SDL_Renderer *renderer);
	virtual void SetTexture(SDL_Texture *texture);

	int GetDrawOrder() const { return mDrawOrder; }
	int GetTextureHeight() const { return static_cast<int>(mTexHeight); }
	int GetTextureWidth() const { return static_cast<int>(mTexWidth); }

private:
	SDL_Texture *mTexture;
	int mDrawOrder;
	float mTexHeight;
	float mTexWidth;
};