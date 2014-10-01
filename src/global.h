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

extern float angle;				// angle of rotation for the camera direction
extern float lx,lz,rx,rz;				// actual vector representing the camera's direction
extern float x, z, X, Z;		// XZ position of the car and camera
extern float rotateCar;
extern float rotateCamera;

// the key states. These variables will be zero when no key is being presses
extern float deltaMove;
extern float deltaRotate;

// extern Model_OBJ obj;
extern objloader obj;

#endif