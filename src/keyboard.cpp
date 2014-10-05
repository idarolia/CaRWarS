#include "global.h"

void processNormalKeys(unsigned char key, int xx, int yy) {   
  if (key == 27)
  exit(0);
} 

void pressKey(int key, int xx, int yy) {
  switch (key) {
    case GLUT_KEY_UP    : deltaMove = 10.0f; break;
    case GLUT_KEY_DOWN  : deltaMove = -10.0f; break;
    case GLUT_KEY_LEFT  : deltaRotate = 1.5f; break;
    case GLUT_KEY_RIGHT : deltaRotate = -1.5f; break;
    case GLUT_KEY_F10   : if( Mix_PausedMusic() == 1 )
                            Mix_ResumeMusic();
                          else
                            Mix_PauseMusic();
                          break;
  }
} 

void releaseKey(int key, int x, int y) {  
  switch (key) {
    case GLUT_KEY_UP : deltaMove = 0;break;
    case GLUT_KEY_DOWN : deltaMove = 0;break;
    case GLUT_KEY_LEFT : deltaRotate = 0;break;
    case GLUT_KEY_RIGHT : deltaRotate = 0;break;
  }
}