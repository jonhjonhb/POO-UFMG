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
    std::cout << "m1 = " << m1 << endl;

    Matrix<float> m2(5, 5, 7.5);
    std::cout << "Matrix<float> m2(5, 5, 7.5)" << endl;
    std::cout << "-> Matriz de dimensao " << m2.getRows() << " x " << m2.getCols() << endl;
    std::cout << "m2 = " << m2 << endl;

    std::cout << "\nPressione qualquer tecla para continuar...";
    getchar();
    clearscreen();
    
    Matrix<float> m3(m2);
    std::cout << "Matrix<float> m3(m2)" << endl;
    std::cout << "-> Matriz de dimensao " << m3.getRows() << " x " << m3.getCols() << endl;
    std::cout << "m3 = " << m3 << endl;

    
    Matrix<double> m4(2, 3, 6);
    std::cout << "Matrix<double> m4(2, 3)" << endl;
    std::cout << "-> Matriz de dimensao " << m4.getRows() << " x " << m4.getCols() << endl;
    std::cout << "m4 = " << m4 << endl;
    
    std::cout << "\nPressione qualquer tecla para continuar...";
    getchar();
    clearscreen();
    
    std::cout << "\n ---------------Testando Inicializacoes -------------- \n" << endl;
    
    Matrix<float> m6(3, 4, 2.3);
    std::cout << "Matrix<float> m6(3, 4, 2.3)" << endl;
    std::cout << "-> Matriz de dimensao " << m6.getRows() << " x " << m6.getCols() << endl;
    std::cout << "m6 = " << m6;
    m6.zeros();
    std::cout << "m6.zeros() :: Matriz Zeros" << endl;
    std::cout << "m6 = " << m6 << endl;
   
    std::cout << "\nPressione qualquer tecla para continuar...";
    getchar();
    clearscreen();
    
    std::cout << "\n --------------- Testando Sobrecarga de Operadores-------------------------- \n" << endl;
    try{ m6(1, 1) = 7; } catch(std::invalid_argument ex) { std::cout << ex.what() << std::endl; }
    try{ m6(1, 3) = -3; } catch(std::invalid_argument ex) { std::cout << ex.what() << std::endl; }
    try{ m6(2, 1) = 3.6; } catch(std::invalid_argument ex) { std::cout << ex.what() << std::endl; }
    try{ m6(2, 2) = -2; } catch(std::invalid_argument ex) { std::cout << ex.what() << std::endl; }
    try{ m6(3, 1) = 4; } catch(std::invalid_argument ex) { std::cout << ex.what() << std::endl; }
    std::cout << "-> Sobrecarga do Operador ( )" << endl;
    std::cout << "m6(1, 1) = 7; m6(1, 3) = -3; m6(2, 1) = 3.6; m6(2, 2) = -2; m6(3, 1) = 4;" << endl;
    std::cout << "m6 = " << m6 << endl;

    
}