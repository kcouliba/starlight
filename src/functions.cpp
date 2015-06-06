#include "../include/functions.hpp"

sf::IntRect                 parserGetArea(std::string const text, char sep)
{
    std::istringstream      iss(text);
    std::string             val;

    std::getline(iss, val, sep);
    int                     x = atoi(val.c_str());
    std::getline(iss, val, sep);
    int                     y = atoi(val.c_str());
    std::getline(iss, val, sep);
    int                     w = atoi(val.c_str());
    std::getline(iss, val, sep);
    int                     h = atoi(val.c_str());

    return (sf::IntRect(x, y, w, h));
}

t_texture                   *loadTexture(std::string const name, t_uint index)
{
    t_texture               *newTexture = new t_texture;

    newTexture->texture = new sf::Texture();
    newTexture->index = index;
    newTexture->name = name;
    if (!newTexture->texture->loadFromFile(static_cast<std::string>(SPRITE_PATH) + name))
        return (NULL);
//    std::cout << "Texture " << name << " loaded" << std::endl;
    return (newTexture);
}

sf::Texture                 *getTextureByFileName(t_texture **textures, std::string const filename)
{
    for (t_uint i = 0; i < TEXTURE_COUNT; i++)
    {
        if (!textures[i]->name.compare(filename))
            return (textures[i]->texture);
    }
    return (NULL);
}

anim::Animation             *loadAnimation(std::string const name, t_texture **textures)
{
    std::ifstream           file;
    std::string             line;
    anim::Animation         *animation = new anim::Animation();
    bool                    splitBy = ANIM_BYFRAMESIZE;

    file.open((static_cast<std::string>(ANIM_DATA_PATH) + name + static_cast<std::string>(ANIM_FILE_EXT)).c_str());
    if (!file.is_open())
    {
        std::cout << "Cannot open the file : "
            << static_cast<std::string>(ANIM_DATA_PATH) + name << static_cast<std::string>(ANIM_FILE_EXT)
            << std::endl;
        return (NULL);
    }
    for (int i = 0; i < ANIM_ACQUIRED; i++) {
        std::getline(file, line, ';');
        if (line.compare(0, 2, "**") == 0)
            continue ;
        switch (i)
        {
            case ANIM_SPRITESHEET:
            {
                animation->setSpriteSheet(getTextureByFileName(textures, line));
                std::cout << "spritesheet loaded : " << line << std::endl;
                break ;
            }
            case ANIM_NAME:
            {
                animation->setName(name);
//                std::cout << "anim name loaded : " << animation->getName() << std::endl;
                break ;
            }
            case ANIM_AREA:
            {
                int x;
                int y;
                int w;
                int h;

                std::istringstream      iss(line);
                std::string             val;
                for (int j = 0; j < 4; j++)
                {
                    std::getline(iss, val, ',');
                    switch (j)
                    {
                        case 0:
                            x = ::atoi(val.c_str());
                            break ;
                        case 1:
                            y = ::atoi(val.c_str());
                            break ;
                        case 2:
                            w = ::atoi(val.c_str());
                            break ;
                        case 3:
                            h = ::atoi(val.c_str());
                            break ;
                        default:
                            break ;
                    }

                }
                sf::IntRect             area(x, y, w, h);
                animation->setSpriteSheetArea(area);
//                std::cout << "anim area loaded : " << std::endl;
                break ;
            }
            case ANIM_NBFRAMES:
            {
                animation->setNbFrames(::atoi(line.c_str()));
//                std::cout << "anim frames loaded : " << animation->getNbFrames() << std::endl;
                break ;
            }
            case ANIM_SPEED:
            {
                animation->setSpeed(::atof(line.c_str()));
//                std::cout << "anim speed loaded : " << animation->getSpeed() << std::endl;
                break ;
            }
            case ANIM_CANCELABLE:
            {
                animation->setCancelable(atoi(line.c_str()));
//                std::cout << "anim cancelable loaded : " << animation->cancelable() << std::endl;
                break ;
            }
            case ANIM_FRAMESPLITBY:
            {
                splitBy = atoi(line.c_str());
//                std::cout << "atoi splitBy : " << splitBy << std::endl;
//                std::string by = (splitBy == ANIM_BYFRAMESIZE) ? "frame size" : "frame position";
//                std::cout << "anim split by : " << by << std::endl;
                break ;
            }
            case ANIM_SPLITFRAMES:
            {
                std::istringstream      iss(line);
                std::string             val;

                if (splitBy == ANIM_BYFRAMESIZE)
                {
                    std::getline(iss, val, ',');
                    int                 width = atoi(val.c_str());
                    std::getline(iss, val, ',');
                    int                 height = atoi(val.c_str());
                    animation->splitFrames(width, height);
//                    std::cout << "anim frame size [" << width << "][" << height << "]" << std::endl;
                }
                else
                {
                    for (t_uint j = 0; j < animation->getNbFrames(); j++)
                    {
                        std::getline(iss, val, ':');
                        (*animation)[j].setTexture(*animation->getSpriteSheet(), true);
                        (*animation)[j].setTextureRect(parserGetArea(val, ','));
                    }
                }
                break ;
            }
            default:
            {
//                std::cout << "Nothing to acquire or do for : " << line << std::endl;
                break ;
            }
        }
    }
    return (animation);
}
