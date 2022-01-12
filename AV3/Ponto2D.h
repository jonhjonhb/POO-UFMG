#ifndef PONTO_H
#define PONTO_H

#include <vector>

class Ponto2D{
    private:

        double _x;
        double _y;
        int id;

        static std::vector<int> identifiers;
        int getNextId()const;

    public:

        Ponto2D(double x = 0.0, double y = 0.0) : _x(x), _y(y){ id = getNextId(); }
        ~Ponto2D();

        double getX()const{ return _x; }
        double getY()const{ return _y; }
        void setX(const double x){ _x = x; }
        void setY(const double y){ _y = y; }
        
        void print()const;
        double distToOrig()const;
        double distTo(const Ponto2D&)const;
        Ponto2D sumOf(const Ponto2D&)const;
        void sum(const Ponto2D&);
        
        
};

#endif