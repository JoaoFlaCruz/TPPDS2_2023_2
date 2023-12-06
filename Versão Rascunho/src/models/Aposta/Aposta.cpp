#include "../../headers/models/aposta/Aposta.hpp"
#include <iostream>

void Aposta::verificar_vitoria(std::array<int, 5> resultado) {
}

bool Aposta::operator==(Aposta outra){
    if (this->nome_do_jogador_ == outra.nome_do_jogador_ && this->valor_ == outra.valor_ && this->cabeca_ == outra.cabeca_ && this->ganhou_ == outra.ganhou_) {
        return 1;
    }
    return false;
}

// CONSTRUTORES E DESTRUTORES
Aposta::Aposta(std::string nome_do_jogador, float valor, bool cabeca) : valor_(valor), cabeca_(cabeca), nome_do_jogador_(nome_do_jogador) {
    if (valor < 0) {
        throw ValorDaApostaNegativo{ valor };
    }
    this->nome_do_jogador_ = nome_do_jogador;
    this->valor_ = valor;
    this->cabeca_ = cabeca;
}

Aposta::~Aposta() {
    // Destrutor
}

// GETTERS
float Aposta::ganho() {
    return ganho_;
}

float Aposta::valor() {
    return valor_;
}

bool Aposta::cabeca() {
    return cabeca_;
}

std::string Aposta::nome_do_jogador() {
    return nome_do_jogador_;
}

bool Aposta::ganhou() {
    return ganhou_;
}

std::vector<int> Aposta::apostas(){

    return this->apostas_;
}

// MÉTODOS CONCRETOS
float Aposta::calcular_ganho() {
    if(cabeca_) {
        return valor_ * ganho_ * 5;
    }
    return valor_ * ganho_;
}
