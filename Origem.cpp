#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "arrays_string.h"
#include "Horta.h"
#include "Produto.h"
#include "Armazem.h"
#include "files.h"


using namespace std;



int main(int argc, char* argv[]) {

	//ABCDEFGHIJKLMNOPQRSTUVWXYZ
	// 
	srand(time(NULL));

	int tamanho_produtos = tamanho("Produtos.txt");
	string* produtos = new string[tamanho_produtos];
	import_files("Produtos.txt", produtos);

	int tamanho_areas = tamanho("Areas.txt");
	string* areas = new string[tamanho_areas];
	import_files("Areas.txt", areas);

	int tamanho_forneecedores = tamanho("Fornecedores.txt");
	string* fornecedores = new string[tamanho_forneecedores];
	import_files("Fornecedores.txt", fornecedores);

	int capacida = 5 + rand() % 6;

	Fila_Armazem armazem;

	inicializar_armazem(armazem,40, produtos, fornecedores, areas, tamanho_produtos, tamanho_forneecedores, tamanho_areas);

	escrever_armazem(armazem);


	escrever_armazem(armazem);

	cout << "--------------" << endl;


	horta* plantacao = new horta[capacida];
	inicializar_plantacao(plantacao, areas, tamanho_areas, id, capacida);
	
	int n_horta = 0;
	n_horta = adicionar_produtos_horta(armazem, plantacao, capacida, n_horta);
	n_horta = adicionar_produtos_horta(armazem, plantacao, capacida, n_horta);
	n_horta = adicionar_produtos_horta(armazem, plantacao, capacida, n_horta);
	n_horta = adicionar_produtos_horta(armazem, plantacao, capacida, n_horta);

	int c = 0;
	for (int i = 0; i < 20; i++)
	{
		executar_ciclo(plantacao, capacida, c);
	}



	
	
}


	



