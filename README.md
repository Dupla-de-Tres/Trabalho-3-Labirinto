# Trabalho 3 - Labirinto(BFS e DFS)
Trabalho 3 de AEDS - Labirinto Randômico, por Largura(BFS) e Profundidade(DFS), implementado em C++


<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/mpiress/midpy/issues">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
</a> 
</div>

<p> </p>
<p> </p>

<h2>  Introdução </h2>

<p> No mundo atual, é possível solucionar um mesmo problema através de diferentes formas, especialmente na área da programação. Com isso, o trabalho do Labirinto foi resolvido através de três formas distintas, visando testar qual labirinto irá percorrer a matriz com o menor tempo e também com o menor custo computacional.  </p>

* ``` Labirinto Randômico ```: O usuário seleciona uma posição da matriz, inserindo uma linha e uma coluna. A partir disso, o programa irá analisar as posições que não contenham um bloqueio de caminho para, depois, sortear uma posição para ser percorrida, até que se encontre o ponto de saída (?).

* ``` Labirinto por Profundidade(DFS) ```: O programa começa percorrendo a matriz a partir da primeira posição, e tende a seguir um caminho em linha reta, começando pela horizontal - direita. Caso não seja encontrado o ponto de saída (?), o sistema irá percorrer em linha reta até bater em uma parede, no qual será realizado o cálculo para caminhar em um percurso não realizado anteriormente.

* ``` Labirinto por Largura(BFS) ```: O programa começa percorrendo a matriz a partir da primeira posição, e logo depois pula para a segunda posição da linha, permanecendo na primeira coluna, até a segunda posição da coluna, na primeira posição da linha. O programa continua percorrendo nesse sentido diagonalmente, começando por baixo e terminando em cima até encontrar o ponto de saída (?). Caso haja alguma parede bloqueando o caminho diagonal, será realizado um novo caminho desviando da parede e voltando para a diagonal original. Ademais, se houver um perigo neste caminho. o proornar para a posição inicial.

<br>
<h2>  Objetivo </h2>

<p> Para vencer o labirinto através das três formas de implementação de percurso, é necessário chegar ao ponto de saída (?) através de caminhos livres para passagem (1), no qual serão enfrentados bloqueios de caminhos, representados por paredes (#) e perigos (*), que retorna a pessoa para a posição inicial. 
  
<p> Uma vez testado a passagem pelos três labirintos, será analisado qual foi o método de passagem no labirinto que teve o menor tempo e o menor custo computacional. No final de cada teste, é apresentado os caminhos que foram percorridos e se o ponto de saída foi alcançado.
  
<h2> Movimentação </h2>  
  
<p> pode caminhar pela direita, esquerda, acima, abaixo, diagonal inferior esquerda, diagonal inferior direita, diagonal superior esquerda e diagonal superior direita</p>  
  
  
<p> </p> 
<h2>  Implementação </h2> 

* ``` Posição das matrizes ```: Foram representadas por uma struct "pos" que verifica a posição atual da matriz que está sendo percorrida. A struct foi utilizada nos três tipos de labirinto.

* ``` Labirinto Randômico ```: Foi necessário a utilização de apenas um vector implementado em uma classe para executar o Labirinto Randômico.

* ``` Labirinto por Profundidade(DFS) ```:

* ``` Labirinto por Largura(BFS) ```: Foram necessários a utilização de dois vectors e uma fila, implementados em uma classe, para realizar a implementação do Labirinto por Largura(BFS).

<h2>Arquivos </h2>

* ``` main.cpp ```: Arquivo e função principal do sistema que recebe os arquivos das classes dos três labirintos para execução do programa;
* ``` Labirinto.hpp ```: Arquivo que cria as funções utilizadas no labirinto randômico;
* ``` Labirinto.cpp ```: Arquivo que implementa as funções criadas no Labirinto.hpp;
* ``` LabirintoLarg.hpp ```: Arquivo que cria as funções utilizadas no labirinto por largura(BFS);
* ``` LabirintoLarg.cpp ```: Arquivo que implementa as funções criadas no LabirintoLarg.hpp;
* ``` LabirintoProf.hpp ```: Arquivo que cria as funções utilizadas no labirinto por profundidade(DFS);
* ``` LabirintoProf.cpp ```: Arquivo que implementa as funções criadas no LabirintoProf.hpp;
* ``` input.data ```: Contém os labirintos utilizados no programa;
* ``` output.data ```: Exibe o resultado do labirinto após ser percorrido.

<h2>Funções </h2>

<h3> Labirinto Randômico: </h3>

* ``` void ReadFile(); ```: Lê o arquivo que contém a matriz; 
* ``` int Tam(); ```: Lê o tamanho da matriz;
* ``` void WalkMatrix(); ```: Caminha pela matriz de forma aleatória. O sistema realiza um sorteio de 0 a 7 para obter a posição no qual a pessoa irá caminhar. Ela pode caminhar pelas oito posições detalhadas no tópico Movimentação. Com o número obtido, o sistema irá, através do switch case, realizar o caminhamento através do número sorteado. 
* ``` void CamPerc(); ```: Esta função pega cada movimento realizado pela função WalkMatrix e demarca o caminho percorrido com "X" e o caminho não percorrido com "@". Logo depois, ela printa a matriz para mostrar o resultado final após o caminhamento pelo labirinto, indicando se o ponto final foi alcançado ou não.

<h3> Labirinto por Largura(BFS): </h3>

* ``` void ReadFile(); ```: Lê o arquivo que contém a matriz; 
* ``` int Tam(); ```: Lê o tamanho da matriz;
* ``` void WalkMatrix(); ```: Caminha pela matriz a partir de sua largura. 
* ``` void CamPerc(); ```: Esta função pega cada movimento realizado pela função WalkMatrix e demarca o caminho percorrido com "X" e o caminho não percorrido com "@". Logo depois, ela printa a matriz para mostrar o resultado final após o caminhamento pelo labirinto, indicando se o ponto final foi alcançado ou não.
* ``` bool VerFila(int i, int j); ```: Verifica e mostra a fila armazenada no vector fila
* ``` bool VerCam(int i, int j); ```: Verifica e mostra o caminho armazenado no vector caminho

<h3> Labirinto por Profundidade(DFS): </h3>

* ``` void ReadFile(); ```: Lê o arquivo que contém a matriz; 
* ``` int Tam(); ```: Lê o tamanho da matriz;
* ``` void WalkMatrix(); ```: Caminha pela matriz a partir de sua largura. 
* ``` void CamPerc(); ```: Esta função pega cada movimento realizado pela função WalkMatrix e demarca o caminho percorrido com "X" e o caminho não percorrido com "@". Logo depois, ela printa a matriz para mostrar o resultado final após o caminhamento pelo labirinto, indicando se o ponto final foi alcançado ou não.
* ``` bool VerFila(int i, int j); ```:
* ``` bool VerCam(int i, int j); ```:

<h2>Compilação e Execução do Programa</h2>

<p>Através do makefile, é posição utilizar comandos que realizam o processo de compilação e execução do programa. A seguir, temos alguns comandos que podem ser utilizados:</p><br>

* ``` make ```: Realiza a compilação do código por meio do gcc, no qual o resultado vai para a pasta build.</li><br>
* ``` make run ```: Executa o programa armazenado na pasta build após este ser compilado.</li><br>
* ``` make clean ```: Exclui a última compilação feita anteriormente na pasta build.</li><br><br>

<p>Também é possível executar o programa através do site de hospedagem de código, Replit, onde foi realizado a programação do código do "O Labirinto Recorrente": <link>https://replit.com/@OsBrabosSoltos/Trabalho-3-Labirinto#src/main.cpp</link></p>


