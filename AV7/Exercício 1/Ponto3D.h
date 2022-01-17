#ifndef PONTO3D_H
#define PONTO3D_H

#include "Ponto2D.h"

class Ponto3D: public Ponto2D{
    
    public:
        Ponto3D(double xx = 0, double yy = 0, double zz=0): Ponto2D(xx, yy), z(zz) { };
        friend std::ostream& operator<< (std::ostream &op, const Ponto3D &p);
        Ponto3D& operator= (const Ponto3D &p);
        Ponto3D& operator= (const Ponto2D &p);
        void set(double nx = 0, double ny = 0, double nz=0) { set(nx, ny); z=nz; }
        double get_z(void) const { return z; }
            
    
    private:
        double z;
};    

std::ostream& operator<< (std::ostream &op, const Ponto3D &p){
            op << std::endl;
            op << "x = " << p.get_x() << std::endl;
            op << "y = " << p.get_y() << std::endl;
            op << "z = " << p.z << std::endl;
            return op;
}

Ponto3D& Ponto3D::operator= (const Ponto3D &p){
    this->set(p.get_x(), p.get_y(), p.get_z());
    return *this;
}

Ponto3D& Ponto3D::operator= (const Ponto2D &p){
    this->set(p.get_x(), p.get_y(), 0);
    return *this;
}

#endif