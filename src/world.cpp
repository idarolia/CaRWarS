#include "global.h"

char filename[100];

struct userStats{
	int health;
	int landmineCount;
	int missileCount;
};
userStats user1 = {100,5,5};

void addBox(float width,float height,float depth,float x,float y,float z,float mass, btRigidBody** BODY)
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
        *BODY = body;
}

void renderBox(btRigidBody* box, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, int OBJECT)
{
        if(box->getCollisionShape()->getShapeType()!=BOX_SHAPE_PROXYTYPE)
                return;
        btVector3 extent=((btBoxShape*)box->getCollisionShape())->getHalfExtentsWithoutMargin();
        btTransform t;
        box->getMotionState()->getWorldTransform(t);
        float mat[16];
    	// t.setOrigin(btVector3(x,y,z));
        t.getOpenGLMatrix(mat);

        glPushMatrix();
                glMultMatrixf(mat);     //translation,rotation
                // glTranslatef(x,y,z);
				// glRotatef(rx, ry, rz, 0.0);
				glScalef(sx,sy,sz);
                glCallList(OBJECT);
                // glBegin(GL_QUADS);
                //         glVertex3f(-extent.x(),extent.y(),-extent.z());
                //         glVertex3f(-extent.x(),-extent.y(),-extent.z());
                //         glVertex3f(-extent.x(),-extent.y(),extent.z());
                //         glVertex3f(-extent.x(),extent.y(),extent.z());         
                // glEnd();
                // glBegin(GL_QUADS);
                //         glVertex3f(extent.x(),extent.y(),-extent.z());
                //         glVertex3f(extent.x(),-extent.y(),-extent.z());
                //         glVertex3f(extent.x(),-extent.y(),extent.z());
                //         glVertex3f(extent.x(),extent.y(),extent.z());          
                // glEnd();
                // glBegin(GL_QUADS);
                //         glVertex3f(-extent.x(),extent.y(),extent.z());
                //         glVertex3f(-extent.x(),-extent.y(),extent.z());
                //         glVertex3f(extent.x(),-extent.y(),extent.z());
                //         glVertex3f(extent.x(),extent.y(),extent.z());          
                // glEnd();
                // glBegin(GL_QUADS);
                //         glVertex3f(-extent.x(),extent.y(),-extent.z());
                //         glVertex3f(-extent.x(),-extent.y(),-extent.z());
                //         glVertex3f(extent.x(),-extent.y(),-extent.z());
                //         glVertex3f(extent.x(),extent.y(),-extent.z());         
                // glEnd();
                // glBegin(GL_QUADS);
                //         glVertex3f(-extent.x(),extent.y(),-extent.z());
                //         glVertex3f(-extent.x(),extent.y(),extent.z());
                //         glVertex3f(extent.x(),extent.y(),extent.z());
                //         glVertex3f(extent.x(),extent.y(),-extent.z());         
                // glEnd();
                // glBegin(GL_QUADS);
                //         glVertex3f(-extent.x(),-extent.y(),-extent.z());
                //         glVertex3f(-extent.x(),-extent.y(),extent.z());
                //         glVertex3f(extent.x(),-extent.y(),extent.z());
                //         glVertex3f(extent.x(),-extent.y(),-extent.z());        
                // glEnd();               
        glPopMatrix();
}

void addSphere(float rad,float x,float y,float z,float mass)
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
        btBullet.push_back(body);
}
 
void renderSphere(btRigidBody* sphere)
{
        if(sphere->getCollisionShape()->getShapeType()!=SPHERE_SHAPE_PROXYTYPE)
                return;
        float r=((btSphereShape*)sphere->getCollisionShape())->getRadius();
        btTransform t;
        sphere->getMotionState()->getWorldTransform(t);
        float mat[16];
        t.getOpenGLMatrix(mat);
        glPushMatrix();
                glMultMatrixf(mat);     //translation,rotation
                gluSphere(quad,r,20,20);
        glPopMatrix();
}



void addPlane(int x, int y, int z, int nx, int ny, int nz, btRigidBody **BODY)
{
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(x,y,z));
	btStaticPlaneShape* plane = new btStaticPlaneShape(btVector3(nx,ny,nz),0);
	btMotionState* motion = new btDefaultMotionState(t);
	btRigidBody::btRigidBodyConstructionInfo info(0.0,motion,plane);
	btRigidBody* body = new btRigidBody(info);
	world->addRigidBody(body);
	*BODY = body;
}

void renderPlane(btRigidBody* plane, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, int OBJECT)
{
        if(plane->getCollisionShape()->getShapeType()!=STATIC_PLANE_PROXYTYPE)
                return;
        btTransform t;
        plane->getMotionState()->getWorldTransform(t);
        t.setOrigin(btVector3(x,y,z));
        float mat[16];
        t.getOpenGLMatrix(mat);
        glPushMatrix();
            glMultMatrixf(mat);     //translation,rotation
			// glTranslatef(x, y, z);
			glRotatef(rx, ry, rz, 0.0);
			glScalef(sx, sy, sz);
			glCallList(OBJECT);
		glPopMatrix();
}

void initializeWorld(){
    addPlane(0,0,0,0,1,0,&btFloor);
    addPlane(-3000,2000,0,1,0,0,&btSideleft);
    addPlane(3000,2000,0,-1,0,0,&btSideright);
    addPlane(0,2000,-3000,0,0,1,&btSideback);
    addPlane(0,2000,3000,0,0,-1,&btSidefront);

    // addBox(50,100,50,0,0,0,1000.0,&btCar);
 	addBox(100,100,100,-150.0f,20.0f,-200.0f,100.0,&btCarNew);
  //   addBox(100,100,100,-150.0f,500.0f,-200.0f,500.0,&btTractor);

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
}

void drawWorld(){
	long unsigned int i;
	if(worldNum == 1){
		// renderBox(btCar,x,0,z,-90+rotateCar, 0,1, 200,175,200, CAR);
		// renderBox(btTractor, 200,185,0,210,0,1,50,50,50, TRACTOR);
		// renderBox(btCarNew, -1500,20,-2000,210,0,1,50,50,50, CARNEW);

		renderPlane(btFloor, 0,0,0, 0,0,0, 3000,0,3000,FLOOR);
		renderPlane(btSideleft,-3000,2000,0, -90,0,1, 3000,2000,0,SIDELEFT);
		renderPlane(btSideright, 3000,2000,0, -90,0,1, 3000,2000,0,SIDERIGHT);
		renderPlane(btSideback, 0,2000,-3000, 0,0,0, 3000,2000,0,SIDEBACK);
		renderPlane(btSidefront, 0,2000,3000, 0,0,0, 3000,2000,0,SIDEFRONT);

		for(i=0; i<btLandmine.size(); i++){
			glDisable(GL_TEXTURE_2D);
				renderBox(btLandmine[i], camPosX,0,camPosY,0,0,0,25,25,25, LANDMINE);
			glEnable(GL_TEXTURE_2D);
		}
		for(i=0; i<btBullet.size(); i++){
			glDisable(GL_TEXTURE_2D);
				renderSphere(btBullet[i]);
			glEnable(GL_TEXTURE_2D);
		}


		// glPushMatrix();								// WALL1
		// 	glRotatef(-15.0, 0.0, 1.0, 0.0);
		// 	glTranslatef(-1500.0f, 0.0f, 2500.0f);
		// 	glScalef(300,300,100);
		// 	glCallList(WALL);
		// glPopMatrix();

		// glPushMatrix();								// WALL2
		// 	glRotatef(25.0, 0.0, 1.0, 0.0);
		// 	glTranslatef(0.0f, 0.0f, 2500.0f);
		// 	glScalef(300,300,100);
		// 	glCallList(WALL);
		// glPopMatrix();

		// glPushMatrix();								// SHED
		// 	glTranslatef(-2410.0f, 0.0f, -800.0f);
		// 	glRotatef(90.0, 0.0, 1.0, 0.0);
		// 	glScalef(150,100,200);
		// 	glCallList(SHED);			
		// glPopMatrix();

		// glPushMatrix();								// BASE
		// 	glTranslatef(1000.0f, 0.0f,1500.0f);
		// 	glRotatef(80.0, 0.0, 1.0, 0.0);
		// 	glScalef(150,125,150);
		// 	glCallList(BASE);
		// glPopMatrix();
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
	renderHUD();
}

void addLandmine()
{
    if(user1.landmineCount>0)
    {
    	btTransform t;
        t.setIdentity();
        t.setOrigin(btVector3(camPosX,0.0,camPosZ));
        float mass = 1.0;
        btBoxShape* box=new btBoxShape(btVector3(10/2.0,5/2.0,10/2.0));
        btVector3 inertia(0,0,0);
        if(mass!=0.0)
                box->calculateLocalInertia(mass,inertia);
       
        btMotionState* motion=new btDefaultMotionState(t);
        btRigidBody::btRigidBodyConstructionInfo info(mass,motion,box,inertia);
        btRigidBody* body=new btRigidBody(info);
        world->addRigidBody(body);
        
        btLandmine.push_back(body);

	    user1.landmineCount--;
	}
}

void addBullet()
{
	// addBox(10,10,10,camPosX,0.0,camPosZ,1.0,&btBullet);
	addSphere(5.0,camPosX,0.0,camPosZ,1.0);
	int size = btBullet.size();
	btBullet[size-1]->setLinearVelocity(btVector3(sin(rotateCar*pi/180)*10000,100,cos(rotateCar*pi/180)*10000));
    // bulletCount=1;
}
