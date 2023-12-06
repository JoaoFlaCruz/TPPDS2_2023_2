/**
 * @file TernoDezena.hpp
 * @brief Definição da classe TernoDezena, derivada da classe Terno.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <vector>
#include "Terno.hpp"

/**
 * @brief Classe que representa uma aposta do tipo TernoDezena.
 */
class TernoDezena : public Terno {
private:
    const float ganho_ = GANHO_TERNO_DEZENA; ///< Ganho de 300 para uma classe TernoDezena.

public:
    /**
     * @brief Construtor da classe TernoDezena.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param valor Valor da aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     * @param apostas Array contendo as apostas do TernoDezena.
     */
    TernoDezena(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 3> apostas);

    /**
     * @brief Destrutor da classe TernoDezena.
     */
    ~TernoDezena();

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
