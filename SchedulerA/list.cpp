/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"
#include <iostream>



void iniciaFila(Tfila& fila)
{
	fila.primeiro = nullptr;
}


PElemento* criarElementoFila(Task arquivo)
{
	PElemento* novo = new PElemento;
	novo->dado = arquivo;
	novo->proximo = nullptr;
	return novo;
}


void queue(Tfila& fila, Task arquivo)
{
	PElemento* novo = criarElementoFila(arquivo);
	if (fila.primeiro == nullptr)
	{
		fila.primeiro = novo;
	}
	else
	{
		PElemento* nav = fila.primeiro;


		while (nav->proximo != nullptr)
		{
			nav = nav->proximo;
		}
		nav->proximo = novo;
	}


}


Task dequeue(Tfila& fila)
{
	Task devolver;
	if (fila.primeiro != nullptr)
	{
		devolver = fila.primeiro->dado;
		PElemento* apagar = fila.primeiro;
		fila.primeiro = fila.primeiro->proximo;
		delete apagar;
		apagar = 0;
		return devolver;

	}
	else
	{
		throw "\n Não existe elemento para remover";

	}

}


int quantosElementos(Tfila fila)
{
	int contador = 0;
	for (PElemento* navegando = fila.primeiro; navegando != nullptr; navegando = navegando->proximo)
	{
		contador++;
	}
	return contador;
}


void destroiFila(Tfila& fila)
{

	for (int tamanhoFila = quantosElementos(fila); tamanhoFila > 0; tamanhoFila--)
	{
		dequeue(fila);
	}
}


bool temElementos(Tfila fila)
{
	if (fila.primeiro == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool estanaFila(Tfila fila, Task arquivo)
{
	for (PElemento* navegando = fila.primeiro; navegando != nullptr; navegando = navegando->proximo)
	{
		if (navegando->dado.name == arquivo.name)
		{
			return true;
		}
	}
	return false;
}


bool posicaovalido(Tfila fila, int posicao)
{
	if (posicao < quantosElementos(fila) and posicao >= 0)
	{
		return true;
	}
	return false;
}


Task pegaElemento(Tfila fila)
{
	return fila.primeiro->dado;
}


void imprimir(Tfila fila)
{
	std::cout << "\n\n Imprimindo fila: \n   ";
	for (PElemento* navegando = fila.primeiro; navegando != nullptr; navegando = navegando->proximo)
	{
		std::cout << navegando->dado.name << " - ";
	}

}
