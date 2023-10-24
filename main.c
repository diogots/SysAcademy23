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
    //criar vetor de alunos
    Aluno alunos[MAX];
    //zerar id
    int id = 0;

    imprimirCabecalho();
    carregarDadosAlunos(alunos, &id);
    limparTela();

    int opc;
    do{
        imprimirCabecalho();
        exibirMenu();
        scanf("%d",&opc);
        Aluno aln;
        switch(opc){
            case 1:
                aln = cadastrarAluno(id);
                alunos[id] = aln;
                id++;
                break;
            case 2:
                printAlunos(alunos,id);
                break;
            case 3: //buscar registro
                break;
            case 4: //filtrar por IMC
                break;
            case 5:
                salvarDadosAlunos(alunos,id);
                salvarCSV(alunos,id);
                break;
            case 6: //sair
                return 0;
            default: puts("Opção inexistente!");

        }
        limparTela();

    }while(TRUE);


}
