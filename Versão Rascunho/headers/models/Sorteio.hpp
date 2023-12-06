#pragma once
//Fazer a função verificar sorteio
//Testar

#include "ListaApostas.hpp"
#include <string>
#include <array>
struct SorteioAindaNaoSorteado {
	std::string data_e_horario;
};

struct DiaInvalido {
	int dia;
};
struct MesInvalido {
	int mes;
};
struct AnoInvalido {
	int ano;
};
struct HorarioInvalido {
	std::string horario;
};

class Sorteio {
public:
	//Inicializa um sorteio
	//Pre_condição: o formato da entrada tem que estar no padrão AA-AA-AAA/PTM

	Sorteio(std::string data_e_horario, std::string nome);

	//Inicializa um sorteio parcialmente preenchido (sorteio sem apostas)
	//Pre_condição: o formato da entrada tem que estar no padrão AA-AA-AAA/PTM
	Sorteio(std::string data_e_horario, std::string nome, std::array<int, 5> numeros_sorteados_, bool status);

	//Retorna a data e horario do sorteio
	std::string data_e_horario();

	std::string nome();

	//Retornar os numeros sorteados
	std::array<int, 5> resultados();

	//Retornar a lista de apostadas feitas
	ListaApostas apostas_feitas();

	//Retornar as apostas ganhas
	ListaApostas apostas_ganhas();

	//Retornar o status do sorteio
	bool status();

	//Sorteia 5 numeros
	void sortear();

	//Testa e Modifica os status das apostas e adiciona elas na lista de ganhadores
	//A seguencia dos numeros sorteados tem que ter tamanho igual a 5, ou seja, é
	// necessario já haver um sorteio
	void verificar_apostas_ganhas();

	void apostar(Aposta* aposta, std::string nome_do_sorteio);


private:

	std::string data_e_horario_;//Data e horario
	std::array<int, 5> numeros_sorteados_;
	ListaApostas apostas_feitas_;
	std::string nome_;
	bool status_; // 0 em andamento e 1 finalizado
	int gerar_numero_aleatorio();
};

