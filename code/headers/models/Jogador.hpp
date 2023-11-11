#pragma once
#include "Sorteio.hpp"
#include "ListaSorteio.hpp"
#include "Carteira.hpp"

class Jogador {
public:
	//Apostar em um sorteio diponivel
	//Pré-condição: Sorteio tem que existir e estar diposnivel
	void apostar(Sorteio& sorteio_diponivel);

	//Retornar nome do jogador
	std::string nome();

	//Rerornar a carteira do jogador
	Carteira carteira();

	//Retornar a lista de sorteio participados
	ListaSorteio sorteios_participados();

	//Retornar CPF
	std::string cpf();

private:
	std::string nome_;
	std::string cpf_;
	Carteira carteira_;
	ListaSorteio sorteios_participados_;
};
