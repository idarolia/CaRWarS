#include "global.h"

char filename[100];

void initializeWorld(){
	strcpy(filename , "../data/characters/car.obj");
    CAR = car.load(filename);

	if(worldNum == 1){
		strcpy(filename , "../data/world1/base.obj");
		BASE = base.load(filename);
		strcpy(filename , "../data/world1/shed.obj");
		SHED = shed.load(filename);
		strcpy(filename , "../data/world1/wall.obj");
		WALL = wall.load(filename);
		strcpy(filename , "../data/world1/floor.obj");
		FLOOR = flooor.load(filename);
		strcpy(filename , "../data/world1/sideleft.obj");
		SIDELEFT = sideleft.load(filename);
		strcpy(filename , "../data/world1/sideright.obj");
		SIDERIGHT = sideright.load(filename);
		strcpy(filename , "../data/world1/sideback.obj");
		SIDEBACK = sideback.load(filename);
		strcpy(filename , "../data/world1/sidefront.obj");
		SIDEFRONT = sidefront.load(filename);
	}
	else if(worldNum == 2){
		strcpy(filename , "../data/world2/world2.obj");
		WORLD2 = world2.load(filename);
		strcpy(filename , "../data/world2/sideleft.obj");
		SIDELEFT = sideleft.load(filename);
		strcpy(filename , "../data/world2/sideright.obj");
		SIDERIGHT = sideright.load(filename);
		strcpy(filename , "../data/world2/sideback.obj");
		SIDEBACK = sideback.load(filename);
		strcpy(filename , "../data/world2/sidefront.obj");
		SIDEFRONT = sidefront.load(filename);

	}
}

void drawWorld(){
	if(worldNum == 1){
		glPushMatrix();								// CAR
			glTranslatef(x,0.0f,z-250.0f);
			glRotatef(rotateCar, 0.0, 1.0, 0.0);
			glScalef(100,75,100);
			glCallList(CAR);
		glPopMatrix();

		glPushMatrix();								// FLOOR
			glTranslatef(0.0f, 0.0f,0.0f);
			glScalef(3000,0,3000);
			glCallList(FLOOR);
		glPopMatrix();

		glPushMatrix();								// LEFT WALL
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			glTranslatef(0.0f, 2000.0f,3000.0f);
			glScalef(3000,2000,0);
			glCallList(SIDELEFT);
		glPopMatrix();

		glPushMatrix();								// BACK WALL
			glTranslatef(0.0f, 2000.0f,-3000.0f);
			glScalef(3000,2000,0);
			glCallList(SIDEBACK);
		glPopMatrix();

		glPushMatrix();								// RIGHT WALL
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			glTranslatef(0.0f, 2000.0f,-3000.0f);
			glScalef(3000,2000,0);
			glCallList(SIDERIGHT);
		glPopMatrix();

		glPushMatrix();								// FRONT WALL
			glTranslatef(0.0f, 2000.0f,3000.0f);
			glScalef(3000,2000,0);
			glCallList(SIDEFRONT);
		glPopMatrix();

		glPushMatrix();								// WALL1
			glRotatef(-15.0, 0.0, 1.0, 0.0);
			glTranslatef(-1500.0f, 0.0f, 2500.0f);
			glScalef(300,300,100);
			glCallList(WALL);
		glPopMatrix();

		glPushMatrix();								// WALL2
			glRotatef(25.0, 0.0, 1.0, 0.0);
			glTranslatef(0.0f, 0.0f, 2500.0f);
			glScalef(300,300,100);
			glCallList(WALL);
		glPopMatrix();

		glPushMatrix();								// SHED
			glTranslatef(-2410.0f, 0.0f, -800.0f);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(150,100,200);
			glCallList(SHED);			
		glPopMatrix();

		glPushMatrix();								// BASE
			glTranslatef(1000.0f, 0.0f,1500.0f);
			glRotatef(80.0, 0.0, 1.0, 0.0);
			glScalef(150,125,150);
			glCallList(BASE);
		glPopMatrix();
	}
	else if(worldNum == 2){
		glPushMatrix();								// CAR
			glTranslatef(x,0.0f,z-250.0f);
			glRotatef(rotateCar, 0.0, 1.0, 0.0);
			glScalef(100,75,100);
			glCallList(CAR);
		glPopMatrix();

		glPushMatrix();								// WHOLE WORLD
			glTranslatef(0.0f, -100.0f, 0.0f);
			glScalef(1000,750,1000);
			glCallList(WORLD2);
		glPopMatrix();

		// glDisable(GL_LIGHTING);
		glPushMatrix();								//LEFT WALL
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			glTranslatef(60.0f, 1900.0f,3900.0f);
			glScalef(3910,2000,0);
			glCallList(SIDELEFT);
		glPopMatrix();

		glPushMatrix();								//BACK WALL
			glTranslatef(0.0f, 1900.0f,-3850.0f);
			glScalef(3910,2000,0);
			glCallList(SIDEBACK);
		glPopMatrix();

		glPushMatrix();								//RIGHT WALL
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			glTranslatef(60.0f, 1900.0f,-3900.0f);
			glScalef(3910,2000,0);
			glCallList(SIDERIGHT);
		glPopMatrix();

		glPushMatrix();								//FRONT WALL
			glTranslatef(0.0f, 1900.0f,3950.0f);
			glScalef(3910,2000,0);
			glCallList(SIDEFRONT);
		glPopMatrix();
		// glEnable(GL_LIGHTING);
	}
}