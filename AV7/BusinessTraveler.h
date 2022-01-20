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
            return *this;
        }
        friend std::ostream& operator<< (std::ostream &op, const Traveler &t){
            op << std::endl;
            op << "Nome: " << t.name;
            return op;
        }
    friend class BusinessTraveler;
};

class Pager {

    protected:
        string id;
    public:
        Pager(string _str):id(_str) {}
        Pager(const Pager &obj):id(obj.id){}
        Pager& operator=(const Pager &obj){
            id = obj.id; 
            return *this;
        }
        Pager& operator=(const string str){
            id = str;
            return *this;
        }
        friend std::ostream& operator<< (std::ostream &op, const Pager &p){
            op << std::endl;
            op << "ID: " << p.id;
            return op;
        }

    friend class BusinessTraveler;    
};

class BusinessTraveler: public Traveler{
    private:
        Pager pag;
    public:
        BusinessTraveler(string _str = "1"): Traveler(_str), pag(Pager(_str)) {}
        BusinessTraveler(const BusinessTraveler &obj): Traveler(obj.name), pag(obj.pag) {}
        BusinessTraveler(const Traveler &obj): Traveler(obj.name), pag(Pager("Undefined")) {}
        BusinessTraveler& operator=(const BusinessTraveler &obj){
            name = obj.name;
            pag = obj.pag;
            return *this;
        }
        BusinessTraveler& operator=(const Traveler &obj){
            name = obj.name;
            return *this;
        }
        void setPagerID(string str){
            pag = str;
        }
        void setPager(const Pager &obj){
            pag = obj;
        }
        friend std::ostream& operator<< (std::ostream &op, const BusinessTraveler &bt){
             op << std::endl;
            op << "Nome: " << bt.name << bt.pag;
            return op;
        }
};

#endif