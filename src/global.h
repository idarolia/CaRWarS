#ifndef _GLOBAL_H_
#define _GLOBAL_H_

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
# include <SDL/SDL.h>
# include "SDL/SDL.h"
# include "SDL/SDL_mixer.h"

# include "main.h"
# include "game.h"
# include "objLoader.h"
# include "keyboard.h"
# include "world.h"
# include "sound.h"

#define pi 3.14159265359

extern float angle;				// angle of rotation for the camera direction
extern float lx,lz,rx,rz;				// actual vector representing the camera's direction
extern float x, z, X, Z;		// XZ position of the car and camera
extern float rotateCar;
extern float rotateCamera;

// the key states. These variables will be zero when no key is being presses
extern float deltaMove;
extern float deltaRotate;

// extern Model_OBJ obj;
extern int worldNum;

extern objloader car, carNew, tractor;
extern objloader sideleft,sideright,sideback,sidefront;
extern objloader shed, base, wall, flooor;
extern objloader world2;

extern int CAR, CARNEW, TRACTOR;
extern int SIDELEFT,SIDERIGHT,SIDEBACK,SIDEFRONT;
extern int SHED,WALL,BASE,FLOOR;
extern int WORLD2;

#endif