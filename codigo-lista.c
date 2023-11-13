#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EstruturaAluno
{
    int matricula;
    char *nome;
    float nota;
    struct EstruturaAluno *prox;
};

typedef struct EstruturaAluno Aluno;

Aluno *insereInicio(Aluno *atual, Aluno no);
Aluno *insereFinal(Aluno *atual, Aluno no);
void imprime(Aluno *atual);
Aluno *buscaPorMatricula(Aluno *atual, int matricula);
float calcularMedia(Aluno *atual);

int main()
{
    Aluno *listaAluno = NULL;
    Aluno no;

    no.matricula = 111;
    no.nome = "Flavio";
    no.nota = 10.0;
    listaAluno = insereInicio(listaAluno, no);

    no.matricula = 222;
    no.nome = "Joao";
    no.nota = 8;
    listaAluno = insereInicio(listaAluno, no);

    no.matricula = 333;
    no.nome = "Fulano";
    no.nota = 7;
    listaAluno = insereFinal(listaAluno, no);

    no.matricula = 444;
    no.nome = "Joao";
    no.nota = 8;
    listaAluno = insereFinal(listaAluno, no);

    imprime(listaAluno);

    int matriculaBuscada;
    printf("\nDigite a matricula a ser buscada: ");
    scanf("%d", &matriculaBuscada);

    Aluno *alunoEncontrado = buscaPorMatricula(listaAluno, matriculaBuscada);

    if (alunoEncontrado != NULL)
    {
        printf("\nAluno Encontrado:\n");
        printf("Matricula: %d\n", alunoEncontrado->matricula);
        printf("Nome: %s\n", alunoEncontrado->nome);
        printf("Nota: %.2f\n", alunoEncontrado->nota);
    }
    else
    {
        printf("\nAluno com matricula %d nao encontrado.\n", matriculaBuscada);
    }

    float media = calcularMedia(listaAluno);
    printf("\nMedia das notas dos alunos: %.2f\n", media);

    return 0;
}

Aluno *insereInicio(Aluno *atual, Aluno no)
{
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    novo->matricula = no.matricula;
    novo->nome = strdup(no.nome);
    novo->nota = no.nota;

    if (atual == NULL)
    {
        novo->prox = NULL;
    }
    else
    {
        novo->prox = atual;
    }
    return novo;
}

void imprime(Aluno *atual)
{
    if (atual == NULL)
    {
        printf("\nLista Vazia!");
    }

    while (atual != NULL)
    {
        printf("\nMatricula: %d", atual->matricula);
        printf("\nNome.....: %s", atual->nome);
        printf("\nNota.....: %.2f", atual->nota);
        printf("\n");
        atual = atual->prox;
    }
}

Aluno *insereFinal(Aluno *atual, Aluno no)
{
    if (atual == NULL)
    {
        return insereInicio(atual, no);
    }

    Aluno *inicio = atual;

    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    novo->matricula = no.matricula;
    novo->nome = strdup(no.nome);
    novo->nota = no.nota;
    novo->prox = NULL;

    atual->prox = novo;
    return inicio;
}

Aluno *buscaPorMatricula(Aluno *atual, int matricula)
{
    while (atual != NULL)
    {
        if (atual->matricula == matricula)
        {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

float calcularMedia(Aluno *atual)
{
    int numAlunos = 0;
    float somaNotas = 0;

    while (atual != NULL)
    {
        somaNotas += atual->nota;
        numAlunos++;
        atual = atual->prox;
    }

    if (numAlunos > 0)
    {
        return somaNotas / numAlunos;
    }
    else
    {
        return 0;
    }
}
