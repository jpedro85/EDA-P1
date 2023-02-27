#include <iostream>
#include <fstream>
#include "Armazem.h"
// Produto.h está incluido no Armazem.h

using namespace std;


//cria os primeios valores do armazem
int inicializar_armazem(Fila_Armazem& armazem, int quantidade, std::string nomes[], std::string fornecedores[], std::string areas[], int tamanho_nomes, int tamanho_fornecedores, int tamanho_areas,int& n) {

	for (int i = 0; i < quantidade; i++) {
		adicionar(armazem, criar_Produto_aleatorio(nomes, fornecedores, areas, tamanho_nomes, tamanho_fornecedores, tamanho_areas));
	}
	return quantidade;
}

void adicionar(Fila_Armazem& fila, Produto produto) {

	if (fila.len_armazem == 0) {

		Fila_Armazem::Fila_Armario::Fila_Prateleira nova_prateleira;
		nova_prateleira.nome = produto.nome;
		nova_prateleira.ary_prateleira = new Produto[1];
		nova_prateleira.len_prateleira = 1;
		nova_prateleira.ary_prateleira[0] = produto; //adiciona o novo produto á prateleira

		Fila_Armazem::Fila_Armario novo_armario;
		novo_armario.area = produto.area;
		novo_armario.ary_armario = new Fila_Armazem::Fila_Armario::Fila_Prateleira[1];
		novo_armario.len_armario = 1;
		novo_armario.n_produtos = 1;
		novo_armario.ary_armario[0] = nova_prateleira; //adiciona a prateleira ao armário

		//cria um auxiliar para o array de armarios "armazem"
		fila.ary_armazem = new Fila_Armazem::Fila_Armario[1];
		fila.ary_armazem[0] = novo_armario; // adiciona o novo armario ao armazem;

		fila.len_armazem++;//atualiza o tamanho	
		fila.n_produtos++; //atualiza o tamanho do armazem no total
	}
	else {

		bool modificado = false;

		for (int i_armario = 0; i_armario < fila.len_armazem; i_armario++)
		{
			if (fila.ary_armazem[i_armario].area == produto.area) {

				for (int i_prateleira = 0; i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
				{
					if (fila.ary_armazem[i_armario].ary_armario[i_prateleira].nome == produto.nome) {

						Produto* prateleira_auxiliar = new Produto[fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira + 1];
						for (int i_produto = 0; i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++)
						{
							prateleira_auxiliar[i_produto] = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto];
						}
						prateleira_auxiliar[fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira] = produto;

						delete[] fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira;
						fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira = prateleira_auxiliar;

						fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira++;
						fila.ary_armazem[i_armario].n_produtos++;
						fila.n_produtos++;

						modificado = true;
						break;
					}
				}

				if (!modificado)
				{

					//criar nova prateleira
					Fila_Armazem::Fila_Armario::Fila_Prateleira nova_prateleira;
					nova_prateleira.nome = produto.nome;
					nova_prateleira.ary_prateleira = new Produto[1];
					nova_prateleira.ary_prateleira[0] = produto;
					nova_prateleira.len_prateleira = 1;


					Fila_Armazem::Fila_Armario::Fila_Prateleira* armario_auxiliar = new Fila_Armazem::Fila_Armario::Fila_Prateleira[fila.ary_armazem[i_armario].len_armario + 1];
					for (int i_prateleira = 0; i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
					{
						armario_auxiliar[i_prateleira] = fila.ary_armazem[i_armario].ary_armario[i_prateleira];

					}
					armario_auxiliar[fila.ary_armazem[i_armario].len_armario] = nova_prateleira;

					delete[] fila.ary_armazem[i_armario].ary_armario;
					fila.ary_armazem[i_armario].ary_armario = armario_auxiliar;
					fila.ary_armazem[i_armario].len_armario++;
					fila.ary_armazem[i_armario].n_produtos++;
					fila.n_produtos++;

					modificado = true;
					break;
				}
				else
					break;

			}

		}

		if (!modificado) {

			//quando não existe aquela area no armazem

			//cira um novo armario para aquela area com 1 lugar
			Fila_Armazem::Fila_Armario novo_armario;
			novo_armario.area = produto.area;
			novo_armario.ary_armario = new Fila_Armazem::Fila_Armario::Fila_Prateleira[1];
			novo_armario.len_armario = 1;

			//cria uma nova prateleira para o armario com 1 lugar
			Fila_Armazem::Fila_Armario::Fila_Prateleira nova_prateleira;
			nova_prateleira.nome = produto.nome;
			nova_prateleira.ary_prateleira = new Produto[1];
			nova_prateleira.len_prateleira = 1;

			nova_prateleira.ary_prateleira[0] = produto; //adiciona o novo produto á prateleira
			novo_armario.ary_armario[0] = nova_prateleira; //adiciona a prateleira ao armário
			novo_armario.n_produtos++;

			//cria um auxiliar para o array de armarios "armazem"
			Fila_Armazem::Fila_Armario* aux = new Fila_Armazem::Fila_Armario[fila.len_armazem + 1];
			//copia todos os armarios para o auxiliar
			for (int i = 0; i < fila.len_armazem; i++)
			{
				aux[i] = fila.ary_armazem[i];
			}
			//adiciona o novo
			aux[fila.len_armazem] = novo_armario; // adiciona o novo armario ao armazem;

			delete[] fila.ary_armazem;// liberta o espaço do armazem antigo
			fila.ary_armazem = aux;// atualiza o armazem
			fila.len_armazem++;//atualiza o tamanho	
			fila.n_produtos++; //atualiza o tamanho do armazem no total

			modificado = true;

		}
	}
}

void remover(Fila_Armazem& fila, int indice) {

	if (fila.len_armazem > 0 && 0 <= indice && indice < fila.n_produtos) {

		//para cada armario se ouver pelo menos 1
		int posisao_atual = 0;
		bool removido = false;
		for (int i_armario = 0; !removido && fila.len_armazem > 0 && i_armario < fila.len_armazem; i_armario++)
		{
			//para cada prateleira se houver pelo menos 1
			for (int i_prateleira = 0; !removido && fila.len_armazem > 0 && i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
			{
				//para cada produto se houver pelo menos 1; != Null porque quão se deleta o ultimo elemento não é posivel aceder a
				for (int i_produto = 0; fila.len_armazem > 0 && i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++)
				{

					posisao_atual++;// conta a posição atual do produto
					if (posisao_atual == indice + 1) { //se for a pretendida

						if (fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira - 1 == 0) {

							if (fila.ary_armazem[i_armario].len_armario - 1 == 0) {

								if (fila.len_armazem - 1 == 0) {

									//resetar o arrray armazem
									delete[] fila.ary_armazem;
									fila.ary_armazem = NULL;
									fila.n_produtos = 0;
									fila.len_armazem = 0;

									removido = true;
									break;// asdasd

								}
								else {
									//remorver armario
									//delete fila.ary_armazem[i_armario].ary_armario;

									Fila_Armazem::Fila_Armario* auxiliar = new Fila_Armazem::Fila_Armario[fila.len_armazem - 1];
									for (int i = 0; i + 1 < fila.len_armazem; i++)
									{
										if (i < i_armario)
											auxiliar[i] = fila.ary_armazem[i];
										else if (i >= i_armario)
											auxiliar[i] = fila.ary_armazem[i + 1];
									}

									delete[] fila.ary_armazem;
									fila.ary_armazem = auxiliar;
									fila.len_armazem--;
									fila.n_produtos--;
									removido = true;
									break;// asdasd
								}

							}
							else {

								//remorver prateleira
								Fila_Armazem::Fila_Armario::Fila_Prateleira* armario_auxiliar = new Fila_Armazem::Fila_Armario::Fila_Prateleira[fila.ary_armazem[i_armario].len_armario - 1];
								for (int i = 0; i + 1 < fila.ary_armazem[i_armario].len_armario; i++)
								{
									if (i < i_prateleira)
										armario_auxiliar[i] = fila.ary_armazem[i_armario].ary_armario[i];
									else if (i >= i_prateleira)
										armario_auxiliar[i] = fila.ary_armazem[i_armario].ary_armario[i + 1];
								}
								delete[] fila.ary_armazem[i_armario].ary_armario;
								fila.ary_armazem[i_armario].ary_armario = armario_auxiliar;
								fila.ary_armazem[i_armario].len_armario--;
								fila.ary_armazem[i_armario].n_produtos--;
								fila.n_produtos--;
								
								removido = true;
								break;// asdasd

							}
						}
						else {

							//remorver prodtuto
							Produto* prateleira_auxiliar = new Produto[fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira - 1];
							for (int i = 0; i + 1 < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i++)
							{
								if (i < i_produto)
									prateleira_auxiliar[i] = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i];
								else if (i >= i_produto)
									prateleira_auxiliar[i] = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i + 1];
							}
							delete[] fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira;
							fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira = prateleira_auxiliar;
							fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira--;
							fila.ary_armazem[i_armario].n_produtos--;
							fila.n_produtos--;
							

							removido = true;
							break;// asdasd
						}
					}
				}
			}
		}
	}
}

Produto* get_Produto(Fila_Armazem& fila, int indice) {

	if (fila.len_armazem > 0 && indice < fila.n_produtos) {

		//para cada armario se ouver pelo menos 1
		int posisao_atual = 0;
		for (int i_armario = 0; i_armario < fila.len_armazem; i_armario++)
		{
			//para cada prateleira se houver pelo menos 1
			if (fila.ary_armazem[i_armario].len_armario > 0) {
				for (int i_prateleira = 0; i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
				{
					//para cada produto se houver pelo menos 1;
					if (fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira > 0) {
						for (int i_produto = 0; i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++)
						{

							posisao_atual++;// conta a posição atual do produto
							if (posisao_atual == indice + 1) { //se for a pretendida

								Produto* novo = new Produto;
								copiar(fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto], *novo);

								return novo; //retorna o produto

							}//return 

						}

					}
					else //se nao houver produtos
						return NULL;
				}

			}
			else // se nao houver prateleiras
				return NULL;
		}

	}
	else // se nao houver armarios
		return NULL;

}

Produto* get_ProdutoOfArmario(Fila_Armazem& fila, int indice, int& posisao_out) {

	Produto* novo = new Produto;
	if (indice < fila.len_armazem && fila.ary_armazem[indice].len_armario > 0)
	{	
		posisao_out = 0;
		for (int i = 0; i < indice; i++)
		{
			posisao_out += fila.ary_armazem[i].n_produtos;
		}
		copiar(fila.ary_armazem[indice].ary_armario[0].ary_prateleira[0], *novo);
		return novo;
	}

	
	return NULL;
}

int len(Fila_Armazem& fila) {

	int contador = 0;
	//para cada armario
	for (int i_armario = 0; i_armario < fila.len_armazem; i_armario++)
	{
		//para cada prateleira
		for (int i_prateleira = 0; i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
		{
			//para cada produto
			for (int i_produto = 0; i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++) {

				contador++;// conta a posição atual do produto
			}
		}
	}

	return contador;

}

void verificar(Fila_Armazem& fila, int& armarios_repetidos, int& prateleiras_repetidas) {

	for (int i_armario = 0; i_armario < fila.len_armazem; i_armario++)
	{
		int count = 0;
		for (int i = 0; i < fila.len_armazem; i++)
		{
			if (i != i_armario && fila.ary_armazem[i].area == fila.ary_armazem[i_armario].area) {
				count++;
			}
		}
		if (count > 0)
			armarios_repetidos = armarios_repetidos + 1;

		int count1 = 0;
		for (int i_prat = 0; i_prat < fila.ary_armazem[i_armario].len_armario; i_prat++)
		{
			for (int i = 0; i < fila.ary_armazem[i_armario].len_armario; i++)
			{
				if (i != i_prat && fila.ary_armazem[i_armario].ary_armario[i].nome == fila.ary_armazem[i_armario].ary_armario[i_prat].nome) {
					count1++;
				}

			}
		}
		//cout << "prateleiras iguais: " << count1 << endl;
		if (count > 0)
			prateleiras_repetidas = prateleiras_repetidas + 1;

	}

}

void escrever_armazem(Fila_Armazem& fila) {

	for (int i_armario = 0; i_armario < fila.len_armazem; i_armario++)
	{
		//para cada prateleira
		for (int i_prateleira = 0; i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
		{
			//para cada produto
			for (int i_produto = 0; i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++) {

				cout << "Area: " << fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].area << " | "
					 << "Nome: " << fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].nome << " | "
					 << "Resistencia: " << fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].resistência << " | " 
					 << "Tempo de Rega " << fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].tempo_rega 
					 << endl;
			}
		}
		cout << "---------------------------" << endl;
	}
}

Produto* Armazem_To_ProdutoArray(Fila_Armazem& fila) {

	Produto* ary = new Produto[fila.n_produtos];

	int indice = 0;
	//para cada armario
	for (int i_armario = 0; i_armario < fila.len_armazem; i_armario++)
	{
		//para cada prateleira
		for (int i_prateleira = 0; i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
		{
			//para cada produto
			for (int i_produto = 0; i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++) {


				ary[indice] = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto];
				indice++;
			}
		}
	}

	return ary;
}

void atualizar_tempo_de_rega(Fila_Armazem& fila, std::string nome, int novo_tempo_rega) {

	for (int i_armario = 0; i_armario < fila.len_armazem; i_armario++)
	{
		for (int i_prateleira = 0; i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
		{
			for (int i_produto = 0; i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++)
			{
				if ( fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].nome == nome)
				{
					fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].tempo_rega = novo_tempo_rega;
				}
			}

		}
	}
}

void limpar(Fila_Armazem& fila) {

	int n = fila.n_produtos;
	for (int i_produto = 0; i_produto < n; i_produto++)
	{
		remover(fila);
	}
}

void guardar(std::string ficheiro, Fila_Armazem& fila){

	fstream file(ficheiro, fstream::out);

	if (file.is_open() && file.good()){

		//para cada armario
		for (int i_armario = 0; i_armario < fila.len_armazem; i_armario++)
		{
			//para cada prateleira
			for (int i_prateleira = 0; i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
			{
				//para cada produto
				for (int i_produto = 0; i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++)
				{
					string str = Produto_To_String(fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto]) + '\n';
					file.write(str.c_str(), str.length());
				}		
			}
		}

		file.close();

	}
	else {
		cout << "O ficheiro está corronpido ou não foi aberto corretamente" << endl;
		file.close();
	}

}

void carregar(std::string ficheiro, Fila_Armazem& fila) {

	fstream file(ficheiro, fstream::in);

	if (file.is_open() && file.good()) {

		string linha = "";
		Produto novo;
		while (true) {

			getline(file,linha);
			if (linha == "")
				break;

			novo = String_To_Produto(linha);
			adicionar(fila, criar_Produto(novo.nome, novo.area, novo.fornecedor, novo.resistência, novo.tempo_plantação, novo.tempo_rega));

		}
		file.close();

	}
	else {
		cout << "Não foi posível carregar!" << '\n' << "Porque ficheiro está corronpido ou não foi aberto corretamente ou já !" << endl;
		file.close();
	}

}

