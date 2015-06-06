#ifndef DEFINES_HPP
# define DEFINES_HPP

/** Paths **/
# define    PROG_NAME           "Simple program"
# define    ASSET_PATH          "assets/"
# define    DATA_PATH           "assets/data/"
# define    SPRITE_PATH         "assets/spritesheet/"
# define    SCENE_DATA_PATH     "assets/data/scene/"
# define    ANIM_DATA_PATH      "assets/data/animation/"

/** config file reading **/
# define    SCN_FILE_EXT        ".scene"
# define    ANIM_FILE_EXT        ".anim"
/* Scene config file */
# define    SCN_NBTEXTURES      0
# define    SCN_TEXTURESLIST    1
# define    SCN_NBANIMATIONS    2
# define    SCN_ANIMATIONFILES  3
# define    SCN_ACQUIRED        4

/* Animation config file */
# define    ANIM_SPRITESHEET    0
# define    ANIM_NAME           1
# define    ANIM_AREA           2
# define    ANIM_NBFRAMES       3
# define    ANIM_SPEED          4
# define    ANIM_CANCELABLE     5
# define    ANIM_FRAMESPLITBY   6
# define    ANIM_SPLITFRAMES    7
# define    ANIM_ACQUIRED       8
# define    ANIM_BYFRAMESIZE    0
# define    ANIM_BYFRAMEPOS     1

/** Window values **/
# define    W_RATIO             3 / 4
# define    W_WIDTH             800
# define    W_HEIGHT            W_WIDTH * W_RATIO

/** Animation values **/
# define    FPS                 45

/** **/
# define    TEXTURE_COUNT       3
# define    ANIMATION_COUNT     3

/** Default values **/
# define    DEFAULT_SPEED       5.0

/** Limit values **/
# define    MAX_PLYR_HITPOINT   300
# define    MAX_ANIMATION_COUNT 30
# define    MIN_PLYR_SPEED      2.5
# define    MAX_PLYR_SPEED      7.5

/** Playing states **/
# define    PLAYING             0
# define    PAUSED              1
# define    STOPPED             2

#endif // DEFINES_HPP_INCLUDED
