#pragma once

#include <vector>

class Extrato {
public:
    // Registra uma transação no extrato.
    // Pré-condição: O valor da transação deve ser não negativo.
    void registrar_transacao(double valor, bool ganho);

    // Calcula e retorna o total de ganhos ou perdas no extrato.
    // Pré-condição: O extrato não deve estar vazio.
    double calcular_ganhos_ou_perdas() const;

private:
    // Armazena informações sobre uma transação.
    // Cada elemento é um par representando o valor e se é ganho (true) ou perda (false).
    std::vector<std::pair<double, bool>> transacoes;
};
