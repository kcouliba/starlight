#ifndef SCENE_HPP
#define SCENE_HPP

# include "starlight.hpp"
# include "Animation.hpp"


class Scene
{
    public:
        Scene(std::string const name, sf::RenderWindow & win);
        Scene(const Scene& other);
        Scene& operator=(const Scene& other);
        virtual ~Scene();

        sf::RenderWindow        &getRenderWindow(void) const;
        std::string             getName(void) const;
        anim::Animation         *getAnimationByName(std::string const animationName) const;
        t_uint                  getPlayingState() const;

        void                    setAnimations(anim::Animation *animations, t_uint const count);

        void                    play(void);
        void                    pause(void);
        void                    stop(void);
        void                    update(void);
        void                    render(void);
        void                    (*handleKeyInput)(void);

    protected:

    private:
        std::string const       _name;
        sf::RenderWindow        &_window;
        t_uint                  _nbAnimations;
        anim::Animation         *_animations;
        t_uint                  _playingState;
};

std::ostream &                  operator<<(std::ostream & o, Scene const & scene);

#endif // SCENE_HPP
