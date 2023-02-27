#pragma once
#include "Produto.h"
#include <string.h>

struct Fila_Armazem
{
	//para aramazenar os produtos das várias areas

	struct Fila_Armario
	{
		//para aramazenar os produtos da mesma area

		struct Fila_Prateleira {

			//para aramazenar os produtos da mesma area com o mesmo nome

			std::string nome = "";
			int len_prateleira = 0;
			Produto* ary_prateleira = NULL;
		};

		std::string area = "";
		int len_armario = 0;
		int n_produtos = 0;
		Fila_Prateleira* ary_armario = NULL;
	};

	int len_armazem = 0;
	int n_produtos = 0;
	Fila_Armario* ary_armazem = NULL;
};

//é a função que cria e adiciona os 15 primeiros produtos do armazem;
int inicializar_armazem(Fila_Armazem& armazem, int quantidade, std::string nomes[], std::string fornecedores[], std::string areas[], int tamanho_nomes, int tamanho_fornecedores, int tamanho_areas, int& n);

//adiciona o elemento ao armazem
void adicionar(Fila_Armazem& fila, Produto produto);
//remove o primeiro elemento do armazem ou de uma certa posição
void remover(Fila_Armazem& fila, int indice = 0);
//retorna o produto da posição pedida
Produto* get_Produto(Fila_Armazem& fila, int indice = 0);
//retorna o tamanho do armazem: fila.n_produtos faz o mesmo;
int len(Fila_Armazem& fila);
//verifica se existem armarios iguais e prateleiras nos armarios iguias
void verificar(Fila_Armazem& fila, int& armarios_repetidos, int& prateleiras_repetidas);
//escreve o armazem
void escrever_armazem(Fila_Armazem& fila);
//conver o armazem para um array de produtos;
Produto* Armazem_To_ProdutoArray(Fila_Armazem& fila);
//altera o tempo de rega de um produto
void atualizar_tempo_de_rega(Fila_Armazem& fila, std::string nome, int novo_tempo_rega);
//lipar armazem
void limpar(Fila_Armazem& fila);
//guardar;
void guardar(std::string ficheiro, Fila_Armazem& fila);
//carregar;
void carregar(std::string ficheiro, Fila_Armazem& fila);
