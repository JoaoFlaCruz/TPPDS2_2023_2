#pragma once

#include <stdlib.h>
#include <iostream>

class Interface{
    private:

    public:
        Interface();
        ~Interface();

        void limpar_tela();
        void cabecalho();
        void barra_final();
        void quebra_linha();

        void executar();

        void pagina_inicial();
};
