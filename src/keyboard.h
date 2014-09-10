#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "global.h"

void processNormalKeys(unsigned char key, int xx, int yy);
void pressKey(int key, int xx, int yy);
void releaseKey(int key, int x, int y);

#endif