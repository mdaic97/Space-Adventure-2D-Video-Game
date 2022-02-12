class spaceship {

public:

	double x, y; // spaceship position (pixels)
	double q; // spaceship angle (rad)
	double v; // spaceship forward velocity (input #1)
	double w; // spaceship angular velocity (input #2)
	int id; // id number of sprite used to draw the spaceship
	double scale; // size of the sprite
	double R; // spaceship radius

	spaceship(double x, double y, double q, char *file_name);

	void draw(); // draws the spaceship using the 2D graphics library

	void sim_step(double dt);
};