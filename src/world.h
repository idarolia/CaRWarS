#include "global.h"

void addBox(float ,float ,float ,float ,float ,float ,float , btRigidBody** );
void addPlane(int, int, int, btRigidBody**);
void renderBox(btRigidBody*, float, float, float, float, float, float, float, float, float, int);
void renderPlane(btRigidBody*, float, float, float, float, float, float, float, float, float, int);
void addPlane(void);
void renderPlane(btRigidBody*);
void addLandmine();
void addBullet();
void initializeWorld(void);
void drawWorld(void);