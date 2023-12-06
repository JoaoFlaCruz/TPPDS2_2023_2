/**
 * @file ListaUsuario.hpp
 * @brief Definição da classe ListaUsuario.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <vector>
#include "Usuario.hpp"

/**
 * @brief Estrutura para representar uma exceção de usuário já existente.
 */
struct UsuarioJaExiste {};

/**
 * @brief Estrutura para representar uma exceção de usuário não encontrado.
 */
struct UsuarioNaoEncontrado {};

/**
 * @brief Classe que representa uma lista de usuários.
 */
class ListaUsuario {
public:
    /**
     * @brief Construtor da classe ListaUsuario.
     * Cria uma lista de usuários vazia.
     */
    ListaUsuario();

    /**
     * @brief Adiciona um novo usuário ao vetor de usuários.
     * @param usuario O usuário a ser adicionado.
     * @pre O usuário não deve existir na lista.
     */
    void adicionarUsuario(const Usuario& usuario);

    /**
     * @brief Verifica se um determinado login existe na lista de usuários.
     * @param login O login a ser verificado.
     * @return True se o login existir, false caso contrário.
     * @pre A lista de usuários não deve estar vazia.
     */
    bool validarLogin(const std::string& login) const;

    /**
     * @brief Retorna um objeto Usuario com o login especificado, se existir.
     * @param login O login do usuário a ser buscado.
     * @return Referência para o objeto Usuario com o login especificado.
     * @pre A lista de usuários não deve estar vazia.
     */
    Usuario& buscarUsuario(const std::string& login);

    /**
     * @brief Remove um usuário com o login especificado da lista.
     * @param login O login do usuário a ser removido.
     * @pre A lista de usuários não deve estar vazia.
     */
    void removerUsuario(const std::string& login);

private:
    std::vector<Usuario> usuarios_; ///< Vetor de usuários.
};
