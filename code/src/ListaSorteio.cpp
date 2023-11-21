#include "ListaSorteios.hpp"
//Realizar os tratamentos de excessões
//Testar

ListaSorteios::ListaSorteios() : tamanho_(0), lista_de_sorteio_({}) {
}

int ListaSorteios::tamanho(){
	return this->tamanho_;
}

std::list<Sorteio> ListaSorteios::lista_de_sorteio(){
	return this->lista_de_sorteio_;
}

void ListaSorteios::adicionar_sorteio(Sorteio sorteio){
	this->lista_de_sorteio_.push_back(sorteio);
	this->tamanho_++;
}

void ListaSorteios::remover_sorteio(Sorteio sorteio){
	//this->lista_de_sorteio_.remove(sorteio); Manutenção!!!
}

ListaSorteios ListaSorteios::sorteios_em_andamento(){
	ListaSorteios sorteios_em_andamento;
	for (auto sorteio : this->lista_de_sorteio_) {
		if (sorteio.status() == 0) {//sorteio não finalizado
			sorteios_em_andamento.adicionar_sorteio(sorteio);
		}
	}
	return sorteios_em_andamento;
}

ListaSorteios ListaSorteios::sorteios_feitos(){
	ListaSorteios sorteios_feitos;
	for (auto sorteio : this->lista_de_sorteio_) {
		if (sorteio.status() == 1) {//sorteio finalizado
			sorteios_feitos.adicionar_sorteio(sorteio);
		}
	}
	return sorteios_feitos;
}

Sorteio ListaSorteios::buscar_sorteio_por_data_e_horario(std::string data_e_horario){
	for (auto sorteio : this->lista_de_sorteio_) {
		if (sorteio.data_e_horario() == data_e_horario) {
			return sorteio;
		}
	}
	return Sorteio({});
}

ListaSorteios ListaSorteios::buscar_participacao(std::string nome){
	ListaSorteios participacao;
	for (auto sorteio : this->lista_de_sorteio_) {//Selciador de cada sorteio
		Sorteio sorteio_participado(sorteio.data_e_horario(), sorteio.numeros_sorteados(), sorteio.status());//Cria um sorteio com as 
		//mesmas informações do sorteio selecionado, exceto as apostas feitas, que é vazia

		for (auto aposta : sorteio.apostas_feitas().lista_de_aposta()) {//Selecionador de aposta de cada torneio
			if (aposta.nome_do_jogador() == nome) {//Se o jogador participou
				sorteio_participado.apostas_feitas().adicionar_aposta(aposta);
				if (aposta.ganhou() == 1) {
					sorteio_participado.apostas_ganhas().adicionar_aposta(aposta);//Adiciona as apostas ganhas do jogador na lista de 
					//apostas ganhas do sorteio participado
				}
			}
		}

		participacao.adicionar_sorteio(sorteio_participado);
	}
	return participacao;
}


