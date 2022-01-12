#include "Ponto2D.h"
#include <math.h>
#include <random>
#include <iostream>
#include <algorithm>

std::vector<int> Ponto2D::identifiers;

Ponto2D::~Ponto2D(){
    identifiers.erase(std::find(identifiers.begin(), identifiers.end(), id));
}

int Ponto2D::getNextId()const{
    int temp = 0;
    for(;;){
        temp = rand()%1001;
        if(std::find(identifiers.begin(), identifiers.end(), temp) == identifiers.end()) break;
    }
    identifiers.push_back(temp);
    return temp;
}

void Ponto2D::print()const{
    std::cout << "O ponto de id " << id << " possui as coordenadas:\nX:" << _x << "\tY:" << _y << std::endl;
}

double Ponto2D::distToOrig()const{
    return sqrt(_x*_x+_y*_y);
}

double Ponto2D::distTo(const Ponto2D& otherPoint)const{
    double Xdif = _x - otherPoint.getX();
    double Ydif = _y - otherPoint.getY();
    return sqrt((Xdif*Xdif)+(Ydif*Ydif));
}

Ponto2D Ponto2D::sumOf(const Ponto2D& otherPoint)const{
    return Ponto2D(_x+otherPoint.getX(), _y+otherPoint.getY());
}

void Ponto2D::sum(const Ponto2D& otherPoint){
    _x += otherPoint.getX();
    _y += otherPoint.getY();
}