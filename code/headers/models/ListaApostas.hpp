#pragma once
#pragma once

#include "Aposta.hpp"
#include <list>

class Lista_apostas {
public:
	//Retorna o tamanho da lista 
	int tamanho();

	//Retorna a lista de apostas
	std::list<Aposta*> lista_de_aposta();

	//Adiciona uma nova aposta na lista
	//Pre-condição: a aposta não deve já existir na lista
	void adicionar_aposta(Aposta aposta);

	//Remove uma aposta na lista
	//Pre-Condição: deve existir essa aposta
	void remover_aposta(Aposta aposta);

private:
	std::list<Aposta*> lista_de_aposta_;
	int tamanho_;
};
