#include <iostream>
#include <cstdio>
#include <cmath>

#include <Windows.h>
#include "2D_graphics.h"

#include "timer.h"
#include "ran.h"
#include "background.h"

using namespace std;

background::background(double x, double y, double q, char *file_name)
{
	this->x = x;
	this->y = y;
	this->q = q;

	scale = -1;

	create_sprite(file_name,id);

}

void background::draw()
{
	draw_sprite(id,x,y,q+3.14159/2,scale);
}