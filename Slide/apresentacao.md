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

Retorna a posição quando a metade é igual ao elemnto procurado, caso ele procure por todo o vetor e não encontre, retornará $-1$.

<!-- Realiza a busca por metades dos vetores -->
---

## Especificações dos arquivos do trabalho

Dentro do projeto há dois arquivos do tipo texto:
- "arquivo_correto.txt" contém os dados de entrada para o processamento pelo algoritmo.
- "arquivo_destino.txt" contém os dados de saída do processamento para a sua abertura novamente pelo algoritmo para terminar o processamento.

<!-- Explicar o porque possui dois arquivos -->