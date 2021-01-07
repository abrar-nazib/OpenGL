#include "display.h"
#include <GL/glew.h>
#include <iostream>


Display::Display(int width, int height, const std::string& title) //constructor function of display
{
    SDL_Init(SDL_INIT_EVERYTHING); //for simplicity: initialized all sdl functionalities

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);  //2^8 = 256
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); //for transparency
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); //8+8+8+8 = 32 bits per pixel
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //will allocate memory for another window (may be for accepting keyboard and mouse input)
    //it won't be shown tho


    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    //sdl c library so takes c equivalent string so title.c_str() is used
    //next two parameters are created because of the positioning of the created window
    //last one is used for indicating that we are using opengl
    m_glContext = SDL_GL_CreateContext(m_window); //creates an sdl context

    GLenum status = glewInit();
    if(status != GLEW_OK)
    {
        std::cout << "glew failed to initialize" << std::endl;
    }
    m_isClosed = false;

}

Display::~Display() //destructor function for display
{
    SDL_GL_DeleteContext(m_glContext); //last one created destroyed first otherwise creates memory allocation bugs
    SDL_DestroyWindow(m_window); //why doesnot work
    SDL_Quit();
}

void Display::Update()
{
    SDL_GL_SwapWindow(m_window);

    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            m_isClosed = true;
        }
    }
}

void Display::ClearSrceen(float r, float g, float b, float x)
{
    glClearColor(r, g, b, x);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::IsClosed()
{
    return m_isClosed;
}
