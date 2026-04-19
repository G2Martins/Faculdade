#include <stdio.h>
#include <stdlib.h>

#define TAM 10
int pilha[TAM];
int topo = 0;

/*
Funções em Vetores
Push - empilha
Pop - Desempilha
Stackpop - Verificar quem está em cima
Empty - Verifica a pilha ta vazia
*/

int push(int valor){
    if(topo >= TAM){
        printf("Nao pode incluir");
        return;
    }else{
        pilha[topo++] = valor; //
    }
}

int pop(){
    if(topo == 0){
        printf("Pilha vazia \n");
        return;
    }else {
        return pilha[topo - 1];
    }
}

int stackpop(){
    if(topo == 0){
        printf("Pilha vazia \n");
        return;
    }else {
        return pilha[topo - 1];
    }
}

int empty(){
    return topo == 1 ? 1 : 0;
