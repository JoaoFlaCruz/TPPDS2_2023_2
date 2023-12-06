#include "../../headers/models/Login.hpp"


Login::Login() : usuarioLogado_(false) {
}

// Define o usuário logado
void Login::definirUsuarioLogado(const Usuario& usuario) {
    usuarioAtual_ = usuario;
    usuarioLogado_ = true;
}

// Verifica se há um usuário logado
bool Login::haUsuarioLogado() const {
    return usuarioLogado_;
}

// Obtém informações do usuário logado
const Usuario& Login::obterUsuarioLogado() const {
    if (!haUsuarioLogado()) {
        throw Nenhum_Usuario_Logado{};
    }
    return usuarioAtual_;
}

// Desconecta o usuário logado
void Login::desconectarUsuario() {
    usuarioLogado_ = false;
   usuarioAtual_ = Usuario();
}

std::string Login::nome() {
    return usuarioAtual_.nome();
}

std::string Login::cpf() {
    return usuarioAtual_.cpf();
}

