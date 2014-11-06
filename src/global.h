#ifndef _GLOBAL_H_
#define _GLOBAL_H_

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <vector>

# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
# include <SDL/SDL.h>
# include "SDL/SDL.h"
# include "SDL/SDL_mixer.h"
# include "SDL/SDL_image.h"
# include <bullet/btBulletDynamicsCommon.h>


# include "main.h"
# include "game.h"
# include "objLoader.h"
# include "keyboard.h"
# include "world.h"
# include "sound.h"
# include "menu.h"
# include "ortho.h"
# include "hud.h"

struct userStats{
        float health;
        int landmineCount;
        int missileCount;
};
extern userStats player1,player2;


#define pi 3.14159265359

extern float camPosX, lookX;
extern float camPosY, lookY;
extern float camPosZ, lookZ;

extern float camPosX1, lookX1	;
extern float camPosY1, lookY1;
extern float camPosZ1, lookZ1;
extern float camPosX2, lookX2;
extern float camPosY2, lookY2;
extern float camPosZ2, lookZ2;

extern float x, z, rotateCar;			// XZ position of the car and camera
extern float x1, z1, rotateCar1;
extern float x2, z2, rotateCar2;

// the key states. These variables will be zero when no key is being presses
extern float deltaMove,deltaMove1,deltaMove2;
extern float deltaRotate, deltaRotate1, deltaRotate2;

extern int viewport1, viewport2;
extern int width, height;

// extern Model_OBJ obj;
extern bool pauseGame;
extern int menuNum;
extern int one, two, three, four, five, zero;
extern int mainMenu, arrow, pauseMenu, settingsMenu, world1Snap, world2Snap, powerUp, healthBar, soundOn, soundOff, title, downArrow, powerFire, powerAir;
extern int worldNum, inGame;
extern int powerToggle, landMineActivate, landX, landY, landZ;

extern objloader car, carNew, tractor;
extern objloader sideleft,sideright,sideback,sidefront;
extern objloader shed, base, wall, flooor;
extern objloader world2;
extern objloader bullet, landmine;

extern int CAR, CARNEW, TRACTOR;
extern int SIDELEFT,SIDERIGHT,SIDEBACK,SIDEFRONT;
extern int SHED,WALL,BASE,FLOOR;
extern int WORLD2;
extern int BULLET, LANDMINE;

extern int bulletCount,landmineCount;

extern GLUquadricObj* quad;

extern btDynamicsWorld* world;

extern btDispatcher* dispatcher;
extern btCollisionConfiguration* collisionConfig;
extern btBroadphaseInterface* broadphase;
extern btConstraintSolver* solver;

struct object{
        btRigidBody* body;
        bool hit;
		char *name;
		int id;			// 0: PLAYER CAR ----- 1: BULLET ----- 2: PLANE ----- 3. LANDMINE
		int index;
        object(btRigidBody* b, bool h, char* n, int i, int x) : body(b),hit(h),name(n),id(i),index(x) {}
};

extern object *btCar, *btCarNew, *btTractor, *btSideleft,*btSideright,*btSideback,*btSidefront, *btShed, *btBase, *btWall, *btFloor, *btWorld2;
extern std::vector<object*> btLandmine, btBullet;

#endif
