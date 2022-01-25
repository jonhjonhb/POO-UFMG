#include <iostream>
#include <ctime>

int aleatorio() {
  srand((unsigned int) time (NULL));
  return 1 + rand()%2;
}

int main() {  
  for(int i = 0; i < 1000; i++) {
    std::cout << i << " : " <<  aleatorio() << std::endl;
  }
  return 0;
}