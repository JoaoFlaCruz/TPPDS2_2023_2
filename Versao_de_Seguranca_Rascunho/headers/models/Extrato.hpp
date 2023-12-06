#pragma once

#include <list>
#include <string>
#include <utility>
//Pronto
struct ExtratoVazio {
};

class Extrato {
	
public:
	//Inicializa um extrato vazio
	Extrato();


	//Retorna o tamanho da lista
	int tamanho();

	//Retorna um extrato por padrão em ordem cronologica
	//Pré-condição:tamanho do extrato deve ser maior que zero
	std::list<std::pair<std::string, float>> extrato_por_ordem_cronologica();

	//Pré-condição:tamanho do extrato deve ser maior que zero
	//Retornar a lista em ordem de maior valor
	std::list<std::pair<std::string, float>> ordenar_por_ordem_de_valor();

	//Adiciona uma movimentação
	//Pré-condição: o valor passado tem que ser valido
	void adicionar_movimentacao(std::string descricao, float valor);

private:
	//Lista de movimentações que guarda se recebido, depositado ou pago, data e valor 
	std::list<std::pair<std::string, float>> extrato_;
	int tamanho_;
};
