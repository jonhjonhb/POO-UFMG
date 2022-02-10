#include<string>
#include<iostream>

using namespace std;

class Professor{
  private:
    string nome;
  public:
    Professor(string n): nome(n){}
    string getName() const { return nome; };
    virtual double getSalario() = 0;
    virtual ~Professor();
};

class ProfHorista: public Professor {
  private:
    double nrNorasTrabalhadas;
    double valorHora;
  public:
    ProfHorista(string n, double nht, double vh): Professor(n), nrNorasTrabalhadas(nht), valorHora(vh) {}
    double getSalario() { return nrNorasTrabalhadas*valorHora; };
    virtual ~ProfHorista() {}
};

class ProfIntegral: public Professor {
  private:
    double salarioMensal;
  public:
    ProfIntegral(string n, double sm): Professor(n), salarioMensal(sm) {}
    double getSalario() { return salarioMensal; };
    virtual ~ProfIntegral(){}
};