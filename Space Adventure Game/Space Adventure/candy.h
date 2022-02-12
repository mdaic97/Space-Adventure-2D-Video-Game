class candy {

public:

	double x, y; // candy position (pixels)
	double q; // candy angle (rad)
	double v; // candy forward velocity (input #1)
	double w; // candy angular velocity (input #2)
	int id; // id number of sprite used to draw the candy
	double scale; // size of the sprite
	double R; //candy radius

	candy(double x, double y, double q, char *file_name);

	void draw(); // draws the candy using the 2D graphics library
	
	void sim_step(double dt);

};