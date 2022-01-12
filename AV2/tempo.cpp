#include "tempo.h"
#include <stdlib.h>
#include <iostream>

Tempo::Tempo(int dia, int hora, int min, int seg):
    _dia(dia), _hora(hora), _min(min), _seg(seg){
        atualizaTempo();
    }

void Tempo::atualizaTempo(){
    for(;_seg >= 60 || _min >= 60 || _hora >= 24;){
        if(_seg >= 60){ _seg -= 60; _min++; }
        if(_min >= 60){ _min -= 60; _hora++; }
        if(_hora >= 24){ _hora -= 24; _dia++; }
    }
}

Tempo Tempo::operator+(const Tempo &timeData){
    Tempo temp(_dia, _hora, _min, _seg);
    temp.setDia(temp.getDia() + timeData.getDia());
    temp.setHora(temp.getHora() + timeData.getHora());
    temp.setMin(temp.getMin() + timeData.getMin());
    temp.setSeg(temp.getSeg() + timeData.getSeg());
    temp.atualizaTempo();
	return temp;
}

Tempo& Tempo::operator++(){
    _seg++;
    atualizaTempo();
    return *this;
}

Tempo& Tempo::operator--(){
    _seg--;
    atualizaTempo();
    return *this;
}

std::ostream& operator<<(std::ostream &out, Tempo const &timeData){
	//timeData.atualizaTempo();
	out << timeData.getDia() << "d "
		<< timeData.getHora() << "h "
		<< timeData.getMin() << "m "
		<< timeData.getSeg() << "s ";
	return out;
}

std::istream& operator>>(std::istream &in, Tempo &timeData){
	std::cout << "Informe, em ordem e separados por ESPAÇOS, dia, hora, minutos e segundos" << std::endl;
	in >> timeData._dia
	>> timeData._hora
	>> timeData._min
	>> timeData._seg;
	timeData.atualizaTempo();
	return in;
}