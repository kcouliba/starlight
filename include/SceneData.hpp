#ifndef SCENEDATA_HPP
# define SCENEDATA_HPP

# include "starlight.hpp"
# include "Animation.hpp"

class SceneData
{
    public:
        SceneData(std::string const name);
        SceneData(SceneData const & other);
        SceneData& operator=(SceneData const & other);
        virtual ~SceneData(void);

        void                    setNbSpriteSheet(t_uint const nb);
        void                    setSpriteSheet(sf::Texture * texture, std::string const fileName, t_uint const index);
        void                    setNbAnimations(t_uint const nb);
        void                    setAnimation(anim::Animation * animation, t_uint const index);

        std::string const       getName(void) const;
        t_uint const            getNbSpriteSheet(void) const;
        s_texture               *getTextures(void) const;
        t_uint const            getNbAnimations(void) const;
        anim::Animation         **getAnimations(void) const;
        sf::Texture             *getTextureByFileName(std::string const textureName) const;
        anim::Animation         *getAnimationByName(std::string const animationName) const;

    protected:

    private:
        std::string const       _name;
        s_texture               *_textures;
        t_uint                  _nbSpriteSheet;
        t_uint                  _nbAnimations;
        anim::Animation         **_animations;
};

std::ostream &                  operator<<(std::ostream & o, SceneData const & sceneData);

#endif // SCENEDATA_HPP
