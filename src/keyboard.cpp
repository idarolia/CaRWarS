#include "global.h"

void processNormalKeys(unsigned char key, int xx, int yy) {   
  if (key == 27 && inGame){
    inGame = false;
    pauseGame = true;
  }
  if (key == 13 && !inGame){
    mainMenuCall();
  }
} 

void pressKey(int key, int xx, int yy) {
  if(!inGame){
    switch (key) {
      case GLUT_KEY_UP    : if(menuNum==1){menuNum=1;}else{menuNum--;} break;
      case GLUT_KEY_DOWN  : if(menuNum==4){menuNum=4;}else{menuNum++;} break;
      case GLUT_KEY_LEFT  : if(menuNum==1){menuNum=1;}else{menuNum--;} break;
      case GLUT_KEY_RIGHT : if(menuNum==4){menuNum=4;}else{menuNum++;} break;
    }
  }else{
    switch (key) {
      case GLUT_KEY_UP    : deltaMove = 10.0f; break;
      case GLUT_KEY_DOWN  : deltaMove = -10.0f; break;
      case GLUT_KEY_LEFT  : deltaRotate = 1.0f; break;
      case GLUT_KEY_RIGHT : deltaRotate = -1.0f; break;
      case GLUT_KEY_F10   : if( Mix_PausedMusic() == 1 )
                              Mix_ResumeMusic();
                            else
                              Mix_PauseMusic();
                            break;
    }
  }
} 

void releaseKey(int key, int x, int y) {
  if(inGame){
    switch (key) {
      case GLUT_KEY_UP : deltaMove = 0;break;
      case GLUT_KEY_DOWN : deltaMove = 0;break;
      case GLUT_KEY_LEFT : deltaRotate = 0;break;
      case GLUT_KEY_RIGHT : deltaRotate = 0;break;
    }
  }
}