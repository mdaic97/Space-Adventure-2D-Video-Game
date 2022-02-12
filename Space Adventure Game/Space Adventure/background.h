class background {

public:

	double x, y, q; // background position (pixels)
	int id; // id number of sprite used to draw the background
	double scale; // size of the sprite

	background(double x, double y, double q, char *file_name);

	void draw(); // draws the background using the 2D graphics library
};

