#include <stdio.h>
#include "funcionalidades.h"
#include "arvore_avl.h"

// b) Consultas Avançadas
// 1. Listagem de eventos ativos por intervalo de severidade
void listarIntervalo(NO* raiz, int min, int max){
	if (raiz == NULL){
		return;
	}
	listarIntervalo(raiz->esq, min, max);

	if(raiz->status == ATIVO && raiz->nivelSeveridade >= min && raiz->nivelSeveridade <= max) {
		printf("\nID: %d | Tipo: %d | Severidade: %d | Regiao: %d\n", raiz->idEvento, raiz->tipo, raiz->nivelSeveridade, raiz->regiao);
	}
	listarIntervalo(raiz->dir, min, max);
}

// 2. Relatório por região
void relatorioRegiao(NO* raiz, RegiaoCidade regiao){
	if(raiz == NULL){
		return;
	}
	relatorioRegiao(raiz->esq, regiao); 

	if (raiz->regiao == regiao && raiz->status == ATIVO){
		printf("\nID: %d | Severidade: %d | Status: %s\n",
			raiz->idEvento,
			raiz->nivelSeveridade,
			raiz->status == ATIVO ? "Ativo" : "Resolvido"); 
	}
	relatorioRegiao(raiz->dir, regiao);
}

// 3. Busca por intervalo de ID
void listarIntervaloID(NO* raiz, int idMin, int idMax){
	if (raiz == NULL){
		return;
	}
	if (raiz->idEvento > idMin){
		listarIntervaloID(raiz->esq, idMin, idMax);
	}

	if (raiz->idEvento >= idMin && raiz->idEvento <= idMax){
		printf("\nID: %d | Status: %s\n", raiz->idEvento, (raiz->status == ATIVO ? "Ativo" : "Resolvido"));
	}

	if(raiz->idEvento < idMax){
		listarIntervaloID(raiz->dir, idMin, idMax);
	}
}

// c) Operações de Atualização
// 1. Alterar o status de um evento (Ativo -> Resolvido)
void atualizarStatus(NO* raiz, int id){
	NO* no_atualizar = buscarId(raiz, id);

	if (no_atualizar) {
		no_atualizar->status = RESOLVIDO;
		printf("\nEvento de ID: %d resolvido.\n", id);
	} else {
		printf("\nEvento de ID: %d nao encontrado.\n", id);
	}
}

// 2. Atualizar severidade de um evento ativo
void atualizarSeveridade(NO* raiz, int id, int novaSeveridade){
	NO* no_atualizar = buscarId(raiz, id);
	if(no_atualizar && no_atualizar->status == ATIVO){
		no_atualizar->nivelSeveridade = novaSeveridade;
		printf("\nSeveridade, do evento de ID: %d, atualizada com sucesso.\n", id);
	} else {
		printf("\nEvento de ID: %d nao encontrado ou ja resolvido.\n", id);
	}
}

// d) Métricas da Árvore
// 1. Cálculo: Número total de nós
int contarTotalNos(NO* raiz){
	if (raiz == NULL){
		return 0;
	}

	return 1 + contarTotalNos(raiz->esq) + contarTotalNos(raiz->dir);
}

// 2. Cálculo: Número de eventos ativos
int contarEventosAtivos(NO* raiz){
	if (raiz == NULL){
		return 0;
	}

	int cont = (raiz->status == ATIVO) ? 1 : 0;
	return cont + contarEventosAtivos(raiz->esq) + contarEventosAtivos(raiz->dir);
}

// 3. Cálculo: Fator de balanceamento médio da árvore
int somaFatores(NO* raiz) {
	if (raiz == NULL){
		return 0;
	}
	int fb = alturaNO(raiz->esq) - alturaNO(raiz->dir);

	if (fb < 0){
		fb *= -1;
	}

	return fb + somaFatores(raiz->esq) + somaFatores(raiz->dir);
}

float calcularFatorMedio(NO* raiz){
	int total = contarTotalNos(raiz);
	if(total == 0){
		return 0;
	}

	// Converte a soma para decimal antes de dividir pelo total
	return (float)somaFatores(raiz) / total;
}