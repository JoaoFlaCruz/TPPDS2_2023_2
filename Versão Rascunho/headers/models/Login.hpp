#pragma once
#include "Usuario.hpp"

struct Nenhum_Usuario_Logado {

std::string mensagem;

};
class Login {
public:
    // Construtor
    Login();

    //Loga usuario
    void logar_usuario(std::string login, std::string senha);

    // Verifica se há um usuário logado
    bool haUsuarioLogado() const;
    

    // Desconecta o usuário logado
    void desconectarUsuario();

private:
    bool usuarioLogado_;
    Usuario usuarioAtual_;
};
