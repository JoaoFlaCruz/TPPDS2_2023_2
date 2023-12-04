#include "doctest.h"
#include "../../headers/models/Carteira.hpp"
#include "../../headers/models/Extrato.hpp"

TEST_CASE("Teste 1 - Construtor da Carteira")
{
    Carteira carteira;
    CHECK(carteira.saldo() == 0.0f);
}

TEST_CASE("Teste 2 - Depositar na Carteira")
{
    Carteira carteira;
    carteira.depositar(100.0f);
    CHECK(carteira.saldo() == 100.0f);

    // Testar depósito de valor negativo
    CHECK_THROWS_AS(carteira.depositar(-50.0f), ValorInvalido);
}

TEST_CASE("Teste 3 - Sacar da Carteira")
{
    Carteira carteira;
    carteira.depositar(200.0f);

    // Testar saque bem-sucedido
    carteira.sacar(50.0f);
    CHECK(carteira.saldo() == 150.0f);

    // Testar saque de valor negativo
    CHECK_THROWS_AS(carteira.sacar(-30.0f), ValorInvalido);

    // Testar saque de valor maior que o saldo
    CHECK_THROWS_AS(carteira.sacar(200.0f), SaldoInsuficiente);
}

TEST_CASE("Teste 4 - Extrato da Carteira")
{
    Carteira carteira;
    carteira.depositar(300.0f);
    carteira.sacar(50.0f);

    Extrato extrato = carteira.extrato();

    // Verificar se as transações foram registradas corretamente no extrato
    CHECK(extrato.tamanho() == 2);

    // Mostrar movimentações
    extrato.exibirMovimentacoes();
}
