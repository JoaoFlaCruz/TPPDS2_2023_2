#pragma once

#include "ListaApostas.hpp"
#include <string>
#include <array>

class Sorteio {
public:
	//Retornar os numeros sorteados
	std::array<int, 5> numeros_sorteados();

	//Retornar a lista de apostadas feitas
	Lista_de_apostas apostas_feitas();

	//Retornar as apostas ganhas 
	Lista_de_apostas apostas_ganhas();

	//Retronar o status do sorteio
	bool status();

	//Inicializa um sorteio
	Sorteio(std::string nome);

	//Sorteia 5 numeros
	void sortear();

	//Modifica os status das apostas e adiciona elas na lista de ganhadores
	//Altera o valor dos status das apostas
	void verificar_apostas_ganhas();

private:
	std::string nome_;
	std::array<int, 5> numeros_sorteados_;
	Lista_de_apostas apostas_feitas_;
	Lista_de_apostas apostas_ganhas_;
	bool status_; // 0 em andamento e 1 finalizado
	int gerar_numero_aleatorio();
};

