#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Texture
{
    public:
        Texture();

        bool loadFromFile(std::string p_path, SDL_Renderer* p_renderer);
        void free();

        float getWidth();
        float getHeight();

    private:
        int width;
        int height;

        SDL_Texture* texture;
};