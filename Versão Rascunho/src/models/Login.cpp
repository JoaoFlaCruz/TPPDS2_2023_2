#include "../../headers/models/Login.hpp"


Login::Login() : usuarioLogado_(false){
   
}

// Define o usuário logado
void Login::logar_usuario(std::string login, std::string senha) {
    Usuario& usuario = listaUsuarios_.buscarUsuario(nome);

    // Verifica se o jogador existe
    if (usuario.nome() == "") {
        throw LoginInvalido{};
    }

    // Verifica se a senha está correta
    if (usuario.senha() != senha) {
        throw LoginInvalido{};
    }

    // Define o usuário logado
    login_.definirUsuarioLogado(usuario);
}

// Verifica se há um usuário logado
bool Login::haUsuarioLogado() const {
    return usuarioLogado_;
}

// Obtém informações do usu/ário logado
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

void Login::adicionar_fundos(float valor) {
    usuarioAtual_.adicionar_fundos(valor);
}

void Login::retirar_fundos(float valor) {
    usuarioAtual_.retirar_fundos(valor);
}

float Login::saldo() {
    return usuarioAtual_.saldo();
}