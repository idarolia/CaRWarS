#include "global.h"
  
void renderHUD()
{
  glColor3f(1.0f, 1.0f, 1.0f);
  glRecti(10,10,150,30);

 // glClear(GL_COLOR_BUFFER_BIT);
 glDisable(GL_LIGHTING);
  //glBindTexture(GL_TEXTURE_2D, POWER1);
  glBegin(GL_QUADS);
	glTexCoord2f(200,200);
	glVertex2f(200,200);
	glTexCoord2f(240,200);
	glVertex2f(240,200);
	glTexCoord2f(240,240);
	glVertex2f(240,240);
	glTexCoord2f(200,240);
	glVertex2f(200,240);
  glEnd();
  glFlush();	
 glEnable(GL_LIGHTING);

}

