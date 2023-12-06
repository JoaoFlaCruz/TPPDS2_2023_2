#include "../../headers/models/ListaUsuario.hpp"

ListaUsuario::ListaUsuario() {}

// Adiciona um novo usuário ao vetor usuarios_
void ListaUsuario::adicionarUsuario(const Usuario& usuario) {
    // Verifica se o usuário já existe
    if (validarLogin(usuario.nome())) {
        UsuarioJaExiste e;
        throw e;
    }

    usuarios_.push_back(usuario);
}

// Verifica se um determinado login existe no vetor usuarios_
bool ListaUsuario::validarLogin(const std::string& login) const {
    for (const auto& usuario : usuarios_) {
        if (usuario.nome() == login) {
            return true;  // Login encontrado
        }
    }
    return false;  // Login não encontrado
}

// Retorna um objeto Usuario com o login especificado, se existir
Usuario& ListaUsuario::buscarUsuario(const std::string& login) {
    for (auto& usuario : usuarios_) {
        if (usuario.nome() == login) {
            return usuario;  // Retorna o usuário encontrado por valor
        }
    }

    UsuarioNaoEncontrado e;
    throw e;
}

void ListaUsuario::removerUsuario(const std::string& login) {
    for (auto it = usuarios_.begin(); it != usuarios_.end(); ++it) {
        if (it->nome() == login) {
            usuarios_.erase(it);
            break;
        }
    }
}
