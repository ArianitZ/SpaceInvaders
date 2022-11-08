#include "window.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

Window::Window(int p_width, int p_height, std::string p_title)
:width(p_width), height(p_height), title(p_title)
{}

void Window::renderPresent()
{
    if(window != NULL)
    {
        SDL_RenderPresent(renderer);
    }
    else
    {
        std::cout << "Window now intialized, cannot render present!" << std::endl;
    }    
}

void Window::renderClear()
{
    if(window != NULL)
    {
        SDL_RenderClear(renderer);
    }
    else
    {
        std::cout << "Window now intialized, cannot render clear!" << std::endl;
    }
}

void Window::render()
{

}

void Window::free()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

bool Window::init()
{
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if(window==NULL)
    {
        std::cout << "Failed to create window. SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer==NULL)
    {
        std::cout << "Failed to create renderer. SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 0XFF, 0XFF, 0XFF, 0XFF);
    return true;
}