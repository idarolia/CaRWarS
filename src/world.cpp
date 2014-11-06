#include "global.h"

char filename[100];

void addBox(char* NAME,float width,float height,float depth,float x,float y,float z,float mass, object** BODY)
{
        btTransform t;
        t.setIdentity();
        t.setOrigin(btVector3(x,y,z));
        btBoxShape* box=new btBoxShape(btVector3(width/2.0,height/2.0,depth/2.0));
        btVector3 inertia(0,0,0);
        if(mass!=0.0)
                box->calculateLocalInertia(mass,inertia);
       
        btMotionState* motion=new btDefaultMotionState(t);
        btRigidBody::btRigidBodyConstructionInfo info(mass,motion,box,inertia);
        btRigidBody* body=new btRigidBody(info);
        world->addRigidBody(body);
        *BODY = new object(body,false,NAME,0,0);
        body->setUserPointer(*BODY);
}

void renderBox(object* box, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, int OBJECT)
{
        if(box->body->getCollisionShape()->getShapeType()!=BOX_SHAPE_PROXYTYPE)
                return;
        btVector3 extent=((btBoxShape*)box->body->getCollisionShape())->getHalfExtentsWithoutMargin();
        btTransform t;
        box->body->getMotionState()->getWorldTransform(t);
        float mat[16];
        
        if(OBJECT == CAR || OBJECT == CARNEW || OBJECT == TRACTOR)
        	t.setOrigin(btVector3(x,y,z));
        
        t.getOpenGLMatrix(mat);
        glPushMatrix();
            glMultMatrixf(mat);     //translation,rotation
			glPushMatrix();
				if(OBJECT==CARNEW | OBJECT==CAR){
					glRotatef(rx,ry,rz,0.0);
				}
				if(OBJECT==TRACTOR)
					glTranslatef(30,0,-5);

				glScalef(sx,sy,sz);
            	glCallList(OBJECT);
        	glPopMatrix();      
        glPopMatrix();
}

void addSphere(char* NAME,float rad,float x,float y,float z,float mass)
{
        btTransform t;
        t.setIdentity();
        t.setOrigin(btVector3(x,y,z));
        btSphereShape* sphere=new btSphereShape(rad);
        btVector3 inertia(0,0,0);
        if(mass!=0.0)
                sphere->calculateLocalInertia(mass,inertia);
       
        btMotionState* motion=new btDefaultMotionState(t);
        btRigidBody::btRigidBodyConstructionInfo info(mass,motion,sphere,inertia);
        btRigidBody* body=new btRigidBody(info);
        world->addRigidBody(body);
        btBullet.push_back(new object(body,false,NAME,1,btBullet.size()));
        body->setUserPointer(btBullet[btBullet.size()-1]);
}
 
void renderSphere(object* sphere)
{
        if(sphere->body->getCollisionShape()->getShapeType()!=SPHERE_SHAPE_PROXYTYPE)
                return;
        float r=((btSphereShape*)sphere->body->getCollisionShape())->getRadius();
        btTransform t;
        sphere->body->getMotionState()->getWorldTransform(t);
        float mat[16];
        t.getOpenGLMatrix(mat);
        glPushMatrix();
                glMultMatrixf(mat);     //translation,rotation
                gluSphere(quad,r,20,20);
        glPopMatrix();
}



void addPlane(char* NAME, float x, float y, float z, float nx, float ny, float nz, object **BODY)
{
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(x,y,z));
	btStaticPlaneShape* plane = new btStaticPlaneShape(btVector3(nx,ny,nz),0);
	btMotionState* motion = new btDefaultMotionState(t);
	btRigidBody::btRigidBodyConstructionInfo info(0.0,motion,plane);
	btRigidBody* body = new btRigidBody(info);
	world->addRigidBody(body);
    *BODY = new object(body,false,NAME,2,0);
    // strcpy(*BODY->name,NAME);
    body->setUserPointer(*BODY);
}

void renderPlane(object* plane, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, int OBJECT)
{
        if(plane->body->getCollisionShape()->getShapeType()!=STATIC_PLANE_PROXYTYPE)
                return;
        btTransform t;
        plane->body->getMotionState()->getWorldTransform(t);
        t.setOrigin(btVector3(x,y,z));
        float mat[16];
        t.getOpenGLMatrix(mat);
        glPushMatrix();
            glMultMatrixf(mat);     //translation,rotation
			glRotatef(rx, ry, rz, 0.0);
			glScalef(sx, sy, sz);
			glCallList(OBJECT);
		glPopMatrix();
}

void initializeWorld(){

	strcpy(filename , "../data/characters/car.obj");
    CAR = car.load(filename);
    strcpy(filename , "../data/characters/carNew.obj");
    CARNEW = carNew.load(filename);
    strcpy(filename , "../data/characters/tractor.obj");
    TRACTOR = tractor.load(filename);

    strcpy(filename, "../data/weapons/bullet.obj");
    BULLET = bullet.load(filename);
    strcpy(filename, "../data/weapons/landmine.obj");
    LANDMINE = landmine.load(filename);

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
	strcpy(filename , "floor");
    addPlane(filename,0,0,0,0,1,0,&btFloor);
	strcpy(filename , "sidewall");
    addPlane(filename,-3000,2000,0,1,0,0,&btSideleft);
    addPlane(filename,3000,2000,0,-1,0,0,&btSideright);
    addPlane(filename,0,2000,-3000,0,0,1,&btSideback);
    addPlane(filename,0,2000,3000,0,0,-1,&btSidefront);

	strcpy(filename , "player1");
    addBox(filename,50,130,200, x1,0,z1, 1000.0,&btCar);
	strcpy(filename , "player2");
 	addBox(filename,120,130,300, x2,15,z2, 1000.0,&btCarNew);
    // addBox(filename,300,270,150, -500,60,-500, 500.0,&btTractor);
}

void drawWorld(){
	long unsigned int i;
	if(worldNum == 1){
		renderBox(btCar, x1,0,z1, -90+rotateCar1,0,1, 200,175,200, CAR);
		renderBox(btCarNew, x2,15,x2, -90+rotateCar2,0,1, 50,50,50, CARNEW);
		// renderBox(btTractor, -500,60,-500, 0,0,0, 50,50,50, TRACTOR);

		renderPlane(btFloor, 0,0,0, 0,0,0, 3000,0,3000,FLOOR);
		renderPlane(btSideleft,-3000,2000,0, -90,0,1, 3000,2000,0,SIDELEFT);
		renderPlane(btSideright, 3000,2000,0, -90,0,1, 3000,2000,0,SIDERIGHT);
		renderPlane(btSideback, 0,2000,-3000, 0,0,0, 3000,2000,0,SIDEBACK);
		renderPlane(btSidefront, 0,2000,3000, 0,0,0, 3000,2000,0,SIDEFRONT);

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
		glPushMatrix();								// CHARACTERS
			glTranslatef(x,0.0f,z);
			glRotatef(-90, 0.0, 1.0, 0.0);
			glRotatef(rotateCar, 0.0, 1.0, 0.0);
			glScalef(200,175,200);
			glCallList(CAR);
		glPopMatrix();

		glPushMatrix();								// CHARACTERS
			glTranslatef(-3500.0f,20.0f,-2500.0f);
			glRotatef(210.0, 0.0, 1.0, 0.0);
			glScalef(50,50,50);
			glCallList(CARNEW);
		glPopMatrix();

		glPushMatrix();								// CHARACTERS
			glTranslatef(3500.0f,60.0f,-2500.0f);
			glRotatef(210.0, 0.0, 1.0, 0.0);
			glScalef(50,50,50);
			glCallList(TRACTOR);
		glPopMatrix();

		glPushMatrix();								// WHOLE WORLD
			glTranslatef(0.0f, -70.0f, 0.0f);
			glScalef(1000,750,1000);
			glCallList(WORLD2);
		glPopMatrix();

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
	}

	for(i=0; i<btLandmine.size(); i++){
		glDisable(GL_TEXTURE_2D);
			renderBox(btLandmine[i], x,0,z, 0,0,0, 25,25,25, LANDMINE);
		glEnable(GL_TEXTURE_2D);
	}
	for(i=0; i<btBullet.size(); i++){
		glDisable(GL_TEXTURE_2D);
			renderSphere(btBullet[i]);
		glEnable(GL_TEXTURE_2D);
	}

	renderHUD();
}

void addLandmine(int n)
{
	int flagLandmine = 0;
	if(n==1){
		x = x1;
		z = z1;
		if(player1.landmineCount>0){ 
			flagLandmine = 1;
	    	player1.landmineCount--;
	    }
	}
	else if(n==2){
		x = x2;
		z = z2;
		if(player2.landmineCount>0){ 
			flagLandmine = 1;
	    	player2.landmineCount--;
	    }
	}

    if(flagLandmine == 1)
    {
    	btTransform t;
        t.setIdentity();
        t.setOrigin(btVector3(x,0,z));
        float mass = 1.0;
        btBoxShape* box=new btBoxShape(btVector3(10/2.0,5/2.0,10/2.0));
        btVector3 inertia(0,0,0);
        if(mass!=0.0)
                box->calculateLocalInertia(mass,inertia);
       
        btMotionState* motion=new btDefaultMotionState(t);
        btRigidBody::btRigidBodyConstructionInfo info(mass,motion,box,inertia);
        btRigidBody* body=new btRigidBody(info);
        world->addRigidBody(body);
        
        strcpy(filename,"landmine");
        btLandmine.push_back(new object(body,false,filename,3,btLandmine.size()));
        body->setUserPointer(btLandmine[btLandmine.size()-1]);
	}
}

void addBullet(int n)
{
	if(n==1){
		x = x1;
		z = z1;
		rotateCar = rotateCar1;
	}
	else if(n==2){
		x = x2;
		z = z2;
		rotateCar = rotateCar2;
	}	

	strcpy(filename , "bullet");
	addSphere(filename,2.5,x,50.0,z,0.5);
	int size = btBullet.size();
	btBullet[size-1]->body->setLinearVelocity(btVector3(sin(rotateCar*pi/180)*5000,0,cos(rotateCar*pi/180)*5000));
	btBullet[size-1]->body->setCollisionFlags(btBullet[size-1]->body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
}
