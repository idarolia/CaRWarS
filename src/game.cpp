#include "global.h"

void computePos(float deltaMove, int n) {
    if(n==1){
        if(deltaMove1>0){
            rotateCar1 += deltaRotate1;
        }else{
            rotateCar1 -= deltaRotate1;
        }
        x1 += deltaMove1 * sin(rotateCar1*pi/180);
        z1 += deltaMove1 * cos(rotateCar1*pi/180);
    }
    else if(n==2){
        if(deltaMove2>0){
            rotateCar2 += deltaRotate2;
        }else{
            rotateCar2 -= deltaRotate2;
        }
        x2 += deltaMove2 * sin(rotateCar2*pi/180);
        z2 += deltaMove2 * cos(rotateCar2*pi/180);
    }
}

void renderGame(void) {
    int i,j;
    if(deltaMove1){
        computePos(deltaMove1,1);
    }
    if(deltaMove2){
        computePos(deltaMove2,2);
    }

    glLoadIdentity();                                             // Reset transformations/*
  
    if(viewport1==1 && viewport2==0)
    {
        lookX1 = x1 + (float)sin(rotateCar1*pi/180)*10.0;
        lookY1 = 100.0f;
        lookZ1 = z1 + (float)cos(rotateCar1*pi/180)*10.0;

        camPosX1 = x1 - (float)sin(rotateCar1*pi/180)*250.0;
        camPosY1 = 100.0f; 
        camPosZ1 = z1 - (float)cos(rotateCar1*pi/180)*250.0;

        gluLookAt(camPosX1 , camPosY1, camPosZ1,     //Change the camera position
                  lookX1 , lookY1 , lookZ1,          //Change Lookat vector
                  0.0f, 100.0f, 0.0f );           //Change Up vector
    }
    else if(viewport1==0 && viewport2==1)
    {
        lookX2 = x2 + (float)sin(rotateCar2*pi/180)*10.0;
        lookY2 = 100.0f;
        lookZ2 = z2 + (float)cos(rotateCar2*pi/180)*10.0;

        camPosX2 = x2 - (float)sin(rotateCar2*pi/180)*250.0;
        camPosY2 = 100.0f; 
        camPosZ2 = z2 - (float)cos(rotateCar2*pi/180)*250.0;

        gluLookAt(camPosX2 , camPosY2, camPosZ2,     //Change the camera position
                  lookX2 , lookY2 , lookZ2,          //Change Lookat vector
                  0.0f, 100.0f, 0.0f );           //Change Up vector

    }
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
}

void initializeGame(void){
    quad=gluNewQuadric();
    collisionConfig = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfig);
    broadphase = new btDbvtBroadphase();
    solver = new btSequentialImpulseConstraintSolver();
    world = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfig);
    world->setGravity(btVector3(0,-100,0));

    arrow = loadTex("../data/images/arrow.bmp");
    downArrow = loadTex("../data/images/downArrow.bmp");
    mainMenu = loadTex("../data/images/mainMenu.bmp");
    pauseMenu = loadTex("../data/images/pauseMenu.bmp");
    world1Snap = loadTex("../data/images/world1Snap.bmp");
    world2Snap = loadTex("../data/images/world2Snap.bmp");
    healthBar = loadTex("../data/images/healthBar.bmp");
    soundOff = loadTex("../data/images/soundOff.bmp");
    soundOn = loadTex("../data/images/soundOn.bmp");
    title = loadTex("../data/images/title.bmp");
    powerFire = loadTex("../data/images/powerFire.bmp");
    powerAir = loadTex("../data/images/powerAir.bmp");
    powerUp = loadTex("../data/images/landmine.bmp");
    one = loadTex("../data/images/one.bmp");
    two = loadTex("../data/images/two.bmp");
    three = loadTex("../data/images/three.bmp");
    four = loadTex("../data/images/four.bmp");
    five = loadTex("../data/images/five.bmp");
}

void changeSize(int w, int h) {
	// Prevent a divide by zero, when window is too short (you cant make a window of zero width).
    if (h == 0)
        h = 1;
    GLfloat aspect = (GLfloat) w / h;

    width = w;
    height = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 10000.0f);
    glMatrixMode(GL_MODELVIEW);
}