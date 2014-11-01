#include "global.h"

float camPosX, lookX;
float camPosY, lookY;
float camPosZ, lookZ;

float angle;			
float lx,lz, rx, rz;			
float x, z, X, Z;				
float rotateCar;
float deltaRotate;
float deltaMove;
int worldNum;
bool pauseGame;
int inGame = 0;
int one, two, three, four, five, zero;
int menuNum, mainMenu, pauseMenu, arrow, settingsMenu, world1Snap, world2Snap, powerUp, healthBar, soundOn, soundOff, title, downArrow, powerFire, powerAir;
int powerToggle, landMineActivate, landX, landY, landZ;

int bulletCount = 0 , landmineCount=0;

GLUquadricObj* quad;

btDynamicsWorld* world;

btDispatcher* dispatcher;
btCollisionConfiguration* collisionConfig;
btBroadphaseInterface* broadphase;
btConstraintSolver* solver;

btRigidBody *btCar, *btCarNew, *btTractor, *btSideleft,*btSideright,*btSideback,*btSidefront, *btShed, *btBase, *btWall, *btFloor, *btWorld2;

std::vector<btRigidBody*> btLandmine, btBullet;

objloader car, carNew, tractor;
objloader sideleft,sideright,sideback,sidefront;
objloader shed, base, wall, flooor;
objloader world2;
objloader bullet, landmine;

int CAR, CARNEW, TRACTOR;
int SIDELEFT,SIDERIGHT,SIDEBACK,SIDEFRONT;
int SHED,WALL,BASE,FLOOR;
int WORLD2;
int BULLET, LANDMINE;
int flag = 0;

void renderScene(void){
  if(inGame < 4){
    renderMenu();
  }
  else{
  	if(flag==0){
	 	initializeWorld();
	 	flag = 1;
	 }
    renderGame();
  }
  glutSwapBuffers();
}

int main(int argc, char **argv) {

	camPosX=0, lookX=0;
	camPosY=0, lookY=0;
	camPosZ=0, lookZ=0;

	angle = 0.0f;						      // angle of rotation for the camera direction
	lx = 0.0f; lz = 0.0f;				  // actual vector representing the camera's direction
    rx = 0.0f; rz= -1.0f;
	x = 0.0f; z = 0.0f;				    // xz position of the car
    X = 0.0f; Z = 0.0f;           // XZ position of the camera
    rotateCar = 180.0f;
	deltaRotate = 0.0f;					  // the key states. These variables will be zero when no key is being presses
	deltaMove = 0;

  
	inGame = 0; menuNum = 1;

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1920,1080);
	glutCreateWindow("CaRWarS");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);

	initialize();
	initializeGame();

	// initializeSound();

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

  // enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
