#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
# include "objLoader.h"

extern float multiplier;

extern float angle;				// angle of rotation for the camera direction
extern float lx,lz;				// actual vector representing the camera's direction
extern float x, z;					// XZ position of the camera

// the key states. These variables will be zero when no key is being presses
extern float deltaAngle;
extern float deltaMove;
extern int xOrigin;

extern Model_OBJ obj;

#endif