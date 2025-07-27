#pragma once  
#include <SFML/Graphics.hpp>  
#include <string>

class Config  
{  
public:  

   struct Entity {
       struct Player {
		static constexpr float FIRE_RATE = 150.0f; // Fire rate in milliseconds
		static constexpr float PLAYER_HEALTH = 100.0f; // Health of the player
        static constexpr sf::Vector2f PLAYER_SPEED = sf::Vector2f(1.0f,1.0f);
		static constexpr sf::Vector2f PLAYER_MAX_SPEED = sf::Vector2f(100.0f, 100.0f); // Maximum speed of the player
		static constexpr sf::Vector2f PLAYER_ACCELERATION = sf::Vector2f(0.2f, 0.2f); // Acceleration of the player	
		static constexpr sf::Vector2f PLAYER_DECELERATION = sf::Vector2f(0.1f, 0.1f); // Deceleration of the player
		static constexpr sf::Vector2f PLAYER_SCALE = sf::Vector2f(3.0f, 3.0f); // Scale factor for the player sprite	
		static constexpr sf::IntRect PLAYER_TEXTURE_RECT = sf::IntRect({ 0,0 }, { 32,32 }); // Texture rectangle for the player sprite
		static constexpr sf::Vector2f PLAYER_SIZE = sf::Vector2f(32.0f, 32.0f); // Size of the player sprite
		static constexpr sf::Vector2f PLAYER_POSITION = sf::Vector2f(1650.0f, 800.0f); // Initial position of the player
	
		static constexpr sf::Color PLAYER_BOUNDING_RECTANGLE_COLOR = sf::Color::Transparent; // Color of the 		
		static constexpr sf::Color PLAYER_BOUNDING_RECTANGLE_OUTLINE_COLOR = sf::Color::Red; // Color of the 
		static constexpr int PLAYER_BOUNDING_RECTANGLE_THICKNESS = 1; // Color of the player sprite
	};

      struct Enemy {
		static constexpr float ENEMY_SPEED = 3.0f; // Speed of the enemy
		static constexpr float ENEMY_HEALTH = 100; // Health of the enemy
		static constexpr sf::Vector2f ENEMY_SCALE = sf::Vector2f(3.0f, 3.0f); // Scale factor for the enemy sprite
		static constexpr sf::IntRect ENEMY_TEXTURE_RECT = sf::IntRect({ 0,0 }, { 85,94 }); // Texture rectangle for the enemy sprite
		static constexpr sf::Vector2f ENEMY_SIZE = sf::Vector2f(85.0f, 94.0f); // Size of the enemy sprite
           
		static constexpr sf::Vector2f ENEMY_POSITION = sf::Vector2f(400.0f, 100.0f); // Initial position of the enemy
		static constexpr sf::Vector2f ENEMY_DIMENSION = sf::Vector2f(1.0f, 1.0f); // Dimension of the enemy
		static constexpr int CHAR_SIZE = 18; // Character size for the enemy health text
       };
	struct Bullet {
		static constexpr const char* BULLET_TEXTURE_PATH= "Assets/Bullet/Arrow.png"; // Path to the bullet texture

		static constexpr float BULLET_SPEED = 10.0f; // Speed of the bullet
		static constexpr int BULLET_DAMAGE = 10; // Damage dealt by the bullet
		static constexpr float BULLET_LIFETIME = 5.0f; // Lifetime of the bullet in seconds
		static constexpr sf::IntRect BULLET_TEXTURE_RECT = sf::IntRect({ 0,0 }, { 367,41 }); // Texture rectangle for the bullet sprite
		static constexpr sf::Vector2f BULLET_SCALE = sf::Vector2f(0.1f, 0.5f); // Scale factor for the bullet sprite in X direction
                       
       };
       
   };
  
  struct Graphics {  

	  struct Map {




	  };

      struct Window {  
      };  

      struct Button {  
		  static constexpr const char* 
			  BUTTON_LIT_PATH = "Assets/Button/litbutton.png"; // Path to the bullet texture
		  static constexpr const char* 
			  BULLET_DIM_PATH = "Assets/Button/dimbutton.png"; // Path to the bullet texture


		static constexpr sf::Color IDLE_COLOR=sf::Color(52,152,219); // Declare as a static const  
		static constexpr sf::Color HOVER_COLOR = sf::Color(41, 128, 185);
		static constexpr sf::Color ACTIVE_COLOR = sf::Color(31, 97, 141);
     
      };  
  };  

  static constexpr float JUMP_HEIGHT = 10.0f;  
  static constexpr int WINDOW_WIDTH = 1920;  
  static constexpr int WINDOW_HEIGHT = 1080;  
  static constexpr bool VSYNC_ENABLED = true;  
  static constexpr int MAX_ENTITIES = 1000;  
  static constexpr float GRAVITY = -9.81f;  
  static constexpr int AUDIO_CHANNELS = 32;  
  static constexpr float CAMERA_FOV = 75.0f;  
  static constexpr bool DEBUG_MODE = false;  

  enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED };  
};  

