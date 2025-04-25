#pragma once
#include "SFML\Graphics.hpp"
#include <map>
#include <iostream>
class Animation
{
public:
	sf::Sprite& sprite;
	sf::Texture& texture;
	float animationTimer;
	float timer;
	int width, height;
	sf::FloatRect startRect, currentRect, endRect;
	Animation(sf::Sprite& sprite, sf::Texture& texture, float width, float height, float timer
		, float start_frame_x, float start_frame_y, float frames_x, int frames_y)
		: sprite(sprite), texture(texture), width(width), height(height), timer(timer)
	{
		std::cout << "Animation constructor called: start frame" << start_frame_x<<  " " 
			<< start_frame_y << " ending frames"
			<< frames_x << " " << frames_y << std::endl;
		std::cout << "Size " << width << " " << height << std::endl;
		animationTimer = 0;
		startRect = sf::FloatRect({ start_frame_x * width, start_frame_y * height }
		, { width, height });
		currentRect = startRect;
		endRect = sf::FloatRect({ frames_x * width, frames_y * height }
		, { width, height });
	}
	void play(const float& dt)
	{
		sf::Vector2f position = sprite.getPosition();
		sf::Vector2f scale = sprite.getScale();
		std::cout << "Player position" << position.x << " " << position.y << std::endl;
		std::cout << "Player Scale" << scale.x << " " << scale.y << std::endl;
		this->timer += (100.f * dt);
		if (this->timer >= this->animationTimer)
		{
			this->timer = 0.f;

			//Animate
			if (this->currentRect.position.x <= this->endRect.position.x)
			{
				this->currentRect.position.x += this->width;
			}
			else //Reset
			{
				this->currentRect.position.x = this->startRect.position.x;
			}
			std::cout << "Current Rectangle " << currentRect.position.x 
				<< " " << currentRect.position.y << " "
				<< " "<< currentRect.size.x<<  " "
				<< currentRect.size.y<<std::endl;
			sprite.setTextureRect(sf::IntRect(this->currentRect));
		}
	}
	void reset()
	{
		this->timer = 0.f;
		this->currentRect = this->startRect;
	}
};
class AnimationComponent
{
private:
	
	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;
public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	virtual ~AnimationComponent();

	//Functions
	void addAnimation(const std::string key,
		float animation_timer,
		int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height);

	void play(const std::string key, const float& dt);
};

