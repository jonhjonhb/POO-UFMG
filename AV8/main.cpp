#include "Agenda.h"
/*
Crie um programa para testar para a Agenda. Peça para o usuário informar (via teclado) quantas pessoas ele deseja colocar na agenda, e crie uma Agenda com esta informação.

imprima na tela a quantidade de amigos e de conhecidos na agenda.
adicione informações à agenda.
imprima todos os aniversários dos amigos presentes na agenda.
imprima todos os e-mails dos conhecidos armazenados na agenda.
*/

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