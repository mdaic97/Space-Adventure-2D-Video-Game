
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

#include <Windows.h>
#include <MMSystem.h>

#include "2D_graphics.h"

#include "timer.h"
#include "ran.h"

#pragma comment(lib, "winmm.lib")
#define KEY(c) ( GetAsyncKeyState((int)(c)) & (SHORT)0x8000 )
#include "Music.h"

using namespace std;

Music::Music(char *file_name)
{
	ifstream fin;
	
	fin.open(file_name, ios::binary);
	
	if (!fin){
		cout << "\nFile Opening Error!";
		exit(1);
	}
	
	fin.seekg(0, ios::end);
	
	n = fin.tellg();

	fin.seekg(0, ios::beg);

	p_buffer = new char[n];

	
	if (p_buffer == NULL){
		cout << "Error in dynamic memory allocation!";
		exit(1);
	}
	
	fin.read(p_buffer, n);
	
	fin.close();
	
}

void Music::play_loop()
{
	PlaySoundA(p_buffer, NULL, SND_MEMORY | SND_ASYNC | SND_LOOP);
	cout << "\nsound\n";

}	

void Music::play()
{
	PlaySoundA(p_buffer, NULL, SND_MEMORY | SND_ASYNC);
	cout << "\nsound\n";

}	
