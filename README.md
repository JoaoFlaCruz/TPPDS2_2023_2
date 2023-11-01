# JOGO DO BICHO - PDS2 2023.2

## Grupo

- João Flávio de Freitas Cruz - 2023421408
- João Vitor Alves - 2021014120
- Matheus de Freitas Andrade - 2023421580
- Maycon Gomes de Oliveira - 2021013949
- Geanderson Luiz de Souza - 2021014350


## Documentação

### Introdução sobre o jogo do bicho

  O jogo do bicho é um tipo de jogo de azar amplamente difundido no Brasil.
Nele, os participantes realizam apostas em grupos, sendo que cada grupo é associado a um animal e a
quatro números consecutivos entre 0 e 99. Na aposta mais simples, a por grupo, cinco números são sorteados, e os jogadores saem vitoriosos caso o número
correspondente ao animal no qual apostaram seja sorteado, seguindo um processo semelhante ao de uma rifa.

  A origem do jogo do bicho remonta ao fim do Império e ao início do período republicano. Segundo registros em
jornais daquela época, João Batista Viana Drummond, um latifundiário que possuía escravos, tomou uma
iniciativa para reverter as dificuldades financeiras enfrentadas pelo zoológico localizado no bairro de
Vila Isabel. Ele concebeu uma espécie de loteria na qual os participantes tinham a opção de escolher um dos
25 animais do zoológico.
  Nessa loteria do jogo do bicho, as pessoas podiam fazer apostas com valores que variavam desde moedas simples até pequenas frações de moedas (tostões furados). Isso aconteceu em um momento de recessão econômica no Brasil, tornando o jogo do bicho uma forma acessível de entretenimento e apostas para a população daquela época.

#### Como se joga
  Com o passar dos anos, o jogo do bicho evoluiu e se refinou. A banca realiza um sorteio de cinco pares de dezenas, numeradas de 00 a 99, que estão associadas a animais. No total, são 25 animais, e cada um deles representa uma dezena composta por quatro números. Para ganhar a aposta, é necessário que o animal escolhido seja sorteado pela banca.

  Outra forma de testar sua sorte no jogo do bicho é através das apostas no milhar. Nesse caso, o jogador não precisa selecionar um animal a ser sorteado; é o oposto! É necessário escolher os quatro números que a banca sorteará. Essa é uma aposta consideravelmente mais desafiadora de acertar, mas, em contrapartida, o valor apostado é multiplicado por 4 mil vezes em caso de acerto.

*Referências:*
+ Jogo do Bicho. In: WIKIPÉDIA: a enciclopédia livre. Disponível em: https://pt.wikipedia.org/wiki/Jogo_do_bicho. Acesso em: 30 out. 2023.
+ TORCATO, Carlos Eduardo Martins. A repressão oficial ao jogo do bicho: uma história dos jogos de azar em Porto Alegre (1885-1917). Dissertação (mestrado). PPG em História, Universidade Federal do Rio Grande do Sul, 2011

### Apresentação do Problema

O projeto do **Jogo do Bicho** foi escolhido como um programa experimental para a automatização do processo de cadastro
e sorteio de números para o funcionamento de uma loteria do bicho. O projeto teve sua escolha baseada na ideia de
trazer uma pegada cômica e interessante à avaliação de desenvolvimento de programas na matéria de PDS2, contando com um
tema que fosse divertido e de fácil engajamento por parte dos alunos envolvidos.

O foco desse projeto é criar uma interface capaz de rodar plenamente as funcionalidades de uma loteria do Jogo do Bicho
contando com cadastro de usuários, compra de cartelas e modalidades de jogo, sorteio de prêmios, distribuição dos
prêmios e avaliação de desempenho por parte dos usuários.

É um fato consumado que a digitalização dos negócios tem crescido como tendência nos mercados em geral e até mesmo em
mercados ilegais a digitalização se torna um processo natural. Vemos diversos modelos de cassinos e loterias virtuais
despontando no Brasil.

### Descrição Geral do Sistema

Com o objetivo de simular o jogo de azar caracterizado como jogo do bicho documentado nesse arquivo, o sistema necessitará de usuarios que poderão participar dos sorteios e um
adiministrador que os organizará.
Esses dois serão representados por duas frentes, Sistema adiministrador e Sistema jogadores que controlam e efetuaram suas respectivas competencias, descritas melhor em Visão Geral da Solução.
Contudo, é esperado que o sistema consiga realizar os sorteios e demonstrar quais foram as perdas e ganhos tanto da banca da loteria quanto dos jogadores.

### Visão Geral da Solução

O sistema deve ser dividido em duas frentes distintas: sistema de jogadores e sistema admin. O sistema de jogadores possui como objetivo representar a interface utilizada por uma usuário que irá apostar nos sorteios e participar como cliente do jogo do bicho. O sistema de admin possui como objetivo representar a interface utilizada por um organizador do sorteio do bicho de modo a permitir a criação de sorteios, o acesso aos fundos do sorteio e o pagamento dos jogadores que venham a ganhar.

#### Requisitos do Projeto

- __Realização de sorteios:__ O sistema deve ser capaz de cadastrar e executar sorteios para o jogo do bicho, encontrar as apostas ganhadoras e distribuir a premiação de acordo às regras de monetização das apostas. Os sorteios deverão seguir o modelo do jogo do bicho com diferentes tipos de premiação para diferentes tipos de apostas.

- __Cadastro e funcionamento para usuários:__ O sistema deve ser capaz de cadastrar usuários e permitir o login no sistema de jogos onde esses poderão realizar apostas em sorteios existentes escolhendo entre os diversos modelos de aposta existentes, adicionar fundos às suas carteiras, ver seus históricos de jogos e de entrada/saída de fundos.

- __Tipos de apostas:__ O sistema deve ser capaz de diferenciar o tipo de aposta feita com base em sua regra de classes implementando herança e polimorfismo de acordo à cada tipo de aposta para verificar sua vitória e sua premiação.

- __Interface com o usuário:__ O sistema deve possuir uma interface em terminal capaz de permitir a manipulação dos dados por meio de um usuário jogador ou de um usuário admin possuindo diferentes capacidades para cada um dos tipos de usuário.

#### Requisitos Funcionais - Usuário

1. O sistema deve permitir o cadastro de usuários com login e senha
2. O sistema deve permitir o login de usuários levantando uma seção de operação para estes
3. O sistema deve perimitir que o usuario modifique certas informações pessoais que sua conta possui
4. O sistema deve permitir a entrada e saída de fundos da carteira de usuário com registro das operações
5. O sistema deve permitir a listagem e apresentação dos sorteios existentes
6. O sistema deve perimitir que o usuario consulte sorteios que ele partipou assim como os resultados do mesmo
7. O sistema deve permitir a aposta nos sorteios existentes

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
5. A organização do código e a adesão a boas práticas de programação deve ser essenciais na implementação do projeto.
