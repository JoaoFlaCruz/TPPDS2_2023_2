#pragma once
#include "Extrato.hpp"

//Pronta

struct ValorInvalido {
	float valor;
};

class Carteira {
public:
	//Inicializa uma carteira vazia 
	Carteira();

	//Retorna o saldo da carteira
	float saldo();

	//Retorna o extrato da carteira
	Extrato extrato();
	
	//Depositar
	//Pré-condição: valor tem que ser maior que zero e positivo
	void depositar(float valor);
	
private:
	float saldo_;
	Extrato extrato_;
};


