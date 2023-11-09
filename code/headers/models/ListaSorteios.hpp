#pragma once
#include "Sorteio.hpp"
#include <list>

class Lista_sorteio {
public:
	//Retorna o tamanho da lista 
	int tamanho();

	//Retorna a lista de sorteio
	std::list<Sorteio> lista_de_sorteio();

	//Adiciona uma nova aposta na lista
	//Pre-condição: a aposta não deve já existir na lista
	void adicionar_sorteio(Sorteio sorteio);

	//Remove uma aposta na lista
	//Pre-Condição: deve existir essa aposta
	void remover_sorteio(Sorteio sorteio);

private:
	std::list<Sorteio> lista_de_sorteio_;
	int tamanho_;
};
