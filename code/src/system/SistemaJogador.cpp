#include "./../../headers/system/SistemaJogador.hpp"
#include <iostream>
SistemaJogador::SistemaJogador(ListaUsuario& listaUsuarios, ListaApostas& listaApostas) 
    : listaUsuarios_(listaUsuarios), listaApostas_(listaApostas), login_() {}

// Método para efetuar o login
void SistemaJogador::login(const std::string& nome, const std::string& senha) {
    Usuario usuario = listaUsuarios_.buscarUsuario(nome);

    // Verifica se o jogador existe
    if (usuario.nome() == "") {
        throw LoginInvalido{};
    }

    // Verifica se a senha está correta
    if (usuario.senha() != senha) {
        throw LoginInvalido{};
    }

    // Define o usuário logado
    login_.definirUsuarioLogado(usuario);
}
// Método para efetuar o logout
void SistemaJogador::logout() {
    login_.desconectarUsuario();
}

// Método para realizar uma aposta
void SistemaJogador::realizarAposta(float valor, const std::array<int, 2>& apostas) {
    if (!login_.haUsuarioLogado()) {
        throw ApostaInvalida{};
    }

    Jogador jogador = login_.obterUsuarioLogado().jogador();

    if (jogador.carteira().saldo() < valor) {
        throw ApostaInvalida{};
    }

    DuqueDezena aposta(login_.obterUsuarioLogado().nome(), valor, true, apostas);
    jogador.carteira().sacar(valor);
    listaApostas_.adicionar_aposta(aposta);
}
// Método para exibir o extrato do jogador
void SistemaJogador::exibirExtrato() {
    if (!login_.haUsuarioLogado()) {
        throw ExtratoInvalido{};
    }

    Jogador jogador = login_.obterUsuarioLogado().jogador();
    Extrato extrato = jogador.carteira().extrato();
    std::cout << "Extrato do jogador " << login_.obterUsuarioLogado().nome() << ":\n";
    extrato.exibirMovimentacoes();
}
