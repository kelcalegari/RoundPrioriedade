/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
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
    std::string nomeArquivo = "rr-schedule.txt";
    std::string linha;

    std::string name;
    int priority;
    int burst;

    iniciar();//Inicia as filas de tarefas para execução

    std::ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        while (!arquivo.eof()) {
            std::getline(arquivo, linha);
            std::cout << "\n Linha: " + linha;
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
                        std::cout << "\n nome: " + temp;
                        name = temp;
                        temp = "";
                        op++;
                        break;
                    case 1:
                        std::cout << "\n priority: " + temp;
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
            std::cout << "\n bust: " + temp;
            burst = stoi(temp);
            add(name, priority, burst);
        }
        
    }
    else {
        std::cout << "Não foi possivel abrir o arquivo!!";


    }
    arquivo.close();

    // invoke the scheduler
    auto start = std::chrono::high_resolution_clock::now();
    schedule();
    auto end = std::chrono::high_resolution_clock::now();
    auto int_s = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Duracao " << int_s.count() << " milissegundos" << std::endl;

    return 0;
}
