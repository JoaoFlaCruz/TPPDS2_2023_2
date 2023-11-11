#pragma once
#include "Extrato.hpp"
class Carteira {
public:
	//Retorna o saldo da carteira
	float saldo();

	//Depositar
	//Pré-condição: valor tem que ser valido
	void depositar(float valor);
	
	//Receber valor da banca
	//Pré-condição: valor tem que ser valido
	void receber(float valor);

	//Pagar banca
	//Pré-condição: valor tem que ser valido
	void pagar(float valor);

private:
	float saldo_;
	Extrato extrato_;
};
