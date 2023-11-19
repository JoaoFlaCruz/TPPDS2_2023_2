#include "Usuario.hpp"

Usuario::Usuario(std::string nome, std::string senha, std::string cpf, Jogador jogador)
    : nome_(nome), senha_(senha), cpf_(cpf), jogador_(jogador) {}

Usuario::~Usuario() {}

void Usuario::alterar_senha(std::string senha_nova) {
    senha_ = senha_nova;
}

std::string Usuario::nome() {
    return nome_;
}

std::string Usuario::senha() {
    return senha_;
}

std::string Usuario::cpf() {
    return cpf_;
}

// Método para obter o objeto Jogador associado ao usuário
Jogador Usuario::jogador() {
    return jogador_;
}
