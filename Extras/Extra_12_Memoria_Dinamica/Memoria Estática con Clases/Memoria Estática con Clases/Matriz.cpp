#include"Matriz.h"


Matriz::Matriz(int** m_1,int**m_2,int** m_r,int dm) {
	this->m1 = m_1;
	this->m2 = m_2;
	this->mr = m_r;
	this->dim = dm;
}
void Matriz::setDim(int dm) {
	dim = dm;
}
void Matriz::setM1(int** m_1) {
	**m1 = **m_1;
}
void Matriz::setM2(int** m_2) {
	**m2 = **m_2;
}
void Matriz::setMr(int** m_r) {
	**mr = **m_r;
}
int** Matriz::getM1() {
	return m1;
}
int** Matriz::getM2() {
	return m1;
}
int** Matriz::getMr() {
	return m1;
}
int Matriz::getDim() {
	return dim;
}
