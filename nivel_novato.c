//================================
// Nivel Novato - Joogo War
// Objetivo: Implementar o cadastro e listagem de 5 territórios usando um array estático.
// Foco em structs, entrada/saída de dados e organização básica.
//Criar uma struct chamada Territorio que armazenará informações como nome, cor do exército e quantidade de
//tropas. O sistema permitirá o cadastro de 5 territórios e exibirá seus dados logo após o preenchimento.
//Entrada dos dados: utilize um laço for para preencher os dados dos 5 territórios.
//Definir uma struct chamada Territorio com os campos char nome[30], char cor[10] e int tropas.
//================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 10

// --- Definição de Structs ---
typedef struct {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
} Territorio;

// --- Função para limpar o buffer de entrada ---
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal ---
int main() {
    Territorio territorios[MAX_TERRITORIOS];

    // Entrada dos dados dos territórios
    printf("=== CADASTRO DE TERRITÓRIOS ===\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Cadastrando Território %d: \n", i + 1);
        printf("Nome do território: \n");
        fgets(territorios[i].nome, TAM_NOME, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // Remove o newline

        printf("Cor do exército (ex: Azul, Verde): \n");
        fgets(territorios[i].cor, TAM_COR, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0'; // Remove o newline

        printf("Quantidade de tropas: \n");
        scanf("%d", &territorios[i].tropas);
        limparBuffer(); // Limpa o buffer após ler a quantidade de tropas
    }

    // Exibição dos dados dos territórios
    printf("\n=== DADOS DOS TERRITÓRIOS ===\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf(" - Nome: %s\n", territorios[i].nome);
        printf(" - Dominado por: Exército %s\n", territorios[i].cor);
        printf(" - Número de Tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}