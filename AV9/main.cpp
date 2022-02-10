#include "universidade.h"

int main(){
  ProfHorista a1("Javier", 100, 25);
  ProfHorista a2("Reginaldo", 100, 27.5);
  ProfIntegral b1("Pablo", 3000);

  Universidade UFMG;
  UFMG.addProfessor(&a1);
  UFMG.addProfessor(&a2);
  UFMG.addProfessor(&b1);
  UFMG.imprimeProfessores();
  cout << "Gastos com salarios: R$ " << UFMG.totalPago() << endl;
  
  return 0;
}