#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
    Vertex(const glm::vec3 &pos)
    { //shall take address of the position variable
        this->pos = pos;
    }

protected:
private:
    glm::vec3 pos; //for vertex data
};

class Mesh
{
public:
    Mesh(Vertex *vertices, unsigned int numVertices);
    void Draw(); //function to draw
    virtual ~Mesh();

protected:
private:
    Mesh(const Mesh &other);
    void operator=(const Mesh &other);

    enum
    {
        POSITION_VB,
        NUM_BUFFERS   //if not specified, position buffer = num_buffers - 1
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif // MESH_H
