#include "global.h"


void computePos(float deltaMove) {
  if(deltaMove>0){
    rotateCar += deltaRotate;
    rotateCamera -= deltaRotate*pi/180;
  }else{
    rotateCar -= deltaRotate;
    rotateCamera += deltaRotate*pi/180;
  }
  lx = deltaMove * cos(-rotateCar*pi/180);
  lz = -deltaMove * sin(-rotateCar*pi/180);
  x = x + lx;
  z = z - lz;
  rx = rx + lx;
  rz = rz - lz;
}

void renderScene(void) {
  int i,j;
  if (deltaMove){
    computePos(deltaMove);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);           // Clear Color and Depth Buffers
  glLoadIdentity();                                             // Reset transformations/*
  gluLookAt(x , 100.0f, z+200,                                 //Change the camera position
            rx, 100.0f, rz,                                     //Change Lookat vector
            // rotateCamera, 50.0f,-1.0f,                       //Change Lookat vector
            0.0f, 100.0f, 0.0f );                               //Change Up vector*/

  drawWorld();

  glutSwapBuffers();
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
    glLightModelfv( GL_LIGHT_MODEL_AMBIENT, amb_light );
    glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse0 );
    glLightfv( GL_LIGHT0, GL_POSITION, lightPos0);
    glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
    glEnable( GL_LIGHT0 );
    glEnable( GL_COLOR_MATERIAL );
    glShadeModel( GL_SMOOTH );
    glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE );
    glDepthFunc( GL_LEQUAL );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
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