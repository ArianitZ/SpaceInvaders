#include "game.h"

#include <memory.h>
#include "window.h"
#include "texture.h"

Game::Game(int p_windowWidth, int p_windowHeight, std::string p_title)
:width(p_windowWidth), height(p_windowHeight), title(p_title), gameRunning(true)
{}

void Game::run()
{
    if(init())
    {
        while(gameRunning)
        {
            handleEvents();
            render();
        }
    }
    close();
}

bool Game::init()
{
    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to intialize SDL. SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize SDL Image
    int img_flags{IMG_INIT_PNG};
    int innit{ IMG_Init(img_flags) };
    if(!(img_flags & innit))
    {
        std::cout << "Failed to initialize SDL Image. SDL Image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    // Initialize window & renderer
    window.reset(new Window(width, height, title));
    if(!window.get()->init())
    {
        std::cout << "Failed to intialize window. Stopping game." << std::endl;
        return false;
    }

    return true;
}

void Game::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT || (event.type==SDL_KEYDOWN and event.key.keysym.sym == SDLK_ESCAPE))
        {
            gameRunning = false;
        }
    }
}

void Game::render()
{
    window.get()->renderClear();
    // window.get()->render();
    window.get()->renderPresent();
}

void Game::close()
{
    window.get()->free();

    SDL_Quit();
    IMG_Quit();
}

