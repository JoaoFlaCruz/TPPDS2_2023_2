/**
 * @file Usuario.hpp
 * @brief Definição da classe Usuario.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <string>
#include "Jogador.hpp"

/**
 * @brief Classe que representa um usuário do sistema.
 */
class Usuario {
private:
    std::string nome_; ///< Nome do usuário.
    std::string senha_; ///< Senha do usuário.
    std::string cpf_; ///< CPF do usuário.
    Jogador jogador_; ///< Jogador associado ao usuário.

public:
    /**
     * @brief Construtor da classe Usuario.
     * Inicializa um usuário com as informações fornecidas.
     * @param nome O nome do usuário.
     * @param senha A senha do usuário.
     * @param cpf O CPF do usuário.
     * @param jogador O jogador associado ao usuário.
     */
    Usuario(std::string nome, std::string senha, std::string cpf, Jogador jogador);

    /**
     * @brief Construtor padrão da classe Usuario.
     * Cria um usuário vazio.
     */
    Usuario();

    /**
     * @brief Destrutor da classe Usuario.
     */
    ~Usuario();

    /**
     * @brief Método de acesso (getter) para o nome do usuário.
     * @return O nome do usuário.
     */
    std::string nome() const;

    /**
     * @brief Método de acesso (getter) para a senha do usuário.
     * @return A senha do usuário.
     */
    std::string senha() const;

    /**
     * @brief Método de acesso (getter) para o CPF do usuário.
     * @return O CPF do usuário.
     */
    std::string cpf() const;

    /**
     * @brief Método de acesso (getter) para o jogador associado ao usuário.
     * @return O jogador associado ao usuário.
     */
    Jogador jogador() const;

    /**
     * @brief Método para alterar a senha do usuário.
     * @param senhaNova A nova senha a ser definida.
     * @note Este método é opcional e pode ser removido se não for necessário.
     */
    void alterarSenha(std::string senhaNova);

    /**
     * @brief Adiciona fundos à carteira do jogador associado ao usuário.
     * @param valor O valor a ser adicionado.
     */
    void adicionar_fundos(float valor);

    /**
     * @brief Retira fundos da carteira do jogador associado ao usuário.
     * @param valor O valor a ser retirado.
     */
    void retirar_fundos(float valor);

    /**
     * @brief Obtém o saldo atual da carteira do jogador associado ao usuário.
     * @return O saldo da carteira.
     */
    float saldo();
};
