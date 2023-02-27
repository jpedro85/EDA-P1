#pragma once
#include <string>
#include "Produto.h"
#include "Armazem.h"

struct horta
{
    char nome = NULL;//id da horta (A,B,C,...)
    std::string area = "";//aletorio do array de areas
    std::string responsavel = "";//inserido pelo utilizador
    int n_plantados = 0;//numero de produtos dentro da horta
    int capacidade = 3;//quantidade de produtos que pode ter na horta
    int n_colhidos = 0;
    Produto* ary_plantados = NULL;
    Produto* ary_colhidos = NULL;
    bool campanha = false;
    int duracao = 0;//dias da campanha

};

//lista dos Ids das hortas
const char id[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
//cria uma horta para ser adicionada a plantaçao
horta criar_horta(std::string areas[], int tamanho_areas, char id);
//cria a plantaçao no inicio do programa
void inicializar_plantacao(horta plantacao[], std::string areas[], int tamanho_areas, const char id[], int capacidade_hortas);
//imprime na consola a plantaçao
void escrever_plantacao(horta plantacao[], int capacidade_hortas);
//procura o Indice na horta em que corresponde ao Id escolhido
int procurar_id(horta plantacao[], int capacidade_hortas, char id_escolhido);
//grava a plantaçao no ficheiro seguindo a sua formataçao
void gravar_plantacao(horta plantacao[], std::string nome, std::string diretorio_colhidos, int capacidade_hortas);
//guarda array colhidos
void guardar_array_colhidos(horta plantacao[], std::string nome, int capacidade_hortas);
//importa a plantaçao do ficheiro
void import_plantacao(std::string nome, horta v[], int capacidade);
//importa os colhidos
void import_colhidos(std::string nome, horta v[], int capacidade);
//capacidade da plantaçao do ficheiro
int tamanho_plantacao(std::string nome);
//tempo de rega atualizar
void tempo_rega_plantacao(horta plantacao[], std::string nome, int capacidade, int novo_tempo);

//adiciona um produto á horta
//int adicionar_produtos_horta(Fila_Armazem& fila, horta plantacao[], int tamanho, int n_produtos_horta);
int adicionar_produtos_horta(Fila_Armazem& fila, horta plantacao[], int tamanho);

//sempre que um produto é removido é adicionado ao ary_colhidos 
//remover da orta o primeiro produto igual 
void remover_da_horta(horta& hortinha, Produto produto);
//remove Todos os produtos com o nome 
void remover_da_horta_colheita(horta& hortinha, std::string nome);

//passa de horta para arrys de produtos
void plantacao_to_produtos(horta plantacao[], Produto*& ary, int capacidade, int& tamaho_ary);
//limpa a plantação
int limpar_plantacao(horta*& plantacao, int capacidade);
//copia a horta 
horta copiar_horta(horta& hortinha);
//copia um arei de plantações
horta* copiar_plantacao(horta plantacao[], int capacidade);
//ordenacao
void ordenar_plantacao_nome(horta plantacao[], int capacidade);
void ordenar_plantacao_tempo_plantacao(horta plantacao[], int capacidade);

//cilcos plantacão
void executar_ciclo(horta plantacao[], int capacidade, int ciclos);

int area_atual(horta plantacao[], int capacidade, int tamanho_a_atuais, std::string*& a_atuais);