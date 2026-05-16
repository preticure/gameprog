#include <SDL3/SDL.h>
#include <vector>

#include "bg_sprite_component.h"

BGSpriteComponent::BGSpriteComponent(Actor *owner, int drawOrder)
	: SpriteComponent(owner, drawOrder)
	, mScrollSpeed(0.0f)
{
}

void BGSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);
	for (auto &bg : mBGTextures)
	{
		// Update the x offset
		bg.mOffset.x += mScrollSpeed * deltaTime;
		// If this is completely off the screen, reset offset to
		// the right of the last bg texture
		if (bg.mOffset.x < -mScreenSize.x)
		{
			bg.mOffset.x = (mBGTextures.size() - 1) * mScreenSize.x - 1;
		}
	}
}

void BGSpriteComponent::Draw(SDL_Renderer *renderer)
{
	// Draw each bg texture
	for (auto &bg : mBGTextures)
	{
		SDL_FRect r;
		// Assume screen size dimensions
		r.w = static_cast<int>(mScreenSize.x);
		r.h = static_cast<int>(mScreenSize.y);
		// Center the rectangle around the position of the owner
		r.x = static_cast<int>(bg.mOffset.x);
		r.y = static_cast<int>(bg.mOffset.y);

		// Draw this background
		SDL_RenderTexture(renderer, bg.mTexture, nullptr, &r);
	}
}

void BGSpriteComponent::SetBGTextures(const std::vector<SDL_Texture *> &textures)
{
	int count = 0;
	for (auto tex : textures)
	{
		BGTexture temp;
		temp.mTexture = tex;
		// Each texture is screen width in offset
		temp.mOffset.x = count * mScreenSize.x;
		temp.mOffset.y = 0.0f;
		mBGTextures.emplace_back(temp);
		count++;
	}
}
