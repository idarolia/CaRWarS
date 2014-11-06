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

  if (key == 47){ 
    addLandmine(1);
  }
  if (key == 118){ 
    addLandmine(2);
  }
  
  if (key == 46){ 
    addBullet(1);
  }
  if (key == 99){ 
    addBullet(2);
  }
  switch (key) {
  case 119    : deltaMove2 = 5.0f; break;
  case 115    : deltaMove2 = -5.0f; break;
  case 97     : deltaRotate2 = 0.5f; break;
  case 100    : deltaRotate2 = -0.5f; break;
  }
} 

void releaseNormalKeys(unsigned char key, int xx, int yy) {
  if(inGame){
    switch (key) {
      case 119 : deltaMove2 = 0; break;
      case 115 : deltaMove2 = 0; break;
      case 97 : deltaRotate2 = 0; break;
      case 100 : deltaRotate2 = 0;break;
    }
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
      case GLUT_KEY_UP    : deltaMove1 = 5.0f; break;
      case GLUT_KEY_DOWN  : deltaMove1 = -5.0f; break;
      case GLUT_KEY_LEFT  : deltaRotate1 = 0.5f; break;
      case GLUT_KEY_RIGHT : deltaRotate1 = -0.5f; break;
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
      case GLUT_KEY_UP : deltaMove1 = 0;break;
      case GLUT_KEY_DOWN : deltaMove1 = 0;break;
      case GLUT_KEY_LEFT : deltaRotate1 = 0;break;
      case GLUT_KEY_RIGHT : deltaRotate1 = 0;break;
    }
  }
}