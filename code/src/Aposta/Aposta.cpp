#include "Aposta.hpp"
#include <stdexcept>
#include <iostream>

// CONSTRUTORES E DESTRUTORES
Aposta::Aposta(std::string nome_do_jogador, float valor, bool cabeca) : valor_(valor), cabeca_(cabeca), nome_do_jogador_(nome_do_jogador) {
    try {
        if (valor < 0) {
            throw std::invalid_argument("O valor da aposta não pode ser negativo.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro durante a criação da aposta: " << e.what() << std::endl;
        
    }
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

// MÉTODOS CONCRETOS
float Aposta::calcular_ganho() {
    try {
        if (valor_ < 0) {
            throw std::logic_error("O valor da aposta não pode ser negativo.");
        }
        return valor_ * ganho_;
    } catch (const std::exception& e) {
        std::cerr << "Erro durante o cálculo do ganho: " << e.what() << std::endl;
        return 0.0; 
    }
}

// MÉTODOS ABSTRATOS
void Aposta::verificar_vitoria() {
    try {
        // Implementação da verificação de vitória
        if (/* não ganhou */) {
            throw std::runtime_error("Condição de vitória não satisfeita.");
        }
        ganhou_ = true; 
    } catch (const std::exception& e) {
        std::cerr << "Erro durante a verificação de vitória: " << e.what() << std::endl;
        ganhou_ = false; 
}
