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

    if (playerTexture.loadFromFile("Assets/Players/Texture/spritesheet.png"))
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
    animationComponent = new AnimationComponent(playerSprite, playerTexture);

    animationComponent->addAnimation("Fire", 10.f, 0, 3, 8, 3, 32, 32);
}
void Player::AddBullet(sf::Vector2f dir1, const sf::RectangleShape& sha, float bul1)
{
	if (bullets == nullptr)
	{
		bullets = new BulletLinkedList(std::make_unique<Bullet>(dir1, sha, bul1));
	}
	else
	{
		BulletLinkedList* b2 = bullets;
		while (b2->next != nullptr)
		{
			b2 = b2->next;
		}
		b2->next = new BulletLinkedList(std::make_unique<Bullet>(dir1, sha, bul1));
	}
}
void Player::ManageBullets(double &deltaTime, Enemy& enemy)
{
	// this logic has to be in gameState logic sort of cause this isnt entitie's logic 
	BulletLinkedList* b2 = bullets;
	BulletLinkedList* b2prev = nullptr;
    BulletLinkedList* start=nullptr;
	while (b2 != nullptr)
	{
		if (Math::DidRectCollide(b2->bullet->m_shape.getGlobalBounds(), 
            enemy.m_boundingRectangle.getGlobalBounds()))
		{
            if (b2prev != nullptr)
            {
                b2prev->next = nullptr;
            }
		}
		else if (b2->bullet->m_sprite.getPosition().x > 1920 || b2->bullet->m_sprite.getPosition().y > 1080
			|| b2->bullet->m_sprite.getPosition().x < 0 || b2->bullet->m_sprite.getPosition().y < 0)
		{
			if (b2prev != nullptr)
			{
				b2prev->next = nullptr;
			}
			
		}
		else
		{
            if (b2prev == nullptr)
            {
                start = b2;
            }
            if (b2prev != nullptr)
            {
				b2prev->next = b2;
            }
            
            b2prev = b2;
			b2->bullet->Update(deltaTime);
			
		}
		b2 = b2->next;
	}
    bullets = start;
}
void Player::Update(double deltaTime, Enemy &ene)
{
    sf::Vector2f position = playerSprite.getPosition();
    mvmt->move(position,deltaTime);
    playerSprite.setPosition(position);
    
    // firing bullet logic code 
    fireRateTimer += deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
    {
		animationComponent->play("Fire", deltaTime);
        sf::RectangleShape bullet(sf::Vector2f(50.0f, 25.0f));
		
		sf::Vector2f bdirection 
            = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)
            -playerSprite.getPosition();
		std::cout << bdirection.x << " " << bdirection.y << std::endl;
        bdirection = Math::NormalizeVector(bdirection);
        sf::FloatRect psz= playerSprite.getLocalBounds();
		sf::Vector2f offset = sf::Vector2f(psz.size.x / 2, psz.size.y / 2);
        bullet.setPosition(playerSprite.getPosition()+offset);
        // go to the end 
        AddBullet(bdirection, bullet, bulletspeed);
		fireRateTimer = 0.0f;
    }
    
    std::vector<std::unique_ptr<Bullet>> vb;
    // this logic has to be in gameState logic sort of cause this isnt entitie's logic 
    ManageBullets(deltaTime, ene);
    
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
	BulletLinkedList* b2 = bullets;
    while (b2 != nullptr)
    {
		b2->bullet->Draw(w);
		b2 = b2->next;
    }
}
