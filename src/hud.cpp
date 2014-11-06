#include "global.h"
  
void renderHUD()
{
  orthoSet();
    if(viewport1==1 && viewport2==0){
      glBindTexture(GL_TEXTURE_2D, healthBar);
      glBegin(GL_QUADS);
        glTexCoord2f(0,0);  glVertex2f(10,435-(player1.health/100)*135);
        glTexCoord2f(1,0);  glVertex2f(30,435-(player1.health/100)*135);
        glTexCoord2f(1,1);  glVertex2f(30,435);
        glTexCoord2f(0,1);  glVertex2f(10,435);
      glEnd();
    }

    if(viewport1==0 && viewport2==1){
      glBindTexture(GL_TEXTURE_2D, healthBar);
      glBegin(GL_QUADS);
        glTexCoord2f(0,0);  glVertex2f(10,435-(player2.health/100)*135);
        glTexCoord2f(1,0);  glVertex2f(30,435-(player2.health/100)*135);
        glTexCoord2f(1,1);  glVertex2f(30,435);
        glTexCoord2f(0,1);  glVertex2f(10,435);
      glEnd();
    }

    glBindTexture(GL_TEXTURE_2D, powerUp);
    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(750,405);
      glTexCoord2f(1,0);  glVertex2f(780,405);
      glTexCoord2f(1,1);  glVertex2f(780,435);
      glTexCoord2f(0,1);  glVertex2f(750,435);
    glEnd();

    if(player1.landmineCount==1)
      glBindTexture(GL_TEXTURE_2D, one);
    else if(player1.landmineCount==2)
      glBindTexture(GL_TEXTURE_2D, two);
    else if(player1.landmineCount==3)
      glBindTexture(GL_TEXTURE_2D, three);
    else if(player1.landmineCount==4)
      glBindTexture(GL_TEXTURE_2D, four);
    else if(player1.landmineCount==5)
      glBindTexture(GL_TEXTURE_2D, five);
    else if(player1.landmineCount==0)
      glBindTexture(GL_TEXTURE_2D, five);

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

    if(player1.missileCount==1)
      glBindTexture(GL_TEXTURE_2D, one);
    else if(player1.missileCount==2)
      glBindTexture(GL_TEXTURE_2D, two);
    else if(player1.missileCount==3)
      glBindTexture(GL_TEXTURE_2D, three);
    else if(player1.missileCount==4)
      glBindTexture(GL_TEXTURE_2D, four);
    else if(player1.missileCount==5)
      glBindTexture(GL_TEXTURE_2D, five);
    else if(player1.missileCount==0)
      glBindTexture(GL_TEXTURE_2D, five);

    glBegin(GL_QUADS);
      glTexCoord2f(0,0);  glVertex2f(745,380);
      glTexCoord2f(1,0);  glVertex2f(755,380);
      glTexCoord2f(1,1);  glVertex2f(755,390);
      glTexCoord2f(0,1);  glVertex2f(745,390);
    glEnd();
  orthoReset();
}

