#include <iostream>
#include <string>
#include "Funcoes.h"
#include "Armazem.h"
#include "Produto.h"
#include "Horta.h"
#include "arrays_string.h"


using namespace std;

void ColherProduto(horta ary[],int tamanho,string prod) {
	getline(cin, prod);
	for (int i = 0; i < tamanho;i++) {
		remover_da_horta_colheita(ary[i],prod);
	}
}

void AtualizarRega(Fila_Armazem& fila,horta plantacao[], std::string nome, int capacidade, int novo_tempo) {
	tempo_rega_plantacao(plantacao, nome, capacidade, novo_tempo);
	atualizar_tempo_de_rega(fila, nome, novo_tempo);
}

void Fertilizacao(horta ary[],int duracao,std::string area,int capacidade) {
	for (int i = 0; i < capacidade; i++) {
		if (area == ary[i].area) {
			ary[i].campanha = true;
			ary[i].duracao = duracao;
		}
	}
}

void GravarPlantacao(horta plantacao[],int capacidade,Fila_Armazem& fila,std::string diretorio_plantacao,std::string diretorio_colhidos, std::string diretorio_armazem) {
	gravar_plantacao(plantacao, diretorio_plantacao, diretorio_colhidos, capacidade);
	guardar(diretorio_armazem, fila);
	cout << "Gravado com sucesso !!" << endl;
}

int CarregarPlantacao(horta*& plantacao, int capacidade, Fila_Armazem& fila, std::string diretorio_plantacao, std::string diretorio_colhidos, std::string diretorio_armazem) {
	limpar_plantacao(plantacao, capacidade);
	capacidade = tamanho_plantacao(diretorio_plantacao);
	plantacao = new horta[capacidade];
	import_plantacao(diretorio_plantacao, plantacao, capacidade);
	import_colhidos(diretorio_colhidos, plantacao, capacidade);
	limpar(fila);
	carregar(diretorio_armazem, fila);

	return capacidade;
}

void ImprimirPlantacao(Fila_Armazem& fila ,horta plantacao[],int capacidade, char choice) {

	Produto* ary = NULL;
	if (choice == '0')
	{
		ary = new Produto[fila.n_produtos];
		ary = Armazem_To_ProdutoArray(fila);
		ordenar_nome(ary, fila.n_produtos);
		cout << "Plantacao:" << endl;
		ordenar_plantacao_nome(plantacao, capacidade);
		cout << "Armazem:" << endl;
		escrever(ary, fila.n_produtos);
	}
	else if(choice == '1')
	{
		ary = new Produto[fila.n_produtos];
		ary = Armazem_To_ProdutoArray(fila);
		ordenar_tempo_plantacao(ary, fila.n_produtos);
		cout << "Plantacao:" << endl;
		ordenar_plantacao_tempo_plantacao(plantacao,capacidade);
		cout << "Armazem:" << endl;
		escrever(ary, fila.n_produtos);
	}
	else
		cout << choice << " opcao invalida" << endl;
}

int CriarArea(std::string*& ary,int tamanho) {
	string area = "";
	cout << "Indique o nome da noa area: " << endl;
	cin.get();
	getline(cin, area);
	tamanho = inserir(ary, 0, area, tamanho);

	escrever(ary, tamanho);
	return tamanho;
}

void RegistroAgricultor(horta ary[], int tamanho) {

	for (int i = 0; i < tamanho; i++) {

		if(ary[i].responsavel == "")
			cout << "Responsavel da horta " << ary[i].nome << " Nao defenido" << endl;
		else
			cout << ary[i].responsavel << endl;

		cout << "--------------------------------------------------------------------------------------------------------" << endl;

		escrever(ary[i].ary_colhidos, ary[i].n_colhidos);

		cout << "--------------------------------------------------------------------------------------------------------" << endl;
	}
}

void AlterarArea(string areas_atuais[],int tamanho_areas_atuais, horta plantacao[], int capacidade) {

	string linha = "";
	int c = -1;
	int len = 0;
	cout << "Indique o id da horta ou o responsavel:" << endl;
	cin.get();
	getline(cin, linha);

	for (int i = 0; i < capacidade; i++)
	{
		if (plantacao[i].nome == linha[0] || plantacao[i].responsavel == linha)
			c = i;
	}

	if (c == -1)
		cout << "Responsavel ou id invalido" << endl;
	else {
		cout << "Qual a nova area?" << endl;
		getline(cin, linha);

		for (int i = 0; i < tamanho_areas_atuais; i++) 
		{
			if (areas_atuais[i] == linha)
			{
				len = plantacao[c].n_plantados;
				for (int j = 0; j < len ; j++)
				{
					plantacao[c].n_plantados = remover(plantacao[c].ary_plantados,0,plantacao[c].n_plantados);
				}
				plantacao[c].area = linha;

				cout << "Sucesso !" << endl;
				break;
			}
		}

		if(len == 0) 
			cout << "Area invalida !" << endl;
	}
}