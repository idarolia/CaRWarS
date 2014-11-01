#include "global.h"

void processNormalKeys(unsigned char key, int xx, int yy) {   
  if (key == 27 && inGame == 4){
    inGame = 1;
  }
  if (key == 27 && inGame == 2){
    if(!pauseGame)
      inGame = 0;
    else 
      inGame = 1;
  }
  if (key == 27 && inGame == 3){
    printf("escape");
    if(!pauseGame)
      inGame = 0;
    else 
      inGame = 1;
  }
  if (key == 13 && inGame < 4){
    mainMenuCall();
  }

  if (key == 122){ 
    addLandmine();
  }
  if (key == 32){ 
    addBullet();
  }
} 

void pressKey(int key, int xx, int yy) {
  if(inGame < 4){
    switch (key) {
      case GLUT_KEY_UP    : if(menuNum==1){menuNum=1;}else{menuNum--;} break;
      case GLUT_KEY_DOWN  : if(menuNum==3){menuNum=3;}else{menuNum++;} break;
      case GLUT_KEY_LEFT  : if(menuNum==1){menuNum=1;}else{menuNum--;} break;
      case GLUT_KEY_RIGHT : if(menuNum==3){menuNum=3;}else{menuNum++;} break;
    }
  }else{
    switch (key) {
      case GLUT_KEY_UP    : deltaMove = 10.0f; break;
      case GLUT_KEY_DOWN  : deltaMove = -10.0f; break;
      case GLUT_KEY_LEFT  : deltaRotate = 1.0f; break;
      case GLUT_KEY_RIGHT : deltaRotate = -1.0f; break;
    }
  }
  switch(key)
  {
    case GLUT_KEY_F10   : if( Mix_PausedMusic() == 1 )
                              Mix_ResumeMusic();
                            else
                              Mix_PauseMusic();
                            break;
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