#include <iostream>
#include <cstdio>
#include <cmath>

#include <Windows.h>
#include "2D_graphics.h"

#include "timer.h"
#include "ran.h"
#include "astronaut.h"

using namespace std;



astronaut::astronaut(double x, double y, double q, char *file_name)
{
	this->x = x;
	this->y = y;
	this->q = q;


	v = 0;
	w = 0;
	scale = 0.05;
	R = 25;


	create_sprite(file_name,id);

}

void astronaut::draw()

{
	draw_sprite(id,x,y,q-3.14159/2,scale);
}

void astronaut::sim_step(double dt)
{
	// one Euler simulation step
	x = x + v*cos(q)*dt;
	y = y + v*sin(q)*dt;
	q = q + w*dt;
}