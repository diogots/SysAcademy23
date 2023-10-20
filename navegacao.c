#include <stdio.h>

void imprimirCabecalho(){
    puts("***********************************************************************");
    puts("*                                                                     *");
    puts("*                            SysAcademy                               *");
    puts("*                                                                     *");
    puts("*                                                          ADS - UNIP *");
    puts("***********************************************************************");
}

void exibirMenu(){
    puts("\nEscolha a opção desejada:");
    puts("1 - Cadastrar");
    puts("2 - Visualizar registro de alunos");
    puts("3 - Buscar");
    puts("4 - Filtrar por IMC");
    puts("5 - Salvar dados");
    puts("6 - Sair");
    puts("---------------------------------");
    printf("opc: ");
}

void limparTela(){
    char ent;
    puts("Pressione qualquer tecla para continuar...");
    fflush(stdin);
    getchar();
    //scanf("%c",&ent);
    system("cls");
}
