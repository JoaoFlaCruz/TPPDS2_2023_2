#pragma once

#include "../models/ListaSorteios.hpp"
#include "../models/Sorteio.hpp"
#include "../models/ListaApostas.hpp"
#include "../models/aposta/Aposta.hpp"
#include "../models/Jogador.hpp"
#include "../models/Carteira.hpp"

class SistemaAdmin {
  private:
    ListaSorteios listaSorteios;

  public:
    SistemaAdmin();
    ~SistemaAdmin();

    // Gerenciar sorteios
    void criarSorteio(Sorteio &sorteio);
    void sortear();
    Jogador verificarGanhador();

    // Realizar pagamento para os ganhadores
    void realizarPagamento(Jogador &ganhador);

    // Manipular toda a seção de admin e suas classes
    void manipularListaSorteios();
    void manipularSorteio(Sorteio &sorteio);
    void manipularListaApostas();
    void manipularAposta(Aposta &aposta);
    void manipularJogador(Jogador &jogador);
    void manipularCarteira(Carteira &carteira);
};
