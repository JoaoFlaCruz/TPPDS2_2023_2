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
        case E6_PAG_CARTEIRA_ADMIN:
            pag_6_carteira_admin();
            break;
        case E7_PAG_JOGADOR:
            pag_7_jogador();
            break;
        case E8_PAG_CADASTRAR_JOGADOR:
            pag_8_cadastrar_jogador();
            break;
        case E9_PAG_LOGAR_JOGADOR:
            pag_9_logar_jogador();
            break;
        case E10_PAG_SIS_JOGADOR:
            pag_10_jogador();
            break;
        case E14_PAG_CARTEIRA_JOGADOR:
            pag_14_carteira_jogador();
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
        msg_erro_ = "O formato da data deve ser DD-MM-AAA/PMT, exemplo: 12-12-2023/COR.";
        erro_tratado_ = false;
    } catch (ValorInvalido e) {
        msg_erro_ = "O valor passado é inválido!";
        erro_tratado_ = false;
    } catch (SaldoInsuficiente e) {
        msg_erro_ = "O saldo é insuficiente!";
        erro_tratado_ = false;
    } catch (ExtratoVazio e) {
        msg_erro_ = "O extrato está vazio.";
        erro_tratado_ = false;
    } catch (ListaDeApostaVazia e) {
        msg_erro_ = "A lista de apostas está vazia.";
        erro_tratado_ = false;
    } catch (ApostaInexistente e) {
        msg_erro_ = "A aposta é inexistente.";
        erro_tratado_ = false;
    } catch (ListaDeSorteioVazia e) {
        msg_erro_ = "A lista de sorteios está vazia.";
        erro_tratado_ = false;
    } catch (SorteioInexistente e) {
        msg_erro_ = "O sorteio não existe.";
        erro_tratado_ = false;
    } catch (JogadorNaoParticipou e) {
        msg_erro_ = "O jogador não participou.";
        erro_tratado_ = false;
    } catch (Nenhum_Usuario_Logado e) {
        msg_erro_ = "Não há usuario logado.";
        erro_tratado_ = false;
    } catch (SorteioAindaNaoSorteado e) {
        msg_erro_ = "O sorteio ainda não foi executado.";
        erro_tratado_ = false;
    } catch (DiaInvalido e) {
        msg_erro_ = "O dia passado é inválido.";
        erro_tratado_ = false;
    } catch (MesInvalido e) {
        msg_erro_ = "O mês passado é inválido.";
        erro_tratado_ = false;
    } catch (AnoInvalido e) {
        msg_erro_ = "O ano passado é inválido.";
        erro_tratado_ = false;
    } catch (HorarioInvalido e) {
        msg_erro_ = "O horário passado é inválido.";
        erro_tratado_ = false;
    } catch (UsuarioJaExiste e) {
        msg_erro_ = "O usuario cadastrado já existe.";
        erro_tratado_ = false;
    } catch (UsuarioNaoEncontrado e) {
        msg_erro_ = "O usuario logado não está cadastrado.";
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

void Interface::logado() {
    InformacoesLogin info = sis_jogador_.informacoes_login();
    std::cout << "########### Usuário: " << info.login << std::endl;
    std::cout << "########### CPF: " << info.cpf << std::endl;
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
        estado_ = E7_PAG_JOGADOR;
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
        estado_ = E6_PAG_CARTEIRA_ADMIN;
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
    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pag_6_carteira_admin() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          SISTEMA ADMINISTRADOR - CARTEIRA ADMIN                                   #" << std::endl;
    std::cout << "#          (1) Adicionar Fundos                                                     #" << std::endl;
    std::cout << "#          (2) Sacar Fundos                                                         #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    std::cout << "########### Saldo: $" << std::fixed << std::setprecision(2) << sis_admin_.retornar_saldo() << std::endl;
    barra_final();
    mensagem_de_erro();
    int entrada = entrada_comando();
    if (entrada == 0) {
        estado_ = E2_PAG_ADMIN;
        return;
    } else if (entrada == 1) {
        double valor;
        std::cout << "########### Valor a adicionar: $";
        std::cin >> valor;
        sis_admin_.adicionar_dinheiro(valor);
        return;
    } else if (entrada == 2) {
        double valor;
        std::cout << "########### Valor a sacar: $";
        std::cin >> valor;
        sis_admin_.retirar_dinheiro(valor);
        return;
    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pag_7_jogador() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          LOGIN COMO JOGADOR                                                       #" << std::endl;
    std::cout << "#          (1) Logar como Jogador                                                   #" << std::endl;
    std::cout << "#          (2) Cadastrar Jogador                                                    #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    mensagem_de_erro();
    int entrada = entrada_comando();
    if (entrada == 0) {
        estado_ = E0_PAG_INICIAL;
        return;
    } else if (entrada == 2) {
        estado_ = E8_PAG_CADASTRAR_JOGADOR;
        return;
    } else if (entrada == 1) {
        estado_ = E9_PAG_LOGAR_JOGADOR;
    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pag_8_cadastrar_jogador() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          CADASTRAR JOGADOR                                                        #" << std::endl;
    std::cout << "#          (1) Cadastrar Jogador                                                    #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    mensagem_de_erro();
    int entrada = entrada_comando();
    if (entrada == 1) {
        std::cout << "########### Insira um apelido de jogador: ";
        std::string apelido;
        std::cin >> apelido;
        std::cout << "########### Insira o login jogador: ";
        std::string login;
        std::cin >> login;
        std::cout << "########### Insira a senha: ";
        std::string senha;
        std::cin >> senha;
        std::cout << "########### Insira o cpf: ";
        std::string cpf;
        std::cin >> cpf;
        sis_jogador_.cadastrar_usuario(apelido, login, senha, cpf);
    } else if (entrada == 0) {
        estado_ = E7_PAG_JOGADOR;
        return;
    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pag_9_logar_jogador() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          LOGIN JOGADOR                                                            #" << std::endl;
    std::cout << "#          (1) Logar Jogador                                                        #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    mensagem_de_erro();
    sis_jogador_.logout();
    int entrada = entrada_comando();
    if (entrada == 1) {
        std::cout << "########### Insira o login: ";
        std::string login;
        std::cin >> login;
        std::cout << "########### Insira a senha: ";
        std::string senha;
        std::cin >> senha;
        sis_jogador_.login(login, senha);
        if(sis_jogador_.logado()) {
            estado_ = E10_PAG_SIS_JOGADOR;
            return;
        }
    } else if (entrada == 0) {
        estado_ = E7_PAG_JOGADOR;
        return;
    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pag_10_jogador() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          SISTEMA JOGADOR                                                          #" << std::endl;
    std::cout << "#          (1) Aposta                                                               #" << std::endl;
    std::cout << "#          (2) Carteira                                                             #" << std::endl;
    std::cout << "#          (3) Logout                                                               #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    logado();
    mensagem_de_erro();
    int entrada = entrada_comando();
    if (entrada == 0) {
        estado_ = E9_PAG_LOGAR_JOGADOR;
        return;
    } else if (entrada == 3) {
        estado_ = E9_PAG_LOGAR_JOGADOR;
        return;
    } else if (entrada == 1) {

    } else if (entrada == 2) {
        estado_ = E14_PAG_CARTEIRA_JOGADOR;
        return;
    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pag_11_aposta() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          SISTEMA JOGADOR - APOSTA                                                 #" << std::endl;
    std::cout << "#          (1) Realizar Aposta                                                      #" << std::endl;
    std::cout << "#          (2) Listar Apostas                                                       #" << std::endl;
    std::cout << "#          (3) Logout                                                               #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    logado();
    mensagem_de_erro();
    int entrada = entrada_comando();
    if (entrada == 1) {

    } else if (entrada == 2) {

    } else if (entrada == 3) {
        estado_ = E9_PAG_LOGAR_JOGADOR;
        return;
    } else if (entrada == 0) {
        estado_ = E10_PAG_SIS_JOGADOR;
        return;
    } else {
        EntradaInvalida e;
        throw e;
    }
}

void Interface::pag_14_carteira_jogador() {
    limpar_tela();
    cabecalho();
    quebra_linha();
    std::cout << "#          SISTEMA JOGADOR - CARTEIRA JOGADOR                                       #" << std::endl;
    std::cout << "#          (1) Adicionar Fundos                                                     #" << std::endl;
    std::cout << "#          (2) Sacar Fundos                                                         #" << std::endl;
    std::cout << "#          (0) Retornar                                                             #" << std::endl;
    quebra_linha();
    barra_final();
    std::cout << "########### Saldo: $" << std::fixed << std::setprecision(2) << sis_jogador_.retornar_saldo() << std::endl;
    barra_final();
    mensagem_de_erro();
    int entrada = entrada_comando();
    if (entrada == 0) {
        estado_ = E10_PAG_SIS_JOGADOR;
        return;
    } else if (entrada == 1) {
        double valor;
        std::cout << "########### Valor a adicionar: $";
        std::cin >> valor;
        sis_jogador_.adicionar_dinheiro(valor);
        return;
    } else if (entrada == 2) {
        double valor;
        std::cout << "########### Valor a sacar: $";
        std::cin >> valor;
        sis_jogador_.retirar_dinheiro(valor);
        return;
    } else {
        EntradaInvalida e;
        throw e;
    }
}
