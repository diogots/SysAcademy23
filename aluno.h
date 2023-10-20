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
Aluno* cadastrarAluno(Aluno alunos[],int id);
