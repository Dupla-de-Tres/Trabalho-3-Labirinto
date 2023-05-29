#ifndef LAB_HPP
#define LAB_HPP
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
using namespace std;

typedef struct posr{
  int l;
  int c;
} posr;

class LabRand
{
  private:
    int **mtrx;
    vector<posr> caminho;
    static int passos;
    
  public:
    LabRand();

    void Readfile();
    int Tam();
    void WalkMatrix();
    void CamPerc();
    int Getpassos();
    void resetpassos();
};
#endif