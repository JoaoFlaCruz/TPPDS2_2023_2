#pragma once

#include <string>
#include "Jogador.hpp"

class Usuario {
private:
    std::string nome_;
    std::string senha_;
    std::string cpf_;
    Jogador jogador_;

public:

    Usuario(std::string nome, std::string senha, std::string cpf, Jogador jogador);

    //Cria um usuario vazio (construtor padrão)
    Usuario();

    ~Usuario();

    // Métodos de acesso (getter) para os membros privados
    std::string nome() const;
    std::string senha() const;
    std::string cpf() const;
    Jogador jogador() const;

    // Método para alterar a senha //opcional podem tirar se quiserem
    void alterarSenha(std::string senhaNova);

    void adicionar_fundos(float valor);
    void retirar_fundos(float valor);
    float saldo();
};

