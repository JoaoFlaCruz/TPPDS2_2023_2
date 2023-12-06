#include "../../headers/models/Jogador.hpp"

// Construtor que recebe o apelido do jogador
Jogador::Jogador(std::string apelido) : nome_do_jogador_(apelido) {
    // Inicializa a carteira com um saldo inicial de 0
    carteira_ = Carteira();
}

// Construtor padrão que cria um jogador vazio
Jogador::Jogador() : nome_do_jogador_(""), carteira_(Carteira()) {}

// Retorna o apelido do jogador
std::string Jogador::nome_do_jogador() {
    return nome_do_jogador_;
}

// Retorna a carteira do jogador
Carteira Jogador::carteira() {
    return carteira_;
}

float Jogador::saldo_da_carteira(){
    return this->carteira_.saldo();
}

void Jogador::depositar_na_carteira(float valor_a_ser_depositado){
    this->carteira_.depositar(valor_a_ser_depositado);
}

void Jogador::sacar_na_carteira(float valor_a_ser_sacado){
    this->carteira_.sacar(valor_a_ser_sacado);
}

Extrato Jogador::extrato()
{
    return this->carteira_.extrato();
}

void Jogador::adicionar_movimentacao(std::string descricao, float valor){
    this->carteira_.adicionar_movimentacao(descricao, valor);
}

