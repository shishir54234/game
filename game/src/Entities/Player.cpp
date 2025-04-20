#include "Player.h"
#include "../Math.h"
#include <iostream>
//sf::Vector2f position = { 0,0 }, sf::Vector2f scale = { 1,1 }, sf::Vector2f size = { 1,1 }
//, sf::Vector2f dimension = { 1,1 }
Player::Player(sf::Vector2f size, sf::Vector2f position) :playerSprite(playerTexture)
, Entity(position,sf::Vector2f(3,3), size)
{
    //sf::Vector2f maxvelocity, sf::Vector2f accelaration,
    //sf::Vector2f decelaration
    mvmt = new Movement(sf::Vector2f(1,1),sf::Vector2f(100,100), sf::Vector2f(0.2,0.2),sf::Vector2f(0.1,0.1));

    m_size = size;
    m_boundingRectangle.setFillColor(sf::Color::Transparent);
    m_boundingRectangle.setOutlineColor(sf::Color::Red);
    m_boundingRectangle.setOutlineThickness(1);
    m_boundingRectangle.setSize(sf::Vector2f(m_size.x, m_size.y));
    m_boundingRectangle.setScale({ m_scale.x,m_scale.y });
}

void Player::Initialize()
{
    
}
void Player::Load()
{

    if (playerTexture.loadFromFile("Assets/Players/Texture/player_front_face.png"))
    {
        std::cerr << "Player texture loaded succesfully" << std::endl;
    }
    else
    {
        std::cout << "You are in the player Load and the texture failed to load" << std::endl;
    }
    playerSprite.setTexture(playerTexture);

    float XIndex = 0,YIndex=0;
    playerSprite.setTextureRect(sf::IntRect({ (int)XIndex* (int)m_size.x,(int)YIndex* (int)m_size.y}, { (int)m_size.x,(int)m_size.y }));
    playerSprite.setScale(m_scale);
    playerSprite.setPosition(sf::Vector2f(1650, 800));
}
void Player::Update(double deltaTime, Enemy &ene)
{
    sf::Vector2f position = playerSprite.getPosition();
    mvmt->move(position,deltaTime);
    playerSprite.setPosition(position);
    
    // firing bullet logic code 
    fireRateTimer += deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X) and fireRateTimer>=maxFireRate)
    {
        
        sf::RectangleShape bullet(sf::Vector2f(50.0f, 25.0f));
		bullet.setPosition(playerSprite.getPosition());
		sf::Vector2f bdirection 
            = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)
            -playerSprite.getPosition();
		std::cout << bdirection.x << " " << bdirection.y << std::endl;
        bdirection = Math::NormalizeVector(bdirection);
        Bullet b = Bullet(bdirection, bullet, bulletspeed);
		bullets.push_back(b);

		fireRateTimer = 0.0f;
    }
    
    std::vector<Bullet> vb;
    // this logic has to be in gameState logic sort of cause this isnt entitie's logic 
    for (size_t i=0;i<bullets.size();i++)
    {       
            bullets[i].Update(deltaTime);
            if (Math::DidRectCollide(bullets[i].shape.getGlobalBounds(), 
                ene.playerSprite.getGlobalBounds()))
            {
                ene.ChangeHealth(-10);
            }
            else 
            {
                vb.push_back(bullets[i]);
            }
    }
	
    bullets = vb;
    vb.clear();
    m_boundingRectangle.setPosition(playerSprite.getPosition());
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
    w.draw(m_boundingRectangle);
    for (auto& x : bullets)
    {
		x.Draw(w);  
    }
}
