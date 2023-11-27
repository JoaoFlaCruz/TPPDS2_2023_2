#include "./../../headers/interface/Interface.hpp"

Interface::Interface(){
    pagina_inicial();
}

Interface::~Interface(){}

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
    std::cout << "###########################################################################";
}

void Interface::pagina_inicial() {
    limpar_tela();
    cabecalho();
    std::cout << "#          (1) Acessar o sistema Admin                                              #";
    barra_final();
}
