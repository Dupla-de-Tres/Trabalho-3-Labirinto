#include <bits/stdc++.h>
#include "Labirinto.hpp"
#include "LabirintoProf.hpp"
#include "LabirintoLarg.hpp"

using namespace std;

int main() 
{
  LabProf lp;
  LabRand lr;
  LabLarg ll;

  cout << "--SIMULAÇÃO DO LABIRINTO COM 3 MÉTODOS--\n";
  cout << "\n----Método 1 - Randômico----\n\n";
  lr.resetpassos();
  lr.Readfile();
  lr.WalkMatrix();
  lr.CamPerc();
  cout << "\n----Método 2 - Profundidade----\n\n";
  lp.resetpassos();
  lp.Readfile();
  lp.CamPerc();
  cout << "\n----Método 3 - Largura----\n\n";
  ll.resetpassos();
  ll.Readfile();
  ll.WalkMatrix();
  ll.CamPerc();
  cout << "\n----Resultados---\n\n";
  cout << "Randômico: " << lr.Getpassos() << " passos" << endl;
  cout << "Profundidade: " << lp.Getpassos() << " passos" << endl;
  cout << "Largura: " << ll.Getpassos() << " passos" << endl;
  
  return 0;
}