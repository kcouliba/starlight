#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "starlight.hpp"
#include "AEntity.hpp"

class Player : public AEntity
{
    public:
        Player(void);
        Player(std::string const name, sf::IntRect hitbox, sf::Vector2i position, float const speed);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        void                            speedUp(float const speed);
        void                            speedDown(float const speed);

        void                            introduce(void) const;

        void                            handleInput(void);

    protected:

    private:
};

#endif // PLAYER_HPP
