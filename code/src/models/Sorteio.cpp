#include "../../headers/models/Sorteio.hpp"
#include <regex>
#include <random>

//Realizar o tratamento de excessões e a função verificar sorteio
//Testar



Sorteio::Sorteio(std::string nome, std::string data_e_horario) : data_e_horario_(data_e_horario), nome_(nome), numeros_sorteados_({}), status_(0),
apostas_feitas_({}) {


    //DECOMPOSIÇÃO DA DATA E HORARIO
    std::string dia = data_e_horario.substr(0, 2);
    std::string mes = data_e_horario.substr(3, 2);
    std::string ano = data_e_horario.substr(6, 4);
    std::string horario = data_e_horario.substr(11, 3); //PTM, PTV, PTN, COR

    std::string separador1 = data_e_horario.substr(2, 1);
    std::string separador2 = data_e_horario.substr(5, 1);
    std::string separador3 = data_e_horario.substr(11, 1);

    int dia_ = stoi(dia);
    int mes_ = stoi(mes);
    int ano_ = stoi(ano);

    //Tratamento de excessão
    if (dia_ < 0 || dia_ > 31) {
        throw DiaInvalido{ dia_ };
    }
    if (mes_ < 0 || mes_ > 12) {
        throw MesInvalido{ mes_ };
    }
    if (ano_ < 1892 || ano_ > 2050) {
        throw AnoInvalido{ ano_ };
    }
    if (!(horario == "PTM" || horario == "PTV" || horario == "PTN" || horario == "COR")) {//Se não for igual a PM ou PTV ou PTN ou COR
        throw HorarioInvalido{ horario };
    }
}

Sorteio::Sorteio(std::string data_e_horario, std::string nome, std::array<int, 5> numeros_sorteados, bool status) : data_e_horario_(data_e_horario), nome_(nome),
    numeros_sorteados_(numeros_sorteados), status_(status) {
        if(data_e_horario.size() < 14) {


        }

        //DECOMPOSIÇÃO DA DATA E HORARIO
        std::string dia = data_e_horario.substr(0, 2);
        std::string mes = data_e_horario.substr(3, 2);
        std::string ano = data_e_horario.substr(6, 4);
        std::string horario = data_e_horario.substr(11, 3); //PTM, PTV, PTN, COR

        std::string separador1 = data_e_horario.substr(2, 1);
        std::string separador2 = data_e_horario.substr(5, 1);
        std::string separador3 = data_e_horario.substr(10, 1);

        int dia_ = stoi(dia);
        int mes_ = stoi(mes);
        int ano_ = stoi(ano);

        //Tratamento de excessão
        if (dia_ < 0 || dia_ > 31) {
            throw DiaInvalido{ dia_ };
        }
        if (mes_ < 0 || mes_ > 12) {
            throw MesInvalido{ mes_ };
        }
        if (ano_ < 1892 || ano_ > 2050) {
            throw AnoInvalido{ ano_ };
        }
        if (!(horario == "PTM" || horario == "PTV" || horario == "PTN" || horario == "COR")) {//Se não for igual a PM ou PTV ou PTN ou COR
            throw HorarioInvalido{ horario };
        }
}

std::string Sorteio::data_e_horario(){
    return this->data_e_horario_;
}

std::string Sorteio::nome() {
    return this->nome_;
}

std::array<int, 5> Sorteio::resultados(){
    return this->numeros_sorteados_;
}

ListaApostas Sorteio::apostas_feitas(){
    return this->apostas_feitas_;
}

ListaApostas Sorteio::apostas_ganhas(){
    ListaApostas apostas_ganhas;
    for (auto aposta_selecionada : this->apostas_feitas_.lista_de_aposta()) {
        if (aposta_selecionada.ganhou() == 1) {
            apostas_ganhas.adicionar_aposta(&aposta_selecionada);
        }
    }
    return apostas_ganhas;
}

bool Sorteio::status(){
    return this->status_;
}

void Sorteio::sortear(){
    std::array<int, 5> numeros_sorteados;
    for (int i = 0; i < 5; i++) {
        numeros_sorteados[i] = 14;
            //gerar_numero_aleatorio();

    }
    this->numeros_sorteados_ = numeros_sorteados;
    this->verificar_apostas_ganhas();
    this->status_ = 1;
}

void Sorteio::verificar_apostas_ganhas(){
    if (this->numeros_sorteados_.size() < 5) {
        throw SorteioAindaNaoSorteado{ this->data_e_horario_ };
    }
    this->apostas_feitas_.verificar_apostas_ganhas(this->resultados());
   
}
void Sorteio::apostar(Aposta* aposta, std::string nome_do_sorteio){
    this->apostas_feitas_.adicionar_aposta(aposta);
}
int Sorteio::gerar_numero_aleatorio(){
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<int> distribuicao(0, 9999);

    return distribuicao(gerador);
}



