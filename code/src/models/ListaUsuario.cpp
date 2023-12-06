#include "../../headers/models/ListaUsuario.hpp"

ListaUsuario::ListaUsuario() {}

Usuario* ListaUsuario::usuario_logado(){
    return this->usuario_logado_;
}

// Adiciona um novo usuário ao vetor usuarios_
void ListaUsuario::adicionarUsuario(std::string nome, std::string senha, std::string cpf) {
    // Verifica se o usuário já existe
    if (pertence(nome)) {
        UsuarioJaExiste e;
        throw e;
    }
    Usuario adicionado(nome, senha, cpf, Jogador());
    usuarios_.push_back(adicionado);
}

// Verifica se um determinado login existe no vetor usuarios_
bool ListaUsuario::pertence(std::string nome) {
    for (const auto& usuario : usuarios_) {
        if (usuario.nome() == nome) {
            return true;  
        }
    }
    return false; 
}

// Retorna um objeto Usuario com o login especificado, se existir
Usuario* ListaUsuario::buscarUsuario(const std::string& login) {
    for (auto& usuario : usuarios_) {
        if (usuario.nome() == login) {
            return &usuario;  // Retorna o usuário encontrado por valor
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

void ListaUsuario::login(std::string nome_do_usuario, std::string senha){
    // Verifica se o jogador existe
    if (nome_do_usuario == "") {
        throw LoginInvalido{};
    }

    // Verifica se a senha está correta
    if (buscarUsuario(nome_do_usuario)->senha() != senha) {
        throw LoginInvalido{};
    }
    this->usuario_logado_ = (buscarUsuario(nome_do_usuario));

}

void ListaUsuario::logout(){
    this->usuario_logado_ = nullptr;
}
