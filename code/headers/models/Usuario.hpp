#include <string>
#include "Jogador.hpp"

class Usuario {
private:
    std::string nome_;
    std::string senha_;
    std::string cpf_;
    Jogador jogador_;

public:
    
    Usuario(std::string nome, std::string senha, std::string cpf, Jogador jogador);

    
    ~Usuario();

    // Métodos de acesso (getter) para os membros privados
    std::string obterNome() const;
    std::string obterSenha() const;
    std::string obterCPF() const;
    Jogador obterJogador() const;

    // Método para alterar a senha //opcional podem tirar se quiserem
    void alterarSenha(std::string senhaNova);
};

