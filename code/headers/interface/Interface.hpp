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
#define E1_PAG_ADMIN 2

//Excecoes lançadas
struct EntradaInvalida {};
struct SenhaInvalida {};

class Interface{
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

        // Execução principal
        void executar();

        // Estados
        // E0_PAG_INICIAL
        void pagina_0_inicial();
        // E1_PAG_LOGIN_ADMIN
        void pagina_1_login_admin();
        // E2_PAG_ADIM
        void pagina_2_admin();
};
