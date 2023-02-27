#include "Horta.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "arrays_string.h"

 // na horta.h #include "Armazem.h" ,  Prosuto.h

using namespace std;

horta criar_horta(std::string areas[],int tamanho_areas, char id) {
    
    horta h;
    int indice_areas = rand() % tamanho_areas;
    h.area = areas[indice_areas];
    h.capacidade = 3 + rand() % 6;
    h.nome = id;
    string responsavel="";
    cout << "Escreva o nome do responsavel da horta "<<id<<" ." << endl;
    getline(cin, responsavel);
    h.responsavel = responsavel;
    return h;
}

void inicializar_plantacao(horta plantacao[], std::string areas[], int tamanho_areas, const char id[], int capacidade_hortas) {
    for (int i = 0; i < capacidade_hortas; i++) {
        plantacao[i] = criar_horta(areas, tamanho_areas, id[i]);
    }
}

void escrever_plantacao(horta plantacao[], int capacidade_hortas) {
    for (int i = 0; i < capacidade_hortas; i++) {
        cout << "Horta:" << plantacao[i].nome << " | Responsavel: " << plantacao[i].responsavel << " | Capacidade: " << plantacao[i].capacidade << " | Produtos: " << plantacao[i].n_plantados << " | Area: " << plantacao[i].area << endl;
        for (int j = 0; j < plantacao[i].n_plantados; j++)
        {
            cout << "Produto: " << plantacao[i].ary_plantados[j].nome << " | Rega : " << plantacao[i].ary_plantados[j].tempo_rega << " | Resistencia: " << plantacao[i].ary_plantados[j].resistência << " | Tempo: " << plantacao[i].ary_plantados[j].tempo_plantação << endl;
        
        }
        cout << "-------------------------" << endl;
    }
}

int procurar_id(horta plantacao[], int capacidade_hortas, char id_escolhido) {
    int indice = 0;
    for (int i = 0; i < capacidade_hortas; i++)
    {
        if (plantacao[i].nome == id_escolhido) indice = i;
    }
    return indice;
}

void guardar_array_colhidos(horta plantacao[], std::string nome, int capacidade_hortas) {
    fstream colhidos;
    colhidos.open(nome, fstream::out);
    int i = 0;
    if (colhidos.is_open()) {
        while (i < capacidade_hortas) {
            colhidos << plantacao[i].nome << endl;
            for (int j = 0; j < plantacao[i].n_colhidos; j++)
            {
                colhidos << plantacao[i].ary_colhidos[j].nome << " , " << plantacao[i].ary_colhidos[j].tempo_rega << " , " << plantacao[i].ary_colhidos[j].resistência << " , " << plantacao[i].ary_colhidos[j].area << " , " << plantacao[i].ary_colhidos[j].tempo_plantação << " , " << plantacao[i].ary_colhidos[j].fornecedor << endl;
            }
            colhidos << "" << endl;
            i++;
        }
    }
    colhidos.close();

}

void gravar_plantacao(horta plantacao[], std::string nome, std::string diretorio_colhidos, int capacidade_hortas) {
    fstream f_plantacao;
    f_plantacao.open(nome, fstream::out);
    int i = 0;
    if (f_plantacao.is_open()) {
        guardar_array_colhidos(plantacao, diretorio_colhidos, capacidade_hortas);
        while (i < capacidade_hortas) {
            f_plantacao << plantacao[i].nome << " , " << plantacao[i].responsavel << " , " << plantacao[i].capacidade << " , " << plantacao[i].area << " , " << plantacao[i].n_plantados << " , " << plantacao[i].n_colhidos << " , " << plantacao[i].campanha << " , " << plantacao[i].duracao << endl;
            for (int j = 0; j < plantacao[i].n_plantados; j++) {
                f_plantacao << plantacao[i].ary_plantados[j].nome << " , " << plantacao[i].ary_plantados[j].tempo_rega << " , " << plantacao[i].ary_plantados[j].resistência << " , " << plantacao[i].ary_plantados[j].area << " , " << plantacao[i].ary_plantados[j].tempo_plantação << " , " << plantacao[i].ary_plantados[j].fornecedor << endl;
            }
            f_plantacao << "" << endl;
            i++;
        }
    }
}

void import_plantacao(std::string nome, horta v[], int capacidade) {
    fstream plantacao;
    string line;
    char c;
    char ID;
    string responsavel = "";
    int capacidade_da_horta = 0;
    string area = "";
    int n_plantados = 0;
    int n_colhidos = 0;
    int duracao = 0;
    int i = 0;
    string produto = "";
    int resistencia = 0;
    int tempo_plantacao = 0;
    int tempo_rega = 0;
    string fornecedor = "";
    int j = 0;
    bool campanha=0;

    Produto novo;

    plantacao.open(nome, ifstream::in);
    if (plantacao.is_open()) {
        while (i < capacidade) {
            getline(plantacao, line);
            if (line == "") {
                continue;
            }

            ID = line.substr(0, line.find(',') - 1)[0];
            line = line.substr(line.find(',') + 2, line.length() - 1);
            responsavel = line.substr(0, line.find(',') - 1);
            line = line.substr(line.find(',') + 2, line.length() - 1);
            capacidade_da_horta = stoi(line.substr(0, line.find(',')));
            line = line.substr(line.find(',') + 2, line.length() - 1);
            area = line.substr(0, line.find(',') - 1);;
            line = line.substr(line.find(',') + 2, line.length() - 1);
            n_plantados = stoi(line.substr(0, line.find(',')));
            line = line.substr(line.find(',') + 2, line.length() - 1);
            n_colhidos = stoi(line.substr(0, line.find(',')));
            line = line.substr(line.find(',') + 2, line.length() - 1);
            campanha = stoi(line.substr(0, line.find(',')));
            line = line.substr(line.find(',') + 2, line.length() - 1);
            duracao = stoi(line.substr(0, line.find(',')));
            line = line.substr(line.find(',') + 2, line.length() - 1);
            v[i].nome = ID;
            v[i].responsavel = responsavel;
            v[i].capacidade = capacidade_da_horta;
            v[i].area = area;
            v[i].n_colhidos = n_colhidos;
            v[i].campanha = campanha;
            v[i].duracao = duracao;
            j = 0;
            while (true)
            {
                if (j == capacidade_da_horta || j == n_plantados) {
                    break;
                };
                getline(plantacao, line);
                produto = line.substr(0, line.find(',') - 1);
                line = line.substr(line.find(',') + 2, line.length() - 1);
                tempo_rega = stoi(line.substr(0, line.find(',')));;
                line = line.substr(line.find(',') + 2, line.length() - 1);
                resistencia = stoi(line.substr(0, line.find(',')));;
                line = line.substr(line.find(',') + 2, line.length() - 1);
                area = line.substr(0, line.find(',') - 1);;
                line = line.substr(line.find(',') + 2, line.length() - 1);
                tempo_plantacao = stoi(line.substr(0, line.find(',')));;
                line = line.substr(line.find(',') + 2, line.length() - 1);
                fornecedor = line;

                inserir(v[i].ary_plantados,j, novo, v[i].n_plantados);
                v[i].n_plantados++;
                
                v[i].ary_plantados[j].nome = produto;
                v[i].ary_plantados[j].tempo_rega = tempo_rega;
                v[i].ary_plantados[j].resistência = resistencia;
                v[i].ary_plantados[j].area = area;
                v[i].ary_plantados[j].tempo_plantação = tempo_plantacao;
                v[i].ary_plantados[j].fornecedor = fornecedor;

                j++;


            }

            i++;
        }

    }
    plantacao.close();
}

void import_colhidos(std::string nome, horta v[], int capacidade) {
    fstream colhidos;
    int i = 0;
    int j = 0;
    char ID;
    int n_colhidos = 0;
    string line = "";
    string produto = "";
    string area = "";
    string fornecedor = "";
    int tempo_rega = 0;
    int resistencia = 0;
    int tempo_plantacao = 0;

    Produto novo;

    colhidos.open(nome, fstream::in);
    if (colhidos.is_open()) {
        while (i < capacidade)
        {
            getline(colhidos, line);
            if (line == "") {
                continue;
            }
            ID = line[0];
            j = 0;
            n_colhidos=0;
            while (true)
            {
                if (j == v[i].n_colhidos) {
                    break;
                };
                getline(colhidos, line);
                produto = line.substr(0, line.find(',') - 1);
                line = line.substr(line.find(',') + 2, line.length() - 1);
                tempo_rega = stoi(line.substr(0, line.find(',')));;
                line = line.substr(line.find(',') + 2, line.length() - 1);
                resistencia = stoi(line.substr(0, line.find(',')));;
                line = line.substr(line.find(',') + 2, line.length() - 1);
                area = line.substr(0, line.find(',') - 1);;
                line = line.substr(line.find(',') + 2, line.length() - 1);
                tempo_plantacao = stoi(line.substr(0, line.find(',')));;
                line = line.substr(line.find(',') + 2, line.length() - 1);
                fornecedor = line;

                inserir(v[i].ary_colhidos, j, novo, n_colhidos);
                n_colhidos++;

                v[i].ary_colhidos[j].nome = produto;
                v[i].ary_colhidos[j].tempo_rega = tempo_rega;
                v[i].ary_colhidos[j].resistência = resistencia;
                v[i].ary_colhidos[j].area = area;
                v[i].ary_colhidos[j].tempo_plantação = tempo_plantacao;
                v[i].ary_colhidos[j].fornecedor = fornecedor;
                j++;
            }
            i++;
        }
    }

    colhidos.close();

}

int tamanho_plantacao(std::string nome) {
    fstream ficheiro;
    string line;
    int i = 0;
    ficheiro.open(nome, ifstream::in);
    if (ficheiro.is_open()) {
        while (getline(ficheiro,line)) {
            if (line == "") i++;
        }
    }
    ficheiro.close();
    return i;
}

void remover_da_horta(horta& hortinha, Produto produto) {

    for (int i = 0; i < hortinha.capacidade; i++)
    {
        if (Produto_igual(produto, hortinha.ary_plantados[i])) {

            inserir(hortinha.ary_colhidos, 0, hortinha.ary_plantados[i], hortinha.n_colhidos);
            hortinha.ary_colhidos++;
            remover(hortinha.ary_plantados, i, hortinha.n_plantados);
            hortinha.n_plantados--;
            break;
        }
    }
}

void remover_da_horta_colheita(horta& hortinha,string nome) {

    int i = 0;
    while(i < hortinha.n_plantados)
    {
        if (nome == hortinha.ary_plantados[i].nome ){

            hortinha.n_colhidos = inserir(hortinha.ary_colhidos, 0, hortinha.ary_plantados[i], hortinha.n_colhidos);
            hortinha.n_plantados = remover(hortinha.ary_plantados, i, hortinha.n_plantados);

        }
        else
            i++;
    }
    
}

int adicionar_produtos_horta(Fila_Armazem& fila, horta plantacao[], int tamanho ) {

    int possissao = 0;
    int espacos_brancos = 0; //não mudei o nome mas é importante para adicionar apenas os elementos que falta preencher
    int adicionados = 0 ;
    int adicionados_total = 0;

    for (int i_armario = 0; adicionados_total < 10 && i_armario < fila.len_armazem; i_armario++)
    {
        for (int i_horta = 0; adicionados_total < 10 && i_horta < tamanho; i_horta++)
        {
            if (fila.ary_armazem[i_armario].area == plantacao[i_horta].area)
            {
                adicionados = 0;
                espacos_brancos = plantacao[i_horta].capacidade - plantacao[i_horta].n_plantados;

                for (int i_prateleira = 0; adicionados_total < 10 && i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
                {
                    for (int i_produto = 0; adicionados_total < 10 && espacos_brancos > 0 && i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++)
                    {
                       
                        inserir(plantacao[i_horta].ary_plantados, 0, fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto], plantacao[i_horta].n_plantados);
                        plantacao[i_horta].n_plantados++; // atualizar o tamanho do array plantados;
      
                        espacos_brancos--;
                        adicionados++; 
                        adicionados_total++;
                       
                    }

                }

                for (int i = 0; i < adicionados; i++)
                {
                    remover(fila, possissao );
                }

            }   

        }

       possissao += fila.ary_armazem[i_armario].n_produtos;

    }
  
    return adicionados_total;
}

void plantacao_to_produtos(horta plantacao[], Produto*& ary, int capacidade, int& tamanho_ary) {

    for (int i = 0; i < capacidade; i++)
    {
        for (int j = 0; j < plantacao[i].n_plantados; j++)
        {
            tamanho_ary = inserir(ary, 0, plantacao[i].ary_plantados[j], tamanho_ary);
        }
    }

}

int limpar_plantacao(horta*& plantacao,int capacidade) {

    int len = 0;
    while (len < capacidade)
    {
        if(plantacao[len].ary_colhidos != NULL)
            delete[] plantacao[len].ary_colhidos;
        if (plantacao[len].ary_plantados != NULL)
            delete[] plantacao[len].ary_plantados;
        len++;
    }

    delete[]plantacao;
    plantacao = NULL;

    return capacidade-len;
}

horta copiar_horta(horta& hortinha) {

    horta hortinha_auxiliar;

    hortinha_auxiliar.nome = hortinha.nome;
    hortinha_auxiliar.area = hortinha.area;
    hortinha_auxiliar.responsavel = hortinha.responsavel;
    hortinha_auxiliar.campanha = hortinha.campanha;
    hortinha_auxiliar.capacidade = hortinha.capacidade;
    hortinha_auxiliar.duracao = hortinha.duracao;

    hortinha_auxiliar.n_plantados = hortinha.n_plantados;
    hortinha_auxiliar.ary_plantados = new Produto[hortinha_auxiliar.n_plantados];

    for (int i_produto = 0; i_produto < hortinha_auxiliar.n_plantados; i_produto++)
    {
        copiar(hortinha.ary_plantados[i_produto],hortinha_auxiliar.ary_plantados[i_produto]);
    }

    hortinha_auxiliar.n_colhidos = hortinha.n_colhidos;
    hortinha_auxiliar.ary_colhidos = new Produto[hortinha_auxiliar.n_colhidos];

    for (int i_produto = 0; i_produto < hortinha_auxiliar.n_colhidos; i_produto++)
    {
        copiar(hortinha.ary_colhidos[i_produto], hortinha_auxiliar.ary_colhidos[i_produto]);
    }

    return hortinha_auxiliar;
}

horta* copiar_plantacao(horta plantacao[], int capacidade) {

    horta* plantacao_auxiliar = new horta[capacidade];

    for (int i = 0; i < capacidade; i++)
    {
        plantacao_auxiliar[i] = copiar_horta(plantacao[i]);
    }

    return plantacao_auxiliar;
}

void ordenar_plantacao_nome(horta plantacao[], int capacidade) {

    horta* copia = copiar_plantacao(plantacao, capacidade);

    for (int i = 0; i < capacidade; i++)
    {
        ordenar_nome(copia[i].ary_plantados, copia[i].n_plantados);
    }

    escrever_plantacao(copia, capacidade);
}

void ordenar_plantacao_tempo_plantacao(horta plantacao[], int capacidade) {

    horta* copia = copiar_plantacao(plantacao, capacidade);

    for (int i = 0; i < capacidade; i++)
    {
        ordenar_tempo_plantacao(copia[i].ary_plantados, copia[i].n_plantados);
    }

    escrever_plantacao(copia, capacidade);

}

void tempo_rega_plantacao(horta plantacao[], std::string nome, int capacidade, int novo_tempo) {

    for (int i = 0; i < capacidade; i++) {

        for (int j = 0; j < plantacao[i].n_plantados; j++) {

            if (plantacao[i].ary_plantados[j].nome == nome)
            {
                plantacao[i].ary_plantados[j].tempo_rega = novo_tempo;
            }
        }
    }
}

int area_atual(horta plantacao[], int capacidade, int tamanho_a_atuais, std::string*& a_atuais) {
   
    string area = "";
    int contador = 0;

    for (int i = 0; i < capacidade; i++) {

        contador = 0;
        area = plantacao[i].area;

        for (int j = 0; j < tamanho_a_atuais; j++) {
            if (a_atuais[j] == area) {
                contador++;
            }
        }
        if (contador == 0) {
            tamanho_a_atuais = inserir(a_atuais, 0, area, tamanho_a_atuais);
        }
    }

    return  tamanho_a_atuais;
}

//ciclo
void executar_ciclo(horta plantacao[], int capacidade , int ciclos) {

    srand(time(NULL));
    int i_produto = 0;
    Produto temporario;
    for (int i_horta = 0; i_horta < capacidade; i_horta++)
    {
        i_produto = 0;
        while(i_produto < plantacao[i_horta].n_plantados)
        {
            
           // a = (1 + rand() % 100);
            if ((1 + rand() % 100) <= 25)
            {   
                //probabilidade de ser colhido
                plantacao[i_horta].n_colhidos = inserir(plantacao[i_horta].ary_colhidos, 0, plantacao[i_horta].ary_plantados[i_produto], plantacao[i_horta].n_colhidos);
                plantacao[i_horta].n_plantados = remover(plantacao[i_horta].ary_plantados, i_produto, plantacao[i_horta].n_plantados);

                cout << "Colheu um produto da horta " << plantacao[i_horta].nome << " com o responsavel:" << plantacao[i_horta].responsavel << " | "
                    << "Produto: " << plantacao[i_horta].ary_colhidos[0].nome << " | "
                    << "Fornecedor: " << plantacao[i_horta].ary_colhidos[0].fornecedor << endl;

                cout << "--------------------------------------------------------------------------------------------------------" << endl;

            }
            else {

                //campanha
                if (plantacao[i_horta].campanha && (plantacao[i_horta].ary_plantados[i_produto].resistência + 10) <= 100) 
                {
                   // cout << "!!!!:" << plantacao[i_horta].ary_plantados[i_produto].nome << " " << plantacao[i_horta].duracao << " " << plantacao[i_horta].campanha << " " << plantacao[i_horta].ary_plantados[i_produto].resistência + 10 << endl;
                    plantacao[i_horta].ary_plantados[i_produto].resistência += 10;
                }

                //pragas
                if ( ( (ciclos + 1) % plantacao[i_horta].ary_plantados[i_produto].tempo_rega) == 0 && (1 + rand() % 100) < (100-plantacao[i_horta].ary_plantados[i_produto].resistência))
                {
                    temporario = plantacao[i_horta].ary_plantados[i_produto];
                    plantacao[i_horta].n_plantados = remover(plantacao[i_horta].ary_plantados, i_produto, plantacao[i_horta].n_plantados);
                        
                    cout << "Perdeu um produto da horta " << plantacao[i_horta].nome << " com o responsavel:" << plantacao[i_horta].responsavel << " | "
                            << "Produto: " << temporario.nome << " | "
                            << "Fornecedor: " << temporario.fornecedor << endl;

                    cout << "--------------------------------------------------------------------------------------------------------" << endl;
             
                }
                else{
                    plantacao[i_horta].ary_plantados[i_produto].tempo_plantação++;
                    i_produto++;
                }     

            }

        }

        if (plantacao[i_horta].campanha) 
        {
            if(plantacao[i_horta].duracao == 0)
            {
                plantacao[i_horta].campanha = false;
            }
            else
                plantacao[i_horta].duracao--;
        }

    }

}