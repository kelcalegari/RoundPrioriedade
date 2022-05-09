#include "schedule_rr.h"

#include "list.h"
#include "task.h"
#include "CPU.h"

Tfila TaskList;

void iniciar() {
	iniciaFila(TaskList);
}

void add(std::string name, int priority, int burst)
{
	Task temp = {name,priority,burst};
	queue(TaskList,temp);
}

// invoke the scheduler
void schedule(){

	int quantum = 8;//Tamanho do processo max

	while (temElementos(TaskList))
	{
		Task atual = dequeue(TaskList);
		int i = 0;
		while ((i < quantum) and (atual.burst > 0)) {
			run(atual, i);
			i++;
			atual.burst--;
		}
		if (atual.burst != 0)
		{
			queue(TaskList, atual);

		}

	}

}
