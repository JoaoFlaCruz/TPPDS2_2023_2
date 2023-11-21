#pragma once
#include "Sorteio.hpp"
#include <list>
//Realizar os tratamentos de excessões
//Testar

class ListaSorteios {
public:
	//Inicializa uma lista de sorteios vazia
	ListaSorteios();

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

	//Buscar sorteios em andamento 
	ListaSorteios sorteios_em_andamento();

	//Buscar sorteios feitos
	ListaSorteios sorteios_feitos();

	//Buscar sorteio por nome(Data e hora)
	Sorteio buscar_sorteio_por_data_e_horario(std::string data_e_horario);

	//Buscar participações de um jogador
	ListaSorteios buscar_participacao(std::string nome);

private:
	std::list<Sorteio> lista_de_sorteio_;
	int tamanho_;
};
