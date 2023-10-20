#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "aluno.h"
#include "navegacao.h"

#define MAX 1000
#define TRUE 1
#define FALSE 0

int main(){
    //consertar acentuação do programa
    setlocale(LC_ALL,"");
    Aluno alunos[MAX];
    int id = 0;

    int opc;
    do{
        imprimirCabecalho();
        exibirMenu();
        scanf("%d",&opc);
        switch(opc){
            case 1: Aluno aln = cadastrarAluno(alunos,id);
                alunos[id] = aln;
                id++;
                break;
            case 2: //imprimir registros
                break;
            case 3: //buscar registro
                break;
            case 4: //filtrar por IMC
                break;
            case 5: //salvar dados
                break;
            case 6: //sair
                return 0;
            default: puts("Opção inexistente!");

        }
        limparTela();

    }while(TRUE);


}
