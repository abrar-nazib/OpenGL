#include "shader.h"
#include <iostream>
#include <fstream> //file stream for getting values from files -> used in LoadShader



static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& fileName);
static GLuint CreateShader(const std::string& text, GLenum shaderType); //defination or declaration?


Shader::Shader(const std::string& fileName)  //constructor for shader class
{
    m_program = glCreateProgram();
    m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER); // m_shader[0] is a vertex shader(.vs)
    m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER); // m_shader[1] is a fragment shader(.fs)

    for(unsigned int i= 0; i < NUM_SHADERS; i++)
        glAttachShader(m_program, m_shaders[i]); // adding shaders to the program

    glBindAttribLocation(m_program, 0, "position");

    glLinkProgram(m_program);
    CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program failed to link"); //checking whether the program was linked properly

    glValidateProgram(m_program);
    CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is Invalid"); //checking whether the program was validated properly
}

Shader::~Shader() //destructor method for shader class
{
    for(unsigned int i= 0; i < NUM_SHADERS; i++)
    {
        glDetachShader(m_program, m_shaders[i]); // detaching the shaders from the program
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_program); // after we are finished we don't wanna program to stick araound in gpu forever
}

static GLuint CreateShader(const std::string& text, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);
    if(shader == 0)
        std::cerr << "Error: shader creation failed" << std::endl;

    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader); //compile the shader
    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed"); //checking whether the program was validated properly

    return shader;
}


void Shader::Bind()
{
    glUseProgram(m_program);
}


static std::string LoadShader(const std::string& fileName)
{
    std::ifstream file; //must search for std::ifstream later
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line); //gets a line into line variable from file
            output.append(line + "\n");
        }
    }
    else
    {
        std::cerr << "Unable to load shader" << fileName << std::endl;
    }
    return output;
}


static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = {0};

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        std::cerr << errorMessage << " : '" << error << "'" << std::endl;
    }
}
