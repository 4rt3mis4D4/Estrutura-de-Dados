#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include "estrutura.h"

// b) Consultas Avançadas

//	1. Listagem de eventos ativos por intervalo de severidade
void listarIntervalo(NO* raiz, int min, int max);
//	2. Relatório por região
void relatorioRegiao(NO* raiz, RegiaoCidade regiao);
//	3. Busca por intervalo de ID
void listarIntervaloID(NO* raiz, int idMin, int idMax);

// c) Operações de Atualização

//	1. Alterar o status de um evento (Ativo -> Resolvido)
void atualizarStatus(NO* raiz, int id);
//	2. Atualizar severidade de um evento ativo
void atualizarSeveridade(NO* raiz, int id, int novaSeveridade);

// d) Métricas da Árvore

//	1. Cálculo: Número total de nós
int contarTotalNos(NO* raiz);
//	2. Cálculo: Número de eventos ativos
int contarEventosAtivos(NO* raiz);
//	3. Cálculo: Fator de balanceamento médio da árvore
float calcularFatorMedio(NO* raiz);

#endif