#pragma once

#include <string>

#define ID_NULL 0

class Exemplo {

    private:

        int id_;
        std::string nome_;

    public:

        Exemplo(int id, std::string nome);
        Exemplo(std::string nome);
        ~Exemplo();
        int identificacao();
        std::string nome();
        void setId(int id);

};