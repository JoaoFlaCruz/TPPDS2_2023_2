#include "SistemaGeral.hpp"
#include <iostream>
#include <vector>
#include <iostream>

// Testando se é salvo os usuarios na lista de usuario
int main() {
	SistemaGeral jogo;
	jogo.cadastrar_usuario("M", "M", "1");
	jogo.logar_usuario("M", "M");
	std::cout << jogo.saldo_da_carteira_do_jogador() << std::endl;
	jogo.depositar_na_carteira_do_jogador(100);
	std::cout << jogo.saldo_da_carteira_do_jogador() << std::endl;
	jogo.logout();
	jogo.logar_usuario("M", "M");
	std::cout << jogo.saldo_da_carteira_do_jogador() << std::endl;
}