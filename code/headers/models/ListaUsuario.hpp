#pragma once

#include <vector>
#include "Usuario.hpp"

struct UsuarioJaExiste {};
struct UsuarioNaoEncontrado {};

class ListaUsuario {
public:
    ListaUsuario();

    // Adiciona um novo usuário ao vetor usuarios_
    // pré-condição: o usuário não deve existir na lista.
    void adicionarUsuario(const Usuario& usuario);

    // Verifica se um determinado login existe no vetor usuarios_
     // pré-condição: a lista de usuários não deve estar vazia
    bool validarLogin(const std::string& login) const;

    // Retorna um objeto Usuario com o login especificado, se existir
     // pré-condição: a lista de usuários não deve estar vazia.
    Usuario& buscarUsuario(const std::string& login);
    void removerUsuario(const std::string& login);

private:
    std::vector<Usuario> usuarios_;
};




