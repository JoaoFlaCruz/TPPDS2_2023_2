#include "SistemaGeral.hpp"

void SistemaGeral::cadastrar_usuario(std::string nome, std::string senha, std::string cpf){
	this->lista_de_usuarios_cadastrados.adicionarUsuario(nome, senha, cpf);
}
void SistemaGeral::logar_usuario(std::string nome, std::string senha){

	this->lista_de_usuarios_cadastrados.login(nome, senha);
	this->usuario_logado = this->lista_de_usuarios_cadastrados.usuario_logado();

}

void SistemaGeral::logout(){
	this->lista_de_usuarios_cadastrados.logout();
	this->usuario_logado = nullptr;
}

void SistemaGeral::apostar(Aposta aposta, std::string nome_do_sorteio){
	this->todos_os_sorteios.buscar_sorteio_por_nome(nome_do_sorteio).apostas_feitas().adicionar_aposta(aposta);
}

ListaSorteios SistemaGeral::buscar_sorteios_participados(std::string nome_do_jogador){
	return this->todos_os_sorteios.buscar_participacao(nome_do_jogador);
}

ListaSorteios SistemaGeral::buscar_sorteios_em_andamento(){
	return this->todos_os_sorteios.sorteios_em_andamento();
}

float SistemaGeral::saldo_da_carteira_do_jogador(){

	return this->usuario_logado->saldo_da_carteira();
}

void SistemaGeral::depositar_na_carteira_do_jogador(float valor_a_ser_depositado){
	this->usuario_logado->depositar_na_carteira(valor_a_ser_depositado);
}

void SistemaGeral::sacar_na_carteira_do_jogador(float valor_a_ser_sacado){
	this->usuario_logado->sacar_na_carteira(valor_a_ser_sacado);
}

Extrato SistemaGeral::extrato_do_jogador(){
	return this->usuario_logado->extrato();
}

void SistemaGeral::cadastrar_sorteio(std::string nome_sorteio_a_ser_cadastrado){
	this->todos_os_sorteios.adicionar_sorteio(this->todos_os_sorteios.buscar_sorteio_por_nome(nome_sorteio_a_ser_cadastrado));
}

void SistemaGeral::sortear(std::string nome_do_sorteio_a_ser_sorteado){
	this->todos_os_sorteios.buscar_sorteio_por_nome(nome_do_sorteio_a_ser_sorteado).sortear();
}

ListaSorteios SistemaGeral::buscar_sorteios_ja_realizados(){
	return this->todos_os_sorteios.sorteios_feitos();
}

float SistemaGeral::saldo_da_carteira_do_administrador(){
	return this->carteira_do_administrador.saldo();
}

void SistemaGeral::depositar_na_carteira_do_administrador(float valor_a_ser_depositado){
	this->carteira_do_administrador.depositar(valor_a_ser_depositado);
}

void SistemaGeral::sacar_na_carteira_do_administrador(float valor_a_ser_sacado){
	this->carteira_do_administrador.sacar(valor_a_ser_sacado);
}

Extrato SistemaGeral::extrato_do_administrador(){
	return this->carteira_do_administrador.extrato();
}
