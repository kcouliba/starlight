#include "AEntity.hpp"

AEntity::AEntity(void)
    : _name("unnamed"), _currentAnim(NULL), _position(0, 0), _speed(DEFAULT_SPEED)
{
    this->_animation.clear();
    this->_hitBox = sf::IntRect(0, 0, 1, 1);
    this->_hitPoint = 1;
    return ;
};

AEntity::AEntity(std::string const name, sf::IntRect hitbox, sf::Vector2i position, float const speed)
    : _name(name), _currentAnim(NULL), _hitBox(hitbox), _position(position), _speed(speed)
{
    this->_animation.clear();
    this->_hitPoint = 1;
    return ;
}

AEntity::AEntity(const AEntity& other)
    : _name(other.getName()), _animation(other.getAnimation())
    , _currentAnim(other.getCurrentAnimation()), _hitBox(other.getHitBox())
    , _position(other.getPosition()), _speed(other.getSpeed())
    , _hitPoint(other.getHitPoint())
{
    return ;
}

AEntity& AEntity::operator=(const AEntity& rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_animation = rhs.getAnimation();
        this->_currentAnim = rhs.getCurrentAnimation();
        this->_hitBox = rhs.getHitBox();
        this->_position = rhs.getPosition();
        this->_speed = rhs.getSpeed();
        this->_hitPoint = rhs.getHitPoint();
    }
    return (*this);
}

AEntity::~AEntity()
{
    this->_animation.clear();
    this->_currentAnim = NULL;
    return ;
}

std::string                     AEntity::getName(void) const
{
    return (this->_name);
}

std::vector<anim::Animation*>   AEntity::getAnimation(void) const
{
    return (this->_animation);
}

anim::Animation                 *AEntity::getCurrentAnimation(void) const
{
    return (this->_currentAnim);
}

sf::IntRect                     AEntity::getHitBox(void) const
{
    return (this->_hitBox);
}

sf::Vector2i                    AEntity::getPosition(void) const
{
    return (this->_position);
}

float                           AEntity::getSpeed(void) const
{
    return (this->_speed);
}

sf::FloatRect                   AEntity::getGlobalBounds(void) const
{
    return ((*this->_currentAnim)[this->_currentAnim->getCurrentFrameIndex()].getGlobalBounds());
}

unsigned int                    AEntity::getHitPoint(void) const
{
    return (this->_hitPoint);
}

void                            AEntity::setName(std::string const name)
{
    this->_name = name;
    return ;
}

void                            AEntity::setCurrentAnimation(int id)
{
    this->_currentAnim = this->_animation[id];
    this->_currentAnim->play();
    this->update();
    return ;
};

void                            AEntity::setHitBox(sf::IntRect hitbox)
{
    this->_hitBox = hitbox;
    return ;
}

void                            AEntity::setPosition(sf::Vector2i position)
{
    this->_position = position;
    return ;
}

void                            AEntity::setSpeed(float const speed)
{
    this->_speed = speed;
    return ;
}

void                            AEntity::setHitPoint(unsigned int const hitPoint)
{
    this->_hitPoint = hitPoint;
    return ;
}

void                            AEntity::addAnimation(anim::Animation *animation)
{
    this->_animation.push_back(animation);
    return ;
};

void                            AEntity::update(void)
{
    if (this->_currentAnim != NULL)
    {
        this->_currentAnim->setPosition(this->_position.x, this->_position.y);
        this->_currentAnim->update();
    }
    return ;
};

void                            AEntity::render(sf::RenderWindow &win)
{
    if (this->_currentAnim != NULL)
    {
        this->update();
        this->_currentAnim->render(win);
    }
    return ;
};
