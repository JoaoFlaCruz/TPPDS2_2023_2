/**
 * @file Dezena.hpp
 * @brief Definição da classe Dezena, derivada da classe Normal.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <vector>
#include "Normal.hpp"

/**
 * @brief Classe que representa uma aposta do tipo Dezena.
 */
class Dezena : public Normal {
public:
    /**
     * @brief Construtor da classe Dezena.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param valor Valor da aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     * @param apostas Array contendo as apostas do tipo Dezena.
     */
    Dezena(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 1> apostas);

    /**
     * @brief Destrutor da classe Dezena.
     */
    ~Dezena();

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
