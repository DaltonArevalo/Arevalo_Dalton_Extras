#include <iostream>

int factorial(int);

int factorial(int n){
	if(n<1){
		return 1;
	}else{
		return n*factorial(n-1);
	}
}

int main(int argc, char** argv) {
	std::cout << factorial(5) << std::endl;
	return 0;
}
