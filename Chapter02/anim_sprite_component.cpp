#include "anim_sprite_component.h"

AnimSpriteComponent::AnimSpriteComponent(Actor *owner, int drawOrder)
	: SpriteComponent(owner, drawOrder), mCurrFrame(0.0f), mAnimFPS(24.0f)
{
}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	if (mAnimTextures.size() > 0)
	{
		// Update current frame based on frame rate and delta time
		mCurrFrame += mAnimFPS * deltaTime;

		// Wrap current frame if needed
		while (mCurrFrame >= mAnimTextures.size())
		{
			mCurrFrame -= mAnimTextures.size();
		}

		// Set the current texture
		SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
	}
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture *> &textures)
{
	mAnimTextures = textures;
	if (!mAnimTextures.empty())
	{
		// Set the active texture to the first frame
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
	}
}