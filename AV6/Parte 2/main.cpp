#include <typeinfo>
#include <cstdlib> // system()
#include <iostream>
using namespace std;

#include "matrix.h"

void clearscreen() {
if (system( "clear" )) system( "cls" );
}

int main(){
    
    std::cout << "\n ---------------Testando construtores -------------- \n" << endl;
    Matrix<int> m1;
    std::cout << "Matrix<int> m1" << endl;
    std::cout << "-> Matriz de dimensao " << m1.getRows() << " x " << m1.getCols() << endl;
    std::cout << "m1 = " << endl << m1 << endl;

    Matrix<float> m2(5, 5, 7.5);
    std::cout << "Matrix<float> m2(5, 5, 7.5)" << endl;
    std::cout << "-> Matriz de dimensao " << m2.getRows() << " x " << m2.getCols() << endl;
    std::cout << "m2 = " << endl << m2 << endl;

    std::cout << "\nPressione Enter para continuar...";
    getchar();
    clearscreen();
    
    Matrix<float> m3(m2);
    std::cout << "Matrix<float> m3(m2)" << endl;
    std::cout << "-> Matriz de dimensao " << m3.getRows() << " x " << m3.getCols() << endl;
    std::cout << "m3 = " << endl << m3 << endl;

    
    Matrix<double> m4(2, 3, 6);
    std::cout << "Matrix<double> m4(2, 3)" << endl;
    std::cout << "-> Matriz de dimensao " << m4.getRows() << " x " << m4.getCols() << endl;
    std::cout << "m4 = " << endl << m4 << endl;
    
    std::cout << "\nPressione Enter para continuar...";
    getchar();
    clearscreen();
    
    std::cout << "\n ---------------Testando Inicializacoes -------------- \n" << endl;
    
    Matrix<float> m6(3, 4, 2.3);
    std::cout << "Matrix<float> m6(3, 4, 2.3)" << endl;
    std::cout << "-> Matriz de dimensao " << m6.getRows() << " x " << m6.getCols() << endl;
    std::cout << "m6 = " << endl << m6;
    m6.zeros();
    std::cout << "m6.zeros() :: Matriz Zeros" << endl;
    std::cout << "m6 = " << endl << m6 << endl;
   
    std::cout << "\nPressione Enter para continuar...";
    getchar();
    clearscreen();
    
    std::cout << "\n --------------- Testando Sobrecarga de Operadores-------------------------- \n" << endl;
    try{ m6(1, 1) = 7; } catch(const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6(1, 3) = -3; } catch(const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6(2, 1) = 3.6; } catch(const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6(2, 2) = -2; } catch(const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6(4, 1) = 4; } catch(const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    std::cout << "-> Sobrecarga do Operador ( )" << endl;
    std::cout << "m6(1, 1) = 7; m6(1, 3) = -3; m6(2, 1) = 3.6; m6(2, 2) = -2; m6(3, 1) = 4;" << endl;
    std::cout << "m6 = " << endl << m6 << endl;

    

    
}

/*int main()
{
    std::ifstream in("myMatrix.txt");
    Matrix<int> Y;
    Matrix<int> X(3,1,0), A(3,3,0), C(3,3,0);
    Matrix<int> Z(3,2,7.0);
    Matrix<int> W(in);
    
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
}*/