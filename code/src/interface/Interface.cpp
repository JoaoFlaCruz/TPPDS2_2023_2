#include "./../../headers/interface/Interface.hpp"

Interface::Interface(){
    estado_ = E0_PAG_INICIAL;
    msg_erro_ = "";
    erro_tratado_ = true;

}

Interface::~Interface(){}

void Interface::executar() {
    try{
        switch (estado_)
        {
        case E0_PAG_INICIAL:
            pagina_0_inicial();
            break;
        case E1_PAG_LOGIN_ADMIN:
            pagina_1_login_admin();
        default:
            break;
        }

    } catch (EntradaInvalida e) {
        msg_erro_ = "A entrada é inválida!";
        erro_tratado_ = false;
    }
}

void Interface::limpar_tela() {
    system("clear||cls");
}

void Interface::cabecalho() {
    std::cout << "###################################"
        << " JOGO DO BICHO "
        << "###################################"
        << std::endl;
}

void Interface::barra_final() {
    std::cout << "#####################################################################################" << std::endl;
}

void Interface::quebra_linha() {
    std::cout << "#                                                                                   #" << std::endl;
}

void Interface::mensagem_de_erro() {
    if (erro_tratado_){return;}
    std::cout << msg_erro_ << std::endl;
    std::cout << "#####################################################################################" << std::endl;
    erro_tratado_ = true;
}

void Interface::pagina_0_inicial() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          (1) Logar como Admin                                                     #" << std::endl;
    std::cout << "#          (2) Logar como Usuario                                                   #" << std::endl;
    quebra_linha();
    barra_final();
    mensagem_de_erro();

    std::cout << "########### ENTRE COM O COMANDO: ";
    int entrada;
    std::cin >> entrada;

    if(entrada == 1) {
        estado_ = E1_PAG_LOGIN_ADMIN;
    } else if(entrada == 2) {

    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pagina_1_login_admin() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          LOGIN COMO ADMINISTRADOR                                                 #" << std::endl;
    std::cout << "#          Insira as credenciais                                                    #" << std::endl;
    quebra_linha();
    barra_final();

    std::cout << "########### ENTRE COM A SENHA: ";
    std::string senha;
    std::cin >> senha;
}
