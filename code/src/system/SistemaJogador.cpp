#pragma once

#include "../models/Jogador.hpp"
#include "../models/Carteira.hpp"
#include "../models/ListaUsuario.hpp"
#include "../models/aposta/Aposta.hpp"
#include "../../headers/models/aposta/duque/DuqueDezena.hpp"
#include "../models/Login.hpp"

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
    SistemaJogador(ListaUsuario& listaUsuarios, ListaApostas& listaApostas);

    // Método para efetuar o login
    void login(const std::string& nome, const std::string& senha);

    // Método para efetuar o logout
    void logout();

    // Método para realizar uma aposta
    void realizarAposta(float valor, const std::array<int, 2>& apostas);

    // Método para exibir o extrato do jogador
    void exibirExtrato();

private:
    ListaUsuario& listaUsuarios_;
    ListaApostas& listaApostas_;
    Login login_;
};
