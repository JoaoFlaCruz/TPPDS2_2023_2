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

	//Saldo na carteira 
	float saldo_da_carteira();

	//Depositar na carteira 
	void depositar_na_carteira(float valor_a_ser_depositado);

	//Sacar na carteira 
	void sacar_na_carteira(float valor_a_ser_sacado);

	//Mostrar extrato
	Extrato extrato();
	
	//Adicinoar movimentação
	void adicionar_movimentacao(std::string descricao, float valor);


private:

	std::string nome_do_jogador_;//O mesmo nome que usuario
	Carteira carteira_;//Carteria do jogador

};
