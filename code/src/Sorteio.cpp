#include "Sorteio.hpp"
#include <random>
//Realizar o tratamento de excessões e a função verificar sorteio
//Testar
Sorteio::Sorteio(std::string data_e_horario) : data_e_horario_(data_e_horario){
}

Sorteio::Sorteio(std::string data_e_horario, std::array<int, 5> numeros_sorteados, bool status) : data_e_horario_(data_e_horario), status_(status) {
        this->numeros_sorteados_ = numeros_sorteados;
}

std::string Sorteio::data_e_horario(){
    return this->data_e_horario_;
}

std::array<int, 5> Sorteio::numeros_sorteados(){
    return this->numeros_sorteados_;
}

ListaApostas Sorteio::apostas_feitas(){
    return this->apostas_feitas_;
}

ListaApostas Sorteio::apostas_ganhas(){
    return this->apostas_ganhas_;
}

bool Sorteio::status(){
    return this->status_;
}

void Sorteio::sortear(){
    std::array<int, 5> numeros_sorteados;
    for (int i = 0; i < 5; i++) {
        numeros_sorteados[i] = gerar_numero_aleatorio();

    }
    this->numeros_sorteados_ = numeros_sorteados;
    this->status_ = 1;
}

void Sorteio::verificar_apostas_ganhas(){
}
int Sorteio::gerar_numero_aleatorio(){
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<int> distribuicao(0, 9999);

    return distribuicao(gerador);
}
