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
        case E3_PAG_SORTEIO:
            pagina_3_sorteio();
            break;
        case E4_PAG_CADASTRAR_SORTEIO:
            pag_4_cadastrar_sorteio();
            break;
        case E5_PAG_LISTAR_SORTEIO:
            pag_5_listar_sorteio();
            break;
        default:
            break;
        }

    } catch (EntradaInvalida e) {
        msg_erro_ = "A entrada é inválida!";
        erro_tratado_ = false;
    } catch (SenhaInvalida e) {
        msg_erro_ = "A senha está errada!";
        erro_tratado_ = false;
    } catch (SorteioJaExistente e) {
        msg_erro_ = "O sorteio já existe!";
        erro_tratado_ = false;
    } catch (FormatoDataHoraInvalido e) {
        msg_erro_ = "O formato da data deve ser DD-MM-AAA/PMT, exemplo: 12-12-2023/COR";
        erro_tratado_ = false;
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
    mensagem_de_erro();
    int entrada = entrada_comando();

    if(entrada == 0) {
        estado_ = E1_PAG_LOGIN_ADMIN;
        return;
    } else if (entrada == 1) {
        estado_ = E3_PAG_SORTEIO;
        return;
    } else if (entrada == 2) {
        // Preencher com PAG_CARTEIRA
        return;
    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pagina_3_sorteio() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          SISTEMA ADMINISTRADOR - SORTEIO                                          #" << std::endl;
    std::cout << "#          (1) Listar Sorteios                                                      #" << std::endl;
    std::cout << "#          (2) Cadastrar Sorteio                                                    #" << std::endl;
    std::cout << "#          (3) Realizar Sorteio                                                     #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    mensagem_de_erro();
    int entrada = entrada_comando();

    if(entrada == 0) {
        estado_ = E2_PAG_ADMIN;
        return;
    } else if (entrada == 1) {
        estado_ = E5_PAG_LISTAR_SORTEIO;
        return;
    } else if (entrada == 2) {
        estado_ = E4_PAG_CADASTRAR_SORTEIO;
        return;
    }else if (entrada == 3) {
        // Preencher com PAG_REALIZAR_SORTEIO
        return;
    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pag_4_cadastrar_sorteio() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          SISTEMA ADMINISTRADOR - CADASTRAR SORTEIO                                #" << std::endl;
    std::cout << "#          (1) Cadastrar                                                            #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    mensagem_de_erro();
    int entrada = entrada_comando();

    if (entrada == 0) {
        estado_ = E3_PAG_SORTEIO;
        return;
    } else if (entrada == 1) {

    } else {
        EntradaInvalida e;
        throw e;
    }

    std::cout << "########### ENTRE COM UM NOME PARA O SORTEIO: ";
    std::string nome;
    std::cin >> nome;
    std::cout << "########### HORÁRIOS POSSÍVEIS:" << std::endl;
    std::cout << "########### PTM : Para Todos Manhã (sorteio de manhã)" << std::endl;
    std::cout << "########### PTV : Para Todos Vespertino (sorteio de tarde)" << std::endl;
    std::cout << "########### PTN : Para Todos Noturno (sorteio de noite)" << std::endl;
    std::cout << "########### COR : Coruja (sorteio de madrugada)" << std::endl;
    std::cout << "########### EXEMPLO DE DATA: 25-12-2023/PTM" << std::endl;
    std::cout << "########### EXEMPLO DE DATA: 02-12-2023/COR" << std::endl;
    std::cout << "########### ENTRE COM A DATA (FORMATO: DD-MM-AAAA/HHH) ";
    std::string data;
    std::cin >> data;

    sis_admin_.adicionar_sorteio(nome, data);
}

void Interface::pag_5_listar_sorteio() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          SISTEMA ADMINISTRADOR - LISTAR SORTEIO                                   #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();

    std::list<DadosSorteio> lista_dados = sis_admin_.dados_sorteios();

    for(auto it = lista_dados.begin(); it != lista_dados.end(); it++) {
        std::cout << "########### Sorteio " << it->nome << " : " << it->data_hora << " - ";
        if(it->status) {
            std::cout << "EXEC" << std::endl;
        } else {
            std::cout << "NEXEC" << std::endl;
        }
    }

    barra_final();
    mensagem_de_erro();
    int entrada = entrada_comando();
    if (entrada == 0) {
        estado_ = E3_PAG_SORTEIO;
        return;
    }
}