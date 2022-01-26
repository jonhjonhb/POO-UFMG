#ifndef AGENDA_H
#define AGENDA_H

#include<string>
#include<iostream>
#include<vector>
#include<ctime>
#include<typeinfo>
using namespace std;

class Pessoa {
  private:
    string _nome;
    int _idade;
  public:
    Pessoa(string nome, int idade):_nome(nome), _idade(idade) {}
    Pessoa():_nome("indefinido"), _idade(0) {}
    // Getters e Setters
    void setNome(string nome) { _nome = nome; }
    void setIdade(int idade) { _idade = idade;}
    virtual void set(string nome, int idade, string) {}
    string getNome(void) const { return _nome;}
    int getIdade(void) const { return _idade;}
    virtual string getInfoVar(void) { return "[ERRO]: class Pessoa."; }
};

class Amigo: public Pessoa {
  private:
    string _aniversario;
  public:
    Amigo(): _aniversario("indefinido") {}
    // Getters e Setters
    void setAniversario(string aniversario) { _aniversario = aniversario; }
    string getAniversario(void) const { return _aniversario; }
    string getInfoVar(void) {return getAniversario(); }
    void set(string nome, int idade, string aniversario){
      setNome(nome);
      setIdade(idade);
      setAniversario(aniversario);
    }
};

class Conhecido: public Pessoa{
  private:
    string _email;
  public:
    Conhecido(): _email("indefinido") {}
    // Getters e Setters
    void setEmail(string email) { _email = email; }
    string getEmail(void) const { return _email; }
    string getInfoVar(void){ return getEmail(); }
    void set(string nome, int idade, string email){
      setNome(nome);
      setIdade(idade);
      setEmail(email);
    }
};

class Agenda{
  private:
    std::vector<Pessoa *> grupo;
    int amigos;
    int conhecidos;
    int aleatorio() {
      srand((unsigned int) time (NULL));
      return 1 + rand()%2;
    }
  public:
    void criarAgenda(int qntPessoas);
    Agenda(int qntPessoas){ criarAgenda(qntPessoas); }
    // Getters
    int getQntPessoas(void) const { return getAmigos() + getConhecidos(); }
    int getAmigos(void) const { return amigos; }
    int getConhecidos(void) const { return conhecidos; }
    void addInformacoes(void);
    void imprimeAniversarios(void);
    void imprimeEmail(void);
};

void Agenda::criarAgenda(int qntPessoas){
  int i = 0; 
  for(i = 0; i < qntPessoas; i++){
    switch(aleatorio()) { 
      case 1: {
        grupo.push_back(new Amigo);
        amigos++;
        break;
      }
      case 2: {
        grupo.push_back(new Conhecido);
        conhecidos++;
        break;
      }
    } 
  }
}

void Agenda::addInformacoes(void) {
  string nome;
  int idade;
  string var;
  for (auto p : grupo){
    cout << endl << "Digite o nome do contato: ";
    cin >> nome;
    cout << "Digite a idade do contato: ";
    cin >> idade;
    if(typeid(*p) == typeid(Amigo)){
      cout << "Digite a data de aniversario do contato: ";
      cin >> var;
    } else if(typeid(*p) == typeid(Conhecido)){
      cout << "Digite o e-mail do contato: ";
      cin >> var;
    }
    p->set(nome, idade, var);
  }
}

void Agenda::imprimeAniversarios(void){
  for (auto p : grupo){
    if(typeid(*p) == typeid(Amigo)){
      cout << p->getNome() << " | Data de Aniversario: " << p->getInfoVar() << endl;
    }
  }
}

void Agenda::imprimeEmail(void){
  for (auto p : grupo){
    if(typeid(*p) == typeid(Conhecido)){
      cout << p->getNome() << " | E-mail: " << p->getInfoVar() << endl;
    }
  }
}

#endif