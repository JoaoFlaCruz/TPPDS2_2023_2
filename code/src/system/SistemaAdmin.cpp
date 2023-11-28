#include "./../../headers/system/SistemaAdmin.hpp"
#include <iostream>
using namespace std;

// Construtor da classe SistemaAdmin
SistemaAdmin::SistemaAdmin() {
}

// Destrutor da classe SistemaAdmin
SistemaAdmin::~SistemaAdmin() {
}

// Validador de senha para login no sistema admin
bool SistemaAdmin::validar_senha(std::string senha) {
  return senha == senha_;
}

// Método para criar um novo sorteio
void SistemaAdmin::criarSorteio(Sorteio &sorteio) {
  // Verifica se o sorteio já existe
  for (auto sorteio_selecionado : this->listaSorteios.lista_de_sorteio()) {
    if (sorteio_selecionado.data_e_horario() == sorteio.data_e_horario()) {
      throw SorteioJaExistente{ sorteio.data_e_horario() };
    }
  }

  // Adiciona o sorteio à lista de sorteios
  this->listaSorteios.adicionar_sorteio(sorteio);
}

// Método para exibir os detalhes de um sorteio
void SistemaAdmin::exibirDetalhesSorteio(Sorteio &sorteio) {
  // Exibe a data e o horário do sorteio
  std::cout << "Data e horário: " << sorteio.data_e_horario() << std::endl;

  // Exibe os números sorteados
  std::cout << "Números sorteados: ";
  for (int numero : sorteio.numeros_sorteados()) {
    std::cout << numero << " ";
  }
  std::cout << std::endl;

  // Exibe o status do sorteio
  std::cout << "Status: " << (sorteio.status() ? "Sorteado" : "Ainda não sorteado") << std::endl;
}

// Método para adicionar uma aposta a um sorteio
void SistemaAdmin::adicionarSorteio(Sorteio &sorteio) {
  // Valida se o sorteio já existe
  auto it = listaSorteios.lista_de_sorteio().begin();
  for (; it != listaSorteios.lista_de_sorteio().end(); it++) {
    if ((*it).data_e_horario() == sorteio.data_e_horario()) {
      throw SorteioJaExistente{ sorteio.data_e_horario() };
    }
  }

  // Adiciona o sorteio à lista de sorteios
  listaSorteios.lista_de_sorteio().push_back(sorteio);
} 


// Método para remover uma aposta de um sorteio

void SistemaAdmin::removerSorteio(Sorteio &sorteio) {
    auto it = listaSorteios.lista_de_sorteio().begin();
    for (; it != listaSorteios.lista_de_sorteio().end(); it++) {
        if ((*it).data_e_horario() == sorteio.data_e_horario()) {
            listaSorteios.lista_de_sorteio().erase(it);
            return;  // Removemos o sorteio e saímos da função
        }
    }

    // Se chegarmos aqui, significa que o sorteio não foi encontrado
    throw SorteioInexistente{ sorteio.data_e_horario() };
}

// Método para verificar as apostas ganhas de todos os sorteios
void SistemaAdmin::verificarApostas() {
  // Itera sobre todos os sorteios
  for (auto sorteio : this->listaSorteios.lista_de_sorteio()) {
    // Verifica as apostas ganhas do sorteio
    sorteio.verificar_apostas_ganhas();
  }
}

// Métodos para manipular carteiras
void SistemaAdmin::adicionarDinheiro(Carteira &carteira, double valor) {
  carteira.depositar(valor);
}

void SistemaAdmin::retirarDinheiro(Carteira &carteira, double valor) {
  carteira.sacar(valor);
}

void SistemaAdmin::exibirSaldo(Carteira &carteira) {
  std::cout << carteira.saldo() << std::endl;
}

//falta fazer os outros metodos pois depende de jogador que ta incompleto
void SistemaAdmin::realizarPagamento(Jogador &jogador, double valor) {
    // Verifica se o valor é não negativo
    if (valor < 0) {
        throw ValorInvalido{};
    }

    // Adiciona o valor à carteira do jogador
    jogador.carteira().depositar(valor);
}
