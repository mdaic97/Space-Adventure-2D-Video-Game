class astronaut {

public:

	double x, y; // astronaut position (pixels)
	double q; // astronaut angle (rad)
	double v; // astronaut forward velocity (input #1)
	double w; // astronaut angular velocity (input #2)
	int id; // id number of sprite used to draw the astronaut
	double scale; // size of the sprite 
	double R;	//enemy radius

	astronaut(double x, double y, double q, char *file_name);

	void draw(); // draws the astronaut using the 2D graphics library

	void sim_step(double dt);
};