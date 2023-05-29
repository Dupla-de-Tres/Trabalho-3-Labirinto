#ifndef LABLARG_HPP
#define LABLARG_HPP
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
using namespace std;

typedef struct pos{
  int l;
  int c;
} pos;

class LabLarg
{
  private:
    int **mtrx;
    vector<pos> fila;
    vector<pos> caminho;
    static int passos;
    
  public:
    LabLarg();

    void Readfile();
    int Tam();
    void WalkMatrix();
    bool VerFila(int i, int j);
    bool VerCam(int i, int j);
    void CamPerc();
    void Output();
    void remove();
    int Getpassos();
    void resetpassos();
};
#endif