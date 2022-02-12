const int N_MAX = 100;

class space {

public:

	int N, NA;
	double V, W;
	
	spaceship *SS;
	astronaut *EN1, *EN2;
	asteroids *AST[N_MAX];
	candy *CN[N_MAX];

	space(int N, int NA, double V, double W,
		char* spaceship_file,
		char* enemy1_file, char* enemy2_file,
		char* asteroid_file,
		char* candy_file);

	~space();

	void draw();
	
	void sim_step(double dt);
	
	void input(); 

	int collision();

	int collection();
	
	void remove_candy (int i);
	
	void remove_asteroid (int i);
	
};