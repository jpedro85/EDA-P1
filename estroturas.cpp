
#include <iostream>
#include "estroturas.h"

using namespace std;

/*
//Funções para Fila_Produtos
//adiciona o elemneto ao fim do da fila
void adicionar(Fila_Produtos& fila, Produto produto) {

	// dois casos especiais:
	//1-caso a fila tenha 0 elementos,
	//2-caso a fila já tenha elementos,

	if (fila.tamanho == 0 && produto.area == fila.area) { 

		fila.ary = new Produto[1];
		fila.ary[0] = produto;
		fila.tamanho++;

	}
	else if (produto.area == fila.area) {

		Produto* aux = new Produto[fila.tamanho + 1]; //cria auxiliar maior que o tamanho em 1
		
		for (int i = 0; i < fila.tamanho; i++) //copia todos os valores do array principal para o auxiliar
		{
			aux[i] = fila.ary[i];
		}
		aux[fila.tamanho] = produto; //adiciona o novo produto ao fim
		fila.tamanho++; //atualiza o tamanho

		delete[] fila.ary; //limpa a memória do aaray principal 
		fila.ary = aux; //atribiu o array auxiliar ao principal
	}
}
//removeo primeiro
void remover(Fila_Produtos& fila) {
	
	/*
		2 casos possíveis:
		-(1) caso a fila tenha um só elemento,
		-(2) caso a fila tenha mais que um elemento

		só remove se a fila não estiver vaizia
	*//*
	if (fila.tamanho > 1){

		//(2) 
		Produto* aux = new Produto[fila.tamanho - 1]; //cira um auxiliar menor em 1

		for (int i = 1; i < fila.tamanho; i++) //copia todos os valores exeto o primeiro
		{
			aux[i-1] = fila.ary[i];
		}
		fila.tamanho--;//atualiza o tamanho

		delete[] fila.ary; //limpa a memória do aaray principal 
		fila.ary = aux;	//atribui o array auxiliar ao principal
	}
	else if(fila.tamanho > 0) {

		//(1) repõe todos os valores da fila
		delete[] fila.ary;  
		fila.ary = NULL; 
		fila.tamanho = 0;
	}
}
// devolve o primeiro
Produto* primeiro(Fila_Produtos& fila) {

	if (fila.tamanho > 0)
		return &fila.ary[0];
	else
		return NULL;
}

//Funções para Fila_Armazem
//adiciona o elemneto ao armazem
void adicionar(Fila_Armazem& fila, Produto produto){

	for (int i = 0; i < fila.tamanho; i++)
	{
		if(fila.ary_armazem[i].area == produto.area) {
		

		
		}
		else if (i + 1 == fila.tamanho) {

			Fila_Armazem::Fila_Armario* aux = new Fila_Armazem::Fila_Armario[fila.tamanho + 1];
			Fila_Armazem::Fila_Armario novo_armario;
			novo_armario.area = produto.area;



		}

	}

}
*/


//adiciona o elemneto ao fim do da fila
/*
void adicionar(Fila_Armazem& fila, Produto produto) {

	if (fila.len_armazem == 0){

		Fila_Armazem::Fila_Armario::Fila_Prateleira nova_prateleira;
		nova_prateleira.nome = produto.nome;
		nova_prateleira.ary_prateleira = new Produto[1];
		nova_prateleira.len_prateleira = 1;
		nova_prateleira.ary_prateleira[0] = produto; //adiciona o novo produto á prateleira

		Fila_Armazem::Fila_Armario novo_armario;
		novo_armario.area = produto.area;
		novo_armario.ary_armario = new Fila_Armazem::Fila_Armario::Fila_Prateleira[1];
		novo_armario.len_armario = 1;
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
		for (int i_armario = 0; fila.len_armazem > 0 && i_armario < fila.len_armazem; i_armario++)
		{
			//para cada prateleira se houver pelo menos 1
			for (int i_prateleira = 0; fila.len_armazem > 0 && i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
			{
				//para cada produto se houver pelo menos 1; != Null porque quão se deleta o ultimo elemento não é posivel aceder a
				for (int i_produto = 0; fila.len_armazem > 0 && i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira ; i_produto++)
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

								}
								else {
									//remorver armario
									//delete fila.ary_armazem[i_armario].ary_armario;

									Fila_Armazem::Fila_Armario* auxiliar = new Fila_Armazem::Fila_Armario[fila.len_armazem - 1];
									for (int i = 0; i+1 < fila.len_armazem; i++)
									{
										if (i < i_armario)
											auxiliar[i] = fila.ary_armazem[i];
										else if (i >= i_armario)
											auxiliar[i] = fila.ary_armazem[i+1];
									}

									delete[] fila.ary_armazem;
									fila.ary_armazem = auxiliar;
									fila.len_armazem--;
									fila.n_produtos--;
								}

							}
							else {

								//remorver prateleira
								Fila_Armazem::Fila_Armario::Fila_Prateleira* armario_auxiliar = new Fila_Armazem::Fila_Armario::Fila_Prateleira[fila.ary_armazem[i_armario].len_armario - 1];
								for (int i = 0; i+1 < fila.ary_armazem[i_armario].len_armario ; i++)
								{
									if (i < i_prateleira)
										armario_auxiliar[i] = fila.ary_armazem[i_armario].ary_armario[i];
									else if (i >= i_prateleira)
										armario_auxiliar[i] = fila.ary_armazem[i_armario].ary_armario[i + 1];
								}
								delete[] fila.ary_armazem[i_armario].ary_armario;
								fila.ary_armazem[i_armario].ary_armario = armario_auxiliar;
								fila.ary_armazem[i_armario].len_armario--;
								fila.n_produtos--;

							}
						}
						else {

							//remorver prodtuto
							Produto* prateleira_auxiliar = new Produto[fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira - 1];
							for (int i = 0; i+1 < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira ; i++)
							{
								if (i < i_produto)
									prateleira_auxiliar[i] = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i];
								else if (i >= i_produto)
									prateleira_auxiliar[i] = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i+1];
							}
							delete[] fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira;
							fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira = prateleira_auxiliar;
							fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira--;
							fila.n_produtos--;

							break;
						}
					}
				}
			}
		}
	}
}

Produto* get_Produto(Fila_Armazem& fila, int indice) {

	if(fila.len_armazem > 0 && indice < fila.n_produtos){
		
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

								Produto * novo = new Produto;
								novo->area = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].area; 
								novo->fornecedor = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].fornecedor;
								novo->nome = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].nome;
								novo->resistência = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].resistência;
								novo->tempo_plantação = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].tempo_plantação;
								novo->tempo_rega = fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].tempo_rega;

								return novo; //retorna o produto

							}

						}
					
					}else //se nao houver produtos
						return NULL;
				}

			}
			else // se nao houver prateleiras
				return NULL;
		}

	}else // se nao houver armarios
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
			for (int i_produto = 0; i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++){

				contador++;// conta a posição atual do produto
			}
		}
	}    

	return contador;

}

void verificar(Fila_Armazem& fila, int& armarios_repetidos , int& prateleiras_repetidas) {

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

void esrcrever_armazem(Fila_Armazem& fila) {
	
	for (int i_armario = 0; i_armario < fila.len_armazem; i_armario++)
	{
		//para cada prateleira
		for (int i_prateleira = 0; i_prateleira < fila.ary_armazem[i_armario].len_armario; i_prateleira++)
		{
			cout << "armario: " << i_armario << " prateleira: " << i_prateleira << "|" << fila.n_produtos << "{" << endl;
			//para cada produto
			for (int i_produto = 0; i_produto < fila.ary_armazem[i_armario].ary_armario[i_prateleira].len_prateleira; i_produto++) {


				cout << "are: " << fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].area << " fornecedor: " << fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].fornecedor << " nome:" << fila.ary_armazem[i_armario].ary_armario[i_prateleira].ary_prateleira[i_produto].nome << endl;
				

			}
			cout << "}" << endl;
		}
	}

}


*/
