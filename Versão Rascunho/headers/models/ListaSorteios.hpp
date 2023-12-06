#pragma once
#include "Sorteio.hpp"
#include <list>

//Realizar os tratamentos de excessões
//Testar
struct ListaDeSorteioVazia {
};

struct SorteioInexistente {
	std::string data_e_horario_que_nao_existe;//Não existe construtor para esse tipo de aposta
};

struct SorteioJaExistente {
	std::string data_e_horario_ja_existente;
};

struct JogadorNaoParticipou {
	std::string nome_do_jogador;
};

struct DadosSorteio {
	std::string nome;
	std::string data_hora;
	bool status;
};

class ListaSorteios {
public:
	//Inicializa uma lista de sorteios vazia
	ListaSorteios();

	//Retorna o tamanho da lista
	int tamanho();

	//Retorna a lista de sorteio
	std::list<Sorteio> lista_de_sorteio();

	//Adiciona uma novo sorteio na lista
	//Pre-condição: o sorteio não deve já existir na lista
	void adicionar_sorteio(Sorteio sorteio);

	//Remove um sorteio na lista
	//Pre-Condição: deve existir esse sorteio
	//Pre_condição: tamanho da lista maior que zero
	void remover_sorteio(std::string data_e_horario);

	//Buscar sorteios em andamento
	//Pre_condição: tamanho da lista maior que zero
	ListaSorteios sorteios_em_andamento();

	//Buscar sorteios feitos
	//Pre_condição: tamanho da lista maior que zero
	ListaSorteios sorteios_feitos();

	//Buscar sorteio por nome
	Sorteio buscar_sorteio_por_nome(std::string nome_do_sorteio);

	//Buscar sorteio por nome(Data e hora)
	//Pre-Condição: deve existir esse sorteio
	//Pre_condição: tamanho da lista maior que zero
	Sorteio buscar_sorteio_por_data_e_horario(std::string data_e_horario);

	//Buscar participações de um jogador
	//Pre-Condição: deve existir pelo menos um sorteio participado
	ListaSorteios buscar_participacao(std::string nome_do_jogador);

	void apostar(Aposta* aposta, std::string nome_do_sorteio);

	void sortear(std::string nome_do_sorteio_a_ser_sortado);

	std::list<DadosSorteio> dados_sorteios();

private:
	std::list<Sorteio> lista_de_sorteio_;
	int tamanho_;
	bool pertence(std::string data_e_horario);
};