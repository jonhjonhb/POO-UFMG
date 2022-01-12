#include <iostream>
#include "ponto.h"


int main() {
  
  Ponto a(1,4), b(3,2), c;
  c = a + b; // soma as coordenadas dos pontos a e b 
  --c; // decrementa em uma unidade as coordenadas de c
  std::cout << "Ponto a:" << std::endl;
  std::cout << "Coordenada x = " << a.getX() << ", Coordenada y = " << a.getY() << std::endl;
  std::cout << "Ponto b:" << std::endl;
  std::cout << "Coordenada x = " << b.getX() << ", Coordenada y = " << b.getY() << std::endl;
  std::cout << "Ponto c:" << std::endl;
  std::cout << "Coordenada x = " << c.getX() << ", Coordenada y = " << c.getY() << std::endl;
  return 0;
}