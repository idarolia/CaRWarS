#include "global.h"

// inGame = 1

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

  gluLookAt(  x - (float)sin(rotateCar*pi/180)*250.0 , 100.0f,  z - (float)cos(rotateCar*pi/180)*250.0,    //Change the camera position
              x + (float)sin(rotateCar*pi/180)*10.0 , 100.0f,  z + (float)cos(rotateCar*pi/180)*10.0,    //Change Lookat vector
             0.0f, 100.0f, 0.0f );                               //Change Up vector*/

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
    mainMenu = loadTex("../data/images/mainMenu.bmp");
    pauseMenu = loadTex("../data/images/mainMenu.bmp");
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