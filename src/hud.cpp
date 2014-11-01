#include "global.h"
  
void renderHUD()
{
  orthoSet();
    glBindTexture(GL_TEXTURE_2D, healthBar);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(10,300);
      glTexCoord2f(1,0);  glVertex2f(30,300);
      glTexCoord2f(1,1);  glVertex2f(30,435);
      glTexCoord2f(0,1);  glVertex2f(10,435);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, powerUp);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(750,405);
      glTexCoord2f(1,0);  glVertex2f(780,405);
      glTexCoord2f(1,1);  glVertex2f(780,435);
      glTexCoord2f(0,1);  glVertex2f(750,435);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, one);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(745,430);
      glTexCoord2f(1,0);  glVertex2f(755,430);
      glTexCoord2f(1,1);  glVertex2f(755,440);
      glTexCoord2f(0,1);  glVertex2f(745,440);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, powerFire);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(750,355);
      glTexCoord2f(1,0);  glVertex2f(780,355);
      glTexCoord2f(1,1);  glVertex2f(780,385);
      glTexCoord2f(0,1);  glVertex2f(750,385);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, two);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(745,380);
      glTexCoord2f(1,0);  glVertex2f(755,380);
      glTexCoord2f(1,1);  glVertex2f(755,390);
      glTexCoord2f(0,1);  glVertex2f(745,390);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, powerAir);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(750,305);
      glTexCoord2f(1,0);  glVertex2f(780,305);
      glTexCoord2f(1,1);  glVertex2f(780,335);
      glTexCoord2f(0,1);  glVertex2f(750,335);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, four);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(745,330);
      glTexCoord2f(1,0);  glVertex2f(755,330);
      glTexCoord2f(1,1);  glVertex2f(755,340);
      glTexCoord2f(0,1);  glVertex2f(745,340);
    glEnd();
  orthoReset();
}

