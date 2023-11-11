#pragma once
#include <list>
#include <string>
#include <map>

class Extrato {
public:
	//Retorna um extrato
	//Pré-condição:tamanho do extrato deve ser maior que zero
	std::list<std::map<std::string, float>> extrato();

	//Adiciona uma movimentação
	//Pré-condição: o valor passado tem que ser valido
	void adicionar_movimentacao(std::map<std::string, float>);

	//Pré-condição:tamanho do extrato deve ser maior que zero
	//Retornar a lista em ordem cronologica
	std::list<std::map<std::string, float>> ordenar_cronologicamente();

	//Pré-condição:tamanho do extrato deve ser maior que zero
	//Retornar a lista em ordem de maior valor
	std::list<std::map<std::string, float>> ordenar_por_valor();

	//Retorna o tamanho da lista
	int tamanho();

private:
	//Lista de movimentações que guarda a se recebido, depositado ou pago, data,  e valor 
	std::list<std::map<std::string, float>> extrato_;
	int tamanho_;
};
