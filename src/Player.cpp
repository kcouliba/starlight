#include "Player.hpp"

Player::Player(void)
    : AEntity::AEntity()
{
    return ;
};

Player::Player(std::string const name, sf::IntRect hitbox, sf::Vector2i position, float const speed)
    : AEntity::AEntity(name, hitbox, position, speed)
{
    return ;
}

Player::Player(const Player& other)
    : AEntity::AEntity(other)
{
    return ;
}

Player& Player::operator=(const Player& rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

Player::~Player()
{
    return ;
}

void                            Player::speedUp(float const speed)
{
    float                       currentSpeed = this->getSpeed();

    currentSpeed += speed;
    currentSpeed = (currentSpeed > MAX_PLYR_SPEED) ? MAX_PLYR_SPEED : currentSpeed;
    this->setSpeed(currentSpeed);
    return ;
}

void                            Player::speedDown(float const speed)
{
    float                       currentSpeed = this->getSpeed();

    currentSpeed -= speed;
    currentSpeed = (currentSpeed < MIN_PLYR_SPEED) ? MIN_PLYR_SPEED : currentSpeed;
    this->setSpeed(currentSpeed);
    return ;
}

void                            Player::introduce(void) const
{
    std::cout << "Hi ! " << this->getName() << " at command." << std::endl;
}

void                            Player::handleInput(void)
{
    float                       currentSpeed = this->getSpeed();
    sf::Vector2i                position = this->getPosition();
    sf::FloatRect               bounds = this->getGlobalBounds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        position.y -= currentSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        position.y += currentSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        position.x -= currentSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        position.x += currentSpeed;
    }
    position.x = (position.x < 0) ? 0 : position.x;
    position.x = (position.x + bounds.width >= W_WIDTH) ? W_WIDTH - bounds.width : position.x;
    position.y = (position.y < 0) ? 0 : position.y;
    position.y = (position.y + bounds.height >= W_HEIGHT) ? W_HEIGHT - bounds.height : position.y;
    this->setPosition(position);
    return ;
};
