/*
	Implementação de uma Árvore Binária utilizando alocação dinâmica
	- Criação da Árvore
	- Inserção de elementos
	- Remoção de elementos
	- Acesso aos elementos
	- Destruição da Árvore
*/

#include <stdio.h>
#include <stdlib.h>

// Definindo estrutura do nó da árvore
typedef struct No{
	int valor; // Armazena o valor do nó
	struct No *pai; // Ponteiro para o nó pai (NULL se for Raiz)
	struct No *filho_esq; // Ponteiro para o filho esquerdo (menor nó)
	struct No *filho_dir; // Ponteiro para o filho direito (maior nó)
}

// Estrutura para identificar a raiz
typedef struct Arvore{
	No *raiz; // Ponteiro que sempre aponta para o topo
} Arvore;

// Função criação de Nó (Inicialização)
No* CriarNo(int valor){
	No* novoNo = (No*)malloc(sizeof(No)); // Alocação de memória
	
	// Verifica se a alocação foi bem sucedida
	if (novoNo == NULL){
		printf("Erro: Falha na alocação de memória.");
		exit(1);
	}
	
	// Inicialização para evitar lixo de memória
	novoNo->valor = valor;
	novoNo->pai = NULL;
	novoNo->filho_esq = NULL;
	novoNo->filho_dir = NULL;
	
	return novoNo; // Retorna o endereço de memória do novo Nó
}

// Função criação de estrutura da Árvore
Arvore* criarArvore(){
	Arvore *arvore = (Arvore*)malloc(sizeof(Arvore)); // Alocação de memória
	
	if (arvore != NULL){
		arvore->raiz = NULL
	}
	
	return arvore;	
}

// Função para inserir elementos
void inserir(Arvore *arvore, int valor){
	// Função Criar Nó para alocar novo elemento
	No *novo = criarNo(valor);
	
	// Se a árvore estiver vazia, o primeiro valor inserido será a raiz
	if(arvore->raiz == NULL){
		arvore->raiz = novo;
	} else {
		No *atual = arvore->raiz; // Busca pelo topo
		No *paiAux = NULL; // Ponteiro para salvar quem sera o pai
		
		// Enquanto não chegar ao fim de um ramo
		while(atual != NULL){
			paiAux = atual; // Salva o nó atual antes de descer
			
			if (valor < atual->valor){
				atual = atual->filho_esq; // Se menor, desce para a esquerda
			} else {
				atual = atual->filho_dir; // Se maior, desde para a direita
			}
		}
		
		novo->pai = paiAux; // Conecta o novo nó ao pai
		if (valor < paiAux->valor){
			paiAux->filho_esq = novo;
		} else {
			paiAux->filho_dir = novo;
		}	
}

// Função imprimir árvore


// Função para buscar elementos
No* buscar(Arvore *arvore, int valor){
	No *atual = arvore->raiz; // Iniciando a busca pela raiz
	
	//Percorre enquanto o nó existir e o valor for diferente do buscado
	while (atual != NULL && atual->valor != valor){
		if(valor < atual->valor){ // Se for menor, busca para a esquerda
			atual = atual->filho_esq;
		} else { // Se maiorr, busca para a direita
			atual = atual->filho_dir;
		}
	}
	
	return atual; // Retorna valor indíce ou NULL
}

// Função para remover elementos
void remover(Arvore *arvore, int valor){
	No *valorRemover = buscar(arvore, valor); // Localiza o nó
	
	// Se não existe, sai da função
	if (valorRemover == NULL){
		return;
	}
	
	// CASO 1: No sem filho esquerdo (pode ter ou não o direito)
	if(valorRemover->filho_esq == NULL){
		No *filho = z->direita;
		
		if (valorRemover->pai == NULL){
			arvore->raiz = filho; // Era a raiz
		} else if (valorRemover == valorRemover->pai->filho_esq){
			valorRemover->pai->filho_esq = filho;
		} else {
			valorRemover->pai->filho_dir = filho;
		}
		
		if (filho != NULL){
			filho->pai = valorRemover->pai;
		}
		
		free(valorRemover); // Libera memória do nó deletado
	}
	
	// CASO 2: Nó com apenas filho esquerdo 
	else if (valorRemover->filho_dir == NULL){
		No *filho = valorRemover->filho_esq;
		
		if (valorRemover->pai == NULL){
			arvore->raiz = filho;
		} else if (valorRemover = valorRemover->pai->filho_esq){
			valorRemover->pai->filho_esq = filho;
		} else {
			valorRemover->pai->filho_dir = filho;
		}
		
		if (filho != NULL){
			filho->pai = valorRemover->pai;
		}
		
		free(valorRemover);
	}
	
	// CASO 3: Nó com dois filhos (busca o sucessor substituto)
	else {
		No *sucessor = valorRemover->filho_dir;
		
		while(sucessor->filho_esq != NULL){
			sucessor = sucessor->filho_esq;
		}
		valorRemover->valor = sucessor->valor; 
		
		No *sub = sucessor->filho_dir;
		
		if(sucessor->pai->filho_esq == sucessor){
			sucessor->pai->filho_esq = sub;
		} else {
			sucessor->pai->filho_dir = sub;
		} 
		
		if (sub != NULL){
			sub->pai = sucessor->pai;
		}
		
		free(sucessor);
	}
}

// Função auxiliar recursiva para destruir nós
void destruirNosRecursivo(No *no){
	// Se for NULL, chegamos ao fim
	if (no == NULL){
		return;
	}
	
	destruirNosRecursivo(no->filho_esq); // visita filho da esquerda
	destruirNosRecursivo(no->filho_dir); // visita filgo da direita
	
	free(no); // Libera memória
}

void destruirArvore(Arvore *arvore){
	if (arvore == NULL){
		return;
	}
	
	destruirNosRecursivo(arvore->raiz);
	arvore->raiz = NULL;
	
	free(arvore);
}

int main() {
	Arvore *novaArvore = criarArvore();
	
	inserir(novaArvore, 100);
	inserir(novaArvore, 50);
	inserir(novaArvore, 80);
	inserir(novaArvore, 150);
	inserir(novaArvore, 250);
	
	No *alvo = buscar(novaArvore, 80);
	if (alvo != NULL){
		printf("Valor %d encontrado!\n", alvo->valor);
	} else {
		printf("Valor %d nao encontrado.\n", alvo);
	}
	
	remover(novaArvore, 150);
	
	destruirArvore(novaArvore);
	
	return 0;
}
