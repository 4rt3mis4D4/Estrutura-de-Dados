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
	Arvore *arvore = (Arvore*)malloc(sizeof(Arvore));
	
	if (arvore == NULL){
		printf("ERRO: Falha na alocação de memória do novo nó");
		printf("\nEncerrando...")
		exit(1);
	}
	
	// Inicializando raiz
	arvore->raiz = NULL;
	
	return arvore;
}

// 1) INSERÇÃO DE FUNCIONARIO
void inserirFuncionario(No* raiz, No* novo){
	// Chamandao função criarNo para alocar novo elemento
	No *novo = criarNo(valor);
	
	// Se não existir nenhum valor
	if (raiz == NULL){
		return novo;
	}
	// Se o valor for menor que o valor da raiz
	else if (novo->matricula < raiz->matricula){
		raiz->left = inserirFuncionario(raiz->left, novo);
	}
	// Se o valor for maior que o valor da raiz
	else if(novo->matricula > raiz->matricula){
		raiz->right = inserirFuncionario(raiz->right, novo);
	}
	// Se a matrícula ja existir
	else {
		printf("ERRO: Matrícula ja existente.");
		free(novo); // Exclui - Libera memória
	}
	
	return raiz;
}

// 3) BUSCA DE FUNCIONÁRIO
No* burcarFuncionario(No* raiz, int matricula){
	if(raiz == NULL || raiz->matricula = matricula){
		return raiz;
	}
	
	if (matricula < raiz->matricula){
		return buscarFuncionario(raiz->left, matricula);
	}
	
	return buscarFuncionario(raiz->right, matricula);
}

// 2) ATUALIZAÇÃO DE FUNCIONÁRIO
void atualizarFuncionario(Arvore *arvore, int matricula){
	// Chama função de busca
	No* funcionario = buscarFuncionario(arvore->raiz, matricula);
	
	// Caso encontre: Solicitação de dados novos 
	if (funcionario != NULL){
		printf("\n--- FUNCIONARIO: %s---", funcionario->nome);
		
		printf("Novo nome: ");
		scanf("%s", funcionario->nome);
		printf("Novo Cargo: ");
		scanf("%s", funcionario->cargo);
		printf("Novo Salario: ");
		scanf("%f", funcionario->salario);
		
		printf("\nSucesso: Funcionário de matricula: %s atualizado!", matricula);
	} else {
		printf("\nERRO: Funcionário não encontrado para efetuar atualização...");
	}
}

// 4) EXIBIÇÃO DE FUNCIONÁRIO (In-Ordem: Esquerda -> Raiz -> Direita)
void exibirFuncionario(No* raiz){
	if (raiz != NULL){ // Desce até encontrar um nó vazio
		exibirFuncionario(raiz->left); // Explora recursivamente TODA a subárvore esquerda
		printf("Matricula %d | Nome: %-15s | Cargo: -15%s | Salario: %2.f", 
		raiz->matricula, raiz->nome, raiz->cargo, raiz->salario); // Ocorre quando não houver mais ninguém à esquerda para visitar
		exibirFuncionario(raiz->right); // Explora recursivamente TODA a subárvore direita
	}
}

int main(){
	Arvore *funcionarios = criarArvore();
	int matricula;
	char nome[50];
	char cargo[50];
	float salario;
	
	int op;
	
	do{
		printf("\n--- SISTEMA DE CADASTRO DE FUNCIONARIOS ---\n");
		printf("1. Cadastrar Funcionario Novo.\n");
		printf("2. Busca de Funcionario.\n");
		printf("3. ")
	} while (op!=0);
	
	return 0;
}




