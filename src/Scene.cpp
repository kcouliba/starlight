#include "Scene.hpp"

Scene::Scene(std::string const name, sf::RenderWindow & win)
    : _name(name), _window(win), _nbAnimations(0), _animations(NULL)
    , _playingState(STOPPED)
{
    return ;
}

Scene::Scene(const Scene& other)
    : _name(other.getName()), _window(other.getRenderWindow())
//    , _animations(other.getAnimations()), _nbAnimations(other.getNbAnimations())
    , _playingState(other.getPlayingState())
{
    return ;
}

Scene& Scene::operator=(const Scene& rhs)
{
    if (this != &rhs)
    {
        //    this->_animations = rhs.getAnimations();
        //    this->_nbAnimations = rhs.getNbAnimations();
        this->_playingState = rhs.getPlayingState();
    }
    return *this;
}

Scene::~Scene(void)
{
    if (this->_nbAnimations > 0)
        delete [] this->_animations;
    return ;
}

sf::RenderWindow        &Scene::getRenderWindow(void) const
{
    return (this->_window);
}

std::string             Scene::getName(void) const
{
    return (this->_name);
}

anim::Animation         *Scene::getAnimationByName(std::string const animationName) const
{
    for (t_uint i = 0; i < this->_nbAnimations; i++)
    {
        if (!this->_animations[i].getName().compare(animationName))
            return (&this->_animations[i]);
    }
    return (NULL);
}

t_uint                  Scene::getPlayingState() const
{
    return (this->_playingState);
}

void                    Scene::setAnimations(anim::Animation *animations, t_uint const count)
{
    this->_nbAnimations = count;
    this->_animations = animations;
}

void                    Scene::play(void)
{
    t_uint              i = 0;

    while (i < this->_nbAnimations)
    {
        if (this->_animations[i].getPlayingState() != PLAYING)
            this->_animations[i].play();
        ++i;
    }
    this->_playingState = PLAYING;
    return ;
}

void                    Scene::pause(void)
{
    t_uint              i = 0;

    while (i < this->_nbAnimations)
    {
        if (this->_animations[i].getPlayingState() != PAUSED)
            this->_animations[i].pause();
        ++i;
    }
    this->_playingState = PAUSED;
    return ;
}

void                    Scene::stop(void)
{
    t_uint              i = 0;

    while (i < this->_nbAnimations)
    {
        if (this->_animations[i].getPlayingState() != STOPPED)
            this->_animations[i].stop();
        ++i;
    }
    this->_playingState = STOPPED;
    return ;
}

void                    Scene::update(void)
{
    t_uint              i = 0;

    if (this->_playingState == PLAYING)
    {
        while (i < this->_nbAnimations)
        {
            this->_animations[i].update();
            ++i;
        }
    }
    return ;
}

void                    Scene::render(void)
{
    t_uint              i = 0;

    if (this->_playingState != STOPPED)
    {
        while (i < this->_nbAnimations)
        {
            this->_animations[i].render(this->_window);
            ++i;
        }
    }
    return ;
}

std::ostream &          operator<<(std::ostream & o, Scene const & scene)
{
    o << "***Scene <" << scene.getName() << ">***";
    return (o);
}
