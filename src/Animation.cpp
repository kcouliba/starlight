#include "../include/Animation.hpp"

namespace anim
{
    Animation::Animation(void)
        : _spritesheet(NULL), _nbFrames(0)
        , _frames(NULL) , _currentFrameIndex(0), _playingState(STOPPED)
        , _frameCounter(0), _done(false), _cancelable(true), _speed(1.0f)
    {
        this->_name = "Unnamed animation";
        this->_position.x = 0;
        this->_position.y = 0;
        this->_frameRate = FPS;
        this->_spritesheetArea = sf::IntRect(0, 0, 0, 0);
        return ;
    }

    Animation::Animation(sf::Texture const * texture, t_uint const nbFrames, sf::IntRect area)
        : _spritesheet(texture), _spritesheetArea(area), _nbFrames(nbFrames)
        , _frames(NULL) , _currentFrameIndex(0), _playingState(STOPPED)
        , _frameCounter(0), _done(false), _cancelable(true), _speed(1.0f)
    {
        this->_name = "Unnamed animation";
        this->_frames = new sf::Sprite[this->_nbFrames];
        this->_position.x = 0;
        this->_position.y = 0;
        this->_frameRate = FPS / this->_nbFrames;
        if (this->_spritesheetArea.width == 0 || this->_spritesheetArea.height == 0)
        {
            this->_spritesheetArea.width = this->_spritesheet->getSize().x;
            this->_spritesheetArea.height = this->_spritesheet->getSize().y;
        }
        return ;
    }

    Animation::Animation(Animation const & other)
        : _spritesheet(other.getSpriteSheet()), _spritesheetArea(other.getSpriteSheetArea())
        , _nbFrames(other.getNbFrames()), _frames(NULL)
        , _currentFrameIndex(other.getCurrentFrameIndex())
        , _playingState(other.getPlayingState()), _position(other.getPosition())
        , _frameCounter(0), _done(other.done()), _cancelable(other.cancelable())
        , _speed(other.getSpeed())
    {
        sf::Sprite  *frames = other.getFrames();

        this->_position.x = 0;
        this->_position.y = 0;
        this->_frameRate = FPS / this->_nbFrames;
        this->_frames = new sf::Sprite[this->_nbFrames];
        if (frames != NULL)
        {
            for (t_uint i = 0; i < this->_nbFrames; i++)
            {
                this->_frames[i] = frames[i];
            }
        }
        return ;
    }

    Animation &         Animation::operator=(Animation const & rhs)
    {
        if (this != &rhs)
        {
            sf::Sprite  *frames = rhs.getFrames();

            this->_spritesheet = rhs.getSpriteSheet();
            this->_spritesheetArea = rhs.getSpriteSheetArea();
            this->_nbFrames = rhs.getNbFrames();
            this->_playingState = rhs.getPlayingState();
            this->_currentFrameIndex = rhs.getCurrentFrameIndex();
            this->_position = rhs.getPosition();
            this->_done = rhs.done();
            this->_cancelable = rhs.cancelable();
            this->_speed = rhs.getSpeed();
            this->_frameRate = FPS / this->_nbFrames;
            if (this->_frames != NULL)
                delete [] this->_frames;
            this->_frames = new sf::Sprite[this->_nbFrames];
            for (t_uint i = 0; i < this->_nbFrames; i++)
            {
                this->_frames[i] = frames[i];
            }
        }
        return (*this);
    }

    sf::Sprite &        Animation::operator[](t_uint const index)
    {
        return (this->_frames[index]);
    }

    std::string         Animation::getName(void) const
    {
        return (this->_name);
    }

    sf::Texture const * Animation::getSpriteSheet(void) const
    {
        return (this->_spritesheet);
    }

    sf::IntRect         Animation::getSpriteSheetArea(void) const
    {
        return (this->_spritesheetArea);
    }

    sf::Sprite          *Animation::getFrames(void) const
    {
        return (this->_frames);
    }

    t_uint              Animation::getNbFrames(void) const
    {
        return (this->_nbFrames);
    }

    sf::Vector2f const  Animation::getPosition(void) const
    {
        return (this->_position);
    }

    t_uint const        Animation::getPlayingState(void) const
    {
        return (this->_playingState);
    }

    t_uint const        Animation::getCurrentFrameIndex(void) const
    {
        return (this->_currentFrameIndex);
    }

    float               Animation::getSpeed(void) const
    {
        return (this->_speed);
    }

    void                Animation::setName(std::string const name)
    {
        this->_name = name;
        return ;
    }

    void                Animation::setSpriteSheet(sf::Texture const * spritesheet, sf::IntRect const & area)
    {
        this->_spritesheet = spritesheet;
        if (area.width > 0 && area.height > 0)
            this->_spritesheetArea = area;
        else
        {
            this->_spritesheetArea.width = this->_spritesheet->getSize().x;
            this->_spritesheetArea.height = this->_spritesheet->getSize().y;
        }
        return ;
    }

    void                Animation::setSpriteSheetArea(sf::IntRect area)
    {
        if (area.width > 0 && area.height > 0)
            this->_spritesheetArea = area;
        return ;
    }

    void                Animation::setNbFrames(t_uint const nbFrames)
    {
        this->_nbFrames = nbFrames;
        if (this->_frames != NULL)
            delete [] this->_frames;
        this->_frames = new sf::Sprite[this->_nbFrames];
        this->_frameRate = FPS / this->_nbFrames;
        return ;
    }

    void                Animation::scale(float x, float y)
    {
        t_uint          i = 0;

        while (i < this->_nbFrames)
            this->_frames[i++].scale(x, y);
        return ;
    }

    void                Animation::setScale(float x, float y)
    {
        t_uint          i = 0;

        while (i < this->_nbFrames)
            this->_frames[i++].setScale(x, y);
        return ;
    }

    void                Animation::setCurrentFrame(t_uint const index)
    {
        if (index < this->_nbFrames)
            this->_currentFrameIndex = index;
        return ;
    }

    void                Animation::setPosition(float const x, float const y)
    {
        t_uint          i = 0;

        this->_position.x = x;
        this->_position.y = y;
        while (i < this->_nbFrames)
            this->_frames[i++].setPosition(this->_position.x, this->_position.y);
        return ;
    }

    void                Animation::setCancelable(bool const cancelable)
    {
        this->_cancelable = cancelable;
        return ;
    }

    void               Animation::setSpeed(float const speed)
    {
        this->_speed = speed;
        return ;
    }

    bool                Animation::done(void) const
    {
        return (this->_done);
    }

    bool                Animation::cancelable(void) const
    {
        return (this->_cancelable);
    }

    void                Animation::splitFrames(t_uint const sizeX, t_uint const sizeY)
    {
        t_uint          cols = this->_spritesheetArea.width / sizeX;
        t_uint coordX = 0;
        t_uint coordY = 0;
        t_uint          i = 0;

        while (i < this->_nbFrames)
        {
            coordX = this->_spritesheetArea.left + (i % cols) * sizeX;
            coordY = this->_spritesheetArea.top + (i / cols) * sizeY;
            this->_frames[i].setTexture(*this->_spritesheet);
            this->_frames[i].setTextureRect(
                sf::IntRect(coordX, coordY, sizeX, sizeY)
            );
            i++;
        }
        return ;
    }

    void                Animation::play(void)
    {
        if (this->_playingState != PLAYING)
        {

        }
        this->_done = false;
        this->_playingState = PLAYING;
    }

    void                Animation::pause(void)
    {
        if (this->_playingState != PAUSED)
        {

        }
        this->_playingState = PAUSED;
    }

    void                Animation::stop(void)
    {
        if (this->_playingState != STOPPED)
        {
            this->_currentFrameIndex = 0;
        }
        this->_playingState = STOPPED;
    }

    void                Animation::update(void)
    {
        if (this->_frames == NULL)
            return ;
        if (this->_playingState == PLAYING)
        {
            if (this->_frameCounter++ >= this->_frameRate / this->_speed)
            {
                if (++this->_currentFrameIndex >= this->_nbFrames)
                {
                    this->_done = true;
                    this->_currentFrameIndex = 0;
                }
                this->_frameCounter = 0;
            }
        }
    }

    void                Animation::render(sf::RenderWindow & win)
    {
        if (this->_frames == NULL)
            return ;
        if (this->_playingState != STOPPED)
            win.draw(this->_frames[this->_currentFrameIndex]);
    }

    Animation::~Animation()
    {
        if (this->_frames != NULL)
            delete [] this->_frames;
        return ;
    }
}
