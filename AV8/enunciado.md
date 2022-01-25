# ELE078 - Programação Orientada a Objetos
## Atividade Prática 08 - Polimorfismo, Funções Virtuais e Classes Abstratas

### Construindo uma Agenda Simples
Crie uma classe chamada Pessoa. Uma pessoa possui um nome (string) e uma idade (int).

* crie 2 construtores: um que recebe o nome e a idade como parâmetros de entrada e um que não recebe parâmetros e inicializa os atributos com um valor padrão (“indefinido” para strings e 0 para inteiros).
* se necessário, crie métodos acessores e modificadores para os atributos (GET e SET).

Crie uma classe Amigo, derivada de Pessoa, e possui uma data de aniversário (string).

* crie um construtor que não recebe parâmetros de entrada, e inicializa o atributo com um valor padrão (“indefinido”, por exemplo).
* se necessário, crie um método de acesso (ou moficação) para o atributo data de nascimento.
 
Crie uma classe Conhecido, derivada de Pessoa, que possui um e-mail (string).

*crie um construtor que não recebe parâmetros de entrada, e inicializa o e-mail com um valor padrão (“indefinido”, por exemplo). • se necessário, crie um método de acesso (ou moficação) para o atributo e-mail.

Crie agora, uma classe Agenda, que possui uma coleção de Pessoas (do tipo vector) e dois atributos que controlam: a quantidade de amigos (int) e a quantidade de conhecidos (int).

* crie um construtor que recebe por parâmetro a quantidade de pessoas que a agenda terá, e inicializa a coleção (vector) de Pessoa. Neste construtor, inicialize todas as posições do vetor criando ALEATORIAMENTE um Conhecido ou um Amigo. Para isso, crie um código para sortear valores um valor  𝑥∈{1,2} . Se o valor encontrado for  1 , crie um Amigo. Se o valor encontrado for  2 , crie um Conhecido.
* se necessário, crie métodos acessores e modificadores para os atributos da classe Agenda.
* crie um método chamado addInformacoes, que não recebe parâmetros de entrada. Para cada Pessoa na agenda, peça para o usuário digitar (via teclado) as informações cabíveis para cada tipo de Pessoa.
* crie um método chamado imprimeAniversários, que imprime os aniversários de todos os amigos que estão armazenados na agenda.
* crie um método chamado imprimeEmail, que imprime os e-mails de todos os conhecidos que estão armazenados na agenda.

// code sample to generate random numbers in C++

#include <iostream>
#include <ctime>

int main()
{
    srand((unsigned int) time (NULL)); //activates the generator
    //...
    int a = rand()%10;        //gives a random from 0 to 9

    double r = ((double) rand() / (RAND_MAX));        //gives a random from 0 to 1

    int max, min;
    //...
    int c = (rand()%(max - min)) + min;              //gives a random from min to max
    //...
    return 0;
}

## Testando sua Agenda
Crie um programa para testar para a Agenda. Peça para o usuário informar (via teclado) quantas pessoas ele deseja colocar na agenda, e crie uma Agenda com esta informação.

* imprima na tela a quantidade de amigos e de conhecidos na agenda.
* adicione informações à agenda.
* imprima todos os aniversários dos amigos presentes na agenda.
* imprima todos os e-mails dos conhecidos armazenados na agenda.