#include "Agenda.h"

int main() {  
  int qntPessoas = 0;
  cout << "Quantas pessoas deseja ter em sua agenda? " << endl;
  cin >> qntPessoas;
  Agenda myContatcs(qntPessoas);
  myContatcs.addInformacoes();
  myContatcs.imprimeAniversarios();
  myContatcs.imprimeEmail();  
  
  return 0;
}