#include <iostream>
#include "Produto.h"

#include <stdlib.h>
#include <time.h>
#include "arrays_string.h"
//string esta incluido no .h

void copiar(Produto& a, Produto& b) {

	b.area = a.area;
	b.fornecedor = a.fornecedor;
	b.nome = a.nome;
	b.resist�ncia = a.resist�ncia;
	b.tempo_planta��o = a.tempo_planta��o;
	b.tempo_rega = a.tempo_rega;

}

bool Produto_igual(Produto& a, Produto& b) {
	
	return a.area == b.area && a.nome == b.nome && a.fornecedor == b.fornecedor && a.resist�ncia == b.resist�ncia && a.tempo_planta��o == b.tempo_planta��o && a.tempo_rega == b.tempo_rega;
}

Produto criar_Produto_aleatorio(std::string nomes[], std::string fornecedores[], std::string areas[], int tamanho_nomes, int tamanho_fornecedores, int tamanho_areas) {
	
	int indice_Produtos = rand() % (tamanho_nomes);
	int indice_fornecedores = rand() % (tamanho_fornecedores);
	int indice_areas = rand() % (tamanho_areas);
	Produto p;
	p.nome = nomes[indice_Produtos];
	p.area = areas[indice_areas];
	p.fornecedor = fornecedores[indice_fornecedores];
	p.tempo_rega = 1 + rand() % 5;
	p.resist�ncia = rand() % 101;
	p.tempo_planta��o = 0;
	return p;
}

Produto criar_Produto(std::string nome, std::string area, std::string fornecedor,int restencia, int tempo_planta��o, int tempo_rega) {

	Produto novo;
	novo.nome = nome;
	novo.area = area;
	novo.fornecedor = fornecedor;
	novo.resist�ncia = restencia;
	novo.tempo_planta��o = tempo_planta��o;
	novo.tempo_rega = tempo_rega;

	return novo;
}

std::string Produto_To_String(Produto produto) {

	std::string str = produto.nome + ',' 
					+ produto.area + ',' 
					+ produto.fornecedor + ',' 
					+ std::to_string(produto.resist�ncia) + ','
					+ std::to_string(produto.tempo_planta��o) + ','
					+ std::to_string(produto.tempo_rega);

	return str;
}

Produto String_To_Produto(std::string produto) {

	Produto novo;

	//stoi converte de string para int microsoft c++ reference
	//substr devolve uma substring da string;

	novo.nome = produto.substr(0, produto.find(','));
	produto = produto.substr(produto.find(',') + 1, produto.length() - 1);

	novo.area = produto.substr(0, produto.find(','));
	produto = produto.substr(produto.find(',') + 1, produto.length() - 1);

	novo.fornecedor = produto.substr(0, produto.find(','));
	produto = produto.substr(produto.find(',') + 1, produto.length() - 1);

	novo.resist�ncia = stoi(produto.substr(0, produto.find(',')));
	produto = produto.substr(produto.find(',') + 1, produto.length() - 1);

	novo.tempo_planta��o = stoi(produto.substr(0, produto.find(',')));
	produto = produto.substr(produto.find(',') + 1, produto.length() - 1);

	novo.tempo_rega = stoi(produto.substr(0, produto.find(',')));
	produto = produto.substr(produto.find(',') + 1, produto.length() - 1);

	return novo;
}

//fun��es para arrays dinamicos
int inserir(Produto*& ary, int posisao, Produto produto, int tamanho) {

	Produto* aux = new Produto[tamanho + 1]; // cria��o de um auxiliar array com um tamanho maior em 1,

	if (posisao == 0) { // quando a posi��o � a primeira

		aux[0] = produto; // aux[0] recebe o valor e depois aux de 1,tamanho copia os valores de ary
		for (int i = 0; i < tamanho; i++)
		{
			aux[i + 1] = ary[i];
		}
	}
	else if (posisao == tamanho - 1) { // quando a posi��o � a ultima

		aux[tamanho] = produto; // aux[ultima posi��o = tamanho ] recebe o valor e depois aux de 0,tamanho copia os valores de ary
		for (int i = 0; i < tamanho; i++)
		{
			aux[i] = ary[i];
		}
	}
	else {

		for (int i = 0; i < tamanho + 1; i++) // no meio
		{
			if (i == posisao) // quando i = � posi��o aux[i] = valor
				aux[i] = produto;
			else if (i > posisao) // depois de aux ter o valor houve uma posi��o de ary que foi saltada por isso i-1;
				aux[i] = ary[i - 1];
			else {
				aux[i] = ary[i]; // at� i = � posi��o copia os valores de ary
			}
		}
	}

	delete[] ary; // apaga o ary antigo
	ary = aux; // atualixza o apontador para o novo array aux

	return tamanho + 1;
	
}
//remove o elemento da posi��o dada
int remover(Produto*& ary, int posisao, int tamanho) {
	
	if (tamanho - 1 == 0) {
		ary = NULL;
		return 0;
	}
	else{

		Produto* aux = new Produto[tamanho - 1]; // cria��o de um auxiliar array com um tamanho menor em 1 pois um elemento � vai ser removido,

		if (posisao == 0) { // quando a posi��o � a primeira o aux coipia todos os valores de ary exeto o 1�

			for (int i = 0; i + 1 < tamanho; i++)
			{
				aux[i] = ary[i + 1];
			}
		}
		else if (posisao == tamanho - 1) { // quando a posi��o � a ultima o aux coipia todos os valores de ary exeto o ultimo�

			for (int i = 0; i < tamanho - 1; i++)
			{
				aux[i] = ary[i];
			}
		}
		else {

			for (int i = 0; i + 1 < tamanho; i++) // quando no meio � a primeira o aux coipia todos os valores de ary exeto o a posi��o removida�
			{
				if (i >= posisao)
					aux[i] = ary[i + 1];
				else
					aux[i] = ary[i];
			}
		}

		delete[] ary; // apaga o ary antigo
		ary = aux; // atualixza o apontador para o novo array aux

		return tamanho - 1; // reorna tamanho -1
	}
}
//remove todas as occorencias de str
int strip(Produto*& ary, Produto produto, int tamanho) {

	int count = 0;
	for (int i = 0; i < tamanho; i++)
	{
		if (Produto_igual(ary[i], produto)) {
			remover(ary,i,tamanho);
			count++;
		}
	}
	return tamanho - count;
}
//retorna a posi��o da 1� ocorrencia do valor igual a str
int procurar(Produto*& ary, Produto produto, int tamanho) {

	for (int i = 0; i < tamanho; i++)
	{
		if (Produto_igual(ary[i], produto)) {
			return i;
		}
	}
	return 0;
}
//l� e imprime os valores do array
void escrever(Produto ary[], int tamanho) {
	
	for (int i = 0; i < tamanho; i++)
	{
		std::cout << "Nome: " << ary[i].nome << " | " << "Rega: " << ary[i].tempo_rega << " | " << "Resistencia: " << ary[i].resist�ncia <<  " | " << "Area: " << ary[i].area << " | " <<"Fornecedor:"<< ary[i].fornecedor << std::endl;
	}

}
//troca de posissao o A com o B
void trocar_posissao(Produto*& ary , int indice_a , int indice_b , int tamanho) {

	if (indice_a != indice_b && indice_a < tamanho && indice_b < tamanho)
	{
		Produto temp = ary[indice_b];
		ary[indice_b] = ary[indice_a];
		ary[indice_a] = temp;
	}

}
//ordena o array de produtos
void ordenar_tempo_plantacao(Produto*& ary,int tamanho){
	
	bool trocado = true;
	for (int i = 0 ; i < tamanho && trocado ; i++)
	{	
		trocado = false;
		for (int j = tamanho -1; j>i; j--)
		{	
			if (ary[j].tempo_planta��o < ary[j - 1].tempo_planta��o)
			{
				trocar_posissao(ary,j,j-1,tamanho);
				trocado = true;
			}
		}
	}
}
//ordena o array de produtos
void ordenar_nome(Produto*& ary, int tamanho) {

	bool trocado = true;
	std::string str_anterior = "" ,str_atual = "";

	for (int i = 0; i < tamanho && trocado; i++)
	{
		trocado = false;
		for (int j = tamanho - 1; j > i; j--)
		{
			 
			str_anterior = ary[j - 1].nome;
			trim(str_anterior);
			to_lower(str_anterior);

			str_atual = ary[j].nome;
			trim(str_atual);
			to_lower(str_atual);
			if (str_atual < str_anterior)
			{
				trocar_posissao(ary, j, j - 1, tamanho);
				trocado = true;
			}
		}
	}
}
//Junta dois arrays de produtos diferentes
void juntar(Produto*& a, int tamanho_a, Produto*& b, int tamanho_b, Produto*& c, int& tamanho_c) {

	c = new Produto[tamanho_a+tamanho_b];

	tamanho_c = tamanho_a + tamanho_b;

	for (int i = 0; i < tamanho_a; i++)
	{
		c[i] = a[i];
	}

	for (int j = 0 ; j < tamanho_b; j++)
	{
		c[j+tamanho_a] = b[j];
	}

	
}

