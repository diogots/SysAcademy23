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
void printTipo(int tipo);
void printAluno(Aluno aln);
Aluno cadastrarAluno(int id);
void printAlunos(Aluno alunos[],int id);
void salvarDadosAlunos(Aluno alunos[], int id);
void carregarDadosAlunos(Aluno alunos[],int *pid);
void salvarCSV(Aluno alunos[], int id);
