#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>
#include <SDL2/SDL.h>
class Display
{
public:
    Display(int width, int height, const std::string& title);
    virtual ~Display();

protected:

private:
    Display(const Display& other) {}
    Display& operator=(const Display& other) {}
};

#endif // DISPLAY_H
