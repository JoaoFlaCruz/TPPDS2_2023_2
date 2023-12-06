#include "headers/models/aposta/Aposta.hpp"
#include "headers/models/Carteira.hpp"
#include "headers/models/Extrato.hpp"
#include "headers/models/Jogador.hpp"
#include "headers/models/ListaApostas.hpp"
#include "headers/models/ListaSorteios.hpp"
#include "headers/models/ListaUsuario.hpp"
#include "headers/models/Sorteio.hpp"
#include "headers/models/Usuario.hpp"

//Provavelmente a parte dos sorteios haverá problemas, mas será facil de corrigir
class SistemaGeral {
public:
	/* Login */

	//Cadastrar usuario
	//Adiciona esse usuario a lista de usuarios
	void cadastrar_usuario(std::string nome, std::string senha, std::string cpf);

	//Logar como usuario
	//Retorna um endereço de memoria de um usuario
	void logar_usuario(std::string nome, std::string senha);

	void logout();

	/* Jogador */

	//Apostar
	//Adiciona uma aposta a lista de apostas de um sorteio desejado
	void apostar(Aposta aposta, std::string nome_do_sorteio);

	//Listar sorteios participados
	ListaSorteios buscar_sorteios_participados(std::string nome_do_jogador);

	//Listar sorteios em andamento
	ListaSorteios buscar_sorteios_em_andamento();

	
	/* Carteira do jogador */
	//Ver saldo da carteira de um jogador
	float saldo_da_carteira_do_jogador();

	//Depositar
	void depositar_na_carteira_do_jogador(float valor_a_ser_depositado);

	//Sacar
	void sacar_na_carteira_do_jogador(float valor_a_ser_sacado);

	//Mostrar extrato do jogador
	Extrato extrato_do_jogador();


	/* Administrador */

	//Cadastrar sorteio
	void cadastrar_sorteio(std::string nome_sorteio_a_ser_cadastrado);

	//Sortear
	void sortear(std::string nome_do_sorteio_a_ser_sorteado);

	//Listar sorteios ja realizados
	ListaSorteios buscar_sorteios_ja_realizados();


	/* Carteira do administrador */
	//Saldo na carteira do administrador
	float saldo_da_carteira_do_administrador();

	//Depositar na carteira do administrador
	void depositar_na_carteira_do_administrador(float valor_a_ser_depositado);

	//Sacar na carteira do administrador
	void sacar_na_carteira_do_administrador(float valor_a_ser_sacado);

	//Mostrar extrato do jogador
	Extrato extrato_do_administrador();


private:
	ListaUsuario lista_de_usuarios_cadastrados;
	Usuario* usuario_logado;
	ListaSorteios todos_os_sorteios;
	Carteira carteira_do_administrador;

}; 