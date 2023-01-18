#include <stdio.h>
#include <stdlib.h>

typedef struct Nascimento {
    int dia;
    int mes;
    int ano;
} Nascimento;

typedef struct Disciplinas {
    char nomeDisciplina[51], aprovado[10];
    float prova[2], trabalho[2], media;

} Disciplinas;

typedef struct Aluno {
    int ra;
    char nome[51];
    Nascimento dataDeNascimento;
    Disciplinas materias[5];
} Aluno;

FILE *arquivo;

void BuscaBinaria(Aluno Aluno, int indice, int baixo, int alto) {
    int medio, indice;
    if (baixo <= alto) {
int BuscaBinaria(float *vetor, int dimensao, int ra, int inicio, int fim) {
    // Vetor: vetor, n: dimensao do vetor, ra: ra a ser localizado
    // inicio e fim: verificar o vetor entre os indices inicio e fim
    int meio, posicao;
    if (inicio <= fim) {
        meio = (inicio + fim) / 2;  // divisao inteira, isto eh, a parte fracionaria nao eh considerada
        if (ra == vetor[meio]) {
            posicao = meio;
        } else {
            if (ra > vetor[meio]) {
                posicao = BuscaBinaria(vetor, dimensao, ra, meio + 1, fim);
            } else {
                posicao = BuscaBinaria(vetor, dimensao, ra, inicio, meio - 1);
            }
        }
    } else {
        posicao = -1;
    }
    return posicao;
}
    }
}

float CalcularMedia(Aluno Aluno) {
}

int main() {
    Aluno a;
    arquivo = fopen("teste.txt", "r");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d\n", &a.ra);
        fscanf(arquivo, "%s\n", a.nome);
        fscanf(arquivo, "%d\n", &a.dataDeNascimento.dia);
        fscanf(arquivo, "%d\n", &a.dataDeNascimento.mes);
        fscanf(arquivo, "%d\n", &a.dataDeNascimento.ano);
        for (int i = 0; i < 5; i++) {
            fscanf(arquivo, "%s\n", &a.materias[i].nomeDisciplina);
            for (int j = 0; j < 2; j++) {
                fscanf(arquivo, "%f\n", &a.materias[i].prova[j]);
            }
            for (int j = 0; j < 2; j++) {
                fscanf(arquivo, "%f\n", &a.materias[i].trabalho[j]);
            }
            fscanf(arquivo, "%f\n", &a.materias[i].media);
            fscanf(arquivo, "%s\n", a.materias[i].aprovado);
        }
    }
    printf("RA: %d\nNome: %s\n%d de %d de %d\n", a.ra, a.nome, a.dataDeNascimento.dia, a.dataDeNascimento.mes, a.dataDeNascimento.ano);
    for (int i = 0; i < 5; i++) {
        printf("Nome disciplina: %s\n", a.materias[i].nomeDisciplina);
        for (int j = 0; j < 2; j++) {
            printf("Nota prova: %.2f\n", a.materias[i].prova[j]);
        }
        for (int j = 0; j < 2; j++) {
            printf("Nota trabalho: %.2f\n", a.materias[i].trabalho[j]);
        }
        printf("Media de %s: %.2f\n", a.materias[i].nomeDisciplina, a.materias[i].media);
        printf("Aprovacao: %s\n", a.materias[i].aprovado);
        printf("\n");
    }
}
