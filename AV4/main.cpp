#include "matrix.h"

int main()
{
    // Matrizes
    std::ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3,1);
    Matrix Z(3,2,7.0);
    Matrix W(in);
	  Matrix V(W);
    Matrix B = Z;
    
    // Print test
	  std::cout << "Matriz V:" << std::endl; V.print();
    std::cout << "Matriz W:" << std::endl; W.print();
    std::cout << "Matriz X:" << std::endl; X.print();
    std::cout << "Matriz Y:" << std::endl; Y.print(); 
    std::cout << "Matriz Z:" << std::endl; Z.print();
    std::cout << "Matriz B:" << std::endl; B.print();

    // Ponto especifico test
    std::cout << "Matriz V(2,1): " << V.get(2,1) << std::endl;
    std::cout << "Matriz W(2,1): " << W.get(2,1) << std::endl;
    std::cout << "Matriz X(1,0): " << X.get(1,0) << std::endl;
    std::cout << "Matriz Z(1,1): " << Z.get(1,1) << std::endl;
    std::cout << "Matriz B(0,0): " << B.get(0,0) << std::endl;
    std::cout << "Matriz B(4,3): " << B.get(4,3) << std::endl;

    // FillWith tests
    V.unit();
    std::cout << "Matriz V:" << std::endl; V.print();
    W.fillWith(10.0);
    std::cout << "Matriz W:" << std::endl; W.print();
    X.zeros();
    std::cout << "Matriz X:" << std::endl; X.print();
    Z.ones();
    std::cout << "Matriz Z:" << std::endl; Z.print();

    return 0;
}