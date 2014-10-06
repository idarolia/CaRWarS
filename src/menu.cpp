#include "global.h"

//inGame = false

void menu(int n){
	int mName;
	if (n==1) mName = mainMenu;
	else if (n==2) mName = pauseMenu;
	glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, mName);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  glVertex2f(100, 100);
        glTexCoord2f(0, 1);  glVertex2f(100, 200);
        glTexCoord2f(1, 1);  glVertex2f(200, 200);
        glTexCoord2f(1, 0);  glVertex2f(200, 100);
    glEnd();
}

void arrowMenu(){
	glBindTexture(GL_TEXTURE_2D, arrow);
        if(menuNum == 1)
        {
            glBegin(GL_QUADS);
                glTexCoord2f(0, 0);  glVertex2f(50, 100);
                glTexCoord2f(0, 1);  glVertex2f(50, 125);
                glTexCoord2f(1, 1);  glVertex2f(100, 125);
                glTexCoord2f(1, 0);  glVertex2f(100, 100);
            glEnd();
            orthoReset();
        }
        else if(menuNum == 2)
        {
            glBegin(GL_QUADS);
                glTexCoord2f(0, 0);  glVertex2f(50, 125);
                glTexCoord2f(0, 1);  glVertex2f(50, 150);
                glTexCoord2f(1, 1);  glVertex2f(100, 150);
                glTexCoord2f(1, 0);  glVertex2f(100, 125);
            glEnd();
            orthoReset();
        }
        else if(menuNum == 3)
        {
            glBegin(GL_QUADS);
                glTexCoord2f(0, 0);  glVertex2f(50, 150);
                glTexCoord2f(0, 1);  glVertex2f(50, 175);
                glTexCoord2f(1, 1);  glVertex2f(100, 175);
                glTexCoord2f(1, 0);  glVertex2f(100, 150);
            glEnd();
            orthoReset();
        }
            else if(menuNum == 4)
        {
            glBegin(GL_QUADS);
                glTexCoord2f(0, 0);  glVertex2f(50, 175);
                glTexCoord2f(0, 1);  glVertex2f(50, 200);
                glTexCoord2f(1, 1);  glVertex2f(100, 200);
                glTexCoord2f(1, 0);  glVertex2f(100, 175);
            glEnd();
            orthoReset();
        }
}

void mainMenuCall(void){
	if(menuNum == 1){
		inGame = true;
	}else if(menuNum == 2){

	}else if(menuNum == 3){

	}else if(menuNum == 4){
		exit(0);
	}
}

void renderGameMenu(void){
	orthoSet();
	menu(1);
	arrowMenu();
	orthoReset();
}

void renderPauseMenu(void){
	orthoSet();
	menu(2);
    arrowMenu();
	orthoReset();	
}

void renderWorldMenu(void){

}

void renderSettingsMenu(void){

}

void renderMenu(void){
	if (!pauseGame){
		renderGameMenu();
	}
	else{
		renderPauseMenu();
	}
}