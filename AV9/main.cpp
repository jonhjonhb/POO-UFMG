#include "universidade.h"
#include "funcao.h"

int main(){
  ProfHorista a1("Javier", 100, 25);
  ProfHorista a2("Reginaldo", 100, 27.5);
  ProfIntegral b1("Pablo", 3000);

  Universidade UFMG;
  UFMG.addProfessor(&a1);
  UFMG.addProfessor(&a2);
  UFMG.addProfessor(&b1);
  UFMG.imprimeProfessores();
  cout << "Gastos com salarios: R$ " << UFMG.totalPago() << endl << endl;

  double resultado;
  //cria um container de ponteiros do tipo Funcao
  Funcao *f[3];

  f[0] = new Quadratica(1,2,4);
  f[1] = new Senoide();
  f[2] = new Linear(1,4);

  cout << "*** Calculo de integrais usando a regra do trapezio: ***"<< endl << endl;
  cout << "*** Funcoes ***" << endl;
  cout << "(1) x^2 + 2x + 4" << endl;
  cout << "(2) sen(x) / x" << endl;
  cout << "(3) x + 4" << endl;
  cout << endl;

  for (int i=0; i<3; i++){
    resultado = f[i]->getIntegral(1,4,10000);
    cout << "Integral da Funcao (" << i+1 << "): " << resultado;
    cout << endl;
  }

  for (int i=0; i<3; i++){
      delete f[i];
  }

  return 0;
}