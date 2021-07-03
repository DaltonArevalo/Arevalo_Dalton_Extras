#pragma once
#include <iostream>

class Vector{
	private:
		int vec[10];
		
	public:
		Vector();
		Vector(int *);
		
		int *getVec();
		void setVec(int */*vec[10]*/);
};

