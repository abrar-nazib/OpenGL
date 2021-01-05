#include "display.h"


Display::Display(int width, int height, const std::string& title) //constructor function of display
{
    SDL_Init(SDL_INIT_EVERYTHING); //for simplicity: initialized all sdl functionalities
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
}

Display::~Display() //destructor function for display
{
    SDL_Quit();
}

