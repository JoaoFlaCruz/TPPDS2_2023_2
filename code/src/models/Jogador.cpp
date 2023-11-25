#include "../../headers/models/Jogador.hpp"
//Testar

Jogador::Jogador(std::string apelido) : nome_do_jogador_(apelido), carteira_({}) {

}

Jogador::Jogador() : nome_do_jogador_({}), carteira_({}) {
}

std::string Jogador::nome_do_jogador(){
	return this->nome_do_jogador_;
}

Carteira Jogador::carteira(){
	return this->carteira_;
}


