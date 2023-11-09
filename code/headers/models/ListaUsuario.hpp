#pragma once
#include <vector>
#include "Usuario.hpp"

class ListaUsuario {
public:
  // inicializa o vetor usuarios_ como vazio.
  ListaUsuario();

  // adiciona um novo usuário ao vetor usuarios_.
  // pré-condição: o usuário não deve existir na lista.
  void adicionar_usuario(const Usuario& usuario);

  // verifica se um determinado login existe no vetor usuarios_.
  // pré-condição: a lista de usuários não deve estar vazia.
  bool validar_login(const std::string& login) const;

  // retorna um ponteiro para um objeto Usuario com o login especificado, se existir.
  // pré-condição: a lista de usuários não deve estar vazia.
  Usuario* buscar_usuario(const std::string& login) const;

private:
  std::vector<Usuario> usuarios_;
};

