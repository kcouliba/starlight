#ifndef TYPEDEFS_HPP
# define TYPEDEFS_HPP

typedef unsigned int    t_uint;

typedef struct          s_texture
{
    sf::Texture         *texture;
    std::string         name;
    t_uint              index;
}                       t_texture;

#endif // TYPEDEFS_HPP
