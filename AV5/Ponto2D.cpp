#include<iostream> 

class Ponto2D{
    
    int x,y;
    
    public:
        Ponto2D(int xx=0, int yy=0):x(xx),y(yy){ };
        Ponto2D& operator-- ();
        Ponto2D operator+ (const Ponto2D& ) const;
        ~Ponto2D(){}; 

        int getX()const{ return x; }
        int getY()const{ return y; }
};

Ponto2D& Ponto2D::operator--(){
    this->x--;
    this->y--;
    return *this;
}

Ponto2D Ponto2D::operator+(const Ponto2D& other)const{
    return Ponto2D(this->x + other.getX(), this->y + other.getY());
}

int main() {

    Ponto2D a(1,4), b(3,2), c;
    c = a + b;               // soma as coordenadas dos pontos a e b 
    --c;                    // decrementa em uma unidade as coordenadas de c
}

