#include "../../headers/models/Usuario.hpp"

Usuario::Usuario(std::string nome, std::string senha, std::string cpf, Jogador jogador_)
    : nome_(nome), senha_(senha), cpf_(cpf), jogador_(jogador_) {

}

Usuario::Usuario() : nome_({}), senha_({}), cpf_({}), jogador_{} {

}


Usuario::~Usuario() {}

std::string Usuario::nome() const {
    return nome_;
}

std::string Usuario::senha() const {
    return senha_;
}

std::string Usuario::cpf() const {
    return cpf_;
}

Jogador Usuario::jogador() const {
    return jogador_;
}

// Método para alterar a senha
void Usuario::alterarSenha(std::string senhaNova) {
    senha_ = senhaNova;
}

void Usuario::adicionar_fundos(float valor) {
    jogador_.adicionar_fundos(valor);
}

void Usuario::retirar_fundos(float valor) {
    jogador_.retirar_fundos(valor);
}

float Usuario::saldo() {
    return jogador_.saldo();
}