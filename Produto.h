#pragma once
#include <string>

struct Produto
{
	std::string nome = "";
	std::string area = "";
	std::string fornecedor;
	int tempo_rega = 0; // ciclo +1 % plantado 
	int tempo_plantação = 0;
	int resistência = 0;
};

//copia o Produto a para b
void copiar(Produto& a,Produto& b);
//devolve true se os produtos forem iguais
bool Produto_igual(Produto& a, Produto& b);
//criao um produto aleatório
Produto criar_Produto_aleatorio(std::string nomes[], std::string fornecedores[], std::string areas[], int tamanho_nomes, int tamanho_fornecedores, int tamanho_areas);
//criao um produto se não dor dado argumentos cria o produto vazio
Produto criar_Produto(std::string nome = "Nulo", std::string area = "Nulo", std::string fornecedor = "Nulo", int restencia = 0, int tempo_plantação = 0, int tempo_rega = 0);
//Transforma um Produto em string do formato: nome,area,fornecedor,res..,temp_plantação,temp_rega
std::string Produto_To_String(Produto produto);
//Transforma uma string do formato: nome,area,fornecedor,res..,temp_plantação,temp_rega para Produto
Produto String_To_Produto(std::string produto);

//funções para arrays dinamicos
//insere numa posição aumentando o tamanhodo array sem eleminar o elemento
int inserir(Produto*& ary, int posisao, Produto produto, int tamanho);
//remove o elemento da posição dada
int remover(Produto*& ary, int posisao, int tamanho);
//remove todas as occorencias de str
int strip(Produto*& ary, Produto produto, int tamanho);
//retorna a posição da 1ª ocorrencia do valor igual a str
int procurar(Produto*& ary, Produto produto, int tamanho);
//lê e imprime os valores do array
void escrever(Produto ary[], int tamanho);
//troca a posissao 
void trocar_posissao(Produto*& ary, int indice_a, int indice_b, int tamanho);
//ordenam o array de produtos
void ordenar_tempo_plantacao(Produto*& ary, int tamanho);
void ordenar_nome(Produto*& ary, int tamanho);
//Junta dois arrays de produtos diferentes
void juntar(Produto*& a,int tamanho_a, Produto*& b, int tamanho_b, Produto*& c, int& tamanho_c);