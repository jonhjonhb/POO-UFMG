#ifndef BUSINESS_H
#define BUSINESS_H

#include<iostream>
#include<string> 
using namespace std;

/*
Crie duas classes chamadas Traveler e Pager sem construtores default, mas com construtores que recebem uma string como parâmetro e copiam para uma variável interna. Para cada classe, escreva o construtor de cópia e o operador de atribuição. Crie uma classe chamada BusinessTraveler derivada de Traveler e insira um membro da classe Pager. Para essa classe crie:

Construtor default que inicializa ambos os strings de Traveler e Pager com “1“
Construtor que recebe uma string e inicializa ambos os strings de Traveler e Pager com o string recebido
Construtor de cópia
Operador de atribuição
*/

class Traveler {

    public:
        string str;
        Traveler(string _str):str(_str) {}
}

class Pager {

    public:
        string str;
        Traveler(string _str):str(_str) {}
}

class BusinessTraveler: public Traveler{
    
    Pager pag;

    public:
        BusinessTraveler(string _str = 1): Traveler(_str), Pager(_str) {}

        businessTraveler(string _str): Traveler(_str), Pager(_str) {}

}

#endif