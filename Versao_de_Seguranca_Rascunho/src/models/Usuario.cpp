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

float Usuario::saldo_da_carteira(){
    return this->jogador_.saldo_da_carteira();
}

void Usuario::depositar_na_carteira(float valor_a_ser_depositado){
    this->jogador_.depositar_na_carteira(valor_a_ser_depositado);
}

void Usuario::sacar_na_carteira(float valor_a_ser_sacado){
    this->jogador_.sacar_na_carteira(valor_a_ser_sacado);
}

Extrato Usuario::extrato(){

    return this->jogador_.extrato();
}

void Usuario::adicionar_movimentacao(std::string descricao, float valor){
    this->jogador_.adicionar_movimentacao(descricao, valor);
}

// Método para alterar a senha
void Usuario::alterarSenha(std::string senhaNova) {
    senha_ = senhaNova;
}

