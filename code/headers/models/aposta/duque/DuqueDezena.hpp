/**
 * @file DuqueDezena.hpp
 * @brief Definição da classe DuqueDezena, derivada da classe Duque.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <vector>
#include "Duque.hpp"

/**
 * @brief Classe que representa uma aposta do tipo DuqueDezena.
 */
class DuqueDezena : public Duque {
private:
    const float ganho_ = GANHO_DUQUE_DEZENA; ///< Ganho de 300 para uma classe DuqueDezena.

public:
    /**
     * @brief Construtor da classe DuqueDezena.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param valor Valor da aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     * @param apostas Array contendo as apostas do DuqueDezena.
     */
    DuqueDezena(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 2> apostas);

    /**
     * @brief Destrutor da classe DuqueDezena.
     */
    ~DuqueDezena();

    /**
     * @brief Verifica a vitória com base no resultado e atualiza a variável "ganhou".
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
