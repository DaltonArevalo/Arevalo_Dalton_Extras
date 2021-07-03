#include"Operaciones.h"
#include <malloc.h>
#include<stdio.h>

Operaciones::Operaciones() {
 
}

Operaciones::Operaciones(int** m_1, int** m_2, int** m_r) {
    this->m.setM1(m_1);
    this->m.setM2(m_2);
    this->m.setMr(m_r);
}
int** Operaciones::segmentar() {
    int** matriz, j;
    matriz = (int**)malloc(this->m.getDim() * sizeof(int*));
    for (j = 0; j < this->m.getDim(); j++) {
        *(matriz + j) = (int*)malloc(this->m.getDim() * sizeof(int));
    }
    return matriz;
}

void Operaciones::encerar() {
    int i, j,**matriz;
    for (i = 0; i < this->m.getDim(); i++)
        for (j = 0; j < this->m.getDim(); j++)
            *(*(matriz + i) + j) = 0;
    this->m.setM1(matriz);
    this->m.setM2(matriz);
    this->m.setMr(matriz);
}

void Operaciones::ingresar(int **matriz) {
    int i, j;
    for (i = 0; i < this->m.getDim(); i++)
        for (j = 0; j < this->m.getDim(); j++)
            scanf_s("%d", &(*(*(matriz + i) + j)));
}

void Operaciones::calcular() {
    int i, j, k;
    for (i = 0; i < this->m.getDim(); i++)
        for (j = 0; j < this->m.getDim(); j++)
            for (k = 0; k < this->m.getDim(); k++)
                *(*(this->m.getMr() + i) + j) = *(*(this->m.getMr() + i) + j) + *(*(this->m.getM1() + i) + k) * *(*(this->m.getM2() + k) + j);
}

void Operaciones::imprimir(int **matriz) {
    int i, j;
    for (i = 0; i < this->m.getDim(); i++) {
        for (j = 0; j < this->m.getDim(); j++) {
            printf("%d", *(*(matriz + i) + j));
            printf("%s", j + 5, " ");
        }
        printf_s("/n");
    }
}