#include <iostream>
#include "Ponto2D.h"

int main() {
	//Pontos
	Ponto2D p1(4, 5);
	Ponto2D p2(1, 1);
	Ponto2D p3 = p1.sumOf(p2);
	Ponto2D p4(-4, -5);
	p4.sum(p1);

	//Teste de sum
	std::cout << "Soma de p1 e p4:\n";
	p4.print();

	//Teste de print
	p1.print();
	p2.print();
	p3.print();

	//Teste de distToOrig
	std::cout << "p1 to origin: " << p1.distToOrig() << std::endl;
	std::cout << "p2 to origin: " << p2.distToOrig() << std::endl;
	std::cout << "p3 to origin: " << p3.distToOrig() << std::endl;

	//Teste de distTo
	std::cout << "p1 to p2: " << p1.distTo(p2) << std::endl;
	std::cout << "p2 to p3: " << p2.distTo(p3) << std::endl;
	std::cout << "p3 to p1: " << p3.distTo(p1) << std::endl;

	return 0;
} 