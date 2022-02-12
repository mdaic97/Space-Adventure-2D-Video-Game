#include <iostream>
#include <cstdio>
#include <cmath>

#include <Windows.h>
#include "2D_graphics.h"

#include "timer.h"
#include "ran.h"
#include "asteroids.h"

using namespace std;



asteroids::asteroids(double x, double y, double q, char *file_name)
{
	this->x = x;
	this->y = y;
	this->q = q;

	v = 0;
	w = 0;
	scale = 0.075;
	R = 25;

	create_sprite(file_name,id);

}

void asteroids::draw()

{
	draw_sprite(id,x,y,q+3.14159,scale);
}

void asteroids::sim_step(double dt)
{
	// one Euler simulation step
	x = x + v*cos(q)*dt;
	y = y + v*cos(q)*dt;
	q = q + w*dt;
}