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
    
    protected:
        string name;
    public:
        Traveler(string _str):name(_str) {}
        Traveler(const Traveler &obj):name(obj.name) {}
        Traveler& operator=(const Traveler &obj){
            name = obj.name; 
        }
    
};

class Pager {

    protected:
        string id;
    public:
        Pager(string _str):id(_str) {}
        Pager(const Pager &obj):id(obj.id){}
        Pager& operator=(const Pager &obj){
            id = obj.id; 
        }
    friend class BusinessTraveler;    
};

class BusinessTraveler: public Traveler{
    private:
    Pager pag;
    public:
        BusinessTraveler(string _str = "1"): Traveler(_str), pag.id(_str) {}
        BusinessTraveler(const BusinessTraveler &obj):
        Traveler(obj.name), pag.id(obj.pag) {}
        BusinessTraveler& operator=(const BusinessTraveler &obj){
            name = obj.pag.id;
            pag = obj.pag; 
        }
};

#endif