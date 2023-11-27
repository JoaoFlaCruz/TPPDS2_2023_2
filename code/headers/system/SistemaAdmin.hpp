#pragma once

#include "../models/ListaSorteios.hpp"
#include "../models/Sorteio.hpp"
#include "../models/ListaApostas.hpp"
#include "../models/aposta/Aposta.hpp"
#include "../models/Jogador.hpp"
#include "../models/Carteira.hpp"

#include <iostream>

class SistemaAdmin {
private:
    ListaSorteios listaSorteios;
    std::string senha_;

public:
    SistemaAdmin();
    ~SistemaAdmin();

    //Validação de login no sistema Admin
    bool validar_senha(std::string senha);

    // Gerenciar sorteios
    void criarSorteio(Sorteio &sorteio);
    auto sortear() -> Jogador;
    Jogador verificarGanhador();

    // Realizar pagamento para os ganhadores
    void realizarPagamento(Jogador &ganhador);

    // Manipular a seção de sorteios
    void adicionarSorteio(Sorteio &sorteio);
    void removerSorteio(Sorteio &sorteio);
    void exibirDetalhesSorteio(Sorteio &sorteio);

    // Manipular a seção de apostas
    void adicionarAposta(Aposta &aposta);
    void removerAposta(Aposta &aposta);
    void verificarApostas();

    // Manipular a seção de jogadores
    void adicionarJogador(Jogador &jogador);
    void removerJogador(Jogador &jogador);
    void exibirDetalhesJogador(Jogador &jogador);

    // Manipular a seção de carteiras
    void adicionarDinheiro(Carteira &carteira, double valor);
    void retirarDinheiro(Carteira &carteira, double valor);
    void exibirSaldo(Carteira &carteira);
};
