#pragma once

#include "../models/Jogador.hpp"
#include "../models/Carteira.hpp"
#include "../models/ListaUsuario.hpp"
#include "../models/ListaSorteios.hpp"
#include "../models/aposta/Aposta.hpp"
#include "../../headers/models/aposta/duque/DuqueDezena.hpp"
#include "../models/Login.hpp"

struct OperacaoInvalida{

std::string mensagem;
};




struct LoginInvalido{

std::string mensagem;
};

struct ApostaInvalida{

std::string mensagem;
};


struct ExtratoInvalido{

std::string mensagem;
};

class SistemaJogador {
public:

    SistemaJogador();
    const Login& obterLogin() const;
    const ListaUsuario& obterListaUsuarios() const;
    const ListaApostas& obterListaApostas() const;

    void login(const std::string& nome, const std::string& senha);
    void logout();
    void realizarAposta(float valor, const std::array<int, 2>& apostas);
    void exibirExtrato();

    void adicionar_dinheiro(double valor);
    void retirar_dinheiro(double valor);
    void realizar_pagamento(Jogador& jogador, double valor);
    float retornar_saldo();

    void cadastrar_usuario(std::string apelido, std::string login, std::string senha, std::string cpf);
    bool logado();

private:
    Login login_;
    ListaApostas listaApostas_;
    ListaUsuario listaUsuarios_;
};
