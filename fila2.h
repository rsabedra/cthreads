
/********************************************************************

	Biblioteca de Filas
	Vers. 1.0 - 3/3/16

********************************************************************/

#ifndef	__FILA2_H__
#define	__FILA2_H__

struct	sFilaNode2 {
	void 	*node;			// Ponteiro para a estrutura de dados do NODO
	struct	sFilaNode2 *ant;	// Ponteiro para o nodo anterior
	struct	sFilaNode2 *next;	// Ponteiro para o nodo posterior
};
struct sFila2 {
	struct	sFilaNode2 *it;		// Iterador para varrer a lista
	struct	sFilaNode2 *first;	// Primeiro elemento da lista
	struct	sFilaNode2 *last;	// Último elemento da lista
};

typedef struct sFilaNode2	NODE2;
typedef struct sFila2		FILA2;
typedef struct sFilaNode2 *	PNODE2;
typedef struct sFila2 *		PFILA2;

/*-------------------------------------------------------------------
Função:	Inicializa uma estrutura de dados do tipo FILA2
Ret:	==0, se conseguiu
	!=0, caso contrário (erro ou fila vazia)
-------------------------------------------------------------------*/
int	CreateFila2(PFILA2 pFila)
{
    // pFila = (PFILA2)malloc(sizeof(struct sFila2));
    pFila->it = 0;
    pFila->first = 0;
    pFila->last = 0;

    return 0;
}


/*-------------------------------------------------------------------
Função:	Seta o iterador da fila no primeiro elemento
Ret:	==0, se conseguiu
	!=0, caso contrário (erro ou fila vazia)
-------------------------------------------------------------------*/
int	FirstFila2(PFILA2 pFila)
{
    if(pFila->first == 0)
    {
        return -1;
    }
    pFila->it = pFila->first;
    return 0;
}

/*-------------------------------------------------------------------
Função:	Seta o iterador da fila no último elemento
Ret:	==0, se conseguiu
	!=0, caso contrário (erro ou fila vazia)
-------------------------------------------------------------------*/
int	LastFila2(PFILA2 pFila)
{
    if(pFila->last == 0)
    {
        return -1;
    }
    pFila->it = pFila->last;
    return 0;
}

/*-------------------------------------------------------------------
Função:	Seta o iterador da fila para o próximo elemento
Ret:	==0, se conseguiu
	!=0, caso contrário (erro, fila vazia ou chegou ao final da fila)
-------------------------------------------------------------------*/
int	NextFila2(PFILA2 pFila)
{
    struct sFila2 * te = pFila;
    if(pFila->it == 0)
    {
        pFila->it = 0;
        return -1;
    }
    if(pFila->it->next == 0)
    {
        pFila->it = 0;
        return -1;
    }
    if(pFila->first == pFila->last && pFila->first == pFila->it)
    {
        pFila->it = 0;
        return -1;
    }
    pFila->it = pFila->it->next;

    return 0;
}

/*-------------------------------------------------------------------
Função:	Retorna o conteúdo do nodo endereçado pelo iterador da lista "pFila"
Ret:	Ponteiro válido, se conseguiu
	NULL, caso contrário (erro, lista vazia ou iterador invalido)
-------------------------------------------------------------------*/
void 	*GetAtIteratorFila2(PFILA2 pFila)
{
    if(pFila->it == 0)
    {
        return -1;
    }
    return pFila->it->node;
}

/*-------------------------------------------------------------------
Função:	Coloca o ponteiro "content" no final da fila "pFila"
Ret:	==0, se conseguiu
	!=0, caso contrário (erro)
-------------------------------------------------------------------*/
int	AppendFila2(PFILA2 pFila, void *content)
{
    NODE2* node = (NODE2*)malloc(sizeof(NODE2));
    node->node = content;
    node->next = 0;

    struct sFila2 * te = pFila;
    if(pFila->last != 0) pFila->last->next = node;

    node->ant = pFila->last;
    pFila->last = node;
    if(pFila->first == 0) pFila->first = node;

    return 0;
}

/*-------------------------------------------------------------------
Função:	Coloca o ponteiro "content" logo após o elemento
	correntemente apontado pelo iterador da fila "pFila"
Ret:	==0, se conseguiu
	!=0, caso contrário (erro)
-------------------------------------------------------------------*/
int	InsertAfterIteratorFila2(PFILA2 pFila, void *content)
{
    NODE2* node = (NODE2*)malloc(sizeof(NODE2));
    node->node = content;
    node->next = pFila->it->next;
    node->ant = pFila->it->ant;
    pFila->it->next->ant = node;
    pFila->it->ant->next = node;
    pFila->it = node;

    return 0;
}

/*-------------------------------------------------------------------
Função:	Remove o elemento indicado pelo iterador, da lista "pFila"
Ret:	==0, se conseguiu
	!=0, caso contrário (erro)
-------------------------------------------------------------------*/
int	DeleteAtIteratorFila2(PFILA2 pFila)
{
    struct sFila2* te = pFila;

    NODE2* node = pFila->it;

    if(node == 0)
    {
        return -1;
    }

    pFila->it = pFila->first;

    if(pFila->first == node)
    {
        pFila->first = node->next;
        pFila->it = pFila->first;
    }

    if(pFila->last == node)
    {
        pFila->last = node->ant;
        pFila->it = pFila->last;
    }

    if(node->ant != 0) node->ant->next = node->next;
    if(node->next != 0) node->next->ant = node->ant;
    if(pFila->first == pFila->last && pFila->first == 0)
    {
        pFila->it = 0;
    }

    free(node);

    return 0;
}


#endif




