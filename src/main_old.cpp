#include "global.h"
#include "keyboard.h"
#include "objLoader.h"
#include "main.h"

#define pi 3.14159265359

float angle;			
float lx,lz, rx, rz;			
float x, z, X, Z;				
float rotateCar, rotateCamera;
float deltaRotate;
float deltaMove;

Model_OBJ shed;
Model_OBJ base;
Model_OBJ wall;
Model_OBJ car;


void computePos(float deltaMove) {
  if(deltaMove>0){
    rotateCar += deltaRotate;
    rotateCamera -= deltaRotate*pi/180;
  }else{
    rotateCar -= deltaRotate;
    rotateCamera += deltaRotate*pi/180;
  }
  lx = deltaMove * cos(rotateCar*pi/180);
  lz = deltaMove * sin(rotateCar*pi/180);
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
  gluLookAt(x , 300.0f, z+1000,                                     //Change the camera position
            rx, 300.0f, rz,                                     //Change Lookat vector
            // rotateCamera, 50.0f,-1.0f,                       //Change Lookat vector
            0.0f, 300.0f, 0.0f );                               //Change Up vector*/

  glPushMatrix();
    glTranslatef(x,0.0f,z-250.0f);
    glRotatef(-180.0 + rotateCar, 0.0, 1.0, 0.0);
    glScalef(100,100,100);
    car.Draw();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.0f, 0.0f, -1000.0f);
    glScalef(125,125,125);
    base.Draw();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-1300.0f, 0.0f, -800.0f);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(150,150,150);
    shed.Draw();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-400.0f, 0.0f, 100.0f);
    glScalef(125,125,125);
    wall.Draw();
  glPopMatrix();

  glutSwapBuffers();
} 


void initialize (void){

    glShadeModel( GL_SMOOTH );
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
    glClearDepth( 1.0f );
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

    GLfloat amb_light[] = { 0.2f, 0.2f, 0.2f, 1.0 };
    GLfloat diffuse0[] = { 0.5f, 0.5f, 0.5f, 1 };
    GLfloat lightPos0[] = {4.0f, 100.0f, 8.0f, 1.0 };
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
    glEnable(GL_LIGHT0); 
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

int main(int argc, char **argv) {

	char filename[100];

	angle = 0.0f;						      // angle of rotation for the camera direction
	lx = 0.0f; lz = 0.0f;				// actual vector representing the camera's direction
  rx = 0.0f; rz= -1.0f;
	x = 0.0f; z = 0.0f;				    // xz position of the car
  X = 0.0f; Z = 0.0f;           // XZ position of the camera
  rotateCar = 90.0f; rotateCamera=0.0f;
	deltaRotate = 0.0f;					  // the key states. These variables will be zero when no key is being presses
	deltaMove = 0;

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1920,1080);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	initialize();

	strcpy(filename , "../data/base.obj");
  base.Load(filename);
  strcpy(filename , "../data/shed.obj");
  shed.Load(filename);
  strcpy(filename , "../data/wall.obj");
  wall.Load(filename);
  strcpy(filename , "../data/car.obj");
  car.Load(filename);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

  // enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
