#include <iostream>
#include "matrix.h"

int main()
{
    std::ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3,1), A(3,3), C(3,3);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    
    // operadores a serem implementados em sua classe:
    
    A(2,1) = 10;                                		// altera o valor de uma posição de A
	std::cout << "A:" << std::endl; A.print();
    C = A + A;                                  		// Soma
	std::cout << "C:" << std::endl; C.print();
    C -= A;                                     		// Subtração  
	std::cout << "C:" << std::endl; C.print();     
    A = C - A;                                  		// Subtração
	std::cout << "A:" << std::endl; A.print();
    A += A;                                     		// Soma
	std::cout << "A:" << std::endl; A.print();
    A = ~C;                                     		// A é igual a transposta de C
	std::cout << "A:" << std::endl; A.print();
    X *= 2;                                     		// multiplicação por uma constante
	std::cout << "X:" << std::endl; X.print();
    C = A*X;                                    		// multiplicação de matrizes
	std::cout << "C:" << std::endl; C.print();
    C *= X;                                     		// multiplicação de matrizes
	std::cout << "C:" << std::endl; C.print();
    if(A == C)std::cout << "Igual" << std::endl;		// verifica a igualdade entre A e C
		else std::cout << "Diferente" << std::endl;
    if(X != Y)std::cout << "Diferente" << std::endl; 	// verifica a desigualdade entre X e Y
		else std::cout << "Igual" << std::endl;
    std::cout << Z << std::endl;                        // impressão de matrizes
    std::cin >> Y;     									// leitura de dados para dentro da matriz Y 
	std::cout << "Y:" << std::endl; Y.print();

    return 0;
}