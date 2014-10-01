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


int CAR,SHED,WALL,BASE,CUBE;
objloader shed;
objloader base;
objloader wall;
objloader car;
objloader cube;


void computePos(float deltaMove) {
  if(deltaMove>0){
    rotateCar += deltaRotate;
    rotateCamera -= deltaRotate*pi/180;
  }else{
    rotateCar -= deltaRotate;
    rotateCamera += deltaRotate*pi/180;
  }
  lx = deltaMove * sin(rotateCar*pi/180);
  lz = -deltaMove * cos(rotateCar*pi/180);
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
  gluLookAt(x , 800.0f, z+100,                                 //Change the camera position
            rx, 800.0f, rz,                                     //Change Lookat vector
            // rotateCamera, 50.0f,-1.0f,                       //Change Lookat vector
            0.0f, 800.0f, 0.0f );                               //Change Up vector*/

  glPushMatrix();
    glTranslatef(x,0.0f,z-250.0f);
    glRotatef(rotateCar, 0.0, 1.0, 0.0);
    glScalef(100,75,100);
    glCallList(CAR);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.0f, 0.0f,0.0f);
    glScalef(2000,0,2000);
    glCallList(CUBE);
  glPopMatrix();

  glPushMatrix();
    glRotatef(-15.0, 0.0, 1.0, 0.0);
    glTranslatef(-800.0f, 0.0f, 1500.0f);
    glScalef(300,300,100);
    glCallList(WALL);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-2020.0f, 0.0f, -800.0f);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(400,400,400);
    glCallList(SHED);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(500.0f, 0.0f, -700.0f);
    glRotatef(-80.0, 0.0, 1.0, 0.0);
    glScalef(300,200,300);
    glCallList(BASE);
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

    // GLfloat fogColor[] = {0.5f,0.5f,0.5f,1.0f};
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
    glEnable(GL_LIGHT0); 
    // glEnable(GL_FOG);
    // glFogi(GL_FOG_MODE,GL_LINEAR);
    // glFogf(GL_FOG_START,10.0);
    // glFogf(GL_FOG_END,100.0);
    // glFogfv(GL_FOG_COLOR, fogColor);
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
  rotateCar = 180.0f; rotateCamera=0.0f;
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

	strcpy(filename , "../data/world1/base.obj");
  BASE = base.load(filename);
  strcpy(filename , "../data/world1/shed.obj");
  SHED = shed.load(filename);
  strcpy(filename , "../data/world1/wall.obj");
  WALL = wall.load(filename);
  strcpy(filename , "../data/characters/car.obj");
  CAR = car.load(filename);
  strcpy(filename , "../data/world1/cube.obj");
  CUBE = cube.load(filename);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

  // enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
