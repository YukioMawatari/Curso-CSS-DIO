#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
 
    //Variável
    int a = 20;
 
    //Imprimindo o valor de uma variável
    printf("Valor de a: %d \n", a);
 
     //Imprimindo o endereço de uma variável
    printf("Endereco de a: %d \n", &a);
 
    //VARIÁVEIS ARMAZENAM VALORES
    int b = 10;
 
    //PONTEIROS ARMAZENAM POSIÇÕES DA MEMÓRIA
    int *ponteiro;
 
    //PONTEIRO RECEBENDO A POSIÇÃO NA MEMÓRIA DA VARIÁVEL b
    ponteiro = &b;
 
    //Imprimindo o valor de uma variável
    printf("Valor de b: %d \n", b);
 
    //* pode ser lido como "CONTEÚDO APONTADO POR"
    *ponteiro = 40;
 
    //Imprimindo o valor de uma variável
    printf("Valor de b: %d \n", b);
 
    return 0;
}
