/**
 * @file Grupo.hpp
 * @brief Definição da classe Grupo, derivada da classe Normal.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <vector>
#include "Normal.hpp"

/**
 * @brief Classe que representa uma aposta do tipo Grupo.
 */
class Grupo : public Normal {
public:
    /**
     * @brief Construtor da classe Grupo.
     * @param valor Valor da aposta.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     * @param apostas Array contendo as apostas do tipo Grupo.
     */
    Grupo(float valor, std::string nome_do_jogador, bool cabeca, std::array<int, 1> apostas);

    /**
     * @brief Destrutor da classe Grupo.
     */
    ~Grupo();

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
