#include <string>
#include "Horta.h"
#pragma once


void ColherProduto(horta ary[], int tamanho,std:: string prod);
void AtualizarRega(Fila_Armazem& fila,horta plantacao[], std::string nome, int capacidade, int novo_tempo);
void Fertilizacao(horta ary[],int duracao,std::string area,int capacidade);
void GravarPlantacao(horta plantacao[], int capacidade, Fila_Armazem& fila, std::string diretorio_plantacao, std::string diretorio_colhidos, std::string diretorio_armazem);
int CarregarPlantacao(horta*& plantacao, int capacidade, Fila_Armazem& fila, std::string diretorio_plantacao, std::string diretorio_colhidos, std::string diretorio_armazem);
void ImprimirPlantacao(Fila_Armazem& fila, horta plantacao[], int capacidade, char choice);
int CriarArea(std::string*& ary, int tamanho);
void RegistroAgricultor(horta ary[], int tamanho);
void AlterarArea(std::string areas_atuais[], int tamanho_areas_atuais, horta plantacao[], int capacidade);
