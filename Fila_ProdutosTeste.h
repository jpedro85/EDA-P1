#pragma once

#include <string>
#include "estroturas.h"

struct Fila_Produtos
{
	Fila_Produtos(std::string area);

	std::string area = "";
	int tamanho = 0;

	Produto* primeiro();
	void adicionar(Produto* produto);
	void remover();

private:
	Produto* ary = NULL;

};