#include "AnimationComponent.h"
#include <iostream>
AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet)
    :sprite(sprite), textureSheet(texture_sheet)
{

}

AnimationComponent::~AnimationComponent()
{
    for (auto& i : this->animations)
    {
        delete i.second;
    }
}

//Functions


void AnimationComponent::addAnimation(
    const std::string key,
    float animation_timer,
    int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height
)
{
    this->animations[key] = new Animation(
        this->sprite, this->textureSheet, width, height,
        animation_timer,
        start_frame_x, start_frame_y, frames_x, frames_y
    );
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	if (this->animations.find(key) == this->animations.end())
	{
		std::cout << "Animation with key: " << key << " does not exist!" << std::endl;
		return;
	}
    this->animations[key]->play(dt);
}