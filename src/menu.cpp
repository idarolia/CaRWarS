#include "global.h"

void menu(int n){
	int mName;
	if (n==1) mName = mainMenu;
	else if (n==2) mName = pauseMenu;
    else if (n==3) mName = soundOff;
    else if (n==4) mName = soundOn;
    if(n==1 || n==2){
        glBindTexture(GL_TEXTURE_2D, mName);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(350, 200);
            glTexCoord2f(0, 1);  glVertex2f(350, 300);
            glTexCoord2f(1, 1);  glVertex2f(450, 300);
            glTexCoord2f(1, 0);  glVertex2f(450, 200);
        glEnd();
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, mName);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(330, 200);
            glTexCoord2f(0, 1);  glVertex2f(330, 250);
            glTexCoord2f(1, 1);  glVertex2f(530, 250);
            glTexCoord2f(1, 0);  glVertex2f(530, 200);
        glEnd();
    }
}

void arrowMenu(){
	glBindTexture(GL_TEXTURE_2D, arrow);
    if(menuNum == 1)
    {
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(310, 205);
            glTexCoord2f(0, 1);  glVertex2f(310, 225);
            glTexCoord2f(1, 1);  glVertex2f(340, 225);
            glTexCoord2f(1, 0);  glVertex2f(340, 205);
        glEnd();
        orthoReset();
    }
    else if(menuNum == 2)
    {
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(310, 240);
            glTexCoord2f(0, 1);  glVertex2f(310, 260);
            glTexCoord2f(1, 1);  glVertex2f(340, 260);
            glTexCoord2f(1, 0);  glVertex2f(340, 240);
        glEnd();
        orthoReset();
    }
    else if(menuNum == 3)
    {
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(310, 275);
            glTexCoord2f(0, 1);  glVertex2f(310, 295);
            glTexCoord2f(1, 1);  glVertex2f(340, 295);
            glTexCoord2f(1, 0);  glVertex2f(340, 275);
        glEnd();
        orthoReset();
    }
}

void mainMenuCall(void){
	if(inGame == 0)
    {
    	if(menuNum == 1){
            inGame = 2;
            menuNum = 1;
    	}else if(menuNum == 2){
            inGame = 3;
            menuNum = 1;
    	}else if(menuNum == 3){
    		exit(0);
    	}
    }
    else if(inGame == 1)
    {
        if(menuNum == 1){
            inGame = 4;
            menuNum = 1;
        }else if(menuNum == 2){
            inGame = 3;
            menuNum = 1;
        }else if(menuNum == 3){
            exit(0);
        }
    }
    else if(inGame == 2)
    {
        if(menuNum == 1 || menuNum == 3)
        {
            inGame = 4;
            worldNum = 1;
        }
        else
        {
            inGame = 4;
            worldNum = 2;
        }
        pauseGame = true;
    }
    else if(inGame == 3)
    {
        if(menuNum == 1)
        {
            if( Mix_PausedMusic() == 1 )
                Mix_ResumeMusic();
            else
                Mix_PauseMusic();
        }
        else
        {
            if(!pauseGame)
                inGame = 0;
            else
                inGame = 1;
        }
    }
}

void renderTitle(void){
    orthoSet();
    glBindTexture(GL_TEXTURE_2D, title);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  glVertex2f(250, 50);
        glTexCoord2f(0, 1);  glVertex2f(250, 150);
        glTexCoord2f(1, 1);  glVertex2f(550, 150);
        glTexCoord2f(1, 0);  glVertex2f(550, 50);
    glEnd();    
    orthoReset();
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

void renderSettingsMenu(void){
    orthoSet();
    if( Mix_PausedMusic() == 1 )
                menu(3);
            else
                menu(4);
    if(menuNum == 1 || menuNum == 3)
    {
        glBindTexture(GL_TEXTURE_2D, arrow);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(290, 200);
            glTexCoord2f(0, 1);  glVertex2f(290, 220);
            glTexCoord2f(1, 1);  glVertex2f(320, 220);
            glTexCoord2f(1, 0);  glVertex2f(320, 200);
        glEnd();    
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, arrow);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(290, 230);
            glTexCoord2f(0, 1);  glVertex2f(290, 250);
            glTexCoord2f(1, 1);  glVertex2f(320, 250);
            glTexCoord2f(1, 0);  glVertex2f(320, 230);
        glEnd();    
    }
    orthoReset();
}

void renderWorldMenu(void){
    orthoSet();
    //glClear(GL_COLOR_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, world1Snap);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  glVertex2f(250, 200);
        glTexCoord2f(0, 1);  glVertex2f(250, 300);
        glTexCoord2f(1, 1);  glVertex2f(350, 300);
        glTexCoord2f(1, 0);  glVertex2f(350, 200);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, world2Snap);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  glVertex2f(450, 200);
        glTexCoord2f(0, 1);  glVertex2f(450, 300);
        glTexCoord2f(1, 1);  glVertex2f(550, 300);
        glTexCoord2f(1, 0);  glVertex2f(550, 200);
    glEnd();

    if(menuNum == 1 || menuNum == 3)
    {
        glBindTexture(GL_TEXTURE_2D, arrow);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(200, 240);
            glTexCoord2f(0, 1);  glVertex2f(200, 260);
            glTexCoord2f(1, 1);  glVertex2f(235, 260);
            glTexCoord2f(1, 0);  glVertex2f(235, 240);
        glEnd();    
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, arrow);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);  glVertex2f(600, 240);
            glTexCoord2f(0, 1);  glVertex2f(600, 260);
            glTexCoord2f(1, 1);  glVertex2f(565, 260);
            glTexCoord2f(1, 0);  glVertex2f(565, 240);
        glEnd();    
    }

    orthoReset();
}

void renderMenu(void){
    glClear(GL_COLOR_BUFFER_BIT);
    renderTitle();
	if (inGame == 0){
		renderGameMenu();
	}
	else if (inGame == 1){
		renderPauseMenu();
	}
    else if (inGame == 2){
        renderWorldMenu();
    }
    else if (inGame == 3){
        renderSettingsMenu();
    }
}