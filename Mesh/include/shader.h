#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <GL/glew.h>

class Shader
{
public:
    Shader(const std::string& fileName);

    void Bind();

    virtual ~Shader();


protected:

private:
    static const unsigned int NUM_SHADERS = 2; //for vertex shader and fragment shader
    Shader(const Shader& other){}
    void operator=(const Shader& other){}

    GLuint m_program; //GLuint gl unsigned integer for keeping track of the program
    GLuint m_shaders[NUM_SHADERS]; //for vertex shader and fragment shader
};

#endif // SHADER_H
