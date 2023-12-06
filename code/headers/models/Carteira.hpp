/**
 * @file Carteira.hpp
 * @brief Definição da classe Carteira.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once
#include "Extrato.hpp"

/**
 * @brief Exceção lançada quando um valor é considerado inválido para operações na carteira.
 */
struct ValorInvalido {
	float valor; /**< Valor inválido. */
};

/**
 * @brief Exceção lançada quando uma tentativa de saque é maior que o saldo disponível na carteira.
 */
struct SaldoInsuficiente {
    float valor; /**< Valor do saque que resultou em saldo insuficiente. */

    /**
     * @brief Construtor que inicializa a exceção com o valor do saque.
     * @param valor Valor do saque.
     */
    SaldoInsuficiente(float valor) : valor(valor) {}
};

/**
 * @brief Classe que representa a carteira do jogador.
 */
class Carteira {
public:
	/**
	 * @brief Construtor padrão da Carteira.
	 */
	Carteira();

	/**
	 * @brief Retorna o saldo atual da carteira.
	 * @return Saldo da carteira.
	 */
	float saldo();

	/**
	 * @brief Retorna o extrato da carteira.
	 * @return Extrato da carteira.
	 */
	Extrato extrato();
	
	/**
	 * @brief Deposita um valor na carteira.
	 * @param valor Valor a ser depositado.
	 * @throw ValorInvalido se o valor não for maior que zero.
	 */
	void depositar(float valor);

	/**
	 * @brief Saca um valor da carteira.
	 * @param valor Valor a ser sacado.
	 * @throw ValorInvalido se o valor não for maior que zero.
	 * @throw SaldoInsuficiente se o valor do saque for maior que o saldo disponível na carteira.
	 */
	void sacar(float valor);
	
private:
	float saldo_; /**< Saldo atual da carteira. */
	Extrato extrato_; /**< Extrato da carteira. */
};
