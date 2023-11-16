#pragma once
#include "Sorteio.hpp"
#include "ListaSorteios.hpp"
#include "Carteira.hpp"
#include "aposta/Grupos.hpp"

class Jogador {
public:
	//*Ainda a determinar quem e como fará a aposta
	//Apostar em um sorteio diponivel
	//Para apostar em um sorteio disponivel
	Aposta* apostar(Grupos grupo_apostado);

	//Retornar nome do jogador
	std::string nome();

	//Retornar a carteira do jogador
	Carteira carteira();

	//Retornar a lista de sorteio participados
	ListaSorteios sorteios_participados();

private:
	//*Ainda a determinar se o mesmo nome do usuario
	std::string apelido_;
	Carteira carteira_;
	ListaSorteios sorteios_participados_;
};
