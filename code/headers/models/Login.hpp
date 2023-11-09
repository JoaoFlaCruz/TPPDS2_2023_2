#pragma once

#include "Usuario.hpp"

class Login {
public:

  Login();

    // Define o usuário logado
    // Pré-condição: O objeto Usuario passado como parâmetro deve ser válido.
    void set_usuario(const Usuario& usuario);

    // Obtém o usuário logado
    // Pré-condição: O usuário logado deve ser válido.
    Usuario get_usuario() const;

    ~Login();

private:
   
    Usuario usuario_;
};
