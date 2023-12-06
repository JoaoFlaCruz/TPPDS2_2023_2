/**
 * @file Sorteio.hpp
 * @brief Definição da classe Sorteio.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include "ListaApostas.hpp"
#include <string>
#include <array>
#include <random>
#include <regex>

/**
 * @brief Estrutura para representar uma exceção de sorteio ainda não realizado.
 */
struct SorteioAindaNaoSorteado {
    std::string data_e_horario; ///< Data e horário do sorteio.
};

/**
 * @brief Estrutura para representar uma exceção de dia inválido.
 */
struct DiaInvalido {
    int dia; ///< Dia inválido.
};

/**
 * @brief Estrutura para representar uma exceção de mês inválido.
 */
struct MesInvalido {
    int mes; ///< Mês inválido.
};

/**
 * @brief Estrutura para representar uma exceção de ano inválido.
 */
struct AnoInvalido {
    int ano; ///< Ano inválido.
};

/**
 * @brief Estrutura para representar uma exceção de horário inválido.
 */
struct HorarioInvalido {
    std::string horario; ///< Horário inválido.
};

/**
 * @brief Estrutura para representar uma exceção de formato de data e hora inválido.
 */
struct FormatoDataHoraInvalido {};

/**
 * @brief Classe que representa um sorteio.
 */
class Sorteio {
public:
    /**
     * @brief Construtor padrão da classe Sorteio.
     * Cria um sorteio vazio.
     */
    Sorteio() = default;

    /**
     * @brief Construtor da classe Sorteio.
     * Inicializa um sorteio com a data, horário e nome especificados.
     * @param data_e_horario A data e horário do sorteio no formato "AA-AA-AAA/PTM".
     * @param nome O nome do sorteio.
     * @throw FormatoDataHoraInvalido se o formato da entrada não estiver no padrão especificado.
     */
    Sorteio(std::string data_e_horario, std::string nome);

    /**
     * @brief Construtor da classe Sorteio.
     * Inicializa um sorteio parcialmente preenchido (sem apostas) com a data, horário, nome e números sorteados especificados.
     * @param data_e_horario A data e horário do sorteio no formato "AA-AA-AAA/PTM".
     * @param nome O nome do sorteio.
     * @param numeros_sorteados_ Os números sorteados no sorteio.
     * @param status O status do sorteio (0 para em andamento, 1 para finalizado).
     * @throw FormatoDataHoraInvalido se o formato da entrada não estiver no padrão especificado.
     */
    Sorteio(std::string data_e_horario, std::string nome, std::array<int, 5> numeros_sorteados_, bool status);

    /**
     * @brief Retorna a data e horário do sorteio.
     * @return A data e horário do sorteio.
     */
    std::string data_e_horario();

    /**
     * @brief Retorna o nome do sorteio.
     * @return O nome do sorteio.
     */
    std::string nome();

    /**
     * @brief Retorna os números sorteados no sorteio.
     * @return Os números sorteados.
     */
    std::array<int, 5> numeros_sorteados();

    /**
     * @brief Retorna a lista de apostas feitas no sorteio.
     * @return A lista de apostas feitas.
     */
    ListaApostas apostas_feitas();

    /**
     * @brief Retorna as apostas ganhas no sorteio.
     * @return As apostas ganhas.
     */
    ListaApostas apostas_ganhas();

    /**
     * @brief Retorna o status do sorteio.
     * @return O status do sorteio (0 para em andamento, 1 para finalizado).
     */
    bool status();

    /**
     * @brief Sorteia 5 números aleatórios.
     */
    void sortear();

    /**
     * @brief Testa e modifica o status das apostas e adiciona-as na lista de ganhadores.
     * A sequência dos números sorteados deve ter tamanho igual a 5, ou seja, é necessário já haver um sorteio.
     * @throw SorteioAindaNaoSorteado se nenhum sorteio foi realizado.
     */
    void verificar_apostas_ganhas();

private:
    std::string data_e_horario_; ///< Data e horário do sorteio.
    std::array<int, 5> numeros_sorteados_; ///< Números sorteados no sorteio.
    ListaApostas apostas_feitas_; ///< Lista de apostas feitas no sorteio.
    std::string nome_; ///< Nome do sorteio.
    bool status_; ///< Status do sorteio (0 para em andamento, 1 para finalizado).

    /**
     * @brief Gera um número aleatório entre 1 e 100.
     * @return O número aleatório gerado.
     */
    int gerar_numero_aleatorio();
};
