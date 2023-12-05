#include "../../headers/models/ListaSorteios.hpp"
//Testar

ListaSorteios::ListaSorteios() : lista_de_sorteio_({}), tamanho_(0) {
}

int ListaSorteios::tamanho(){
	return this->tamanho_;
}

std::list<Sorteio> ListaSorteios::lista_de_sorteio(){
	return this->lista_de_sorteio_;
}

void ListaSorteios::adicionar_sorteio(Sorteio sorteio){
	for (auto sorteio_selecionado : this->lista_de_sorteio_) {
		if (sorteio_selecionado.data_e_horario() == sorteio.data_e_horario()) {
			throw SorteioJaExistente{ sorteio.data_e_horario() };
		}
	}
	this->lista_de_sorteio_.push_back(sorteio);
	this->tamanho_++;
}

void ListaSorteios::remover_sorteio(std::string data_e_horario){
	if (this->tamanho_ == 0) {
		throw ListaDeSorteioVazia{};
	}

	if (!pertence(data_e_horario)){ //Se o sorteio não pertence a lista não pode ser adicionado
		throw SorteioInexistente{ data_e_horario };
	}

	for (auto it = this->lista_de_sorteio_.begin(); it != this->lista_de_sorteio_.end(); it++) {
		if (it->data_e_horario() == data_e_horario) {
			this->lista_de_sorteio_.erase(it);
			this->tamanho_--;
			break;
		}
	}
}

ListaSorteios ListaSorteios::sorteios_em_andamento(){
	if (this->tamanho_ == 0) {
		throw ListaDeSorteioVazia{};
	}

	ListaSorteios sorteios_em_andamento;

	for (auto sorteio : this->lista_de_sorteio_) {
		if (sorteio.status() == 0) {//sorteio não finalizado
			sorteios_em_andamento.adicionar_sorteio(sorteio);
		}
	}
	return sorteios_em_andamento;
}

ListaSorteios ListaSorteios::sorteios_feitos(){
	if (this->tamanho_ == 0) {
		throw ListaDeSorteioVazia{};
	}

	ListaSorteios sorteios_feitos;

	for (auto sorteio : this->lista_de_sorteio_) {
		if (sorteio.status() == 1) {//sorteio finalizado
			sorteios_feitos.adicionar_sorteio(sorteio);
		}
	}
	return sorteios_feitos;
}

Sorteio& ListaSorteios::buscar_sorteio_por_nome(std::string nome_do_sorteio){
	if (this->tamanho_ == 0) {
		throw ListaDeSorteioVazia{};
	}

	if (!pertence(nome_do_sorteio)) { //Se o sorteio não pertence a lista não pode ser adicionado
		throw SorteioInexistente{ nome_do_sorteio };
	}

	for (auto& sorteio : this->lista_de_sorteio_) {
		if (sorteio.data_e_horario() == nome_do_sorteio) {
			return sorteio;
		}
	}
	Sorteio vazio(" ", " ");
	return vazio;
}

Sorteio ListaSorteios::buscar_sorteio_por_data_e_horario(std::string data_e_horario){
	if (this->tamanho_ == 0) {
		throw ListaDeSorteioVazia{};
	}

	if (!pertence(data_e_horario)) { //Se o sorteio não pertence a lista não pode ser adicionado
		throw SorteioInexistente{ data_e_horario };
	}

	for (auto sorteio : this->lista_de_sorteio_) {
		if (sorteio.data_e_horario() == data_e_horario) {
			return sorteio;
		}
	}
	Sorteio vazio(" ", " ");
	return vazio;
}

ListaSorteios ListaSorteios::buscar_participacao(std::string nome_do_jogador){
	ListaSorteios participacao;
	bool existe_participacao = 0; //Existe participação em pelo menos um sorteio
	for (auto sorteio : this->lista_de_sorteio_) {//Selciador de cada sorteio
		Sorteio sorteio_participado(sorteio.data_e_horario(), sorteio.nome());//Cria um sorteio com as
		//mesmas informações do sorteio selecionado, exceto as apostas feitas, que é vazia

		for (auto aposta : sorteio.apostas_feitas().lista_de_aposta()) {//Selecionador de aposta de cada torneio
			if (aposta.nome_do_jogador() == nome_do_jogador) {//Se o jogador participou
				sorteio_participado.apostas_feitas().adicionar_aposta(aposta);
				existe_participacao = 1;
				if (aposta.ganhou() == 1) {
					sorteio_participado.apostas_ganhas().adicionar_aposta(aposta);//Adiciona as apostas ganhas do jogador na lista de
					//apostas ganhas do sorteio participado
				}
			}
		}

		participacao.adicionar_sorteio(sorteio_participado);
	}

	if (!existe_participacao) {
		throw JogadorNaoParticipou{ nome_do_jogador };
	}

	return participacao;
}

bool ListaSorteios::pertence(std::string data_e_horario){
	for (auto sorteio_selecionado : this->lista_de_sorteio_) {
		if (sorteio_selecionado.data_e_horario() == data_e_horario) {
			return true;
		}
	}

	return false;
}

std::list<DadosSorteio> ListaSorteios::dados_sorteios() {
	std::list<DadosSorteio> lista;
	DadosSorteio dados;
	for(auto it = lista_de_sorteio_.begin(); it != lista_de_sorteio_.end(); it++) {
		dados.nome = it->nome();
		dados.data_hora = it->data_e_horario();
		dados.status = it->status();
		lista.push_back(dados);
	}
	return lista;
}