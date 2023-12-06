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

    //Saldo na carteira 
    float saldo_da_carteira();

    //Depositar na carteira 
    void depositar_na_carteira(float valor_a_ser_depositado);

    //Sacar na carteira 
    void sacar_na_carteira(float valor_a_ser_sacado);

    //Mostrar extrato
    Extrato extrato();

    //Adicinoar movimentação
    void adicionar_movimentacao(std::string descricao, float valor);

    // Método para alterar a senha //opcional podem tirar se quiserem
    void alterarSenha(std::string senhaNova);
};

