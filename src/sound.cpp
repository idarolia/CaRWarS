#include "global.h"

Mix_Music *gMusic = NULL;

bool init(){
  //Initialization flag
  bool success = true;

  //Initialize SDL
  if( SDL_Init(SDL_INIT_VIDEO |SDL_INIT_AUDIO) < 0 ){
    printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    success = false;
  }
  if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    success = false;
  }
  return success;
}

bool loadMedia(){
  //Loading success flag
  bool success = true;
  gMusic = Mix_LoadMUS( "../data/sound/beat.wav" );
  if( gMusic == NULL ){
    printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
    success = false;
  }
  return success;
}

void close(){
  Mix_FreeMusic( gMusic );
  gMusic = NULL;
  Mix_Quit();
  SDL_Quit();
}

void initializeSound(){
  if( !init() ){
    printf( "Failed to initialize!\n" );
  }
  else{
    if( !loadMedia() ){
      printf( "Failed to load media!\n" );
    }
    else{ 
      Mix_PlayMusic( gMusic, -1 );
    }
  }
}