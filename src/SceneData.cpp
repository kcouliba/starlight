#include "../include/SceneData.hpp"

SceneData::SceneData(std::string const name)
    : _name(name), _textures(NULL), _nbSpriteSheet(0)
    , _nbAnimations(0), _animations(NULL)
{

    return ;
}

SceneData::SceneData(SceneData const & other)
    : _name(other.getName()), _textures(other.getTextures())
    , _nbSpriteSheet(other.getNbSpriteSheet())
    , _nbAnimations(other.getNbAnimations()), _animations(other.getAnimations())
{
    return ;
}

SceneData &                 SceneData::operator=(SceneData const & rhs)
{
    if (this != &rhs)
    {
        this->_textures = rhs.getTextures();
        this->_nbSpriteSheet = rhs.getNbSpriteSheet();
        this->_animations = rhs.getAnimations();
        this->_nbAnimations = rhs.getNbAnimations();
    }
    return (*this);
}

SceneData::~SceneData(void)
{
    if (this->_textures != NULL)
    {
        for (t_uint i = 0; i < this->_nbSpriteSheet; i++)
        {
            delete this->_textures[i].texture;
        }
        delete [] this->_textures;
    }
    if (this->_animations != NULL)
        delete [] this->_animations;
    return ;
}

void                    SceneData::setNbSpriteSheet(t_uint const nb)
{
    this->_nbSpriteSheet = nb;
    if (this->_textures == NULL)
        this->_textures = new s_texture[this->_nbSpriteSheet];
    for (t_uint i = 0; i < this->_nbSpriteSheet; i++)
    {
        this->_textures[i].texture = new sf::Texture();
    }
    return ;
}

void                    SceneData::setSpriteSheet(sf::Texture * texture, std::string const fileName, t_uint const index)
{
    if (this->_textures != NULL && texture != NULL)
    {
        this->_textures[index].texture = texture;
        this->_textures[index].name = fileName;
        this->_textures[index].index = index;
    }
    return ;
}

void                    SceneData::setNbAnimations(t_uint const val)
{
    this->_nbAnimations = val;
    if (this->_animations == NULL)
        this->_animations = new anim::Animation*[this->_nbAnimations];
    return ;
}

void                    SceneData::setAnimation(anim::Animation * animation, t_uint const index)
{
    if (this->_animations != NULL && animation != NULL)
        this->_animations[index] = animation;
    return ;
}

std::string const       SceneData::getName(void) const
{
    return (this->_name);
}

t_uint const            SceneData::getNbSpriteSheet(void) const
{
    return (this->_nbSpriteSheet);
}

s_texture               *SceneData::getTextures(void) const
{
    return (this->_textures);
}

t_uint const            SceneData::getNbAnimations(void) const
{
    return (this->_nbAnimations);
}

anim::Animation         **SceneData::getAnimations(void) const
{
    return (this->_animations);
}

sf::Texture             *SceneData::getTextureByFileName(std::string const textureName) const
{
    for (t_uint i = 0; i < this->_nbSpriteSheet; i++)
    {
        if (!this->_textures[i].name.compare(textureName))
            return (this->_textures[i].texture);
    }
    return (NULL);
}

anim::Animation         *SceneData::getAnimationByName(std::string const animationName) const
{
    for (t_uint i = 0; i < this->_nbAnimations; i++)
    {
        if (!this->_animations[i]->getName().compare(animationName))
            return (this->_animations[i]);
    }
    return (NULL);
}

std::ostream &          operator<<(std::ostream & o, SceneData const & sceneData)
{
    t_uint              i = 0;

    o << "***SceneData <" << sceneData.getName() << ">***" << std::endl;
    o << "Composed with spritesheet/texture : " << std::endl;
    while (i < sceneData.getNbSpriteSheet())
    {
        o << "\t" << sceneData.getTextures()[i].name << std::endl;
        ++i;
    }
    o << "Composed with animation : " << std::endl;
    i = 0;
    while (i < sceneData.getNbAnimations())
    {
        o << "\t" << sceneData.getAnimations()[i]->getName() << std::endl;
        ++i;
    }
    return (o);
}
