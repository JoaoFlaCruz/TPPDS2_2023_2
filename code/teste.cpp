
#include <iostream>
#include <array>
#include <string>

#include "./headers/models/aposta/normal/Normal.hpp"
#include "./headers/models/aposta/normal/Grupo.hpp"
#include "./headers/models/aposta/normal/Dezena.hpp"
#include "./headers/models/aposta/normal/Centena.hpp"
#include "./headers/models/aposta/normal/Milhar.hpp"
#include "./headers/models/aposta/duque/DuqueGrupo.hpp"
#include "./headers/models/aposta/duque/DuqueDezena.hpp"
#include "./headers/models/aposta/terno/TernoGrupo.hpp"
#include "./headers/models/aposta/terno/TernoDezena.hpp"
#include "./headers/models/Carteira.hpp"
#include "./headers/models/Extrato.hpp"
#include "./headers/models/Jogador.hpp"
#include "./headers/models/ListaApostas.hpp"
#include "./headers/models/ListaSorteios.hpp"
#include "./headers/models/ListaUsuario.hpp"
#include "./headers/models/Login.hpp"
#include "./headers/models/Sorteio.hpp"
#include "./headers/models/Usuario.hpp"

//Rotinas de teste
void apostas() {

    float valor = 100;
    std::string nome = "Fulano de Tal";
    std::array<int, 5> resultado;
    resultado[0] = 7635;
    resultado[1] = 9427;
    resultado[2] = 3684;
    resultado[3] = 1298;
    resultado[4] = 6413;

    // Aposta Duque em um Grupo
    std::array<int, 2> aposta;
    aposta[0] = 4;
    aposta[1] = 25;
    DuqueGrupo duque_grupo(nome, valor, false, aposta);

    duque_grupo.verificar_vitoria(resultado);
    if(duque_grupo.ganhou()) {
        std::cout << "Vitoria DuqueGrupo" << std::endl;
    } else {
        std::cout << "Derrota DuqueGrupo" << std::endl;
    }

}

void carteira() {}
void extrato() {}
void jogador() {}
void lista_apostas() {}
void lista_sorteios() {}
void lista_usuario() {}
void login() {}
void sorteio() {}
void usuario() {}

int main() {

    apostas();
    //carteira();
    //extrato();
    //jogador();
    //lista_apostas();
    //lista_sorteios();
    //lista_usuario();
    //login();
    //sorteio();
    //usuario();

}