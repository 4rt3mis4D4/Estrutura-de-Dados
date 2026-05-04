#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura Mínima do nó 

// Enumns: Tipo do Evento, Região da Cidade e Status
 
typedef enum { 	ACIDENTE_TRANSITO, 
				FALHAS_SEMAFORO, 
				INTERRUPCOES_ENERGIA, 
				ALAGAMENTOS, 
				INCENDIOS
} TipoEvento;

typedef enum { NORTE, SUL, LESTE, OESTE, CENTRO} RegiaoCidade;
typedef enum { ATIVO, RESOLVIDO} StatusEvento;

// Structs: Data/Hora do Registro + Nó

typedef struct {
	int dia, mes, ano;
	int hora, minuto;
} DataHoraRegistro;

typedef struct NO {
	int idEvento; // chave primária da AVL
	
	TipoEvento tipo;
	int nivelSeveridade; // 1 a 5
 	DataHoraRegistro dataHora; 
	RegiaoCidade regiao; 
	StatusEvento status;
	 
	int altura; 
	struct NO *esq; // ponteiro esquerdo
	struct NO *dir; // ponteiro direito
} NO;

#endif