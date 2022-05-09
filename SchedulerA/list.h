/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

struct PElemento
{
	Task dado;
	PElemento* proximo;
};

struct Tfila
{
	PElemento* primeiro;
};


// insert and delete operations.
void iniciaFila(Tfila& fila);
PElemento* criarElementoFila(Task arquivo);
void queue(Tfila& fila, Task arquivo);
Task dequeue(Tfila& fila);
int quantosElementos(Tfila fila);
void destroiFila(Tfila& fila);
bool temElementos(Tfila fila);
bool estanaFila(Tfila fila, Task arquivo);
bool posicaovalido(Tfila fila, int posicao);
Task pegaElemento(Tfila fila);
void imprimir(Tfila fila);
