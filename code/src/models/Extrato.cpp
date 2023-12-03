#include "../../headers/models/Extrato.hpp"
#include <iostream>
Extrato::Extrato() : extrato_({}), tamanho_(0) {}

std::list<std::pair<std::string, float>> Extrato::extrato_por_ordem_cronologica() {
    if (this->tamanho_ == 0) {
        throw ExtratoVazio{};
    }
    return this->extrato_;
}

std::list<std::pair<std::string, float>> Extrato::ordenar_por_ordem_de_valor() {
    if (this->tamanho_ == 0) {
        throw ExtratoVazio{};
    }
    std::list<std::pair<std::string, float>> lista_reordenada = this->extrato_;
    auto comparador = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };
    lista_reordenada.sort(comparador);

    return lista_reordenada;
}

void Extrato::adicionar_movimentacao(std::string descricao, float valor) {
    this->extrato_.push_back({descricao, valor});
    this->tamanho_++;
}

int Extrato::tamanho() {
    return this->tamanho_;
}

void Extrato::exibirMovimentacoes() const {
    for (const auto& movimento : this->extrato_) {
        std::cout << "Tipo: " << movimento.first << ", Valor: " << movimento.second << std::endl;
    }
}
