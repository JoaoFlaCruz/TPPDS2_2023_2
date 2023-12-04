#pragma once
#include "Usuario.hpp"

struct Nenhum_Usuario_Logado {

std::string mensagem;

};
class Login {
public:
    // Construtor
    Login();

    // Define o usuário logado
    void definirUsuarioLogado(const Usuario& usuario);

    // Verifica se há um usuário logado
    bool haUsuarioLogado() const;

    // Obtém informações do usuário logado
    const Usuario& obterUsuarioLogado() const;

    // Desconecta o usuário logado
    void desconectarUsuario();

    std::string nome();
    std::string cpf();

    void adicionar_fundos(float valor);
    void retirar_fundos(float valor);
    float saldo();


private:
    bool usuarioLogado_;
    Usuario usuarioAtual_;
};
