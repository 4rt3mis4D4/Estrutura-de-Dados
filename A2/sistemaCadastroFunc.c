// Sistema de Cadastro de Funcionários Utilizando Árvore Binária de Pesquisa
// Aluna: Gabriela Pedroso - 26/03/2026 (Ciência da Computação)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- DETALHES DO SISTEMA ---
typedef struct No{
	int matricula; // Valor chave
	char nome[50];
	char cargo[50];
	float salario;
	struct No *left; // Nó filho á esquerda
	struct No *right; // Nó filho á direita
}No;

// Estrutura da árvore para identificar facilmente a raiz
typedef struct Arvore{
	No *raiz;
} Arvore;

// Funções de Inicialização: criação da estrutura de Nó e Árvore
No* criarNo(int *matricula, char *nome, char *cargo, float *salario){
	// Alocação Dinâmica + Teste de erro
	No* novo = (No*)malloc(sizeof(No));
	
	if (novo == NULL){
		printf("ERRO: Falha na alocação de memória do novo nó");
		printf("\nEncerrando...")
		exit(1);
	}
	
	// Inicializando chave + nós informativos
	novo->matricula = matricula;
	strcpy(novo->nome = nome);
	strcpy(novo->cargo = cargo);
	novo->salario = salario;
	
	// Inicializando nós da Árvore Binária
	novo->left = NULL;
	novo->right = NULL;
}

Arvore* criarArvore(){
	// Alocação Dinâmica + Teste de erro
	Arvore *arv = (Arvore*)malloc(sizeof(Arvore));
	
	if (arv == NULL){
		printf("ERRO: Falha na alocação de memória do novo nó");
		printf("\nEncerrando...")
		exit(1);
	}
	
	// Inicializando raiz
	arv->raiz = NULL;
	
	return arvore;
}
