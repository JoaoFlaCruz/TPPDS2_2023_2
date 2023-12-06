#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

#include "./../system/SistemaAdmin.hpp"
#include "./../system/SistemaGeral.hpp"
#include "./../system/SistemaJogador.hpp"

/**
 * @brief Lista de possíveis estados para a interface.
 */
#define E0_PAG_INICIAL 0
#define E1_PAG_LOGIN_ADMIN 1
#define E2_PAG_ADMIN 2
#define E3_PAG_SORTEIO 3
#define E4_PAG_CADASTRAR_SORTEIO 4
#define E5_PAG_LISTAR_SORTEIO 5
#define E6_PAG_CARTEIRA_ADMIN 6
#define E7_PAG_JOGADOR 7
#define E8_PAG_CADASTRAR_JOGADOR 8
#define E9_PAG_LOGAR_JOGADOR 9
#define E10_PAG_SIS_JOGADOR 10
#define E11_PAG_APOSTA 11
#define E12_PAG_CADASTRAR_APOSTA 12
//#define E13_PAG_LISTAR_APOSTA 13
#define E14_PAG_CARTEIRA_JOGADOR 14

/**
 * @brief Exceção lançada para entrada inválida.
 */
struct EntradaInvalida {};

/**
 * @brief Exceção lançada para senha inválida.
 */
struct SenhaInvalida {};

/**
 * @brief Classe que representa a interface do sistema.
 */
class Interface {
private:
    int estado_;           ///< Estado atual da interface
    std::string msg_erro_; ///< Mensagem de erro
    bool erro_tratado_;    ///< Flag indicando se o erro foi tratado

    SistemaAdmin sis_admin_;   ///< Sistema Admin
    SistemaGeral sis_geral_;   ///< Sistema Geral
    SistemaJogador sis_jogador_; ///< Sistema do Jogador

public:
    /**
     * @brief Construtor padrão da interface.
     */
    Interface();

    /**
     * @brief Destrutor da interface.
     */
    ~Interface();

    // Comandos básicos de interface gráfica
    void limpar_tela();
    void cabecalho();
    void barra_final();
    void quebra_linha();
    void mensagem_de_erro();
    std::string entrada_comando();
    void logado();

    // Execução principal
    void executar();

    // Estados
    // E0_PAG_INICIAL
    void pagina_0_inicial();
    // E1_PAG_LOGIN_ADMIN
    void pagina_1_login_admin();
    // E2_PAG_ADMIN
    void pagina_2_admin();
    // E3_PAG_SORTEIO
    void pagina_3_sorteio();
    // E4_PAG_CADASTRAR_SORTEIO
    void pag_4_cadastrar_sorteio();
    // E5_PAG_LISTAR_SORTEIO
    void pag_5_listar_sorteio();
    // E6_PAG_CARTEIRA_ADMIN
    void pag_6_carteira_admin();

    // Estados relacionados ao SistemaJogador
    // E7_PAG_JOGADOR
    void pag_7_jogador();
    // E8_PAG_CADASTRAR_JOGADOR
    void pag_8_cadastrar_jogador();
    // E9_PAG_LOGAR_JOGADOR
    void pag_9_logar_jogador();
    // E10_PAG_SIS_JOGADOR
    void pag_10_jogador();
    // E11_PAG_APOSTA
    void pag_11_aposta();
    // E12_PAG_CADASTRAR_APOSTA
    void pag_12_cadastrar_aposta();
    // E14_PAG_CARTEIRA_JOGADOR
    void pag_14_carteira_jogador();
};
