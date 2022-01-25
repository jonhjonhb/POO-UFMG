#ifndef AGENDA_H
#define AGENDA_H

#include<iostream>
#include<string>

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
    string getNome(void) const { return _nome;}
    int getIdade(void) const { return _idade;}
}

#endif