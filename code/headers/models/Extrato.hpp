#pragma once
#include "Extrato.hpp"

//Pronta

struct ValorInvalido {
	float valor;
};

struct SaldoInsuficiente {
    float valor;

    SaldoInsuficiente(float valor) : valor(valor) {}
};

class Carteira {
public:
	//Inicializa uma carteira vazia 
	Carteira();

	//Retorna o saldo da carteira
	float saldo();

	//Retorna o extrato da carteira
	Extrato extrato();

	//Adiciona uma movimentação
	//Pré-condição: o valor passado tem que ser valido
	void adicionar_movimentacao(std::string descricao, float valor);
	
	//Depositar
	//Pré-condição: valor tem que ser maior que zero e positivo
	void depositar(float valor);

	//Sacar
	//Pré-condição: valor tem que ser maior que zero e menor que o saldo
	void sacar(float valor);
	
private:
	float saldo_;
	Extrato extrato_;
};




