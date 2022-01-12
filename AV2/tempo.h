#ifndef TEMPO_H
#define TEMPO_H

#include <iostream>

class Tempo {
    private:

        int _dia;  // {01~}
        int _hora; // {00~23}
        int _min;  // {00~59}
        int _seg;  // {00~59}

    public:

        // Construtores
        Tempo(int dia, int hora, int min, int seg);
        Tempo(int dia, int hora, int min) : Tempo(dia, hora, min, 0){}
        Tempo(int dia, int hora) : Tempo(dia, hora, 0, 0){}
        Tempo(int dia) : Tempo(dia, 0, 0, 0){}
        Tempo() : Tempo(0, 0, 0, 0){}

        // getters
        int getDia()const{ return _dia; }
        int getHora()const{ return _hora; }
        int getMin()const{ return _min; }
        int getSeg()const{ return _seg; }
        void setDia(int dia){ _dia = dia; }        
        void setHora(int hora){ _hora = hora; }
        void setMin(int min){ _min = min; }
        void setSeg(int seg){ _seg = seg; }
        
        // métodos
        void atualizaTempo();

        // operadores
        Tempo operator+(const Tempo& timeData);
        Tempo& operator++();
        Tempo& operator--();

        friend std::ostream& operator<<(std::ostream &out, const Tempo &timeData);
		friend std::istream& operator>>(std::istream &in, Tempo &timeData);
};

#endif