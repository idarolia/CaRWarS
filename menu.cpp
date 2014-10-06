#include "global.h"
#include <SDL/SDL_image.h>
#include <string.h>
int arrow, mainMenu;

int loadTex(std::string fileName)
{
    SDL_Surface* image = SDL_LoadBMP(fileName.c_str());
    //SDL_Surface *image = IMG_Load(fileName.c_str());
    //SDL_DisplayFormatAlpha(image);
    unsigned int object;
    glGenTextures(1, &object);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, object);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    //glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    //glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->w,image->h,0, GL_RGB, GL_UNSIGNED_BYTE, image -> pixels);
    SDL_FreeSurface(image);
    return object;
}

void initMenu(void)
{
    arrow = loadTex("../data/menu/pics/arrow.bmp");
    mainMenu = loadTex("../data/menu/pics/mainMenu.bmp");
}

void renderMenu(void)
{
	orthoSet();
	glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, mainMenu);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  glVertex2f(100, 100);
        glTexCoord2f(0, 1);  glVertex2f(100, 200);
        glTexCoord2f(1, 1);  glVertex2f(200, 200);
        glTexCoord2f(1, 0);  glVertex2f(200, 100);
    glEnd();
	orthoReset();
	
}

