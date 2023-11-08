#include <string>
#include <iostream>

#include "Exemplo.hpp"

int main() {
    std::string nome = "Fulano de Tal";
    Exemplo ex(nome);

    std::cout << ex.nome() << std::endl;
}