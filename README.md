CaRWarS
=======
How to run the game in lunux:

change directory to /src

1) g++ main.cpp  game.cpp  objLoader.cpp  world.cpp  keyboard.cpp  sound.cpp menu.cpp ortho.cpp hud.cpp -o run -lm  -lGL -lGLU -lglut -lSDL -lSDL_mixer -lSDL_image

2) ./run
