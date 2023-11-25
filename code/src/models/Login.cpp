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
        throw "Nenhum usuário logado.";
    }
    return usuarioAtual_;
}

// Desconecta o usuário logado
void Login::desconectarUsuario() {
    usuarioLogado_ = false;
    //Usuario atual não deveria ser zero ou alterado aqui??
}
