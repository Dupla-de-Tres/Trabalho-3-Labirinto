#ifndef LABPROF_HPP
#define LABPROF_HPP
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
using namespace std;

typedef struct posp{
  int l;
  int c;
} posp;

class LabProf
{
  private:
    vector<posp> caminho;
    vector<posp> pilha;
    static int passos;
    
  public:
    LabProf();

    void Readfile();
    int Tam();
    void WalkMatrix(int **mtrx);
    unsigned short int SetCam(int **mtrx, int i, int j, unsigned short int move, int rsize);
    bool VerCam(int i, int j);
    bool VerPilha(int i, int j);
    void CamPerc();
    int Getpassos();
    void resetpassos();
};
#endif