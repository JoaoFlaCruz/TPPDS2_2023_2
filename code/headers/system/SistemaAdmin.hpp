/**
 * @file SistemaAdmin.hpp
 * @brief Definição da classe SistemaAdmin.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include "../models/ListaSorteios.hpp"
#include "../models/Sorteio.hpp"
#include "../models/ListaApostas.hpp"
#include "../models/aposta/Aposta.hpp"
#include "../models/Jogador.hpp"
#include "../models/Carteira.hpp"

#include <iostream>
#include <list>

/**
 * @brief Classe que representa o sistema administrativo.
 */
class SistemaAdmin {
private:
    ListaSorteios listaSorteios_; ///< Lista de sorteios disponíveis.
    Carteira carteira_; ///< Carteira do sistema administrativo.
    std::string senha_; ///< Senha do sistema administrativo.

public:
    /**
     * @brief Construtor da classe SistemaAdmin.
     */
    SistemaAdmin();

    /**
     * @brief Destrutor da classe SistemaAdmin.
     */
    ~SistemaAdmin();

    /**
     * @brief Validação de login no sistema administrativo.
     * @param senha A senha a ser validada.
     * @return true se a senha for válida, false caso contrário.
     */
    bool validar_senha(std::string senha);

    /**
     * @brief Cria um sorteio e o adiciona à lista de sorteios.
     * @param sorteio Referência para o sorteio a ser criado.
     */
    void criar_sorteio(Sorteio &sorteio);

    /**
     * @brief Realiza o sorteio e retorna o jogador vencedor.
     * @return O jogador vencedor do sorteio.
     */
    auto sortear() -> Jogador;

    /**
     * @brief Verifica o ganhador do sorteio mais recente.
     * @return O jogador ganhador do último sorteio.
     */
    Jogador verificar_ganhador();

    /**
     * @brief Realiza o pagamento para o jogador ganhador.
     * @param ganhador Referência para o jogador ganhador.
     */
    void realizar_pagamento(Jogador &ganhador);

    /**
     * @brief Adiciona um sorteio à lista de sorteios.
     * @param nome Nome do sorteio.
     * @param data Data do sorteio.
     */
    void adicionar_sorteio(std::string nome, std::string data);

    /**
     * @brief Remove um sorteio da lista de sorteios.
     * @param sorteio Referência para o sorteio a ser removido.
     */
    void remover_sorteio(Sorteio &sorteio);

    /**
     * @brief Exibe os detalhes de um sorteio.
     * @param sorteio Referência para o sorteio.
     */
    void exibir_detalhes_sorteio(Sorteio &sorteio);

    /**
     * @brief Retorna uma lista com os dados dos sorteios.
     * @return Lista contendo os dados dos sorteios.
     */
    std::list<DadosSorteio> dados_sorteios();

    /**
     * @brief Realiza o pagamento para um jogador específico.
     * @param jogador Referência para o jogador.
     * @param valor Valor a ser pago ao jogador.
     */
    void realizar_pagamento(Jogador &jogador, double valor);

    /**
     * @brief Adiciona dinheiro à carteira do sistema administrativo.
     * @param valor Valor a ser adicionado à carteira.
     */
    void adicionar_dinheiro(double valor);

    /**
     * @brief Retira dinheiro da carteira do sistema administrativo.
     * @param valor Valor a ser retirado da carteira.
     */
    void retirar_dinheiro(double valor);

    /**
     * @brief Retorna o saldo atual da carteira do sistema administrativo.
     * @return O saldo da carteira.
     */
    float retornar_saldo();
};
