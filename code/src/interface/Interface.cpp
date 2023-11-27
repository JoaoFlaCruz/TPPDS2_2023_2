#include "./../../headers/interface/Interface.hpp"

Interface::Interface(){}

Interface::~Interface(){}

void Interface::executar() {
    pagina_inicial();
}

void Interface::limpar_tela() {
    system("clear||cls");
}

void Interface::cabecalho() {
    std::cout << "###################################"
        << " JOGO DO BICHO "
        << "###################################"
        << std::endl;
}

void Interface::barra_final() {
    std::cout << "#####################################################################################" << std::endl;
}

void Interface::quebra_linha() {
    std::cout << "#                                                                                   #" << std::endl;
}

void Interface::pagina_inicial() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          (1) Acessar o sistema Admin                                              #" << std::endl;
    quebra_linha();
    barra_final();
}
