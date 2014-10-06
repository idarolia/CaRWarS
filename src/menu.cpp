#include "global.h"

//inGame = false

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
	glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, mainMenu);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  glVertex2f(100, 100);
        glTexCoord2f(0, 1);  glVertex2f(100, 200);
        glTexCoord2f(1, 1);  glVertex2f(200, 200);
        glTexCoord2f(1, 0);  glVertex2f(200, 100);
    glEnd();
	orthoReset();
}

void renderPauseMenu(void){
	orthoSet();
	glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, pauseMenu);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  glVertex2f(100, 100);
        glTexCoord2f(0, 1);  glVertex2f(100, 200);
        glTexCoord2f(1, 1);  glVertex2f(200, 200);
        glTexCoord2f(1, 0);  glVertex2f(200, 100);
    glEnd();
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