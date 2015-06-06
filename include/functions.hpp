#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include "starlight.hpp"
# include "SceneData.hpp"
# include "Scene.hpp"
# include "Animation.hpp"
# include "Player.hpp"
# include <fstream>
# include <sstream>

sf::IntRect                 parserGetArea(std::string const text, char sep);
t_texture                   *loadTexture(std::string const name, t_uint index);
anim::Animation             *loadAnimation(std::string const name, t_texture **textures);


#endif // FUNCTIONS_HPP
