#include "./../../headers/system/SistemaJogador.hpp"
#include <iostream>

SistemaJogador::SistemaJogador(ListaApostas& listaApostas, ListaUsuario& listaUsuarios)
    : listaApostas_(listaApostas), listaUsuarios_(listaUsuarios) {
    // Inicializações adicionais, se necessário.
}

const Login& SistemaJogador::obterLogin() const {
    return login_;
}

const ListaUsuario& SistemaJogador::obterListaUsuarios() const {
    return listaUsuarios_;
}

const ListaApostas& SistemaJogador::obterListaApostas() const {
    return listaApostas_;
}

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

void SistemaJogador::logout() {
    login_.desconectarUsuario();
}

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

void SistemaJogador::exibirExtrato() {
    if (!login_.haUsuarioLogado()) {
        throw ExtratoInvalido{};
    }

    Jogador jogador = login_.obterUsuarioLogado().jogador();
    Extrato extrato = jogador.carteira().extrato();
    std::cout << "Extrato do jogador " << login_.obterUsuarioLogado().nome() << ":\n";
    extrato.exibirMovimentacoes();
}

void SistemaJogador::adicionar_dinheiro(double valor) {
    if (!login_.haUsuarioLogado()) {
        throw OperacaoInvalida{};
    }

    Jogador jogador = login_.obterUsuarioLogado().jogador();
    jogador.carteira().depositar(valor);
}

void SistemaJogador::retirar_dinheiro(double valor) {
    if (!login_.haUsuarioLogado()) {
        throw OperacaoInvalida{};
    }

    Jogador jogador = login_.obterUsuarioLogado().jogador();
    jogador.carteira().sacar(valor);
}


float SistemaJogador::retornar_saldo() {
    if (!login_.haUsuarioLogado()) {
        throw OperacaoInvalida{};
    }

    Jogador jogador = login_.obterUsuarioLogado().jogador();
    return jogador.carteira().saldo();
}

