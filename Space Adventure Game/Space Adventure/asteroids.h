class asteroids {

public:

	double x, y; // asteroids position (pixels)
	double q; // asteroids angle (rad)
	double v; // asteroids forward velocity (input #1)
	double w; // asteroids angular velocity (input #2)
	int id; // id number of sprite used to draw the asteroids
	double scale; // size of the sprite
	double R; //asteroid radius

	asteroids(double x, double y, double q, char *file_name);

	void draw(); // draws the asteroids using the 2D graphics library

	void sim_step(double dt);
};