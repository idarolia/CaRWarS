#include "global.h"

int loadTex(std::string fileName)
{
    SDL_Surface* image = SDL_LoadBMP(fileName.c_str());
    unsigned int object;
    glGenTextures(1, &object);
    glBindTexture(GL_TEXTURE_2D, object);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->w,image->h,0, GL_RGB, GL_UNSIGNED_BYTE, image -> pixels);
    SDL_FreeSurface(image);
    return object;
}

void orthoSet(void)
{
  glLoadIdentity();
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
    glLoadIdentity();
    glOrtho(0,800,450,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();  
      glLoadIdentity();
}
 
void orthoReset(void)
{
      glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
}
