/**
 * @file Centena.hpp
 * @brief Definição da classe Centena, derivada da classe Normal.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <vector>
#include "Normal.hpp"

/**
 * @brief Classe que representa uma aposta do tipo Centena.
 */
class Centena : public Normal {
private:
    const float ganho_ = GANHO_CENTENA; ///< Ganho associado a uma aposta do tipo Centena.

public:
    /**
     * @brief Construtor da classe Centena.
     * @param valor Valor da aposta.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     * @param apostas Array contendo as apostas do tipo Centena.
     */
    Centena(float valor, std::string nome_do_jogador, bool cabeca, std::array<int, 1> apostas);

    /**
     * @brief Destrutor da classe Centena.
     */
    ~Centena();

    /**
     * @brief Verifica a vitória com base no resultado e atualiza a variável "ganho".
     * @param resultado Array contendo o resultado do jogo.
     */
    void verificar_vitoria(std::array<int, 5> resultado);

    /**
     * @brief Sobrescreve o operador de igualdade para comparar com outra aposta.
     * @param outra A outra aposta a ser comparada.
     * @return True se as apostas forem iguais, false caso contrário.
     */
    bool operator==(Aposta outra) override;
};
