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






// space member function definitions ////////////////
using namespace std;

space::space(int N, int NA, double V, double W, 
				char *spaceship_file, 
				char *astronaut1_file, char *astronaut2_file,  
				char *asteroid_file,
				char *candy_file)
{
	int i;
	double x, y, q;
	long int s1 = -7; // seed value for random function
	double width = 800, height = 600;

	this->N = N;
	this->NA = NA;
	this->V = V;
	this->W = W;

	x = ran(s1); // returns a value between 0 and 1
	x *= width; // x1 is between 0 and width
	y = ran(s1); // returns a value between 0 and 1
	y *= height; // y1 is between 0 and height
	q = ran(s1); // returns a value between 0 and 1
	q *= (2*3.14159); // q1 is between 0 and 2*PI
	
	SS = new spaceship(x,y,q, spaceship_file);
		
		// set inputs
		SS->v = V;
		SS->w = W;
		
	EN1 = new astronaut(x,y,q, astronaut1_file);
	
		// set inputs
		EN1->v = V;
		EN1->w = W;

	EN2 = new astronaut(x, y, q, astronaut2_file);

		// set inputs
		EN2->v = V;
		EN2->w = W;
	
	for(i=0;i<NA;i++) {

		x = ran2(s1); // returns a value between 0 and 1
		x *= width; // x1 is between 0 and width
		y = ran(s1); // returns a value between 0 and 1
		y *= height; // y1 is between 0 and height
		q = ran2(s1); // returns a value between 0 and 1
		q *= (2 * 3.14159); // q1 is between 0 and 2*PI

		AST[i] = new asteroids(x, y, q, asteroid_file);
				
		// set inputs
		AST[i]->v = V;
		AST[i]->w = W;

	}
	
		for(i=0;i<N;i++) {

		x = ran3(s1); // returns a value between 0 and 1
		x *= width; // x1 is between 0 and width
		y = ran(s1); // returns a value between 0 and 1
		y *= height; // y1 is between 0 and height
		q = ran3(s1); // returns a value between 0 and 1
		q *= (2 * 3.14159); // q1 is between 0 and 2*PI

		CN[i] = new candy(x, y, q, candy_file);
				
		// set inputs
		CN[i]->v = V;
		CN[i]->w = W;

	}

}


space::~space()
{
	
	int i;
	
		// safe delete
		if( SS == NULL ) {
			cout << "\nerror in ~space";
			return;
		} else {
			delete SS;
		}
	

	
		// safe delete
		if (EN1 == NULL) {
			cout << "\nerror in ~space";
			return;
		}
		else {
			delete EN1;
		}

		// safe delete
		if (EN2 == NULL) {
			cout << "\nerror in ~space";
			return;
		}
		else {
			delete EN2;
		}
	
	
	for (i = 0; i < NA; i++) {
		// safe delete
		if (AST[i] == NULL) {
			cout << "\nerror in ~space";
			return;
		}
		else {
			delete AST[i];
		}
	}
	
	for (i = 0; i < N; i++) {
		// safe delete
		if (CN[i] == NULL) {
			cout << "\nerror in ~space";
			return;
		}
		else {
			delete CN[i];
		}
	}
}


void space::draw()
{
	int i;
	double x, y, q;
	long int s1 = -7; // seed value for random function
	double width = 800, height = 600;

	x = ran(s1); // returns a value between 0 and 1
	x *= width; // x1 is between 0 and width
	y = ran(s1); // returns a value between 0 and 1
	y *= height; // y1 is between 0 and height
	q = ran(s1); // returns a value between 0 and 1
	q *= (2 * 3.14159); // q1 is between 0 and 2*PI

	SS->draw(); // draw spaceship
	EN1->draw(); // draw enemy1
	EN2->draw(); // draw enemy2
	
	// draw each asteroid
	for (i = 0; i < NA; i++) {

		
		x = ran2(s1); // returns a value between 0 and 1
		x *= width; // x1 is between 0 and width
		y = ran(s1); // returns a value between 0 and 1
		y *= height; // y1 is between 0 and height
		q = ran2(s1); // returns a value between 0 and 1
		q *= (2 * 3.14159); // q1 is between 0 and 2*PI

		AST[i]->draw();
	
	}
	
	// draw each candy
	for (i = 0; i < N; i++) {

		
		x = ran3(s1); // returns a value between 0 and 1
		x *= width; // x1 is between 0 and width
		y = ran(s1); // returns a value between 0 and 1
		y *= height; // y1 is between 0 and height
		q = ran3(s1); // returns a value between 0 and 1
		q *= (2 * 3.14159); // q1 is between 0 and 2*PI

		CN[i]->draw();
	
	}

}

void space::sim_step(double dt)
{
	int i;
	double width = 800, height = 600;	

	// simulate each spaceship
	
	SS->sim_step(dt);

		if( SS->x < 0.0 ) 		SS->q += 3.14159;
		if( SS->x > width ) 	SS->q += 3.14159;
		if( SS->y < 0.0 ) 		SS->q += 3.14159;
		if( SS->y > height ) 	SS->q += 3.14159;
	
	EN1->sim_step(dt);
	
		if( EN1->x < 0.0-75 ) 		EN1->q += 3.14159;
		if( EN1->x > width+75 ) 	EN1->q += 3.14159;
		if( EN1->y < 0.0-75 ) 		EN1->q += 3.14159;
		if( EN1->y > height+75 ) 	EN1->q += 3.14159;

	EN2->sim_step(dt);

		if (EN2->x < 0.0-50) 		EN2->q += 3.14159;
		if (EN2->x > width+50) 	EN2->q += 3.14159;
		if (EN2->y < 0.0-50) 		EN2->q += 3.14159;
		if (EN2->y > height+50) 	EN2->q += 3.14159;

	// simulate each asteroid
	for (i = 0; i < NA; i++) {
		AST[i]->sim_step(dt);
	}

	// check for collisions and calculate collision response
	for (i = 0; i < NA; i++) {
		if (AST[i]->x < 0.0 - 200) AST[i]->q += 3.14159;
		if (AST[i]->x > width + 200) AST[i]->q += 3.14159;
		if (AST[i]->y < 0.0 - 200) AST[i]->q += 3.14159;
		if (AST[i]->y > height + 200) AST[i]->q += 3.14159;
	}
	
	// simulate each asteroid
	for (i = 0; i < N; i++) {
		CN[i]->sim_step(dt);
	}
	// check for collisions and calculate collision response
	for (i = 0; i < N; i++) {
		if (CN[i]->x < 0.0) CN[i]->q += 3.14159;
		if (CN[i]->x > width) CN[i]->q += 3.14159;
		if (CN[i]->y < 0.0) CN[i]->q += 3.14159;
		if (CN[i]->y > height) CN[i]->q += 3.14159;
	}

}
void space::input()
// sets spaceship inputs to identical values using the arrow keys
{
	int i;
	double V_input, W_input;
	double V_enemy1, W_enemy1;
	double V_enemy2, W_enemy2;
	double V_asteroid, W_asteroid;
	double V_candy, W_candy;

	// set default values for dV and dV, otherwise 
	// they will be uninitialized when there is no keyboard input.
	// this is similar to the default else in an if-else ladder
	V_input = 0.0;
	W_input = 0.0;

	if( KEY('W')) V_input = -250;
	if( KEY('A')) W_input = 2.5;
	if( KEY('D')) W_input = -2.5;


	// increment input for each spaceship
	SS->v = V_input;
	SS->w = W_input;
	
	V_enemy1 = 250;
	W_enemy1 = 1;

		EN1->v = V_enemy1;
		EN1->w = W_enemy1;

	V_enemy2 = 350;
	W_enemy2 = -1;

		EN2->v = V_enemy2;
		EN2->w = W_enemy2;

	V_asteroid = 150;
	W_asteroid = 0.0;

	// increment input for each spaceship
	for (i = 0; i < NA; i++) {

		AST[i]->v = V_asteroid;
		AST[i]->w = W_asteroid;
	}
	
	V_candy = 0.0;
	W_candy = 1.0;	

	// increment input for each spaceship
	for (i = 0; i < N; i++) {

		CN[i]->v = V_candy;
		CN[i]->w = W_candy;
	}

}

int space::collision()
{
	int i;
	double x1, y1, R1, x2, y2, R2, d12;
	int ia[N_MAX] = { 0 }, N_orig;
	static int count = 3;

	N_orig = NA;


	for (i = 0; i < NA; i++) {
		x1 = AST[i]->x;
		y1 = AST[i]->y;
		R1 = AST[i]->R;

		x2 = SS->x;
		y2 = SS->y;
		R2 = SS->R;

		d12 = sqrt((x2 - x1) * (x2 - x1) +
			(y2 - y1) * (y2 - y1));

		// check for a collision
		if (d12 <= (R1 + R2)) {
		
		
		count--;
		cout << "\ncollision_detected.\n";
		
		//text("OUCH! watch out for the asteroids.", 150, 300, 0.5);
		
		ia[i] = 1;
		
		}

	} // end for i
		text("Lives", 700, 575, 0.5);
		text(count, 700, 550, 0.5);
		
	for (i = N_orig - 1; i >= 0; i--) {
		if (ia[i] == 1) {
			remove_asteroid(i);
			NA--;
			Music crash("collision_sound.wav");
			crash.play();

		}
	}
	
	for (i = N_orig - 1; i >= 0; i--) {
		if (count <= 0) {
			return 1;
		}
	}

}

int space::collection()
{
	int i;
	double x1, y1, R1, x2, y2, R2, d12;
	int ic[N_MAX] = { 0 }, N_orig;
	static int count = 0;
	int max_count = 10;

	N_orig = N;


	for (i = 0; i < N; i++) {
		x1 = CN[i]->x;
		y1 = CN[i]->y;
		R1 = CN[i]->R;

		x2 = SS->x;
		y2 = SS->y;
		R2 = SS->R;

		d12 = sqrt((x2 - x1) * (x2 - x1) +
			(y2 - y1) * (y2 - y1));

		// check for a collision
		if (d12 <= (R1 + R2)) {
		
		count++;
		cout << "\ncollection_detected.\n" << count;
		
		//text("GREAT WORK... keep collecting", 150, 300, 0.5);
		
		ic[i] = 1;
		
		}

	} // end for i
	
	
		text("Collected", 25, 575, 0.5);
		text(count, 25, 550, 0.5);
		
		
	for (i = N_orig - 1; i >= 0; i--) {
		if (ic[i] == 1) {
			remove_candy(i);
			N--;
			Music coins("candy_sound.wav");
			coins.play();
		}
	}
	
		for (i = 0; i <= N_MAX; i++) {
		if (count >= max_count) {
			return 1;
		}
	}
}
	
	
void space::remove_candy (int i)
{

	if( CN[i] == NULL ) {
		cout << "\nerror in ~World";
		return;
	} else {
		delete CN[i];
	}
		CN[i] = CN[N-1];

} //remove

void space::remove_asteroid (int i)
{

	if( AST[i] == NULL ) {
		cout << "\nerror in ~World";
		return;
	} else {
		delete AST[i];
	}
		AST[i] = AST[NA-1];

} //remove
