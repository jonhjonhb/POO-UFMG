# ELE078 - Programação Orientada a Objetos
## Atividade Prática 05

### Parte 01: Sobrecarga de Operadores
Dado o código a seguir, implemente as sobrecargas para os operadores de adição (+) e decremento pré-fixado (--). Considere a sobrecarga como funções membro de classe.

#include <iostream>
class Ponto2D {

    int x,y;
    public:
        Ponto(int xx=0, int yy=0):x(xx),y(yy){ };
        Ponto& operator-- ();
        Ponto operator+ (const Ponto& ) const;
        ~Ponto(){}; 
};

int main() {

    Ponto a(1,4), b(3,2), c;
    c = a + b;               // soma as coordenadas dos pontos a e b 
    --c;                    // decrementa em uma unidade as coordenadas de c
}

### Parte 02: Sobrecarga de Operadores na classe Matrix
Adicionar à classe Matrix (atividade prática 04), os seguinte operadores de forma que operações sobre objetos desta classe possam ser manipuladas de forma similar ao que ocorre no MatLab :

int main()
{
    ifstream in("myMatrix.txt");std:endl
    Matrix Y;
    Matrix X(3,1), A(3,3), C(3,3);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    
    // operadores a serem implementados em sua classe:
    
    A(2,1) = 10;                               // altera o valor de uma posição de A
    C = A + A;                                  // Soma
    C -= A;                                     // Subtração       
    A = C - A;                                  // Subtração
    A += A;                                   // Soma
    A = ~C;                                  // A é igual a transposta de C
    X *= 2;                                   // multiplicação por uma constante
    C = A*X;                                         // multiplicação de matrizes
    C *= X;                                            // multiplicação de matrizes
    if (A == C)                                 // verifica a igualdade entre A e C
    if(X != Y)                                  // verifica a desigualdade entre A e C
    cout << Z << endl;                        // impressão de matrizes
    cin >> W                                        // leitura de dados para dentro da matriz Y 
  
    return 0;
}