/**
 * @file Terno.hpp
 * @brief Definição da classe Terno, derivada da classe Aposta.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <array>
#include <vector>
#include "../Aposta.hpp"

/**
 * @brief Classe que representa uma aposta do tipo Terno.
 */
class Terno : public Aposta {
protected:
    std::vector<int> apostas_; ///< Guarda as apostas do Terno.

public:
    /**
     * @brief Construtor da classe Terno.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param valor Valor da aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     * @param apostas Array contendo as apostas do Terno.
     */
    Terno(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 3> apostas);

    /**
     * @brief Destrutor da classe Terno.
     */
    ~Terno();

    /**
     * @brief Getter para o atributo apostas.
     * @return Vetor contendo as apostas do Terno.
     */
    std::vector<int> apostas();
};
