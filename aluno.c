#include <stdio.h>
#include <stdlib.h>

#define NORMAL 1
#define ECONOMICO 2

struct data{
    int dia;
    int mes;
    int ano;
};
typedef struct data Data;

struct aluno{
    char nome[120];
    int id;
    Data dtIngresso;
    float peso;
    float alt;
    int tipo;
};
typedef struct aluno Aluno;

Aluno cadastrarAluno(int id){
    Aluno aln;
    puts("Digite o nome do aluno:");

    return aln;

}
