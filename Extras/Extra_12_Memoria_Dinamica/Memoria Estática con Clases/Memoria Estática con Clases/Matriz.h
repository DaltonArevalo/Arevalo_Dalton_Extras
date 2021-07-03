#pragma once
class Matriz {
	private:
		int** m1, ** m2, ** mr;
		int dim;
	public:
		Matriz() = default;
		Matriz(int**, int**,int**,int);
		void setDim(int);
		int getDim();
		void setM1(int**);
		int** getM1();
		void setM2(int**);
		int** getM2();
		void setMr(int**);
		int** getMr();



};
