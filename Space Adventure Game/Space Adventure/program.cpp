
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

#include <Windows.h>
#include "2D_graphics.h"

#include "timer.h"
#include "ran.h"

#include "spaceship.h"
#include "asteroids.h"
#include "astronaut.h"
#include "candy.h"
#include "space.h"
#include "background.h"

#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")
#include "Music.h"
#define KEY(c) ( GetAsyncKeyState((int)(c)) & (SHORT)0x8000 )


using namespace std;


int main()
{
	int N = 10;
	int NA = 12;


	double V = 0.0;
	double W = 0.0;
	double dt = 1.0/60;

	// make sure initialize graphics goes before any code
	// that uses the graphics library
	initialize_graphics();

	
	background BG0(N, V, W, "background01.png");
	//Music BGM("starting02.wav");
	
	space GAME (N,NA,V,W,
				"spaceship01.png",
				"astronaut01.png","astronaut02.png",
				"asteroid01.png",
				"candy01.png");

	background BG_win(N, V, W, "win01.png");
	background BG_lose(N, V, W, "lose01.jpg");
				
	
	//background music
	//BGM.play();
	
	// graphics drawing / animation loop
	while(1) { 
		
		clear(); // clear the previous drawing
		
		//background
		BG0.draw();
		
		//space
		GAME.input(); 
		GAME.collision();
		GAME.collection();
		GAME.sim_step(dt);
		GAME.draw();
		
		update(); // update the drawing
		
		if (GAME.collision()==1) 
		{
			Music defeat("defeat01.wav");
			defeat.play();
			
			while (1){
				clear();
				BG_lose.draw();
				text("GAME OVER", 250, 350, 1.0);
				
				update();
			}
		}
		
		if (GAME.collection()==1) 
		{
			Music victory("victory01.wav");
			victory.play();
			
			while (1){
				clear();
				BG_win.draw();
				text("YOU WIN", 250, 350, 1.0);
				
				update();
			}
		}
		
	}	

	getchar();
	return 0;
}


