#pragma once

#include <string>

#include "Jogador.hpp"

class Usuario{
    private:
        std::string nome_;
        std::string senha_;
        std::string cpf_;
        Jogador jogador_;
    public:
        Usuario(
            std::string nome,
            std::string senha,
            std::string cpf,
            Jogador jogador);
        ~Usuario();

        void alterar_senha(std::string senha_nova);
        std::string nome();
        std::string senha();
        std::string cpf();
        Jogador jogador();
};