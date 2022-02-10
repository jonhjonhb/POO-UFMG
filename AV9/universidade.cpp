#include<string>
#include<iostream>

using namespace std;

class Professor{
  private:
    string nome;
  public:
    Professor(string n);
    string getName() const;
    virtual double getSalario() = 0;
    virtual ~Professor();
};

class ProfHorista: public Professor {
  private:
    double nrNorasTrabalhadas;
    double valorHora;
  public:
    ProfHorista(string n, double nht, double vh);
    double getSalario();
    virtual ~ProfHorista();
};

class ProfIntegral: public Professor {
  private:
    double salarioMensal;
  public:
    ProfIntegral(string n, double sm);
    double getSalario();
    virtual ~ProfIntegral(){}
};