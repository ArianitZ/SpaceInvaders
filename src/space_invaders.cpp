#include <string>
#include "game.h"

int main(int argc, char* argv[])
{
    const int screenWidth(1200);
    const int screenHeight(600);
    const std::string title = "Space Invaders";

    Game game(screenWidth, screenHeight, title);
    game.run();

    return 0;
}