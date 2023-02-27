
#include <iostream>
#include <string>
#include "estroturas.h"
#include "Fila_ProdutosTeste.h"

using namespace std;

Fila_Produtos::Fila_Produtos(std::string area) {
	this->area = area;
}

void Fila_Produtos::adicionar(Produto* produto){

	if (this->tamanho == 0 && (*produto).area == this->area) {

		this->ary = new Produto[1];
		this->ary[0] = *produto;
		this->tamanho = 1;
		
	}
	else if((*produto).area == this->area) {

		Produto* aux = new Produto[this->tamanho + 1];

		aux[tamanho] = *produto;
		for (int i = 0; i < this->tamanho; i++)
		{
			aux[i] = this->ary[i];
		}

		this->tamanho++;

		delete[] this->ary;
		this->ary = aux;

	}
}

void Fila_Produtos::remover() {

	if (this->tamanho - 1 >= 0) {

		Produto* aux = new Produto[this->tamanho - 1];

		for (int i = 1; i < this->tamanho; i++)
		{
			aux[i-1] = this->ary[i];
		}

		this->tamanho--;

		delete[] this->ary;
		this->ary = aux;

	}
}

Produto* Fila_Produtos::primeiro() {

	if (this->tamanho > 0)
		return &this->ary[0];
	else
		return NULL;

}