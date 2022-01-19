#include "Box.h"

int main()
{
  Ponto3D p1(0,2,0), p2(1,2,0); // Vertices superiores da frente 
  Ponto3D p3(0,0,0), p4(1,0,0); // Vertices Inferiores da frente 
  Ponto3D p5(0,2,5), p6(1,2,5); // Vertices superiores da traseira 
  Ponto3D p7(0,0,5), p8(1,0,5); // Vertices Inferiores da traseira 
  
  Box a1(p1, p2, p3, p4, p5, p6, p7, p8);
  std::cout << "Largura do objeto: " << a1.getLargura() << std::endl;
  std::cout << "Altura do objeto: " << a1.getAltura() << std::endl;
  std::cout << "Profundidade do objeto: " << a1.getProfundidade() << std::endl;  
  std::cout << "Volume do objeto: " << a1.getVolume() << std::endl;
  std::cout << "Area do objeto: " << a1.getArea() << std::endl;

  return 0;
}