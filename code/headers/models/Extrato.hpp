/**
 * @file Extrato.hpp
 * @brief Definição da classe Extrato.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <list>
#include <string>
#include <utility>

/**
 * @brief Estrutura para representar um extrato vazio.
 */
struct ExtratoVazio {};

/**
 * @brief Classe que representa um extrato de movimentações financeiras.
 */
class Extrato {
public:
    /**
     * @brief Construtor da classe Extrato.
     */
    Extrato();

    /**
     * @brief Retorna o tamanho do extrato.
     * @return O tamanho do extrato.
     */
    int tamanho();

    /**
     * @brief Retorna um extrato em ordem cronológica.
     * @return Lista de pares representando o extrato em ordem cronológica.
     * @pre O tamanho do extrato deve ser maior que zero.
     */
    std::list<std::pair<std::string, float>> extrato_por_ordem_cronologica();

    /**
     * @brief Retorna o extrato ordenado por ordem de valor.
     * @return Lista de pares representando o extrato ordenado por ordem de valor.
     * @pre O tamanho do extrato deve ser maior que zero.
     */
    std::list<std::pair<std::string, float>> ordenar_por_ordem_de_valor();

    /**
     * @brief Adiciona uma movimentação ao extrato.
     * @param descricao Descrição da movimentação.
     * @param valor Valor da movimentação.
     * @pre O valor passado deve ser válido.
     */
    void adicionar_movimentacao(std::string descricao, float valor);

    /**
     * @brief Exibe as movimentações do extrato.
     */
    void exibirMovimentacoes() const;

private:
    std::list<std::pair<std::string, float>> extrato_; ///< Lista de movimentações que guarda descrição e valor.
    int tamanho_; ///< Tamanho do extrato.
};
