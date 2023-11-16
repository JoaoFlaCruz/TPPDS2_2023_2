#pragma once
#include "Extrato.hpp"
class Carteira {
public:
	//Inicializa uma carteira vazia 
	Carteira();

	//Retorna o saldo da carteira
	float saldo();

	//Retorna o extrato da carteira
	Extrato extrato();
	
	//Depositar
	//Pré-condição: valor tem que ser maior que zero
	void depositar(float valor);

	//*Indefinido ainda quem irá pagar
	//Pagar banca
	//Pré-condição: valor tem que ser valido e menor que o saldo e maior que zero
	void pagar(float valor);
	
private:
	float saldo_;
	Extrato extrato_;
};
