#include "global.h"
#include "main.h"
#include "objLoader.h"

void computePos(float deltaMove) {
  x += deltaMove * lx * 0.1f;
  z += deltaMove * lz * 0.1f;
}
 
void drawOuterBoundary(void){
  glBegin(GL_QUADS);
      // Back face
      glColor3f(0.9f, 0.9f, 0.9f);
    glVertex3f( 10.0*multiplier,  10.0*multiplier, -10.0*multiplier);
    glVertex3f(-10.0*multiplier,  10.0*multiplier, -10.0*multiplier);
    glVertex3f(-10.0*multiplier,   0.0*multiplier, -10.0*multiplier);
    glVertex3f( 10.0*multiplier,   0.0*multiplier, -10.0*multiplier);

    // Right face
    glVertex3f( 10.0*multiplier,  10.0*multiplier, -10.0*multiplier);
    glVertex3f( 10.0*multiplier,  10.0*multiplier,  10.0*multiplier);
    glVertex3f( 10.0*multiplier,   0.0*multiplier,  10.0*multiplier);
    glVertex3f( 10.0*multiplier,   0.0*multiplier, -10.0*multiplier);

    // Left face
    glVertex3f(-10.0*multiplier,  10.0*multiplier, -10.0*multiplier);
    glVertex3f(-10.0*multiplier,  10.0*multiplier,  10.0*multiplier);
    glVertex3f(-10.0*multiplier,   0.0*multiplier,  10.0*multiplier);
    glVertex3f(-10.0*multiplier,   0.0*multiplier, -10.0*multiplier);

    // Top face
    glVertex3f(-10.0*multiplier,  10.0*multiplier, -10.0*multiplier);
    glVertex3f(-10.0*multiplier,  10.0*multiplier,  10.0*multiplier);
    glVertex3f( 10.0*multiplier,  10.0*multiplier,  10.0*multiplier);
    glVertex3f( 10.0*multiplier,  10.0*multiplier, -10.0*multiplier);

    // Front face
    glVertex3f(-10.0*multiplier,  10.0*multiplier,  10.0*multiplier);
    glVertex3f( 10.0*multiplier,  10.0*multiplier,  10.0*multiplier);
    glVertex3f( 10.0*multiplier,   0.0*multiplier,  10.0*multiplier);
    glVertex3f(-10.0*multiplier,   0.0*multiplier,  10.0*multiplier);

    // Bottom face
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-10.0*multiplier,   0.0*multiplier, -10.0*multiplier);
    glVertex3f(-10.0*multiplier,   0.0*multiplier,  10.0*multiplier);
    glVertex3f( 10.0*multiplier,   0.0*multiplier,  10.0*multiplier);
    glVertex3f( 10.0*multiplier,   0.0*multiplier, -10.0*multiplier);

  glEnd();
}

void renderScene(void) {
  int i,j;
  if (deltaMove){
    computePos(deltaMove);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         // Clear Color and Depth Buffers
  glLoadIdentity();                         // Reset transformations
  gluLookAt(  x   , 1.0f, z,
        x+lx, 01.0f, z+lz, 
        0.0f, 01.0f, 0.0f);   // Set the camera

    
    drawOuterBoundary();  

    // glPushMatrix();
   //    obj.Draw();
   //   glPopMatrix();

    glutSwapBuffers();
} 
