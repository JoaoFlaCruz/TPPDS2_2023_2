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

void Jogador::adicionar_fundos(float valor) {
    carteira_.depositar(valor);
}

void Jogador::retirar_fundos(float valor) {
    carteira_.sacar(valor);
}

float Jogador::saldo() {
    return carteira_.saldo();
}