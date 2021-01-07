# OpenGL Tutorial notes from benny

[Link to the youtube playlist](https://www.youtube.com/playlist?list=PLHP-Z9TUFhhptXLqnmGdvLNrStOybEp1Q)

## Basic stuffs

* Codeblocks needs linking GL, GLEW, SDL2

## Basic GPU Workflow

Modern GPUs Do three things:\
```1.``` Draw filled triangles\
```2.``` Interpolate between two existing values\
```3.``` Parallel code execution\
Image generation Process of modern GPUs: Workflow\
**Data** -> **Processing(*Vertex Shader*)** -> **Resterization** -> **More Processing(*Fragment Shader*)** -> **Output**\
**Data:** Instructions for graphics(assume Triangle)\
**Processing(*Vertex Shader*):** Converting the instructions into a specific form(dots) that GPU can Understand and work with\
**Resterization:** Connects the dots and fills the triangle.\
**More Processing(*Fragment Shader*):** Works on every individual pixel of the triangle and determines its color.\
**Output:** Stores the processed outputted pixels(doesn't show until full data is processed). All parallely.

## **SDL**

[Link to SDL documentation](https://wiki.libsdl.org)\
**Installation:** ```sudo apt-get install libsdl2-dev```

* Linking needed (as SDL2).\
 Including process ```#include <SDL2/SDL.h>```

* ```SDL_Window* window;``` pointer to window object(returned by SDL_CreateWindow())

* ```SDL_GLContext m_glcontext;``` context object returned by SDL_GL_CreateContext()
  
### **SDL** Functions & Flags

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

* [**```void SDL_GL_SwapWindow(SDL_Window* window)```**](https://wiki.libsdl.org/SDL_GL_SwapWindow)\
  Is used for updating window with opengl rendering

* [**```SDL_Event```**](https://wiki.libsdl.org/SDL_Event)\
  Is used for Event Handling\
  **Event-Types:** (returned from ```event.type```\
  * ```SDL_QUIT``` quit event  

* [**```int SDL_PollEvent(SDL_Event* event)```**](https://wiki.libsdl.org/SDL_PollEvent)\
  Poll for currently pending event. Returns 1 if there is a pending event.\
  Looks(polls) for the next event and then handles it\

  ```c++
     while (SDL_PollEvent(&test_event)) {//used inside while loops}
  ```

## **GLEW**

[Link to opengl ref page(khronos.org)](https://www.khronos.org/registry/OpenGL-Refpages/gl4/)

**Installation:** ```sudo apt-get install libglew-dev```

* Linking needed (as GLEW)\
  Including process ```#include <GL/glew.h>```

### **GLEW** Functions & Flags

* [**```GLenum glewInit()```**](http://glew.sourceforge.net/basic.html)\
  Will find every single opengl function OS supports. Returns ```GLEW_OK``` flag if everything is ok\
  Actual implementation ```GLenum status = glewInit();```

* [**```void glClearColor(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha);```**](https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glClearColor.xhtml)\
  Values specified [0,1]. Def: glClearColor — specify clear values for the color buffers

## **GLM**

**Installation:** ```sudo apt-get install libglm-dev```

* header only library. Does not need linking.

* 