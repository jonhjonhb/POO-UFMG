#include <iostream>
#include <cmath>
using namespace std;

class Funcao{
    public:

    //funcao que obtem a integral da funcao pela regra do trapezio
    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos);

    // funcao virtual representando a funcao cuja integral deve ser calculada
    virtual double func(double input) = 0;
};

class Linear: public Funcao{
    private: 
        double A, B;
        double func(double input);
    public:
        Linear(double _a, double _b): A(_a), B(_b){}
};

class Quadratica: public Funcao{
    private:
        double A, B, C;
        double func(double input);
    public:
        Quadratica(double _a, double _b, double _c): A(_a), B(_b), C(_c){}
};

class Senoide: public Funcao{
    private:
        double func(double input);
    public:
        Senoide(){}
};

double Linear::func(double input){
    return input*A + B;
}

double Quadratica::func(double input){
    return input*input*A + input*B + C;
}

double Senoide::func(double input){
    return sin(input)/input;
}

double Funcao::getIntegral(double limiteInferior, double limiteSuperior, double intervalos){
    double tamIntervalo = (limiteSuperior - limiteInferior)/intervalos;
    double integral = func(limiteInferior) + func(limiteSuperior);
    double currentValue = 0;
    for(int i = 1; i <= intervalos - 1; i++){
        currentValue = limiteInferior + i*tamIntervalo;
        integral += 2*func(currentValue);
    }
    integral *= tamIntervalo/2;
    return integral;
}
