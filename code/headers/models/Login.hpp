/**
 * @file Login.hpp
 * @brief Definição da classe Login.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include "Usuario.hpp"

/**
 * @brief Estrutura para representar uma exceção de nenhum usuário logado.
 */
struct Nenhum_Usuario_Logado {
    std::string mensagem; ///< Mensagem associada à exceção.
};

/**
 * @brief Classe que representa o processo de login.
 */
class Login {
public:
    /**
     * @brief Construtor da classe Login.
     * Cria um objeto de login sem usuário logado.
     */
    Login();

    /**
     * @brief Define o usuário logado.
     * @param usuario O usuário a ser definido como logado.
     */
    void definirUsuarioLogado(const Usuario& usuario);

    /**
     * @brief Verifica se há um usuário logado.
     * @return True se há um usuário logado, false caso contrário.
     */
    bool haUsuarioLogado() const;

    /**
     * @brief Obtém informações do usuário logado.
     * @return Referência constante para o objeto Usuario do usuário logado.
     * @throws Nenhum_Usuario_Logado se nenhum usuário estiver logado.
     */
    const Usuario& obterUsuarioLogado() const;

    /**
     * @brief Desconecta o usuário logado.
     */
    void desconectarUsuario();

    /**
     * @brief Retorna o nome do usuário logado.
     * @return O nome do usuário logado.
     * @throws Nenhum_Usuario_Logado se nenhum usuário estiver logado.
     */
    std::string nome();

    /**
     * @brief Retorna o CPF do usuário logado.
     * @return O CPF do usuário logado.
     * @throws Nenhum_Usuario_Logado se nenhum usuário estiver logado.
     */
    std::string cpf();

    /**
     * @brief Adiciona fundos à carteira do usuário logado.
     * @param valor O valor a ser adicionado.
     * @throws Nenhum_Usuario_Logado se nenhum usuário estiver logado.
     */
    void adicionar_fundos(float valor);

    /**
     * @brief Retira fundos da carteira do usuário logado.
     * @param valor O valor a ser retirado.
     * @throws Nenhum_Usuario_Logado se nenhum usuário estiver logado.
     */
    void retirar_fundos(float valor);

    /**
     * @brief Retorna o saldo da carteira do usuário logado.
     * @return O saldo da carteira do usuário logado.
     * @throws Nenhum_Usuario_Logado se nenhum usuário estiver logado.
     */
    float saldo();

private:
    bool usuarioLogado_; ///< Flag indicando se há um usuário logado.
    Usuario usuarioAtual_; ///< Usuário logado.
};
