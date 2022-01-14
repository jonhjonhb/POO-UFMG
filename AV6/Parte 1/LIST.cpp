#include <iostream>
#include <cstdlib> // system()
#include "List.h"

void clearscreen() {
if (system( "clear" )) system( "cls" );
}

int main(int argc, char *argv[])
{
    // Cria Lista
    List<int> A;
    std::cout << "Criacao da Lista A:" << std::endl;
    std::cout << "-> Lista A: " << A << std::endl;
    
    //Insere elementos no Final da lista
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);
    A.push_back(6);
    A.push_back(1);
    A.push_back(2);
    std::cout << "A.push_back(3), A.push_back(4), A.push_back(5), A.push_back(6), A.push_back(6), A.push_back(1), A.push_back(2)" << std::endl;
    std::cout << "-> Lista A " << A << std::endl;
    
    //Insere elementos no Inicio da lista
    A.push_front(8);
    A.push_front(9);
    A.push_front(4);
    A.push_front(9);
    std::cout << "A.push_front(8), A.push_front(9), A.push_front(4), A.push_front(9)" << std::endl;
    std::cout << "-> Lista A " << A << std::endl;
    
    // remove os elementos de valor igual a 6 existentes na lista 
    try{ A.erase(6); } catch (const std::invalid_argument &erro) { std::cout << erro.what() << std::endl ; }
    std::cout << "A.erase(6)" << std::endl << "-> Lista A " << A << std::endl;
    
    // retorna o tamanho da lista
    int tam;
    tam = A.size();
    std::cout << "tam = A.size" << std::endl;
    std::cout << "-> tamanho da Lista A = " << tam << std::endl << std::endl;
     
    std::cout << "\nPressione qualquer tecla para continuar...";
    getchar();
    clearscreen();
    
}
