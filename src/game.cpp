#include "global.h"

void computePos(float deltaMove) {
  if(deltaMove>0){
    rotateCar += deltaRotate;
  }else{
    rotateCar -= deltaRotate;
  }
  x += deltaMove * sin(rotateCar*pi/180);
  z += deltaMove * cos(rotateCar*pi/180);
  rx += deltaMove * sin(rotateCar*pi/180);
  rz += deltaMove * cos(rotateCar*pi/180);
}

void renderGame(void) {
  int i,j;
  if (deltaMove){
    computePos(deltaMove);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);           // Clear Color and Depth Buffers
  glLoadIdentity();                                             // Reset transformations/*
  
  lookX = x + (float)sin(rotateCar*pi/180)*10.0;
  lookY = 100.0f;
  lookZ = z + (float)cos(rotateCar*pi/180)*10.0;

  camPosX = x - (float)sin(rotateCar*pi/180)*250.0;
  camPosY = 100.0f; 
  camPosZ = z - (float)cos(rotateCar*pi/180)*250.0;

  gluLookAt(camPosX , camPosY, camPosZ,     //Change the camera position
            lookX , lookY , lookZ,          //Change Lookat vector
            0.0f, 100.0f, 0.0f );           //Change Up vector
  world->stepSimulation(1/60.0);
  drawWorld();
} 


void initialize (void){

    glShadeModel( GL_SMOOTH );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
    glClearDepth( 1.0f );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

    GLfloat amb_light[] = { 0.2f, 0.2f, 0.2f, 1.0 };
    GLfloat diffuse0[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat lightPos0[] = {1000.0f, 1000.0f, 1000.0f, 1.0 };
    GLfloat specular[] = { 0.7, 0.7, 0.3, 1 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    arrow = loadTex("../data/images/arrow.bmp");
    downArrow = loadTex("../data/images/downArrow.bmp");
    mainMenu = loadTex("../data/images/mainMenu.bmp");
    pauseMenu = loadTex("../data/images/pauseMenu.bmp");
    world1Snap = loadTex("../data/images/world1Snap.bmp");
    world2Snap = loadTex("../data/images/world2Snap.bmp");
    powerUp = loadTex("../data/images/powerUp.bmp");
    healthBar = loadTex("../data/images/healthBar.bmp");
    soundOff = loadTex("../data/images/soundOff.bmp");
    soundOn = loadTex("../data/images/soundOn.bmp");
    title = loadTex("../data/images/title.bmp");
    powerFire = loadTex("../data/images/powerFire.bmp");
    powerAir = loadTex("../data/images/powerAir.bmp");
    one = loadTex("../data/images/one.bmp");
    two = loadTex("../data/images/two.bmp");
    four = loadTex("../data/images/four.bmp");
}

void initializeGame(void){
    quad=gluNewQuadric();
    collisionConfig = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfig);
    broadphase = new btDbvtBroadphase();
    solver = new btSequentialImpulseConstraintSolver();
    world = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfig);
    world->setGravity(btVector3(0,-100,0));
}

void changeSize(int w, int h) {
	// Prevent a divide by zero, when window is too short (you cant make a window of zero width).
	if (h == 0)
		h = 1;
    GLfloat aspect = (GLfloat) w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, aspect, 0.1f, 10000.0f);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
}