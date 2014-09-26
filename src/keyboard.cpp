#include "global.h"
#include "main.h"
#include "objLoader.h"

void processNormalKeys(unsigned char key, int xx, int yy) {   
  if (key == 27)
  exit(0);
} 

void pressKey(int key, int xx, int yy) {
  switch (key) {
    case GLUT_KEY_UP    : deltaMove = 1.0f; break;
    case GLUT_KEY_DOWN  : deltaMove = -1.0f; break;
    case GLUT_KEY_LEFT   : deltaRotateCar = 0.5f; break;
    case GLUT_KEY_RIGHT  : deltaRotateCar = -0.5f; break;
  }
} 

void releaseKey(int key, int x, int y) {  
  switch (key) {
    case GLUT_KEY_UP : deltaMove = 0;break;
    case GLUT_KEY_DOWN : deltaMove = 0;break;
    case GLUT_KEY_LEFT : deltaRotateCar = 0;break;
    case GLUT_KEY_RIGHT : deltaRotateCar = 0;break;
  }
}