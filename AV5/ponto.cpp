#include "ponto.h"

Ponto &Ponto::operator--(){
  _x--;
  _y--;
  return *this;
}

Ponto Ponto::operator+(const Ponto& pontoData) const{
  Ponto temp(_x, _y);
  temp.setX(temp.getX() + pontoData.getX());
  temp.setY(temp.getY() + pontoData.getY());
  return temp;
}