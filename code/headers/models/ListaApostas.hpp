/**
 * @file ListaApostas.hpp
 * @brief Definição da classe ListaApostas.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include "aposta/Aposta.hpp"
#include <list>

/**
 * @brief Estrutura para representar uma lista de apostas vazia.
 */
struct ListaDeApostaVazia {};

/**
 * @brief Estrutura para representar uma aposta inexistente na lista.
 */
struct ApostaInexistente {
    Aposta aposta_que_nao_existe; ///< Aposta inexistente, não existe construtor para esse tipo de aposta.
};

/**
 * @brief Classe que representa uma lista de apostas.
 */
class ListaApostas {
public:
    /**
     * @brief Construtor da classe ListaApostas.
     * Cria uma lista de apostas vazia.
     */
    ListaApostas();

    /**
     * @brief Retorna a lista de apostas.
     * @return A lista de apostas.
     */
    std::list<Aposta> lista_de_aposta();

    /**
     * @brief Retorna o tamanho da lista de apostas.
     * @return O tamanho da lista de apostas.
     */
    int tamanho();

    /**
     * @brief Adiciona uma nova aposta à lista.
     * @param aposta A aposta a ser adicionada.
     */
    void adicionar_aposta(Aposta aposta);

    /**
     * @brief Remove uma aposta da lista.
     * @param aposta A aposta a ser removida.
     * @pre Deve existir a aposta a ser removida.
     * @pre O tamanho da lista deve ser maior que zero.
     */
    void remover_aposta(Aposta aposta);

    /**
     * @brief Busca e retorna uma lista de apostas que foram ganhas.
     * @return A lista de apostas ganhas.
     */
    ListaApostas apostas_ganhas();

    /**
     * @brief Destrutor da classe ListaApostas.
     * Libera todo o espaço reservado para os conteúdos da lista.
     */
    ~ListaApostas();

private:
    std::list<Aposta> lista_de_aposta_; ///< Lista de apostas.
    int tamanho_; ///< Tamanho da lista de apostas.

    /**
     * @brief Verifica se uma aposta pertence à lista.
     * @param aposta A aposta a ser verificada.
     * @return True se a aposta pertence à lista, false caso contrário.
     */
    bool pertence(Aposta aposta);
};
