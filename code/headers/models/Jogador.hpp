/**
 * @file Jogador.hpp
 * @brief Definição da classe Jogador.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include "Sorteio.hpp"
#include "Carteira.hpp"
#include "./aposta/normal/Grupo.hpp"

/**
 * @brief Classe que representa um jogador.
 */
class Jogador {
public:
    /**
     * @brief Construtor da classe Jogador.
     * @param apelido Apelido do jogador.
     */
    Jogador(std::string apelido);

    /**
     * @brief Construtor padrão da classe Jogador.
     * Cria um jogador vazio.
     */
    Jogador();

    /**
     * @brief Retorna o apelido do jogador.
     * @return O apelido do jogador.
     */
    std::string nome_do_jogador();

    /**
     * @brief Retorna a carteira do jogador.
     * @return A carteira do jogador.
     */
    Carteira carteira();

    /**
     * @brief Adiciona fundos à carteira do jogador.
     * @param valor O valor a ser adicionado.
     */
    void adicionar_fundos(float valor);

    /**
     * @brief Retira fundos da carteira do jogador.
     * @param valor O valor a ser retirado.
     */
    void retirar_fundos(float valor);

    /**
     * @brief Retorna o saldo da carteira do jogador.
     * @return O saldo da carteira do jogador.
     */
    float saldo();

private:
    std::string nome_do_jogador_; ///< O apelido do jogador, o mesmo que o nome de usuário.
    Carteira carteira_; ///< A carteira do jogador.
};
