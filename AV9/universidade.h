#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Professor{
  private:
    string nome;
  public:
    Professor(string n): nome(n){}
    string getName() const { return nome; };
    virtual double getSalario() = 0;
};

class ProfHorista: public Professor {
  private:
    double nrHorasTrabalhadas;
    double valorHora;
  public:
    ProfHorista(string n, double nht, double vh): Professor(n), nrHorasTrabalhadas(nht), valorHora(vh) {}
    double getSalario() { return nrHorasTrabalhadas*valorHora; };
};

class ProfIntegral: public Professor {
  private:
    double salarioMensal;
  public:
    ProfIntegral(string n, double sm): Professor(n), salarioMensal(sm) {}
    double getSalario() { return salarioMensal; };
};

class Universidade {
  private:
    std::vector<Professor*> funcionarios;
  public:
    void addProfessor(Professor *a) { funcionarios.push_back(a); };
    double totalPago() const;
    void imprimeProfessores() const;
};

double Universidade::totalPago() const {
  double soma = 0;
  for( Professor *a : funcionarios){
    soma += a->getSalario();
  }
  return soma;
}

void Universidade::imprimeProfessores() const{
  for( Professor *a : funcionarios){
    cout << a->getName() << endl;
  }
}

#endif