#ifndef BOX_H
#define BOX_H

#include "Ponto3D.h"

/*Crie uma classe Box definida como um paralelepípedo retangular, uma figura tridimensional formada por 
seis paralelogramos. Os atributos de um objeto Box são largura, altura e profundidade. Defina funções
membro para o cálculo da área e do volume da Box. Crie pelo menos um construtor de forma que seja possível 
inicializar um objeto Box a partir das coordenadas de seus vértices, ou seja, objetos do tipo Ponto 3D.*/

class Box: public Ponto3D{
	
		private:
			double _largura;
			double _altura;
			double _profundidade;

		public:
			Box(Ponto3D frenteSupEsq, Ponto3D frenteSupDir, Ponto3D frenteInfEsq, Ponto3D frenteInfDir, 
			 Ponto3D traseiraSupEsq, Ponto3D traseiraSupDir, Ponto3D traseiraInfEsq, Ponto3D traseiraInfDir): 
			 _largura(frenteInfDir.get_x() - frenteInfEsq.get_x()), 
			 _altura(frenteSupDir.get_y() - frenteInfDir.get_y()), 
			 _profundidade(traseiraInfDir.get_z() - frenteInfDir.get_z()) { }
			double getLargura(void) const { return _largura; }
			double getAltura(void) const { return _altura; }
			double getProfundidade(void) const { return _profundidade; }
			double getArea(void) const { return 2*(getLargura()*getProfundidade() + 
			 getLargura()*getAltura() + getProfundidade()*getAltura()); }
			double getVolume(void) const { return getLargura() * getAltura() * getProfundidade(); }


};    

#endif