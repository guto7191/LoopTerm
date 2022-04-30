# LoopTerm


<div align="justify">LoopTerm foi um trabalho de faculdade proposto pelo professor de processamento de dados 2(PD2). O jogo utiliza a linguagem C, pois é a linguagem   que é ministrada em PD2, basicamente o LoopTerm foi  inspirado no Term.ooo famoso jogo das palavras, no jogo Term o jogador tem que adivinhar uma palavra de 5 letras     usando outras palavras para chegar na palavra secreta. Quando o usuário digita uma palavra há três possibilidades para cada letra da palavra digitada, verde indica que   a letra pertence a palavra e está no posição certa, amarelo indica que a letra pertence a palavra, mas está na posição errada e a cor preta que indica que a letra não   pertence a palavra secreta. Com essa mecânica o jogador pode chegar a palavra secreta partindo de outras palavras. 
</div>

<br>
<br>

<div align = "center">
    <img src = "https://github.com/guto7191/LoopTerm/blob/master/imagem/img9.png"> 
</div>

<br>
<br>

<div align = "justify">
No LoopTerm, mantém-se a mesma mecânica para chegar ao resultado da palavra, o único detalhe que muda é que caso o jogador acerte a palavra secreta o programa vai     gerar uma nova palavra dando mais 6 tentativas para o usuário e isso se repete até que o jogador erre a palavra,  se o jogador acertar as palavras secretas no final da   partida o programa pedirá o seu nome e salvará sua pontuação em um arquivo .txt, caso o jogador não acerte nenhuma palavra ele não poderá registrar seu nome no    arquivo.
  <br>
  <br>
  A tela inicial do LoopTerm é um menu com duas opções: uma de mostrar o ranking do jogo e outra que vai direto para a partida.
</div>

<br>

<div>
    <img src = "https://github.com/guto7191/LoopTerm/blob/master/imagem/img1.png">
</div>

<br>
<br>

<div align = "justify">
   Quando o usuário digita 1:
</div>

<br>

<div>
    <img src = "https://github.com/guto7191/LoopTerm/blob/master/imagem/img2.png">
</div>

<br>
<br>

<div align = "justify">
   Quando o usuário digita 2:
</div>
<br>
<div>
    <img src = "https://github.com/guto7191/LoopTerm/blob/master/imagem/img3.png">
</div>

<br>
<br>

<div align = "justify">
     Para simular a mecânica  das cores do Term.ooo foi utilizado os caracteres ‘ * ’,  ‘ + ’   e ‘ - ’  o asterisco representa a letra na posição certa, o mais            representa a letra pertence a palavra, mas está na posição errada e o menos representa a letra não pertence a palavra. Quando o usuário digita uma palavra o jogo      imprime em baixo da palavra digitada a condição de cada letra.
</div>

<br>

<div>
    <img src = "https://github.com/guto7191/LoopTerm/blob/master/imagem/img4.png">
</div>


<br>
<br>

<div align = "justify">
   Quando o jogador acerta é mostrado sua pontuação e uma nova palavra é gerada  e suas 6 tentativas são inicializadas novamente.
</div>

<br>

<div>
    <img src = "https://github.com/guto7191/LoopTerm/blob/master/imagem/img5.png">
</div>

<br>
<br>

<div align = "justify">
  Quando o usuário perde, se ele tiver acertado pelo menos uma palavra a sua pontuação será salva no arquivo do ranking.
</div>

<br>

<div>
    <img src = "https://github.com/guto7191/LoopTerm/blob/master/imagem/img6.png">
</div>

<br>
<br>

<div align = "justify">
  Se o jogador digitar uma palavra inválida ou uma palavra que não esteja listada no arquivo txt que estão as palavras secretas uma mensagem será mostrada na tela        informado que a palavra é inválida.  

<br>
<br>

</div>
     <img src = "https://github.com/guto7191/LoopTerm/blob/master/imagem/img7.png">
<div>

<br>
<br>

<div align = "justify">
 Se o jogador digitar uma palavra com um carácter inválido, será mostrado uma mensagem indicando que a palavra digitada apresenta caracteres inválidos. 

<br>
<br>

</div>
     <img src = "https://github.com/guto7191/LoopTerm/blob/master/imagem/img8.png">
<div>

## 
  
<br>
  
<div align = "justify">
  O LoopTerm foi meu primeiro grande projeto e realmente não apresenta as melhores condições de desempenho e arquitetura de software, mas tenho muito orgulho dele       principalmente pelo aprendizado obtido durante a produção e as dificuldades que possibilitaram-me ver como complexo e radical é o mundo da computação. Como metas     para   próxima atualização do jogo irei implementar um sistema ranking que leve em consideração a pontuação do jogador, pois o atual funciona mais como um registro   de jogadores que pontuaram,e uma nova interface (interface de terminal), para deixar um pouco mais elegante, fluido. 
</div>

