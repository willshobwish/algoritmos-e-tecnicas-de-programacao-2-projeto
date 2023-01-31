#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMOALUNO 50

// Parte 1 Construcao do struct
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
    int registroAcademico;
    char nome[101];
    Nascimento dataDeNascimento;
    Disciplinas materias[5];
} Aluno;

FILE *arquivo;

// void OrdenacaoSelecao(int *vetor, ti) {
// }

int BuscaBinaria(Aluno *vetorAluno, int dimensao, int registroAcademico, int inicio, int fim) {
    int meio, posicao;
    if (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (registroAcademico == vetorAluno[meio].registroAcademico) {
            posicao = meio;
        } else {
            if (registroAcademico > vetorAluno[meio].registroAcademico) {
                posicao = BuscaBinaria(vetorAluno, dimensao, registroAcademico, meio + 1, fim);
            } else {
                posicao = BuscaBinaria(vetorAluno, dimensao, registroAcademico, inicio, meio - 1);
            }
        }
    } else {
        posicao = -1;
    }
    return posicao;
}

// void pesquisa(int *x, int n) {
//     int dado, pos;
//     printf("Digite um valor para buscar no vetor: (0 para finalizar vetorAluno[aluno] busca) ");
//     scanf("%d", &dado);
//     while (dado != 0) {
//         pos = BuscaBinaria(x, n, dado, 0, n - 1);

//         if (pos != -1) {
//             printf("Valor %d encontrado na posicao %d\n", dado, pos);
//         } else {
//             printf("Valor %d nao encontrado\n", dado);
//         }
//         printf("Digite um valor para buscar no vetor: (0 para finalizar vetorAluno[aluno] busca) ");
//         scanf("%d", &dado);
//     }
// }
void CalcularAprovacao(Aluno *Aluno) {
    for (int i = 0; i < 5; i++) {
        if (Aluno->materias[i].media >= 5) {
            strcpy(Aluno->materias[i].aprovado, "Aprovado");
        } else {
            strcpy(Aluno->materias[i].aprovado, "Reprovado");
        }
    }
}

void CalcularMedia(Aluno *Aluno) {
    for (int i = 0; i < 5; i++) {
        float mediaProva = 0, mediaTrabalho = 0;
        for (int j = 0; j < 2; j++) {
            mediaProva += Aluno->materias[i].prova[j];
            mediaTrabalho += Aluno->materias[i].trabalho[j];
        }
        Aluno->materias[i].media = (mediaProva + mediaTrabalho) / 4;
    }
}

int main() {
    // Parte 2 Leitura e alocacao dos dados no struct
    Aluno vetorAluno[MAXIMOALUNO], vetorAlunoPesquisa[MAXIMOALUNO];
    float vetorTrabalhos[5], vetorProvas[5], vetorMedia[5];
    char arquivoOrigem[] = "arquivo_correto.txt", arquivoDestino[] = "arquivo_destino.txt";
    arquivo = fopen(arquivoOrigem, "r");
    while (!feof(arquivo)) {
        for (int alunoIndice = 0; alunoIndice < MAXIMOALUNO; alunoIndice++) {
            fscanf(arquivo, "%d\n", &vetorAluno[alunoIndice].registroAcademico);
            fscanf(arquivo, "%s\n", vetorAluno[alunoIndice].nome);
            fscanf(arquivo, "%d\n", &vetorAluno[alunoIndice].dataDeNascimento.dia);
            fscanf(arquivo, "%d\n", &vetorAluno[alunoIndice].dataDeNascimento.mes);
            fscanf(arquivo, "%d\n", &vetorAluno[alunoIndice].dataDeNascimento.ano);
            for (int i = 0; i < 5; i++) {
                fscanf(arquivo, "%s\n", &vetorAluno[alunoIndice].materias[i].nomeDisciplina);
                for (int j = 0; j < 2; j++) {
                    fscanf(arquivo, "%f\n", &vetorAluno[alunoIndice].materias[i].prova[j]);
                }
                for (int j = 0; j < 2; j++) {
                    fscanf(arquivo, "%f\n", &vetorAluno[alunoIndice].materias[i].trabalho[j]);
                }
                fscanf(arquivo, "%f\n", &vetorAluno[alunoIndice].materias[i].media);
                // fscanf(arquivo, "%s\n", vetorAluno[aluno].materias[i].aprovado);
            }
        }
    }
    fclose(arquivo);
    // Parte 3.1 calculo da media e resultado
    for (int i = 0; i < MAXIMOALUNO; i++) {
        CalcularMedia(&vetorAluno[i]);
        CalcularAprovacao(&vetorAluno[i]);
    }

    // Parte 3.2 escrita do resultado e media
    arquivo = fopen(arquivoDestino, "w");
    for (int i = 0; i < MAXIMOALUNO; i++) {
        fprintf(arquivo, "%d\n", vetorAluno[i].registroAcademico);
        for (int j = 0; j < 5; j++) {
            fprintf(arquivo, "%s\n", vetorAluno[i].materias[j].nomeDisciplina);
            fprintf(arquivo, "%f\n", vetorAluno[i].materias[j].media);
            fprintf(arquivo, "%s\n", vetorAluno[i].materias[j].aprovado);
        }
    }
    fclose(arquivo);

    for (int alunoIndice = 0; alunoIndice < MAXIMOALUNO; alunoIndice++) {
        printf("Registro Academico: %05d\nNome: %s\n%d de %d de %d\n", vetorAluno[alunoIndice].registroAcademico, vetorAluno[alunoIndice].nome, vetorAluno[alunoIndice].dataDeNascimento.dia, vetorAluno[alunoIndice].dataDeNascimento.mes, vetorAluno[alunoIndice].dataDeNascimento.ano);
        for (int i = 0; i < 5; i++) {
            printf("Nome disciplina: %s\n", vetorAluno[alunoIndice].materias[i].nomeDisciplina);
            for (int j = 0; j < 2; j++) {
                printf("Nota prova: %f\n", vetorAluno[alunoIndice].materias[i].prova[j]);
            }
            for (int j = 0; j < 2; j++) {
                printf("Nota trabalho: %f\n", vetorAluno[alunoIndice].materias[i].trabalho[j]);
            }
            printf("Media de %s: %f\n", vetorAluno[alunoIndice].materias[i].nomeDisciplina, vetorAluno[alunoIndice].materias[i].media);
            printf("Aprovacao: %s\n", vetorAluno[alunoIndice].materias[i].aprovado);
            printf("\n");
        }
    }

    // Parte 4 leitura do arquivo com media e resultado
    arquivo = fopen(arquivoDestino, "r");
    // char nome[5 * MAXIMOALUNO][51], aprovado[5 * MAXIMOALUNO][20], disciplina[5 * MAXIMOALUNO][20];
    // int registroAcademico[MAXIMOALUNO];
    // float medias[5 * MAXIMOALUNO];

    // fscanf(arquivo, "%d\n", registroAcademico[0]);
    // printf("Registro Academico: %d\n", registroAcademico[0]);
    for (int i = 0; i < MAXIMOALUNO; i++) {
        fscanf(arquivo, "%d\n", &vetorAlunoPesquisa[i].registroAcademico);
        for (int j = 0; j < 5; j++) {
            fscanf(arquivo, "%s\n", vetorAlunoPesquisa[i].materias[j].nomeDisciplina);
            fscanf(arquivo, "%f\n", &vetorAlunoPesquisa[i].materias[j].media);
            fscanf(arquivo, "%s\n", vetorAlunoPesquisa[i].materias[j].aprovado);
        }
    }
    fclose(arquivo);

    printf("Parte 4\n");
    for (int i = 0; i < MAXIMOALUNO; i++) {
        printf("Registro Academico: %d\n", vetorAlunoPesquisa[i].registroAcademico);
        for (int j = 0; j < 5; j++) {
            printf("Disciplina: %s\n", vetorAlunoPesquisa[i].materias[j].nomeDisciplina);
            printf("Media da disciplina: %f\n", vetorAlunoPesquisa[i].materias[j].media);
            printf("Situacao: %s\n\n", vetorAlunoPesquisa[i].materias[j].aprovado);
        }
    }
}
