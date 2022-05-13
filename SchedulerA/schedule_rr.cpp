#include "schedule_rr.h"
#include <chrono>
#include "list.h"
#include "task.h"
#include "CPU.h"



Tfila TaskList_1;
Tfila TaskList_2;
Tfila TaskList_3;
Tfila TaskList_4;
Tfila TaskList_5;
Tfila TaskList_6;
Tfila TaskList_7;
Tfila TaskList_8;
Tfila TaskList_9;
Tfila TaskList_10;


void iniciar() {
	iniciaFila(TaskList_1);
	iniciaFila(TaskList_2);
	iniciaFila(TaskList_3);
	iniciaFila(TaskList_4);
	iniciaFila(TaskList_5);
	iniciaFila(TaskList_6);
	iniciaFila(TaskList_7);
	iniciaFila(TaskList_8);
	iniciaFila(TaskList_9);
	iniciaFila(TaskList_10);
}
//Adicionando a tarefa na lista de executados;
void add(std::string name,int tid, int priority, int burst)
{
	Task temp;
	temp.name = name;
	temp.tid = tid;
	temp.priority = priority;
	temp.burst = burst;

	//É adicionado ao fim da fila da sua prioriedade;
	switch (priority)
	{
	case 1:
		queue(TaskList_1, temp);
		break;
	case 2:
		queue(TaskList_2, temp);
		break;
	case 3:
		queue(TaskList_3, temp);
		break;
	case 4:
		queue(TaskList_4, temp);
		break;
	case 5:
		queue(TaskList_5, temp);
		break;
	case 6:
		queue(TaskList_6, temp);
		break;
	case 7:
		queue(TaskList_7, temp);
		break;
	case 8:
		queue(TaskList_8, temp);
		break;
	case 9:
		queue(TaskList_9, temp);
		break;
	case 10:
		queue(TaskList_10, temp);
		break;
	default:
		throw "\n Erro: prioriedade inexistente";
		break;
	}
	
}


// invoke the scheduler
void schedule(){
	// Variável que define a quantidade de ciclos que o processo tem acesso interupto a CPU, antes da mudança de contexto;
	int quantum = 8;
	// Variável para contar quantos ciclos foi utilizado nessa tarefa;
	int cont = 0;

	// Vai ser executado primeiro as filas de acordo com a sua prioriedade sendo a 1 de maior e 10 de menor;
	for (size_t i = 1; i <= 10; i++)
	{
		switch (i)
		{
		case 1:
			//Se tem elementos a ser executado continua o loop
			while (temElementos(TaskList_1))
			{
				Task atual = dequeue(TaskList_1);
				if (atual.iniciou == false) {
					//Informa qual foi cont onde a tarefa começou para posterior análise;
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				else
				{
					//Informa qual foi cont onde a tarefa já iniciada voltou a ser executada para posterior análise;
					std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				//Informa que essa tarefa já inciou(variavel criada somente para teste);
				atual.iniciou = true;
				int j = 1;
				//executa a tarefa até finalizar o burst ou mudança de contexto;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}

				//Se a tarefa não finalizou ela volta na final da fila;
				if (atual.burst != 0)
				{
					queue(TaskList_1, atual);

				}
				else {
					//Informa em qual momento a tarefa foi finalizada para análise;
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		case 2:
			while (temElementos(TaskList_2))
			{
				Task atual = dequeue(TaskList_2);
				if (atual.iniciou == false) {
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;" ;
				}
				else
				{
					//std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;" ;
				}
				atual.iniciou = true;
				int j = 1;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}
				if (atual.burst != 0)
				{
					queue(TaskList_2, atual);

				}
				else {
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		case 3:
			while (temElementos(TaskList_3))
			{
				Task atual = dequeue(TaskList_3);
				if (atual.iniciou == false) {
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				else
				{
					std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				atual.iniciou = true;
				int j = 1;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}
				if (atual.burst != 0)
				{
					queue(TaskList_3, atual);

				}
				else {
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		case 4:
			while (temElementos(TaskList_4))
			{
				Task atual = dequeue(TaskList_4);
				if (atual.iniciou == false) {
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				else
				{
					std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				atual.iniciou = true;
				int j = 1;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}
				if (atual.burst != 0)
				{
					queue(TaskList_4, atual);

				}
				else {
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		case 5:
			while (temElementos(TaskList_5))
			{
				Task atual = dequeue(TaskList_5);
				if (atual.iniciou == false) {
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				else
				{
					std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				atual.iniciou = true;
				int j = 1;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}
				if (atual.burst != 0)
				{
					queue(TaskList_5, atual);

				}
				else {
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		case 6:
			while (temElementos(TaskList_6))
			{
				Task atual = dequeue(TaskList_6);
				if (atual.iniciou == false) {
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				else
				{
					std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				atual.iniciou = true;
				int j = 1;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}
				if (atual.burst != 0)
				{
					queue(TaskList_6, atual);

				}
				else {
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		case 7:
			while (temElementos(TaskList_7))
			{
				Task atual = dequeue(TaskList_7);
				if (atual.iniciou == false) {
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				else
				{
					std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				atual.iniciou = true;
				int j = 1;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}
				if (atual.burst != 0)
				{
					queue(TaskList_7, atual);

				}
				else {
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		case 8:
			while (temElementos(TaskList_8))
			{
				Task atual = dequeue(TaskList_8);
				if (atual.iniciou == false) {
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				else
				{
					std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				atual.iniciou = true;
				int j = 1;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}
				if (atual.burst != 0)
				{
					queue(TaskList_8, atual);

				}
				else {
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		case 9:
			while (temElementos(TaskList_9))
			{
				Task atual = dequeue(TaskList_9);
				if (atual.iniciou == false) {
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				else
				{
					std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				atual.iniciou = true;
				int j = 1;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}
				if (atual.burst != 0)
				{
					queue(TaskList_9, atual);

				}
				else {
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		case 10:
			while (temElementos(TaskList_10))
			{
				Task atual = dequeue(TaskList_10);
				if (atual.iniciou == false) {
					std::cout << std::endl << " Iniciando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				else
				{
					std::cout << std::endl << " Executanto Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				atual.iniciou = true;
				int j = 1;
				while ((j <= quantum) and (atual.burst > 0)) {
					run(atual, j);
					cont++;
					j++;
					atual.burst--;
				}
				if (atual.burst != 0)
				{
					queue(TaskList_10, atual);

				}
				else {
					std::cout << std::endl << " Finalizando Task:" << atual.name << " Burst: " << atual.burst << " Prioriedade: " << atual.priority << ": " << cont << " contagem;";
				}
				

			}
			break;
		default:
			throw "\n Erro: prioriedade inexistente";
			break;
		}
	}


	// Informa qual foi cont onde todas as tarefas terminaram para posterior análise;
	std::cout << "\n Duracao " << cont << " contagem" << std::endl;
}
