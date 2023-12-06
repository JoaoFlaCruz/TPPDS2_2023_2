#include "SistemaGeral.hpp"
#include <iostream>
#include <vector>
#include <iostream>

void testar_cadastro_carteira_jogador(SistemaGeral jogo) {
	// Testando se é salvo os usuarios na lista de usuario
	jogo.cadastrar_usuario("M", "M", "1");
	jogo.logar_usuario("M", "M");
	std::cout << jogo.saldo_da_carteira_do_jogador() << std::endl;
	jogo.depositar_na_carteira_do_jogador(100);
	std::cout << jogo.saldo_da_carteira_do_jogador() << std::endl;
	jogo.logout();
	jogo.logar_usuario("M", "M");
	std::cout << jogo.saldo_da_carteira_do_jogador() << std::endl;
	jogo.logout();

	//Lindo com diversas entradas e saidas de usuarios e conferindo se os dados como saldo e extrato estão salvando
	jogo.cadastrar_usuario("A", "A", "2");
	jogo.logar_usuario("M", "M");
	std::cout << jogo.saldo_da_carteira_do_jogador() << std::endl;
	jogo.logar_usuario("A", "A");
	std::cout << jogo.saldo_da_carteira_do_jogador() << std::endl;
	jogo.logar_usuario("M", "M");
	jogo.depositar_na_carteira_do_jogador(50);
	std::cout << jogo.saldo_da_carteira_do_jogador() << std::endl;
	std::cout << jogo.extrato_do_jogador().extrato_por_ordem_cronologica().front().first;
}
void testar_adm_carteira_cadastrar_sorteio_lista_de_sorteio(SistemaGeral jogo) {
	
	std::cout << "ADM logado: " << jogo.login_administardor("1234") << std::endl;
	jogo.cadastrar_sorteio("Sorteio1", "05-12-2023/PTN"); //Testado
	Aposta* apostaGrupo = new Grupo("M", 100, 0, { 14 });
	std::cout << apostaGrupo->apostas().front();
	jogo.apostar(apostaGrupo, "Sorteio1");
	jogo.sortear("Sorteio1");

	
}
int main() {
	SistemaGeral jogo;
	testar_adm_carteira_cadastrar_sorteio_lista_de_sorteio(jogo);
	

	
}