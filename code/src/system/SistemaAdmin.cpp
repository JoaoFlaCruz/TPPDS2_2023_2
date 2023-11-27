#include "./../../headers/system/SistemaAdmin.hpp"

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
void SistemaAdmin::adicionarAposta(Aposta &aposta) {
  // Obtém o sorteio da aposta
  Sorteio sorteio_selecionado = this->listaSorteios.buscar_sorteio_por_data_e_horario(aposta.data_e_horario());

  // Adiciona a aposta ao sorteio
  sorteio_selecionado.apostas_feitas().adicionar_aposta(aposta);
}

// Método para remover uma aposta de um sorteio
void SistemaAdmin::removerAposta(Aposta &aposta) {
  // Obtém o sorteio da aposta
  Sorteio sorteio_selecionado = this->listaSorteios.buscar_sorteio_por_data_e_horario(aposta.data_e_horario());

  // Verifica se o sorteio foi sorteado
  if (sorteio_selecionado.status() == 1) {
    return;
  }

  // Remove a aposta do sorteio
  sorteio_selecionado.apostas_feitas().remover_aposta(aposta);
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
