---
marp: true
header: Algoritmos e técnicas de programação 2
footer: Willian Yoshio Murayama
math: katex
---

# Trabalho final de algoritmos e técnicas de programação 2

---

# Structs

---

## Nascimento

```c
typedef struct Nascimento {
    int dia;
    int mes;
    int ano;
} Nascimento;

```

---

## Disciplinas

```c
typedef struct Disciplinas {
    char nomeDisciplina[51], aprovado[10];
    float prova[2], trabalho[2], media;

} Disciplinas;
```

---

## Aluno

```c
typedef struct Aluno {
    int registroAcademico;
    char nome[101];
    Nascimento dataDeNascimento;
    Disciplinas materias[5];
} Aluno;
```

---

# Busca binária e pesquisa
---
## Busca binária

```c
int BuscaBinaria(float *vetor, int dimensao, int registroAcademico, int inicio, int fim) {
    int meio, posicao;
    if (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (registroAcademico == vetor[meio]) {
            posicao = meio;
        } else {
            if (registroAcademico > vetor[meio]) {
                posicao = BuscaBinaria(vetor, dimensao, registroAcademico, meio + 1, fim);
            } else {
                posicao = BuscaBinaria(vetor, dimensao, registroAcademico, inicio, meio - 1);
            }
        }
    } else {
        posicao = -1;
    }
    return posicao;
}
```
<!-- Executa até acabar todos os elementos possiveis do vetor -->

---

## Busca binária 

Busca o registro academico utilizando uma busca binária, retorna a posição que se encontra o registro academico dentro de um vetor do tipo alunos.

Retorna a posição quando a metade é igual ao elemento procurado, caso ele procure por todo o vetor e não encontre, retornará $-1$.

Vale lembrar que os elementos precisam estar em ordem crescente, caso contrário não funcionará corretamente.
<!-- Realiza a busca por metades dos vetores -->
---

## Pesquisa com busca binária

```c
void Pesquisa(Aluno *vetorAluno, int dimensaoVetor) {
    int registroAcademicoBusca, posicao;
    printf("Insira um numero de registro academico para buscar: ");
    scanf("%d", &registroAcademicoBusca);
    while (registroAcademicoBusca != 0) {
        posicao = BuscaBinaria(vetorAluno, dimensaoVetor, registroAcademicoBusca, 0, dimensaoVetor - 1);

        if (posicao != -1) {
            printf("Registro academico encontrado na posicao %d com o valor %d \n", posicao, registroAcademicoBusca);
            printf("Registro Academico: %d\n", vetorAluno[posicao].registroAcademico);
            for (int j = 0; j < 5; j++) {
                printf("Disciplina: %s\n", vetorAluno[posicao].materias[j].nomeDisciplina);
                printf("Media da disciplina: %f\n", vetorAluno[posicao].materias[j].media);
                printf("Situacao: %s\n\n", vetorAluno[posicao].materias[j].aprovado);
            }
        } else {
            printf("Valor %d nao encontrado\n", registroAcademicoBusca);
        }
        printf("Insira um numero de registro academico para buscar (ou 0 para encerrar): ");
        scanf("%d", &registroAcademicoBusca);
    }
}
```

---
## Especificações dos arquivos do trabalho

Dentro do projeto há dois arquivos do tipo texto:
- "arquivo_correto.txt" contém os dados de entrada para o processamento pelo algoritmo (50 alunos).
- "arquivo_destino.txt" contém os dados de saída do processamento para a sua abertura novamente pelo algoritmo para terminar o processamento.

<!-- Explicar o porque possui dois arquivos -->