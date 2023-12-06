#pragma once

#include <vector>
#include "Usuario.hpp"

struct LoginInvalido {
    std::string mensagem;
};

struct UsuarioJaExiste {};
struct UsuarioNaoEncontrado {};

class ListaUsuario {
public:
    ListaUsuario();

    //Retornar usuario logado
    Usuario* usuario_logado();

    // Adiciona um novo usuário ao vetor usuarios_
    // pré-condição: o usuário não deve existir na lista.
    void adicionarUsuario(std::string nome, std::string senha, std::string cpf);

    // Verifica se um determinado login existe no vetor usuarios_
     // pré-condição: a lista de usuários não deve estar vazia
    bool pertence(std::string nome);

    // Retorna um objeto Usuario com o login especificado, se existir
     // pré-condição: a lista de usuários não deve estar vazia.
    Usuario* buscarUsuario(const std::string& login);

    void removerUsuario(const std::string& login);

    void login(std::string nome_do_usuario, std::string senha);

    void logout();

private:
    std::vector<Usuario> usuarios_;
    Usuario* usuario_logado_;
};



