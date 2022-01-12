// Escreva um programa que abra um arquivo e conte o número de espaços em branco do arquivo
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>

int main(){
    std::fstream in("enum.txt");
    std::vector<char> vetor;
    std::string s;
    char espaco = ' ';

    while(getline(in, s)){
        for(char c : s){
            if(c == espaco){
                vetor.push_back(c);
            }
        }
    }

    std::cout << vetor.size();

    return 0;
}