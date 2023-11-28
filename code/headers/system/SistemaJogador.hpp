#ifndef SISTEMAJOGADOR_HPP
#define SISTEMAJOGADOR_HPP

#include "../models/Jogador.hpp"
#include "../models/Carteira.hpp"
#include "../models/aposta/Aposta.hpp"

#include <vector>

class SistemaJogador {
public:
    // Construtor
    SistemaJogador();

    // Destrutor
    ~SistemaJogador();

private:
    // Lista de jogadores registrados no sistema
    std::vector<Jogador> listaJogadores;
};

#endif // SISTEMAJOGADOR_HPP
