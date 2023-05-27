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
  
<br>
<h2>  Implementação </h2> 

<p>  </p>


<h2>Compilação e Execução do Programa</h2>

<p>Através do makefile, é posição utilizar comandos que realizam o processo de compilação e execução do programa. A seguir, temos alguns comandos que podem ser utilizados:</p><br>

* ``` make ```: Realiza a compilação do código por meio do gcc, no qual o resultado vai para a pasta build.</li><br>
* ``` make run ```: Executa o programa armazenado na pasta build após este ser compilado.</li><br>
* ``` make clean ```: Exclui a última compilação feita anteriormente na pasta build.</li><br><br>

<p>Também é possível executar o programa através do site de hospedagem de código, Replit, onde foi realizado a programação do código do "O Labirinto Recorrente": <link>https://replit.com/@OsBrabosSoltos/Trabalho-3-Labirinto#src/main.cpp</link></p>


