#ifndef _Point_hh
#define _Point_hh

#include "Include.hh"

class Point {
	
	// private field
	int x;
	int y;
	
	// public field
	public:
		Point(int = 0, int = 0);
		~Point();
		
		int getX();
		int getY();
};

#endif
