#include <stdio.h>
#include <stdlib.h>

#define NORMAL 1
#define ECONOMICO 2
#define INATIVO 3

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


void printTipo(int tipo){
    if (tipo == 1){
        printf("Normal");
    }else if (tipo == 2){
        printf("Econômico");
    }else{
        printf("Inativo");
    }
}

void printAluno(Aluno aln){
    puts("-----------------------");
    printf("ID: %d\n",aln.id);
    printf("Nome: %s\n",aln.nome);
    printf("Data de ingresso: %d/%d/%d\n",aln.dtIngresso.dia, aln.dtIngresso.mes, aln.dtIngresso.ano);
    printf("Peso: %.2f\n",aln.peso);
    printf("Altura: %.2f\n",aln.alt);
    printf("Tipo: "); printTipo(aln.tipo); printf("\n");
    puts("-----------------------");
}

Aluno cadastrarAluno(int id){
    Aluno aln;
    puts("Cadastrando aluno...\n");
    puts("Nome do aluno: ");
    limparBuffer();
    scanf("%119[^\n]s",aln.nome);
    puts("Data de ingresso: ('dd'/'mm'/'aaaa'): ");
    scanf("%d/%d/%d",&aln.dtIngresso.dia, &aln.dtIngresso.mes, &aln.dtIngresso.ano);
    puts("Peso (Kg): ");
    scanf("%f",&aln.peso);
    puts("Altura (m): ");
    scanf("%f",&aln.alt);
    while(1){
        int tipo;
        puts("Tipo de matrícula: 1 - Normal 2- Econômica");
        scanf("%d",&tipo);
        if (tipo == 1 || tipo == 2){
            aln.tipo = tipo;
            break;
        }else{
            puts("Tipo inválido!");
        }
    }
    aln.id = id;

    puts("Dados do aluno cadastrado:");
    printAluno(aln);
    return aln;
}

void printAlunos(Aluno alunos[],int id){
    Aluno aln;
    puts("Imprimindo registros de alunos...\n");
    for (int i =0; i< id; i++){
        aln = alunos[i];
        printAluno(aln);
    }
}

void salvarDadosAlunos(Aluno alunos[], int id){
    FILE *fp;
    fp = fopen("Alunos.txt","w");
    puts("Salvando dados em arquivo...");
    //salvando dados de id
    fprintf(fp,"%d\n",id);
    //salvando cada registro de aluno
    for (int i =0; i< id; i++){
        Aluno aln;
        aln = alunos[i];
        fprintf(fp,"%s\n",aln.nome);
        fprintf(fp,"%d/%d/%d\n",aln.dtIngresso.dia,aln.dtIngresso.mes,aln.dtIngresso.ano);
        fprintf(fp,"%f %f %d %d\n",aln.peso,aln.alt,aln.id,aln.tipo);
    }
    puts("Dados foram salvos com sucesso!");
    fclose(fp);
}

void carregarDadosAlunos(Aluno alunos[],int *pid){
    FILE *fp;
    fp = fopen("Alunos.txt","r");
    if (fp != NULL){
        puts("Carregando dados do arquivo...");
        puts("Lendo informação de id...");
        int id;
        fscanf(fp,"%d\n",&id);
        *pid = id;
        puts("Lendo dados de registros de alunos...");
        int qtd = 0;
        while(!feof(fp)){
            Aluno aln;
            fscanf(fp,"%[^\n]s",aln.nome);
            fscanf(fp,"%d/%d/%d\n",&aln.dtIngresso.dia,&aln.dtIngresso.mes,&aln.dtIngresso.ano);
            fscanf(fp,"%f %f %d %d\n",&aln.peso,&aln.alt,&aln.id, &aln.tipo);
            alunos[aln.id] = aln;
            qtd++;
        }
        fclose(fp);
        puts("Dados carregados com sucesso...");
        printf("Foram carregados %d registros de alunos...\n",qtd);
    }else{
        puts("Arquivo inexistente ou erro de leitura de arquivo!");
    }

}

void salvarCSV(Aluno alunos[], int id){
    FILE *fp;
    fp = fopen("Alunos.csv","w");
    puts("Salvando dados em arquivo...");
    //salvando cada registro de aluno
    for (int i =0; i< id; i++){
        Aluno aln;
        aln = alunos[i];
        fprintf(fp,"%s;%d/%d/%d;%f;%f;%d;%d\n",aln.nome,aln.dtIngresso.dia,aln.dtIngresso.mes,aln.dtIngresso.ano,aln.peso,aln.alt,aln.id,aln.tipo);
    }
    puts("Dados foram salvos com sucesso!");
    fclose(fp);
}
