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
    for(;;){
        
    }
}

int main()
{
    double resultado;

    //cria um container de ponteiros do tipo Funcao
    Funcao *f[3];

    f[0] = new Quadratica(1,2,4);
    f[1] = new Senoide();
    f[2] = new Linear(1,4);

    cout << "*** Calculo de integrais usando a regra do trapezio: ***"<<endl<<endl;
    cout << "*** Funcoes ***" << endl;
    cout << "(1) x^2 + 2x + 4" << endl;
    cout << "(2) sen(x) / x" << endl;
    cout << "(3) x + 4" << endl;
    cout << endl;

    for (int i=0; i<3; i++)
    {
        resultado = f[i]->getIntegral(1,4,1000);
        cout << "Integral da Funcao (" << i+1 << "): " << resultado;
        cout << endl;
    }

    for (int i=0; i<3; i++)
    {
        delete f[i];
    }

    return 0;
}