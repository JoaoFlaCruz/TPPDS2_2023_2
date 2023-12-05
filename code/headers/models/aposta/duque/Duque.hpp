/**
 * @file Duque.hpp
 * @brief Definição da classe Duque, derivada da classe Aposta.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <array>
#include <vector>
#include "../Aposta.hpp"

/**
 * @brief Classe que representa uma aposta do tipo Duque.
 */
class Duque : public Aposta {
protected:
    std::vector<int> apostas_; ///< Guarda as apostas do Duque.

public:
    /**
     * @brief Construtor da classe Duque.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param valor Valor da aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     * @param apostas Array contendo as apostas do Duque.
     */
    Duque(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 2> apostas);

    /**
     * @brief Destrutor da classe Duque.
     */
    ~Duque();

    /**
     * @brief Getter para o atributo apostas.
     * @return Vetor contendo as apostas do Duque.
     */
    std::vector<int> apostas();
};
