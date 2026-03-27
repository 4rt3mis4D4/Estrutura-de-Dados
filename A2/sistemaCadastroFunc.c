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
No* criarNo(int matricula, char *nome, char *cargo, float salario){
	// Alocação Dinâmica + Teste de erro
	No* novo = (No*)malloc(sizeof(No));
	
	if (novo == NULL){
		printf("ERRO: Falha na alocação de memória do novo nó");
		printf("\nEncerrando...");
		exit(1);
	}
	
	// Inicializando chave + nós informativos
	novo->matricula = matricula;
	strcpy(novo->nome, nome);
	strcpy(novo->cargo, cargo);
	novo->salario = salario;
	
	// Inicializando nós da Árvore Binária
	novo->left = NULL;
	novo->right = NULL;
	
	return novo;
}

Arvore* criarArvore(){
	// Alocação Dinâmica + Teste de erro
	Arvore *arvore = (Arvore*)malloc(sizeof(Arvore));
	
	if (arvore == NULL){
		printf("ERRO: Falha na alocação de memória do novo nó");
		printf("\nEncerrando...");
		exit(1);
	}
	
	// Inicializando raiz
	arvore->raiz = NULL;
	
	return arvore;
}

// 1) INSERÇÃO DE FUNCIONARIO
No* inserirFuncionario(No* raiz, No* novo){
	
	// Se não existir nenhum valor
	if (raiz == NULL){
		return novo;
	}
	
	// Se o valor for menor que o valor da raiz, insere no lado esquerdo
	if (novo->matricula < raiz->matricula){
		raiz->left = inserirFuncionario(raiz->left, novo);
	}
	// Se o valor for maior que o valor da raiz, insere no lado direito
	else{
		raiz->right = inserirFuncionario(raiz->right, novo);
	}
	
	return raiz;
}

// 2) BUSCA DE FUNCIONÁRIO
No* buscarFuncionario(No* raiz, int matricula){
	
	// Verifica se árvore está vazia ou se funcionário existe na árvore
	if(raiz == NULL || raiz->matricula == matricula){
		return raiz;
	}
	
	// Se o valor da matrícula for menor que o nó atual, desce para a esquerda
	if (matricula < raiz->matricula){
		return buscarFuncionario(raiz->left, matricula);
	}
	
	// Se o valor da matrícula for menor que o nó atual, desce para a direita
	return buscarFuncionario(raiz->right, matricula);
}

// 3) ATUALIZAÇÃO DE FUNCIONÁRIO
void atualizarFuncionario(Arvore *arvore, int matricula){
	// Chama função de busca
	No* funcionario = buscarFuncionario(arvore->raiz, matricula);
	
	// Caso encontre: Solicitação de dados novos 
	if (funcionario != NULL){
		printf("\n--- FUNCIONARIO: %s ---\n", funcionario->nome);
		
		getchar(); // Limpa o buffer
		
		printf("Novo nome: ");
		fgets(funcionario->nome, sizeof(funcionario->nome), stdin);
		funcionario->nome[strcspn(funcionario->nome, "\n")] = 0; // Marca o fim da string
		printf("\nNovo Cargo: ");
		fgets(funcionario->cargo, sizeof(funcionario->cargo), stdin);
		funcionario->cargo[strcspn(funcionario->cargo, "\n")] = 0; // Marca o fim da string
		
		printf("\nNovo Salario: R$ ");
		scanf("%f", &funcionario->salario);
		
		printf("\nSucesso: Funcionario de matricula: %d atualizado!\n", matricula);
	} 
	
	// Caso não encontre: Imprimi mensagem de erro
	else { 
		printf("\nERRO: Funcionario nao encontrado para efetuar atualizacao...\n");
	}
}

// 4) EXIBIÇÃO DE FUNCIONÁRIO (In-Ordem: Esquerda -> Raiz -> Direita)
void exibirFuncionarios(No* raiz){
	// Desce até encontrar um nó vazio
	if (raiz != NULL){ 
		exibirFuncionarios(raiz->left); // Explora recursivamente TODA a subárvore esquerda
		
		// Ocorre quando não houver mais ninguém à esquerda para visitar
		printf("Matricula %d | Nome: %s | Cargo: %s | Salario: %.2f\n", 
		raiz->matricula, raiz->nome, raiz->cargo, raiz->salario); 
		
		exibirFuncionarios(raiz->right); // Explora recursivamente TODA a subárvore direita
	}
}

int main(){
	Arvore *empresa = criarArvore(); // Criando Árvore denominada de empresa
	
	// Declarando variáveis (opcao para switch-case | func para funcionario)
	int matricula, opcao;
	char nome[50], cargo[50], func[50];
	float salario;
	
	// Menu do sistema de cadastro de funcionarios
	do{
		printf("\n--- SISTEMA DE CADASTRO DE FUNCIONARIOS ---\n");
		printf("1. Cadastro de Funcionario.\n");
		printf("2. Busca de Funcionario.\n");
		printf("3. Atualizacao de Funcionario.\n");
		printf("4. Exibir Funcionarios.\n");
		printf("0. Sair.\n\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\n--- CADASTRO DE FUNCIONARIO ---\n");
				
				printf("Informe a matricula: ");
				scanf("%d", &matricula);
				
				// Verifica se funcionário ja existe
				if (buscarFuncionario(empresa->raiz, matricula) != NULL) {
        			printf("\nERRO: Matricula ja existente.\n");
    			}
				else {
					getchar(); // Limpando buffer
					
					printf("\nInforme o nome: ");
					fgets(nome, sizeof(nome), stdin);
					nome[strcspn(nome, "\n")] = 0; // Marca o fim da string
			
					printf("\nInforme o cargo: ");
					fgets(cargo, sizeof(cargo), stdin);
					cargo[strcspn(cargo, "\n")] = 0; // Marca o fim da string
					
					printf("\nInforme o valor do salario: R$ ");
					scanf("%f", &salario);
					
					empresa->raiz = inserirFuncionario(empresa->raiz, criarNo(matricula, nome, cargo, salario));
				}
				
				break;
			case 2:
				printf("\n--- BUSCA DE FUNCIONARIO ---\n");
				
				printf("Informe a matricula: ");
				scanf("%d", &matricula);
				
				No* func = buscarFuncionario(empresa->raiz, matricula);
				
				if (func != NULL){
					printf("\nFuncionario encontrado!\n\n");
					
					printf("Nome: %s\n", func->nome);
					printf("Cargo: %s\n", func->cargo);
					printf("Salario: R$ %2.f\n", func->salario);
				} else {
					printf("\nFuncionario nao encontrado.\n");
				}
				
				break;
			case 3:
				printf("\n--- ATUALIZACAO DE FUNCIONARIO ---\n");
				
				printf("Digite a matricula do funcionario: ");
				scanf("%d", &matricula);
				
				atualizarFuncionario(empresa, matricula);
				
				break;
			case 4:
				printf("\n--- EXIBIR FUNCIONARIO (CRESCENTE)---\n");
				exibirFuncionarios(empresa->raiz);
				break;
			case 0:
				printf("\nSaindo do sistema...");
				break;
			default:
				printf("\nOpcao invalida.");
		}
	} while (opcao!=0);
	
	return 0;
}
