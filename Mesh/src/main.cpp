#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"

int main()
{
    Display display(800, 600, "My First Window");

    Shader shader("./res/basicShader");

    while (!display.IsClosed()){
        display.ClearSrceen(0.0f, 0.1f, 0.1f, 1.0f);
        shader.Bind();
        display.Update();
    }
    return 0;
}
