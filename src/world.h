#include "global.h"

void addBox(char*,float,float,float,float,float,float, float,struct object**);
void renderBox(struct object*, float, float, float, float, float, float, float, float, float, int);
void addSphere(char*,float,float,float,float,float);
void renderSphere(struct object*);
void addPlane(char*, float, float, float, float, float, float,struct object**);
void renderPlane(struct object*, float, float, float, float, float, float, float, float, float, int);
void initializeWorld(void);
void drawWorld(void);
void addLandmine(int);
void addBullet(int);