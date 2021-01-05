# OpenGL Tutorial notes from benny

[Link to the youtube playlist](https://www.youtube.com/playlist?list=PLHP-Z9TUFhhptXLqnmGdvLNrStOybEp1Q)

## Basic stuffs

* Codeblocks needs linking GL, GLEW, SDL2

## **SDL**

**Installation:** ```sudo apt-get install libsdl2-dev```

* Linking needed (as SDL2).\
 Including process ```#include <SDL2/SDL.h>```

* ```SDL_Window* window;``` pointer to window object(returned by SDL_CreateWindow())
* ```SDL_GLContext m_glcontext;``` context object returned by SDL_GL_CreateContext()
 
### SDL Functions and flags

* [**```int SDL_Init(Uint32 flags)```**](https://wiki.libsdl.org/SDL_Init)\
  Initializes SDL Library.
  * ```SDL_INIT_EVERYTHING``` Flag initializes all the subsystems available
  
* [**```void SDL_Quit(void)```**](https://wiki.libsdl.org/SDL_Quit)\
  Cleans up all initialized subsystems

* [**```SDL_Window* SDL_CreateWindow(const char* title, int x,int y, int w,int h,Uint32 flags)```**](https://wiki.libsdl.org/SDL_CreateWindow)\
  Function to create a window with the specified position, dimensions, and flags\
  Here is an issue with title. It does not accept c++ std::string(cz its from c). so ```string.c_str()``` should be used.
  * ```SDL_WINDWOPOS_CENTERED``` flag for x and y variable puts the window in the center of the screen
  * ```SDL_WINDOW_OPENGL``` last param flag -> window usable with OpenGL context(I'm gonna use it with opengl)

* [**```int SDL_GL_SetAttribute(SDL_GLattr attr, int value)```**](https://wiki.libsdl.org/SDL_GL_SetAttribute)\
  Function to set an OpenGL window attribute before window creation.
  * ```SDL_GL_RED_SIZE``` the minimum number of bits for the red channel of the color buffer; defaults to 3
  * ```SDL_GL_GREEN_SIZE``` the minimum number of bits for the green channel of the color buffer; defaults to 3
  * ```SDL_GL_BLUE_SIZE``` the minimum number of bits for the blue channel of the color buffer; defaults to 2
  * ```SDL_GL_ALPHA_SIZE``` the minimum number of bits for the alpha channel of the color buffer; defaults to 0             (determines transparency)
  * ```SDL_GL_BUFFER_SIZE``` the minimum number of bits for frame buffer size; defaults to 0(used 32)\
    How much memory per pixel is going to be allocated by sdl is determined here. It says I'll give you at least x bits
  * ```SDL_GL_DOUBLEBUFFER``` whether the output is single or double buffered; defaults to double buffering on
    SDL will allocate memory for two windows if double Buffer is on. One for drawing stuff(opengl Will draw). Another for OS\
    OS will show on the window.

* [**```SDL_GLContext SDL_GL_CreateContext(SDL_Window* window)```**](https://wiki.libsdl.org/SDL_GL_CreateContext)\
  Creates an OpenGL context with an opengl window.

* [**```void SDL_GL_DeleteContext(SDL_GLContext context)```**](https://wiki.libsdl.org/SDL_GL_DeleteContext)\
  Is used to delete an opengl context (Delete the one last one created first)

* [**```void SDL_DestroyWindow(SDL_Window* window)```**](https://wiki.libsdl.org/SDL_DestroyWindow)\
  Is used to delete a window (Delete the one last one created first)

* [**```void SDL_DestroyWindow(SDL_Window* window)```**](https://wiki.libsdl.org/SDL_DestroyWindow)\
  Is used to delete a window (Delete the one last one created first)


## **GLEW**

**Installation:** ```sudo apt-get install libglew-dev```

* Linking needed (as GLEW)

## **GLM**

**Installation:** ```sudo apt-get install libglm-dev```

* header only library. Does not need linking.

* 