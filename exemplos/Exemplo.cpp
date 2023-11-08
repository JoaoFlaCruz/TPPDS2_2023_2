#include "Exemplo.hpp"

Exemplo::Exemplo(int id, std::string nome) {

    id_ = id;
    nome_ = nome;

}

Exemplo::Exemplo(std::string nome) {

    id_ = ID_NULL;
    nome_ = nome;

}

Exemplo::~Exemplo() {}

int Exemplo::identificacao() {

    return id_;

}

std::string Exemplo::nome() {

    return nome_;

}

void Exemplo::setId(int id) {

    id_ = id;

}