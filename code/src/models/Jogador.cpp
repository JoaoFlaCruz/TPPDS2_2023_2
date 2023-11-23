#include "Jogador.hpp"
//Testar

Jogador::Jogador(std::string apelido) : apelido_(apelido) {

}

std::string Jogador::apelido(){
	return this->apelido_;
}

Carteira Jogador::carteira(){
	return this->carteira_;
}


