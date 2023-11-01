# JOGO DO BICHO - PDS2 2023.2

## Grupo

- João Flávio de Freitas Cruz - 2023421408
- João Vitor Alves - 2021014120
- Matheus de Freitas Andrade - 2023421580
- Maycon Gomes de Oliveira - 2021013949
- Geanderson Luiz de Souza - 2021014350


## Documentação

### Apresentação do Problema

O projeto do *Jogo do Bicho* foi escolhido como um programa experimental para automatizar o cadastro e sorteio de números de uma loteria do bicho. A escolha foi motivada pela ideia de adicionar um toque cômico e interessante à avaliação de desenvolvimento de programas na disciplina de PDS2, de forma envolvente para os alunos.

É notável que a digitalização dos negócios tem crescido como tendência em diversos mercados, inclusive em setores considerados ilegais, como o do Jogo do Bicho. Observamos o surgimento de cassinos e loterias virtuais no Brasil.

O foco deste projeto é criar uma interface que suporte as funcionalidades de uma loteria do Jogo do Bicho, incluindo cadastro de usuários, compra de cartelas, modalidades de jogo, sorteio de prêmios, distribuição dos prêmios e avaliação de desempenho dos usuários.

Este projeto reconhece não apenas a digitalização crescente dos negócios, mas também presta homenagem a um jogo que desempenhou um papel singular na cultura popular brasileira. O Jogo do Bicho representa um exemplo de como a tecnologia pode ser empregada de forma criativa e inovadora, independentemente do contexto, mantendo a diversão e o envolvimento como elementos centrais.

### Descrição Geral do Sistema

O sistema deve ser dividido em duas frentes distintas: sistema de jogadores e sistema admin. O sistema de jogadores possui como objetivo representar a interface utilizada por uma usuário que irá apostar nos sorteios e participar como cliente do jogo do bicho. O sistema de admin possui como objetivo representar a interface utilziada por um organizador do sorteio do bicho de modo a permitir a criação de sorteios, o acesso aos fundos do sorteio e o pagamento dos jogadores que venham a ganhar.

#### Requisitos do Projeto

- __Realização de sorteios:__ O sistema deve ser capaz de cadastrar e executar sorteios para o jogo do bicho, encontrar as apostas ganhadoras e distribuir a premiação de acordo às regras de monetização das apostas. Os sorteios deverão seguir o modelo do jogo do bicho com diferentes tipos de premiação para diferentes tipos de apostas.

- __Cadastro e funcionamento para usuários:__ O sistema deve ser capaz de cadastrar usuários e permitir o login no sistema de jogos onde esses poderão realizar apostas em sorteios existentes escolhendo entre os diversos modelos de aposta existentes, adicionar fundos às suas carteiras, ver seus históricos de jogos e de entrada/saída de fundos.

- __Tipos de apostas:__ O sistema deve ser capaz de diferenciar o tipo de aposta feita com base em sua regra de classes implementando herança e polimorfismo de acordo à cada tipo de aposta para verificar sua vitória e sua premiação.

- __Interface com o usuário:__ O sistema deve possuir uma interface em terminal capaz de permitir a manipulação dos dados por meio de um usuário jogador ou de um usuário admin possuindo diferentes capacidades para cada um dos tipos de usuário.

#### Requisitos Funcionais - Usuário

1. O sistema deve permitir o cadastro de usuários com login e senha
2. O sistema deve permitir o login de usuários levantando uma seção de operação para estes
3. O sistema deve permitir a entrada e saída de fundos da carteira de usuário com registro das operações
4. O sistema deve permitir a listagem e apresentação dos sorteios existentes
5. O sistema deve permitir a aposta nos sorteios existentes
6. O sistema deve permitir que os usuários visualizem seus históricos de apostas e ganhos.

#### Requisitos Funcionais - Administrador

1. O sistema deve permitir um login com uma conta de admin padronizada
2. O sistema deve permitir a criação de sorteios
3. O sistema deve permitir a listagem dos sorteios existentes
4. O sistema deve permitir a listagem das apostas feitas em um sorteio
5. O sistema deve permitir a execução de um sorteio obtendo um resultado
6. O sistema deve permitir o mapeamento dos ganhadores do sorteio por meio das suas apostas
7. O sistema deve permitir o pagamento dos jogadores ganhadores do valor pretendido por suas apostas
8. O sistema deve permitir a entrada e saída de fundos da carteira administradora bem como o registro das transações executadas

#### Requisitos Não-Funcionais

1. Deve ser amigável para o usuário jogador e para o usuário admin de modo a ter um fácil entendimento por parte dos que o usam
2. Deve possuir tratamento das excessões apresentando em liguagem simples os erros obtidos
3. Deve ser robusto para resistir às entradas de dados errados e permitir que o usuário tente o quebrar sem êxito
4. Deve ser realístico provando a possibilidade prática da implementação de um jogo do bicho em um programa computacional sendo um modelo para possíveis implementações em rede
