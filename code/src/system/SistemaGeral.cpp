#include "./../../headers/system/SistemaGeral.hpp"

void SistemaGeral::cadastrar_usuario(std::string nome, std::string senha, std::string cpf){
	this->lista_de_usuarios_cadastrados.adicionarUsuario(nome, senha, cpf);
}
void SistemaGeral::logar_usuario(std::string nome, std::string senha){

	this->lista_de_usuarios_cadastrados.login(nome, senha);
	this->usuario_logado_ = this->lista_de_usuarios_cadastrados.usuario_logado();

}

Usuario SistemaGeral::usuario_logado(){
	return *usuario_logado_;
}

void SistemaGeral::logout(){
	this->lista_de_usuarios_cadastrados.logout();
	this->usuario_logado_ = nullptr;
}

void SistemaGeral::apostar(Aposta* aposta, std::string nome_do_sorteio){
	this->sorteios_em_andamento.apostar(aposta, nome_do_sorteio);
}

ListaSorteios SistemaGeral::buscar_sorteios_participados(std::string nome_do_jogador){
	return this->sorteios_realizados.buscar_participacao(nome_do_jogador);
}

ListaSorteios SistemaGeral::buscar_sorteios_em_andamento(){
	return this->sorteios_em_andamento.sorteios_feitos();
}

float SistemaGeral::saldo_da_carteira_do_jogador(){

	return this->usuario_logado_->saldo_da_carteira();
}

void SistemaGeral::depositar_na_carteira_do_jogador(float valor_a_ser_depositado){
	this->usuario_logado_->depositar_na_carteira(valor_a_ser_depositado);
}

void SistemaGeral::sacar_na_carteira_do_jogador(float valor_a_ser_sacado){
	this->usuario_logado_->sacar_na_carteira(valor_a_ser_sacado);
}

Extrato SistemaGeral::extrato_do_jogador(){
	return this->usuario_logado_->extrato();
}

bool SistemaGeral::login_administardor(std::string senha){
	if (senha == "1234") {
		return 1;
	}
	else {
		return 0;
	}
}

void SistemaGeral::cadastrar_sorteio(std::string nome_sorteio_a_ser_cadastrado, std::string data_e_horario){
	Sorteio sorteio_criado(nome_sorteio_a_ser_cadastrado, data_e_horario);
	this->sorteios_em_andamento.adicionar_sorteio(sorteio_criado);
	
}

void SistemaGeral::sortear(std::string nome_do_sorteio_a_ser_sorteado){
	this->sorteios_em_andamento.sortear(nome_do_sorteio_a_ser_sorteado);
	//pagar os jogadores
	//copiar sorteio da lista de sorteios em andamento para a de sorteios realizados e exclui-lo de em andamentos
}

ListaSorteios SistemaGeral::buscar_sorteios_ja_realizados(){
	return this->sorteios_realizados.sorteios_feitos();
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
