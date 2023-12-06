#include "../../headers/models/Extrato.hpp"
Extrato::Extrato() : extrato_({}), tamanho_(0) {

}

std::list<std::pair<std::string, float>> Extrato::extrato()
{
    return this->extrato_;
}

Extrato Extrato::extrato_por_ordem_cronologica() {
    if (this->tamanho_ == 0) {
        throw ExtratoVazio{};
    }
    Extrato extrato;
    extrato.extrato_ = this->extrato_;
    return extrato;
}

Extrato Extrato::ordenar_por_ordem_de_valor(){
    if (this->tamanho_ == 0) {
        throw ExtratoVazio{};
    }
    std::list<std::pair<std::string, float>> lista_reordenada = this->extrato_;
    auto comparador = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };
    lista_reordenada.sort(comparador);

    Extrato extrato;
    extrato.extrato_ = lista_reordenada;
    return extrato;
}


void Extrato::adicionar_movimentacao(std::string descricao, float valor){
    this->extrato_.push_back({descricao, valor});
    this->tamanho_++;
}
int Extrato::tamanho() {
    return this->tamanho_;
}
