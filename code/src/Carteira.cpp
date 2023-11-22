#include "Carteira.hpp"

Carteira::Carteira() : saldo_(0), extrato_(Extrato()) {

}

float Carteira::saldo(){
    return this->saldo_;
}

Extrato Carteira::extrato(){
    return this->extrato_;
}

void Carteira::depositar(float valor){
    if (valor <= 0) {
        throw ValorInvalido{ valor };
    }
    this->saldo_ += valor;
    this->extrato_.adicionar_movimentacao("Depositado", valor);
}

