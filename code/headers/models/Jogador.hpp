#pragma once
#include "Sorteio.hpp"
#include "Carteira.hpp"
#include "aposta/Grupos.hpp"
//Testar

class Jogador {
public:
	Jogador(std::string apelido);

	//Retornar apelido do jogador
	std::string apelido();

	//Retornar a carteira do jogador
	Carteira carteira();

private:

	std::string apelido_;//O mesmo nome que usuario
	Carteira carteira_;//Carteria do jogador

};
