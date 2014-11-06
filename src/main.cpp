#include "global.h"

userStats player1 = {100,5,5};
userStats player2 = {100,5,5};

float camPosX, lookX;
float camPosY, lookY;
float camPosZ, lookZ;

float camPosX1, lookX1;
float camPosY1, lookY1;
float camPosZ1, lookZ1;
float camPosX2, lookX2;
float camPosY2, lookY2;
float camPosZ2, lookZ2;
		
float x, z, rotateCar;
float x1, z1, rotateCar1;
float x2, z2, rotateCar2;

float deltaMove,deltaMove1,deltaMove2;
float deltaRotate, deltaRotate1, deltaRotate2;

int viewport1 = 0, viewport2 = 0;
int width, height;

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

object *btCar, *btCarNew, *btTractor, *btSideleft,*btSideright,*btSideback,*btSidefront, *btShed, *btBase, *btWall, *btFloor, *btWorld2;

std::vector<object*> btLandmine, btBullet;

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
int flag = 0, flag1=0;

void renderScene(void){
	if(inGame < 4){
		GLfloat aspect = (GLfloat) width / (height);
		glViewport(0, 0, width, height);    	
    	renderMenu();
	}
	else{
		if(flag==0){
		 	initializeWorld();
		 	flag = 1;
		}

		GLfloat aspect = (GLfloat) width / (2*height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, aspect, 0.1f, 10000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		glViewport(width/2, 0, width/2, height);
			viewport1=1; viewport2=0;
			renderGame();

		glViewport(0, 0, width/2, height);
			viewport1=0; viewport2=1;
			renderGame();
	}
glutSwapBuffers();
}

void killBullet(int index){
	world->removeCollisionObject(btBullet[index]->body);
    btMotionState* motionState = btBullet[index]->body->getMotionState();
    btCollisionShape* shape = btBullet[index]->body->getCollisionShape();

    delete shape;
    delete motionState;
    btBullet.erase (btBullet.begin()+index);

	for(int i=index;i<btBullet.size();i++){
		btBullet[i]->index = i;
	}
}

bool callbackFunc(btManifoldPoint& cp,const btCollisionObjectWrapper* obj1,int id1,int index1,const btCollisionObjectWrapper* obj2,int id2,int index2){
	int x,y, index;

	x = ((object*)obj1->getCollisionObject()->getUserPointer())->id;
	y = ((object*)obj2->getCollisionObject()->getUserPointer())->id;
	if(x==1)
		index = ((object*)obj1->getCollisionObject()->getUserPointer())->index;
	else if(y==1)
		index = ((object*)obj2->getCollisionObject()->getUserPointer())->index;

	// 0: PLAYER CAR ----- 1: BULLET ----- 2: PLANE ----- 3. LANDMINE
    if((x==1 && y==0)|(x==0 && y==1)){				//BULLET-CAR
    	killBullet(index);
    	player1.health = player1.health - 5;
    	player2.health = player2.health - 5;
    }
    else if((x==1 && y==2)|(x==2 && y==1)){			//BULLET-PLANE
    	killBullet(index);
    }


    return false;
}

int main(int argc, char **argv) {
	camPosX=0, lookX=0;
	camPosY=0, lookY=0;
	camPosZ=0, lookZ=0;

	camPosX1=0, lookX1=0;
	camPosY1=0, lookY1=0;
	camPosZ1=0, lookZ1=0;
	camPosX2=0, lookX2=0;
	camPosY2=0, lookY2=0;
	camPosZ2=0, lookZ2=0;

	x = 0.0f; z = 0.0f;				 	// xz position of the car
    rotateCar = 180.0f;
    x1 = 0.0f; z1 = 0.0f;				 	// xz position of the car
    rotateCar1 = 180.0f;
    x2 = 0.0f; z2 = 0.0f;				 	// xz position of the car
    rotateCar2 = 180.0f;

	deltaRotate = 0.0f;deltaRotate1 = 0.0f;deltaRotate2 = 0.0f;					// the key states. These variables will be zero when no key is being presses
	deltaMove = 0;deltaMove1 = 0;deltaMove2 = 0;

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
	gContactAddedCallback = (ContactAddedCallback) callbackFunc;

	initializeSound();

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutKeyboardUpFunc(releaseNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

  	// enter GLUT event processing cycle
	glutMainLoop();
	return 1;
}
