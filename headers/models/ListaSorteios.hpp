/**
 * @file ListaSorteios.hpp
 * @brief Definição da classe ListaSorteios.
 * @version 1.0
 * @date 2023-12-05
 */
#pragma once
#include "Sorteio.hpp"
#include <list>

/**
 * @brief Exceção lançada quando a lista de sorteios está vazia.
 */
struct ListaDeSorteioVazia {
};

/**
 * @brief Exceção lançada quando um sorteio não existe na lista.
 */
struct SorteioInexistente {
	std::string data_e_horario_que_nao_existe; /**< Data e horário do sorteio inexistente. */
};

/**
 * @brief Exceção lançada quando tenta-se adicionar um sorteio que já existe na lista.
 */
struct SorteioJaExistente{
	std::string data_e_horario_ja_existente; /**< Data e horário do sorteio que já existe. */
};

/**
 * @brief Exceção lançada quando um jogador não participou do sorteio.
 */
struct JogadorNaoParticipou {
	std::string nome_do_jogador; /**< Nome do jogador que não participou. */
};

/**
 * @brief Estrutura para armazenar dados de um sorteio.
 */
struct DadosSorteio {
    std::string nome; /**< Nome do sorteio. */
    std::string data_hora; /**< Data e horário do sorteio. */
    bool status; /**< Status do sorteio (em andamento ou feito). */
};

/**
 * @brief Classe que representa uma lista de sorteios.
 */
class ListaSorteios {
public:
	/**
	 * @brief Construtor padrão da ListaSorteios.
	 */
	ListaSorteios();

	/**
	 * @brief Retorna o tamanho da lista de sorteios.
	 * @return Tamanho da lista.
	 */
	int tamanho();

	/**
	 * @brief Retorna a lista de sorteios.
	 * @return Lista de sorteios.
	 */
	std::list<Sorteio> lista_de_sorteio();

	/**
	 * @brief Adiciona um novo sorteio à lista.
	 * @param sorteio Sorteio a ser adicionado.
	 * @throw SorteioJaExistente se o sorteio já existe na lista.
	 */
	void adicionar_sorteio(Sorteio sorteio);

	/**
	 * @brief Remove um sorteio da lista.
	 * @param data_e_horario Data e horário do sorteio a ser removido.
	 * @throw SorteioInexistente se o sorteio não existe na lista.
	 * @pre O tamanho da lista deve ser maior que zero.
	 */
	void remover_sorteio(std::string data_e_horario);

	/**
	 * @brief Retorna uma lista de sorteios em andamento.
	 * @return Lista de sorteios em andamento.
	 * @pre O tamanho da lista deve ser maior que zero.
	 */
	ListaSorteios sorteios_em_andamento();

	/**
	 * @brief Retorna uma lista de sorteios feitos.
	 * @return Lista de sorteios feitos.
	 * @pre O tamanho da lista deve ser maior que zero.
	 */
	ListaSorteios sorteios_feitos();

	/**
	 * @brief Busca um sorteio na lista pelo nome (data e horário).
	 * @param data_e_horario Data e horário do sorteio a ser buscado.
	 * @return Sorteio encontrado.
	 * @throw SorteioInexistente se o sorteio não existe na lista.
	 * @pre O tamanho da lista deve ser maior que zero.
	 */
	Sorteio buscar_sorteio_por_data_e_horario(std::string data_e_horario);

	/**
	 * @brief Busca participações de um jogador na lista de sorteios.
	 * @param nome_do_jogador Nome do jogador a ser buscado.
	 * @return Lista de sorteios em que o jogador participou.
	 * @throw JogadorNaoParticipou se o jogador não participou de nenhum sorteio.
	 * @pre Deve existir pelo menos um sorteio participado.
	 */
	ListaSorteios buscar_participacao(std::string nome_do_jogador);

	/**
	 * @brief Retorna uma lista de dados dos sorteios.
	 * @return Lista de dados de sorteios.
	 */
	std::list<DadosSorteio> dados_sorteios();

private:
	std::list<Sorteio> lista_de_sorteio_; /**< Lista de sorteios. */
	int tamanho_; /**< Tamanho atual da lista. */

	/**
	 * @brief Verifica se um sorteio com a data e horário fornecidos pertence à lista.
	 * @param data_e_horario Data e horário do sorteio a ser verificado.
	 * @return True se pertence, False caso contrário.
	 */
	bool pertence(std::string data_e_horario);
};
