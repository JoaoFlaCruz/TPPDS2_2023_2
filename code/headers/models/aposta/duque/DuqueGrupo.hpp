/**
 * @file DuqueGrupo.hpp
 * @brief Definição da classe DuqueGrupo, derivada da classe Duque.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <vector>
#include "Duque.hpp"

/**
 * @brief Classe que representa uma aposta do tipo DuqueGrupo.
 */
class DuqueGrupo : public Duque {
private:
    const float ganho_ = GANHO_DUQUE_GRUPO; ///< Ganho de 18.5 para uma classe DuqueGrupo.

public:
    /**
     * @brief Construtor da classe DuqueGrupo.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param valor Valor da aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     * @param apostas Array contendo as apostas do DuqueGrupo.
     */
    DuqueGrupo(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 2> apostas);

    /**
     * @brief Destrutor da classe DuqueGrupo.
     */
    ~DuqueGrupo();

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
