#pragma once
#include <vector>
#include "Usuario.hpp"

 class ListaUsuario {
 public:
  // inicializa o vetor usuarios_ como vazio.
  ListaUsuario();

  //adiciona um novo usuário ao vetor usuarios_.
  //Pre condição :  O usuário não deve existir na lista.
  void AdicionarUsuario(const Usuario& usuario);

  //verifica se um determinado login existe no vetor usuarios_.
  //Pre condição : A lista de usuários não deve estar vazia.
  bool ValidarLogin(const std::string& login) const;

  //retorna um ponteiro para um objeto Usuario com o login especificado, se existir.
  //Pre condição : A lista de usuários não deve estar vazia.
  Usuario* BuscarUsuario(const std::string& login) const;

 private:
  std::vector<Usuario> usuarios_;
};
