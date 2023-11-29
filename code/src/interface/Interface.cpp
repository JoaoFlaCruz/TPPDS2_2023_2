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
            break;
        case E2_PAG_ADMIN:
            pagina_2_admin();
            break;
        default:
            break;
        }

    } catch (EntradaInvalida e) {
        msg_erro_ = "A entrada é inválida!";
        erro_tratado_ = false;
    } catch (SenhaInvalida e) {
        msg_erro_ = "A senha está errada!";
    }
}

void Interface::limpar_tela() {
    std::cout << "\033[2J\033[1;1H";
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

int Interface::entrada_comando() {
    std::cout << "########### ENTRE COM O COMANDO: ";
    int entrada;
    std::cin >> entrada;
    return entrada;
}

void Interface::pagina_0_inicial() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          PÁGINA INICIAL                                                           #" << std::endl;
    std::cout << "#          (1) Logar como Admin                                                     #" << std::endl;
    std::cout << "#          (2) Logar como Usuario                                                   #" << std::endl;
    quebra_linha();
    barra_final();
    mensagem_de_erro();
    int entrada = entrada_comando();

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
    std::cout << "#          (1) Logar como Admin                                                     #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    mensagem_de_erro();
    int entrada = entrada_comando();

    if(entrada == 1) {
    } else if(entrada == 0) {
        estado_ = E0_PAG_INICIAL;
        return;
    } else {
        EntradaInvalida e;
        throw e;
    }

    std::cout << "########### ENTRE COM A SENHA: ";
    std::string senha;
    std::cin >> senha;

    if(sis_admin_.validar_senha(senha)) {
        estado_ = E2_PAG_ADMIN;
        return;
    } else {
        SenhaInvalida e;
        throw e;
    }

}

void Interface::pagina_2_admin() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          SISTEMA ADMINISTRADOR                                                    #" << std::endl;
    std::cout << "#          (1) Sorteios                                                             #" << std::endl;
    std::cout << "#          (2) Carteira                                                             #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    int entrada = entrada_comando();

    if(entrada == 0) {
        estado_ = E1_PAG_LOGIN_ADMIN;
        return;
    }
}

