#pragma once
#include <string>
#include "Produto.h"
struct Horta
{
	std::string agricultor = "";
	std::string area = "";
	int capacidade = 0;
	int n_plantados = 0;
	Produto* ary_plantados = NULL;
	//lista(array) dos que já foram colhidos

};

//colher
//regar
//fertilizar
//

/*

struct Fila_Produtos
{
	std::string area = "";
	int tamanho = 0;
	Produto* ary = NULL;
};

//adiciona o elemneto ao fim do da fila
void adicionar(Fila_Produtos& fila,Produto produto);
//removeo primeiro
void remover(Fila_Produtos& fila);
//retorna o primeiro
Produto* primeiro(Fila_Produtos& fila);
*/

/*
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
		Fila_Prateleira* ary_armario = NULL;
	};

	int len_armazem = 0;
	int n_produtos = 0;
	Fila_Armario* ary_armazem = NULL;
};


//adiciona o elemento ao armazem
void adicionar(Fila_Armazem& fila, Produto produto);
//remove o primeiro elemento do armazem ou de uma certa posição
void remover(Fila_Armazem& fila, int indice = 0);
//retorna o produto da posição pedida
Produto* get_Produto(Fila_Armazem& fila, int indice = 0);
//retorna o tamanho do armazem fila.n_produtos faz o mesmo;
int len(Fila_Armazem& fila);
//verifica se existem armarios iguais e prateleiras nos armarios iguias
void verificar(Fila_Armazem& fila, int& armarios_repetidos, int& prateleiras_repetidas);
//escreve o armazem
void esrcrever_armazem(Fila_Armazem& fila);
//guardar;
//import;

*/

