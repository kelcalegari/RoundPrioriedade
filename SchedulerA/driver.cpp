/**
 * Aluno Kelvynn Bordin Calegari
 * Scheduler Round-Robin com Prioriedade
 *
 */

#include <chrono>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "task.h"
#include "list.h"
#include "schedule_rr.h"




int main()
{
    std::string nomeArquivo = "rr-schedule_pri.txt";
    std::string linha;

    std::string name;
    int priority;
    int burst;

    iniciar();//Inicia as filas de tarefas para execução

    std::ifstream arquivo(nomeArquivo);


    if (arquivo.is_open()) {
        int tid = 1;
        while (!arquivo.eof()) {
            std::getline(arquivo, linha);
            
            std::string temp = "";
            int op = 0;
            for (size_t i = 0; i < linha.length(); i++)
            {
                char charAtual = linha.at(i);
                if (charAtual == ',')
                {
                    switch (op)
                    {
                    case 0:
                        
                        name = temp;
                        temp = "";
                        op++;
                        break;
                    case 1:
                        
                        priority = stoi(temp);
                        temp = "";
                        op++;
                        break;
   
                    default:
                        break;
                    }
                }
                else {
                    temp = temp + charAtual;
                }
                
            }
 
            burst = stoi(temp);
            add(name,tid, priority, burst);
            tid++;
        }
        
    }
    else {
        std::cout << "Não foi possivel abrir o arquivo!!";


    }
    arquivo.close();

    // invoke the scheduler
    
    schedule();
   
    

    return 0;
}
