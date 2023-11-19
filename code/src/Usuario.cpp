#include "Usuario.hpp"

Usuario::Usuario(std::string nome, std::string senha, std::string cpf, Jogador jogador)
    : nome_(nome), senha_(senha), cpf_(cpf), jogador_(jogador) {}


Usuario::~Usuario() {}

std::string Usuario::obterNome() const {
    return nome_;
}

std::string Usuario::obterSenha() const {
    return senha_;
}

std::string Usuario::obterCPF() const {
    return cpf_;
}

Jogador Usuario::obterJogador() const {
    return jogador_;
}

// Método para alterar a senha 
void Usuario::alterarSenha(std::string senhaNova) {
    senha_ = senhaNova;
}

