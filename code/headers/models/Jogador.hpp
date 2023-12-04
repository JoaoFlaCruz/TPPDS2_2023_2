#pragma once
#include "Sorteio.hpp"
#include "Carteira.hpp"
#include "./aposta/normal/Grupo.hpp"
//Testar

class Jogador {
public:
	Jogador(std::string apelido);

	//Cria um jogador vazio (construtor padrão)
	Jogador();

	//Retornar apelido do jogador
	std::string nome_do_jogador();

	//Retornar a carteira do jogador
	Carteira carteira();

	void adicionar_fundos(float valor);
    void retirar_fundos(float valor);
    float saldo();

private:

	std::string nome_do_jogador_;//O mesmo nome que usuario
	Carteira carteira_;//Carteria do jogador

};
