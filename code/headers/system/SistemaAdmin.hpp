#pragma once

#include "../models/ListaSorteios.hpp"
#include "../models/Sorteio.hpp"
#include "../models/ListaApostas.hpp"
#include "../models/aposta/Aposta.hpp"
#include "../models/Jogador.hpp"
#include "../models/Carteira.hpp"

#include <iostream>
#include <list>

class SistemaAdmin {
private:
    ListaSorteios listaSorteios_;
    Carteira carteira_;
    std::string senha_;

public:
    SistemaAdmin();
    ~SistemaAdmin();

    //Validação de login no sistema Admin
    bool validar_senha(std::string senha);

    // Gerenciar sorteios
    void criar_sorteio(Sorteio &sorteio);
    auto sortear() -> Jogador;
    Jogador verificar_ganhador();

    // Realizar pagamento para os ganhadores
    void realizar_pagamento(Jogador &ganhador);

    // Manipular a seção de sorteios
    void adicionar_sorteio(std::string nome, std::string data);
    void remover_sorteio(Sorteio &sorteio);
    void exibir_detalhes_sorteio(Sorteio &sorteio);
    std::list<DadosSorteio> dados_sorteios();

    /*
    // Manipular a seção de apostas
    void adicionar_aposta(Aposta &aposta);
    void remover_aposta(Aposta &aposta);
    void verificar_apostas();

    // Manipular a seção de jogadores
    void adicionar_jogador(Jogador &jogador);
    void remover_jogador(Jogador &jogador);
    void exibir_detalhes_jogador(Jogador &jogador);
    */

    void  realizar_pagamento(Jogador &jogador, double valor);

    // Manipular a seção de carteiras
    void adicionar_dinheiro(double valor);
    void retirar_dinheiro(double valor);
    float retornar_saldo();
};
