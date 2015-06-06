#ifndef ANIMATION_HPP
# define ANIMATION_HPP

# include "starlight.hpp"

namespace anim
{
    class Animation
    {
        public:
            Animation(void);
            Animation(sf::Texture const * texture, t_uint const nbFrames, sf::IntRect area = sf::IntRect());
            Animation(Animation const & other);
            Animation & operator=(Animation const & rhs);
            sf::Sprite & operator[](t_uint const index);

            virtual ~Animation();

            std::string         getName(void) const;
            sf::Texture const   *getSpriteSheet(void) const;
            sf::IntRect         getSpriteSheetArea(void) const;
            sf::Sprite          *getFrames(void) const;
            t_uint              getNbFrames(void) const;
            sf::Vector2f const  getPosition(void) const;
            t_uint const        getPlayingState(void) const;
            t_uint const        getCurrentFrameIndex(void) const;
            float               getSpeed(void) const;

            void                setName(std::string const name);
            void                setSpriteSheet(sf::Texture const * spritesheet, sf::IntRect const & area = sf::IntRect());
            void                setSpriteSheetArea(sf::IntRect area);
            void                setNbFrames(t_uint const nbFrames);
            void                scale(float x, float y);
            void                setScale(float x, float y);
            void                setCurrentFrame(t_uint const index);
            void                setPosition(float const x, float const y);
            void                setCancelable(bool const cancelable);
            void                setSpeed(float const speed);

            bool                done(void) const;
            bool                cancelable(void) const;
            void                splitFrames(t_uint sizeX, t_uint sizeY);
            void                play(void);
            void                pause(void);
            void                stop(void);

            void                update(void);
            void                render(sf::RenderWindow & win);

        protected:

        private:
            std::string         _name;
            sf::Texture const   *_spritesheet;
            sf::IntRect         _spritesheetArea;
            t_uint              _nbFrames;
            sf::Sprite          *_frames;
            t_uint              _currentFrameIndex;
            t_uint              _playingState;
            sf::Vector2f        _position;
            t_uint              _frameCounter;
            t_uint              _frameRate;
            bool                _done;
            bool                _cancelable;
            float               _speed;
    };
}

#endif // ANIMATION_HPP
