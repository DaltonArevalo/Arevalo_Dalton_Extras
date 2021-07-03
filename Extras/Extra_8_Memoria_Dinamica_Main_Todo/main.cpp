#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

//Memoria Dinamica

int **segmentar(int);
void encerar(int**, int);
void ingresar(int**, int);
void procesar(int**, int**, int**, int);
void imprimir(int**, int);

int **segmentar(int dim){
	int **matriz, i;
	matriz = (int**)malloc(dim*sizeof(int*)); //Definiendo un puntero simple y casting para puntero doble
	
	for(i=0 ; i<dim ; i++){
		*(matriz + i) = (int*)malloc(dim*sizeof(int)); //de matriz a arreglo unidimensional
	}
	
	return matriz;
} 

void encerar(int** matriz, int dim){
	int i,j;
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			*(*(matriz+i)+j) = 0;
		}
	}
}

void ingresar(int** matriz, int dim){
	int i,j;
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			scanf("%d",&(*(*(matriz+i)+j)));
		}
	}
}

void procesar(int** m1, int** m2, int** mr, int dim){
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			for(int k=0;k<dim;k++){
				(*(*(mr + i)+j)) = (*(*(mr + i)+j)) + ((*(*(m1 + i)+k)) + (*(*(m2 + k)+j)));
			}
		}
	}
}

void imprimir(int** matriz, int dim){
	int i,j;
	
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			printf("%d",(*(*(matriz+i)+j)));
			printf("%*s",j+5," ");	
		}
		printf("\n");
	}
}
int main(int argc, char** argv) {
	int dim;
	int** m1, ** m2, ** mr;
	std::cout<<"Ingrese la dimension de la matriz: ";
	std::cin>>dim;
	
	m1 = segmentar(dim);
	m2 = segmentar(dim);
	mr = segmentar(dim);
	
	encerar(m1, dim);
	encerar(m2, dim);
	encerar(mr, dim);
	
	ingresar(m1, dim);
	ingresar(m2, dim);
	
	imprimir(m1,dim);
	std::cout << std::endl;
	imprimir(m2,dim);
	std::cout << std::endl;
	
	procesar(m1, m2, mr, dim);
	std::cout << " Matriz Resultante" << std::endl;
	imprimir(mr,dim);
	return 0;
}
