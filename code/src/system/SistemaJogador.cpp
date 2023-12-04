#include "./../../headers/system/SistemaJogador.hpp"
#include <iostream>

// Construtor da classe SistemaJogador
SistemaJogador::SistemaJogador(){
    // Inicialize listaApostas_ e listaUsuarios_ aqui com objetos válidos

    ListaApostas listaApostas_;
    ListaUsuario listaUsuarios_;

    
}

// Método para obter o objeto Login
const Login& SistemaJogador::obterLogin() const {
    return login_;
}

// Método para obter a lista de usuários
const ListaUsuario& SistemaJogador::obterListaUsuarios() const {
    return listaUsuarios_;
}

// Método para obter a lista de apostas
const ListaApostas& SistemaJogador::obterListaApostas() const {
    return listaApostas_;
}

// Método para realizar o login
void SistemaJogador::login(const std::string& nome, const std::string& senha) {
    // Busca o usuário na lista de usuários
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

// Método para realizar o logout
void SistemaJogador::logout() {
    login_.desconectarUsuario();
}

// Método para realizar uma aposta
void SistemaJogador::realizarAposta(float valor, const std::array<int, 2>& apostas) {
    if (!login_.haUsuarioLogado()) {
        throw ApostaInvalida{};
    }

    // Obtém o jogador logado
    Jogador jogador = login_.obterUsuarioLogado().jogador();

    // Verifica se o saldo é suficiente para a aposta
    if (jogador.carteira().saldo() < valor) {
        throw ApostaInvalida{};
    }

    // Cria uma aposta DuqueDezena com as informações fornecidas
    DuqueDezena aposta(login_.obterUsuarioLogado().nome(), valor, true, apostas);

    // Realiza o saque do valor da aposta na carteira do jogador
    jogador.carteira().sacar(valor);

    // Adiciona a aposta à lista de apostas
    listaApostas_.adicionar_aposta(aposta);
}

// Método para exibir o extrato do jogador
void SistemaJogador::exibirExtrato() {
    if (!login_.haUsuarioLogado()) {
        throw ExtratoInvalido{};
    }

    // Obtém o jogador logado
    Jogador jogador = login_.obterUsuarioLogado().jogador();

    // Obtém o extrato da carteira do jogador
    Extrato extrato = jogador.carteira().extrato();

    // Exibe o extrato na saída padrão
    std::cout << "Extrato do jogador " << login_.obterUsuarioLogado().nome() << ":\n";
    extrato.exibirMovimentacoes();
}

// Método para adicionar dinheiro à carteira do jogador
void SistemaJogador::adicionar_dinheiro(double valor) {
    if (!login_.haUsuarioLogado()) {
        throw OperacaoInvalida{};
    }

    // Obtém o jogador logado
    Jogador jogador = login_.obterUsuarioLogado().jogador();

    // Realiza o depósito na carteira do jogador
    jogador.carteira().depositar(valor);
}

// Método para retirar dinheiro da carteira do jogador
void SistemaJogador::retirar_dinheiro(double valor) {
    if (!login_.haUsuarioLogado()) {
        throw OperacaoInvalida{};
    }

    // Obtém o jogador logado
    Jogador jogador = login_.obterUsuarioLogado().jogador();

    // Realiza o saque da carteira do jogador
    jogador.carteira().sacar(valor);
}

// Método para retornar o saldo da carteira do jogador
float SistemaJogador::retornar_saldo() {
    if (!login_.haUsuarioLogado()) {
        throw OperacaoInvalida{};
    }

    // Obtém o jogador logado
    Jogador jogador = login_.obterUsuarioLogado().jogador();

    // Retorna o saldo da carteira do jogador
    return jogador.carteira().saldo();
}

// Método para cadastrar um novo usuário
void SistemaJogador::cadastrar_usuario(std::string apelido, std::string login, std::string senha, std::string cpf) {
    // Cria um novo jogador com o apelido fornecido
    Jogador jogador(apelido);

    // Cria um novo usuário com as informações fornecidas
    Usuario user(login, senha, cpf, jogador);

    // Adiciona o novo usuário à lista de usuários
    listaUsuarios_.adicionarUsuario(user);
}

// Método para verificar se há um usuário logado
bool SistemaJogador::logado() {
    return login_.haUsuarioLogado();
}

// Método para obter informações de login (nome e CPF)
InformacoesLogin SistemaJogador::informacoes_login(){
    InformacoesLogin info{login_.nome(), login_.cpf()};
    return info;
}
