#include "Player.h"
#include "../Math.h"
#include <iostream>
//sf::Vector2f position = { 0,0 }, sf::Vector2f scale = { 1,1 }, sf::Vector2f size = { 1,1 }
//, sf::Vector2f dimension = { 1,1 }

template<typename Config>
Player<Config>::Player(sf::Vector2f size, sf::Vector2f position, 
    Map<Config> &map) 
    :playerSprite(playerTexture)
, Entity(position,Config::Entity::Player::PLAYER_SCALE, size), m_map(map)
{
    //sf::Vector2f maxvelocity, sf::Vector2f accelaration,
    //sf::Vector2f decelaration
    mvmt = new Movement(Config::Entity::Player::PLAYER_SPEED
        , Config::Entity::Player::PLAYER_MAX_SPEED,
        Config::Entity::Player::PLAYER_ACCELERATION,
        Config::Entity::Player::PLAYER_DECELERATION);

    m_size = size;
    m_boundingRectangle.setFillColor(Config::Entity::Player::PLAYER_BOUNDING_RECTANGLE_COLOR);
    m_boundingRectangle.setOutlineColor(Config::Entity::Player::PLAYER_BOUNDING_RECTANGLE_OUTLINE_COLOR);
    m_boundingRectangle.setOutlineThickness(Config::Entity::Player::PLAYER_BOUNDING_RECTANGLE_THICKNESS);
    m_boundingRectangle.setSize(m_size);
    m_boundingRectangle.setScale(m_scale);
}
template<typename Config>
void Player<Config>::Initialize()
{
    
}
template<typename Config>
void Player<Config>::Load()
{

    if (playerTexture.loadFromFile("Assets/Players/Texture/spritesheet.png"))
    {
        std::cerr << "Player texture loaded succesfully" << std::endl;
    }
    else
    {
        std::cout << "You are in the player Load and the texture failed to load" << std::endl;
        abort();
    }
    playerSprite.setTexture(playerTexture);
    float XIndex = 0,YIndex=0;
    playerSprite.setTextureRect(sf::IntRect({ (int)XIndex* (int)m_size.x,(int)YIndex* (int)m_size.y}, 
        { (int)m_size.x,(int)m_size.y }));
    playerSprite.setScale(m_scale);
    playerSprite.setPosition(sf::Vector2f(1650, 800));
    animationComponent = new AnimationComponent(playerSprite, playerTexture);

    animationComponent->addAnimation("Fire", 10.f, 0, 3, 8, 3, 32, 32);
	animationComponent->addAnimation("Idle", 10.f, 0, 0, 8, 0, 32, 32);
	animationComponent->addAnimation("Run", 10.f, 0, 2, 3, 2, 32, 32);
}
template<typename Config>
Bullet<Config>* Player<Config>::AddBullet(sf::Vector2f dir1, const sf::RectangleShape& sha, float bul1)
{
    return new Bullet<Config>(Team::PLAYER, dir1, sha, bul1);
}
template<typename Config>
void Player<Config>::ManageBullets(double &deltaTime)
{

}
template<typename Config>
void Player<Config>::Update(double deltaTime)
{ 

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
        or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        animationComponent->play("Run", deltaTime);
        
    
    }
    mvmt->move<Config>(playerSprite,m_map, deltaTime);

    m_boundingRectangle.setPosition(playerSprite.getPosition());
    m_boundingRectangle.setScale(sf::Vector2f( 
        abs(m_boundingRectangle.getScale().x)*(playerSprite.getScale().x
            /abs(playerSprite.getScale().x))
        ,abs(m_boundingRectangle.getScale().y) * 
        (playerSprite.getScale().y / abs(playerSprite.getScale().y))));
    

}
template<typename Config>
void Player<Config>::DrawUpdate()
{

}
template<typename Config>
Bullet<Config>* Player<Config>::Shoot(double deltaTime)
{
    animationComponent->play("Fire", deltaTime);
    sf::RectangleShape bullet(sf::Vector2f(50.0f, 25.0f));

    sf::Vector2f shootingposn;
	int sgn = playerSprite.getScale().x/abs(playerSprite.getScale().x);
    if (sgn == 1)
    {
        shootingposn = sf::Vector2f(playerSprite.getGlobalBounds().position.x + 
            (playerSprite.getGlobalBounds().size.x)
            , playerSprite.getGlobalBounds().position.y
            + (playerSprite.getGlobalBounds().size.y) / 2);
    }
    else 
    {
		shootingposn = sf::Vector2f(playerSprite.getGlobalBounds().position.x
			, playerSprite.getGlobalBounds().position.y
			+ (playerSprite.getGlobalBounds().size.y) / 2);
    }
    sf::Vector2f bdirection
        = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)
        - shootingposn;
    bdirection = Math::NormalizeVector(bdirection);
    bullet.setPosition(shootingposn);
    // go to the end 
    fireRateTimer = 0.0f;
    return AddBullet(bdirection, bullet, bulletspeed);
}
template<typename Config>
void Player<Config>::Draw(sf::RenderWindow &w)
{
    w.draw(playerSprite);
    w.draw(m_boundingRectangle);
}


#include "../Settings/Config.h"
template class Player<Config>;