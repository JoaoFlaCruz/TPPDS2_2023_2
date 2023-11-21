#include "ListaApostas.hpp"
//Testar

ListaApostas::ListaApostas() : lista_de_aposta_({}), tamanho_(0) {

}

std::list<Aposta> ListaApostas::lista_de_aposta() {
	return std::list<Aposta>();
}

int ListaApostas::tamanho(){
	return this->tamanho_;
}

void ListaApostas::adicionar_aposta(Aposta aposta){
	this->lista_de_aposta_.push_back(aposta);
	this->tamanho_++;
}

void ListaApostas::remover_aposta(Aposta aposta) {
	if (this->tamanho_ == 0) {
		throw ListaDeApostaVazia{};
	}
	if (!pertence(aposta)) {
		throw ApostaDeApostaInexistente{ aposta };
	}
	
	//this->lista_de_aposta_.remove(aposta); Manutenção!!
}

ListaApostas ListaApostas::apostas_ganhas(){
	ListaApostas apostas_ganhas;
	for (auto& aposta : this->lista_de_aposta_) {
		if (aposta.ganhou()) {
			apostas_ganhas.adicionar_aposta(aposta);
		}
	}
	return apostas_ganhas;
}

ListaApostas::~ListaApostas() {
	for (auto it = this->lista_de_aposta_.begin(); it != this->lista_de_aposta_.end(); it++) {
		delete &it;
	}
}



bool ListaApostas::pertence(Aposta aposta) {
	for (auto aposta_selecionada : this->lista_de_aposta_) {
		if (0) {//manutençao dessa função
			return 1;
		}
	}
	return 0;
}
