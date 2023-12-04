#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

#include "./../system/SistemaAdmin.hpp"
#include "./../system/SistemaGeral.hpp"
#include "./../system/SistemaJogador.hpp"

//Lista de possíveis estados
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

//Excecoes lançadas
struct EntradaInvalida {};
struct SenhaInvalida {};

class Interface {
private:
    int estado_;
    std::string msg_erro_;
    bool erro_tratado_;

    SistemaAdmin sis_admin_;
    SistemaGeral sis_geral_;
    SistemaJogador sis_jogador_;

public:
    Interface();
    ~Interface();

    // Comandos básicos de interface gráfica
    void limpar_tela();
    void cabecalho();
    void barra_final();
    void quebra_linha();
    void mensagem_de_erro();
    int entrada_comando();
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
    // E_PAG_CARTEIRA_JOGADOR
    void pag_carteira_jogador();

};

// INTERFACE_HPP
