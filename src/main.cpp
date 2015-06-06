#include "include/starlight.hpp"
#include "include/functions.hpp"

int     main(void)
{
    /// Create the main window
    sf::RenderWindow    window(sf::VideoMode(W_WIDTH, W_HEIGHT), PROG_NAME);
    window.setFramerateLimit(FPS);

    /// Loading state
    bool                resourcesLoaded = false;

    /// Textures
    t_texture           *textures[TEXTURE_COUNT];

    textures[0] = loadTexture("cow.png", 0);
    textures[1] = loadTexture("explosion.png", 1);
    textures[2] = loadTexture("intro.jpg", 2);

    for (t_uint i = 0; i < TEXTURE_COUNT; i++)
    {
        if (textures[i] == NULL)
            return (EXIT_FAILURE);
    }

    /// Displayable animations
    anim::Animation     *animations[ANIMATION_COUNT];

    animations[0] = loadAnimation("idle_cow", textures);
    animations[1] = NULL;
    animations[2] = NULL;

    /// Player init
    Player pl/*(sf::IntRect(0, 0, 64, 64), sf::Vector2i(0, 0), 2.0f)*/;

    pl.setName("airmeuh");
    pl.setHitBox(sf::IntRect(0, 0, 64, 25));
    pl.addAnimation(animations[0]);
    pl.setCurrentAnimation(0);
    pl.introduce();

    /// Game loop
    bool keyIsPressed = false;
    // Start the game loop
    while (window.isOpen())
    {
        /// Event handling
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::U)
                    pl.speedUp(.75f);
                if (event.key.code == sf::Keyboard::Y)
                    pl.speedDown(.75f);
            }
        }

        /// Input Handling
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

//        currentScene->handleKeyInput();

        /// Updating
//        currentScene->update();

        /// Refreshing
        window.clear();

        /// Tests ///

        pl.handleInput();
        pl.render(window);

        /// Tests ///

        /// drawing
//        currentScene->render();

        // Draw
//        animations[0].update();
//        animations[0].render(window);
//        animations[1].update();
//        animations[1].render(window);
        /*
        currentAnimation->play();
        currentAnimation->render(window);
        */
        window.display();
    }
    for (t_uint i = 0; i < ANIMATION_COUNT; i++)
    {
        if (animations[i] != NULL)
            delete animations[i];
    }
    for (t_uint i = 0; i < TEXTURE_COUNT; i++)
    {
        if (textures[i]->texture != NULL)
            delete textures[i]->texture;
    }
    return (0);
}
