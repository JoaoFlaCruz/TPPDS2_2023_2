#pragma once
#pragma once

#include "aposta/Aposta.hpp"
#include <list>
//Testar 
struct ListaDeApostaVazia {
};

struct ApostaInexistente {
	Aposta aposta_que_nao_existe;//Não existe construtor para esse tipo de aposta
};

class ListaApostas {
public:
	//Cria uma lista de apostas vazia
	ListaApostas();

	//Retorna a lista de apostas
	std::list<Aposta> lista_de_aposta();

	//Retorna o tamanho da lista 
	int tamanho();

	//Adiciona uma nova aposta na lista
	void adicionar_aposta(Aposta* aposta);//

	//Remove uma aposta na lista
	//Pre-Condição: deve existir a aposta a ser removida
	//Pre-condicao: o tamanho da lista tem que ser maior que zero 
	void remover_aposta(Aposta aposta);//
	
	//Buscar aposta que ganharam
	ListaApostas apostas_ganhas();

	//Libera todo espaço reservado para os conteudos da lista
	~ListaApostas();

	void verificar_apostas_ganhas(std::array<int, 5> resultados);

private:
	std::list<Aposta*> lista_de_aposta_;
	int tamanho_;
	bool pertence(Aposta aposta);
};
