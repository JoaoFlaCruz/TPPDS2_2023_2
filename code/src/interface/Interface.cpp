#include "./Interface.hpp"

Interface::Interface(){}

Interface::~Interface(){}

void Interface::limpar_tela() {
    system("clear||cls");
}

void Interface::cabecalho() {
    std::cout << "########################" << "" << "#########################" << std::endl;
}

void Interface::pagina_inicial() {
    limpar_tela();
    cabecalho();
}
