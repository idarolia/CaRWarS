#include "global.h"
#include "main.h"
#include "objLoader.h"

void processNormalKeys(unsigned char key, int xx, int yy) {   
        if (key == 27)
              exit(0);
} 

void pressKey(int key, int xx, int yy) {
       switch (key) {
             case GLUT_KEY_UP : deltaMove = 10.0f; break;
             case GLUT_KEY_DOWN : deltaMove = -10.0f; break;
       }
} 

void releaseKey(int key, int x, int y) {  
        switch (key) {
             case GLUT_KEY_UP :
             case GLUT_KEY_DOWN : deltaMove = 0;break;
        }
}