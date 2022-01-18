#include <typeinfo>
#include <cstdlib> // system()
#include <iostream>
#include <locale>
using namespace std;

#include "matrix.h"

void clearscreen() {
if (system( "clear" )) system( "cls" );
}

int main(){
    
    std::ifstream in("myMatrix.txt");

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
    try{ m6.zeros(); } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    std::cout << "m6.zeros() :: Matriz Zeros" << endl;
    std::cout << "m6 = " << endl << m6 << endl;
   
    std::cout << "\nPressione Enter para continuar...";
    getchar();
    clearscreen();
    
    std::cout << "-> Metodo matriz identidade em m2<float>" << endl;
    std::cout << "-> Matriz de dimensao " << m2.getRows() << " x " << m2.getCols() << endl;
    std::cout << "m2 = " << endl << m2 << endl;
    try{ m2.unit(); } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    std::cout << "m2.unit() :: Matriz Identidade" << endl;
    std::cout << "m2 = " << endl << m2 << endl;

    std::cout << "-> Metodo m6.get(row, col)" << endl;
    std::cout << "m6.get(1, 1); m6.get(1, 3); m6.get(2, 1); m6.get(2, 2); m6.get(4, 1);" << endl;
    try{ m6.get(1, 1); } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6.get(1, 3); } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6.get(2, 1); } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6.get(2, 2); } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6.get(4, 1); } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    
    std::cout << "\nPressione Enter para continuar...";
    getchar();
    clearscreen();
    
    std::cout << "\n --------------- Testando Sobrecarga de Operadores-------------------------- \n" << endl;
    std::cout << "-> Sobrecarga do Operador ( )" << endl;
    std::cout << "m6(1, 1) = 7; m6(1, 3) = -3; m6(2, 1) = 3.6; m6(2, 2) = -2; m6(4, 1) = 4;" << endl;
    try{ m6(1, 1) = 7; } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6(1, 3) = -3; } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6(2, 1) = 3.6; } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6(2, 2) = -2; } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    try{ m6(4, 1) = 4; } catch (const std::invalid_argument &ex) { std::cout << ex.what() << std::endl; }
    std::cout << "m6 = " << endl << m6 << endl;

    std::cout << "\nPressione Enter para continuar...";
    getchar();
    clearscreen();

    bool noExceptionCaught = true;
    Matrix<float> m7(5, 5, 1.0); m7=m2;
    std::cout << "-> Sobrecarga dos Operadores + e =" << endl;
    std::cout << "Matrix<float> m7 = m2:" << endl << m7 << endl;
    std::cout << "m7 = m2+m3:" << endl;
    try { m7 = m2+m3; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m7 << endl; noExceptionCaught = true;
    std::cout << endl << "m7 = m2+m6:" << endl;
    try { m7 = m2+m6; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m7 << endl; noExceptionCaught = true;
    std::cout << endl << "m7 = m6:" << endl;
    try { m7 = m6; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m7 << endl; noExceptionCaught = true;

    std::cout << "\nPressione Enter para continuar...";
    getchar();
    clearscreen();

    std::cout << "-> Sobrecarga dos Operadores += e -=" << endl;
    std::cout << "Matrix<float> m7 += m7:" << endl;
    try { m7 += m7; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m7 << endl; noExceptionCaught = true;
    std::cout << endl << "m7 += m6:" << endl;
    try { m7 += m6; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout <<  m7 << endl; noExceptionCaught = true;
    std::cout << endl << "m7 -= m6:" << endl;
    try { m7 -= m6; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m7 << endl; noExceptionCaught = true;
    std::cout << endl << "m7 -= m7:" << endl;
    try { m7 -= m7; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m7 << endl; noExceptionCaught = true;

    std::cout << "\nPressione Enter para continuar...";
    getchar();
    clearscreen();

    Matrix<float> m8(5, 2, 1.0);
    std::cout << "-> Sobrecarga dos Operadores *, *= e *= por constante" << endl;
    std::cout << "Matrix<float> m8:" << endl << m8 << endl;
    std::cout << "Matrix<float> m7 = m2*m3:" << endl;
    try { m7 = m2*m3; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m7 << endl; noExceptionCaught = true;
    std::cout << endl << "m7 *= m8:" << endl;
    try { m7 *= m8; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m7 << endl; noExceptionCaught = true;
    std::cout << endl << "m7 *= 2:" << endl;
    try { m7 *= 2; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m7 << endl; noExceptionCaught = true;

    std::cout << "\nPressione Enter para continuar...";
    getchar();
    clearscreen();
    
    std::cout << "\n --------------- Testando Tipos Diferentes de Matrizes-------------------------- \n" << endl;
    Matrix<std::string> m9(5, 1, "Elem."); m9(1,1) = "Elem.1"; m9(2,1) = "Elem.2"; m9(3,1) = "Elem.3"; m9(4,1) = "Elem.4"; m9(5,1) = "Elem.5";
    std::cout << "Matrix<string> m9:" << endl << m9 << endl;
    std::cout << endl << "m10 = ~m9 :: Matriz Transposta" << endl;
     Matrix<std::string> m10(1, 5, "0");
    try{ m10 = ~m9; } catch (const std::invalid_argument &ex) { noExceptionCaught = false; std::cout << ex.what() << std::endl; }
    if(noExceptionCaught) std::cout << m10 << endl; noExceptionCaught = true;
}