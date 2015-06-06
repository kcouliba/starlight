#ifndef AEntity_HPP
#define AEntity_HPP

#include "starlight.hpp"
#include "Animation.hpp"

class AEntity
{
    public:
        AEntity(void);
        AEntity(std::string const name, sf::IntRect hitbox, sf::Vector2i position, float const speed);
        virtual ~AEntity();
        AEntity(const AEntity& other);
        AEntity& operator=(const AEntity& other);

        std::string                     getName(void) const;
        std::vector<anim::Animation*>   getAnimation(void) const;
        anim::Animation                 *getCurrentAnimation(void) const;
        sf::IntRect                     getHitBox(void) const;
        sf::Vector2i                    getPosition(void) const;
        float                           getSpeed(void) const;
        sf::FloatRect                   getGlobalBounds(void) const;
        unsigned int                    getHitPoint(void) const;

        void                            setName(std::string const name);
        void                            setCurrentAnimation(int id);
        void                            setHitBox(sf::IntRect hitbox);
        void                            setPosition(sf::Vector2i position);
        void                            setSpeed(float const speed);
        void                            setHitPoint(unsigned int const hitPoint);

        void                            addAnimation(anim::Animation *animation);
        void                            update(void);
        void                            render(sf::RenderWindow &win);

        virtual void                    introduce(void) const = 0;

    protected:

    private:
        std::string                     _name;
        std::vector<anim::Animation*>    _animation;
        anim::Animation                 *_currentAnim;
        sf::IntRect                     _hitBox;
        sf::Vector2i                    _position;
        float                           _speed;
        unsigned int                    _hitPoint;
};

#endif // AEntity_HPP
