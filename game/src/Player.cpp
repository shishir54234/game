#include "Player.h"
#include "Math.h"
#include <iostream>

Player::Player() :playerSprite(playerTexture)

{
    //// Initialize playerSprite with the playerTexture
    //playerSprite.setTexture(playerTexture);
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);
    boundingRectangle.setSize(sf::Vector2f(width, height));
    boundingRectangle.setScale({ scaleX,scaleY });
}

void Player::Initialize()
{
    size = sf::Vector2f(width,height);
}
void Player::Load()
{

    if (!playerTexture.loadFromFile("Assets/Players/Texture/player_front_face.png"))
    {
        std::cerr << "Error loading player texture" << std::endl;
    }
    playerSprite.setTexture(playerTexture);

    float XIndex = 0,YIndex=0;
    playerSprite.setTextureRect(sf::IntRect({ (int)XIndex* (int)size.x,(int)YIndex* (int)size.y}, { (int)width,(int)height }));
    playerSprite.setScale({ scaleX,scaleY });
    playerSprite.setPosition(sf::Vector2f(1650, 800));
}
void Player::Update(double deltaTime, Enemy &ene)
{
    sf::Vector2f position = playerSprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        playerSprite.setPosition(position + sf::Vector2f(1, 0)*(float)deltaTime * playerSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        playerSprite.setPosition(position + sf::Vector2f(-1, 0) * (float)deltaTime * playerSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        playerSprite.setPosition(position + sf::Vector2f(0, -1) * (float)deltaTime * playerSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        playerSprite.setPosition(position + sf::Vector2f(0, 1) * (float)deltaTime * playerSpeed);
    }
    //----------------------------------------------
    fireRateTimer += deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X) and fireRateTimer>=maxFireRate)
    {
        sf::RectangleShape bullet(sf::Vector2f(50.0f, 25.0f));
		bullet.setPosition(playerSprite.getPosition());
        //auto bdirection = ene.playerSprite.getPosition() - mouse;
		sf::Vector2f bdirection = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)-playerSprite.getPosition();
		//
		std::cout << bdirection.x << " " << bdirection.y << std::endl;
        bdirection = Math::NormalizeVector(bdirection);
        Bullet b = Bullet(bdirection, bullet, bulletspeed);
		bullets.push_back(b);

		fireRateTimer = 0.0f;
    }
    
    std::vector<Bullet> vb;
    for (size_t i=0;i<bullets.size();i++)
    {
        /*if (ene.health > 0) 
        {*/
            
            bullets[i].Update(deltaTime);
            if (Math::DidRectCollide(bullets[i].shape.getGlobalBounds(), ene.playerSprite.getGlobalBounds()))
            {
                ene.ChangeHealth(-10);
            }
            else 
            {
                vb.push_back(bullets[i]);
            }
        //}
    }
	
    bullets = vb;
    vb.clear();
    boundingRectangle.setPosition(playerSprite.getPosition());
}

void Player::DrawUpdate()
{

}

void Player::Shoot(Bullet &b)
{
}

void Player::Draw(sf::RenderWindow &w)
{
    w.draw(playerSprite);
    w.draw(boundingRectangle);
    for (auto& x : bullets)
    {
		x.Draw(w);  
    }
}
