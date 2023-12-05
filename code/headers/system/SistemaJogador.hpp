#pragma once

#include "../models/Jogador.hpp"
#include "../models/Carteira.hpp"
#include "../models/ListaUsuario.hpp"
#include "../models/ListaSorteios.hpp"
#include "../models/aposta/Aposta.hpp"
#include "../../headers/models/aposta/duque/DuqueDezena.hpp"
#include "../models/Login.hpp"

/**
 * @brief Exceção lançada quando uma operação é considerada inválida.
 */
struct OperacaoInvalida{
    std::string mensagem;
};

/**
 * @brief Exceção lançada quando um login é considerado inválido.
 */
struct LoginInvalido{
    std::string mensagem;
};

/**
 * @brief Exceção lançada quando uma aposta é considerada inválida.
 */
struct ApostaInvalida{
    std::string mensagem;
};

/**
 * @brief Exceção lançada quando um extrato é considerado inválido.
 */
struct ExtratoInvalido{
    std::string mensagem;
};

/**
 * @brief Estrutura para armazenar informações de login.
 */
struct InformacoesLogin{
    std::string login;
    std::string cpf;
};

/**
 * @brief Classe que representa o sistema do jogador.
 */
class SistemaJogador {
public:

    /**
     * @brief Construtor padrão do SistemaJogador.
     */
    SistemaJogador();

    /**
     * @brief Obtém o objeto Login associado ao SistemaJogador.
     * @return Referência constante ao objeto Login.
     */
    const Login& obterLogin() const;

    /**
     * @brief Obtém a lista de usuários associada ao SistemaJogador.
     * @return Referência constante à ListaUsuario.
     */
    const ListaUsuario& obterListaUsuarios() const;

    /**
     * @brief Obtém a lista de apostas associada ao SistemaJogador.
     * @return Referência constante à ListaApostas.
     */
    const ListaApostas& obterListaApostas() const;

    /**
     * @brief Realiza o login no sistema.
     * @param nome Nome do jogador.
     * @param senha Senha do jogador.
     */
    void login(const std::string& nome, const std::string& senha);

    /**
     * @brief Realiza o logout do sistema.
     */
    void logout();

    /**
     * @brief Realiza uma aposta no sistema.
     * @param valor Valor da aposta.
     * @param apostas Array de inteiros representando as apostas.
     */
    void realizarAposta(float valor, const std::array<int, 2>& apostas);

    /**
     * @brief Exibe o extrato do jogador no sistema.
     */
    void exibirExtrato();

    /**
     * @brief Adiciona dinheiro à carteira do jogador.
     * @param valor Valor a ser adicionado.
     */
    void adicionar_dinheiro(double valor);

    /**
     * @brief Retira dinheiro da carteira do jogador.
     * @param valor Valor a ser retirado.
     */
    void retirar_dinheiro(double valor);

    /**
     * @brief Realiza um pagamento para o jogador.
     * @param jogador Referência ao jogador.
     * @param valor Valor do pagamento.
     */
    void realizar_pagamento(Jogador& jogador, double valor);

    /**
     * @brief Retorna o saldo atual na carteira do jogador.
     * @return Saldo atual.
     */
    float retornar_saldo();

    /**
     * @brief Cadastra um novo usuário no sistema.
     * @param apelido Apelido do usuário.
     * @param login Login do usuário.
     * @param senha Senha do usuário.
     * @param cpf CPF do usuário.
     */
    void cadastrar_usuario(std::string apelido, std::string login, std::string senha, std::string cpf);

    /**
     * @brief Verifica se o jogador está logado no sistema.
     * @return True se estiver logado, False caso contrário.
     */
    bool logado();

    /**
     * @brief Obtém informações de login do jogador.
     * @return Estrutura InformacoesLogin contendo login e CPF.
     */
    InformacoesLogin informacoes_login();

private:
    Login login_;           ///< Objeto Login associado ao SistemaJogador.
    ListaApostas listaApostas_;     ///< Lista de apostas associada ao SistemaJogador.
    ListaUsuario listaUsuarios_;    ///< Lista de usuários associada ao SistemaJogador.
};
