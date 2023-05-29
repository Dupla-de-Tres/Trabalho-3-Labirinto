#include "LabirintoProf.hpp"
int LabProf::passos=0;

LabProf::LabProf()
{}

void LabProf::Readfile()
{
  ifstream matt;
  int size=Tam(), i, j;
  float a;

  matt.open("dataset/input.data");
  matt >> a >> a;

  char **mtr=new char*[size];
  for (i=0; i<size; i++)
    mtr[i]=new char[size];

  for (i=0; i<a; i++)
  {
    for (j=0; j<a; j++)
    {
      matt >> mtr[i][j];
    }
  }

  for (i=0; i<a; i++)
  {
    for (j=0; j<a; j++)
    {
      cout << mtr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  matt.close();

  int **mtrx=new int*[size];
  for (i=0; i<size; i++)
    mtrx[i]=new int[size];

  for (i=0; i<size; i++)
  {
    for (j=0; j<size; j++)
    {
      if (mtr[i][j]=='*')
        mtrx[i][j] = -1;
      else if (mtr[i][j]=='#')
        mtrx[i][j] = -2;
      else if (mtr[i][j]=='?')
        mtrx[i][j] = 0;
      else
        mtrx[i][j] = 1;
    }
  }
  WalkMatrix(mtrx);
}

int LabProf::Tam()
{
  ifstream tam;
  char e;

  tam.open("dataset/input.data");
  int size;

  tam >> e;
  size = e - '0';

  tam.close();

  return size;
}

void LabProf::WalkMatrix(int **mtrx)
{
  unsigned short int yy=1, zz=1, move=1, gg=0, vr, nmove;
  int rsize=6, im=0, jm=0, nn;
  posp elm;

  while (yy==1)
  {
    if (gg==0)
    {
      if (mtrx[im][jm]==1)
      {
        zz=1;
        elm.l=im;
        elm.c=jm;
        caminho.push_back(elm);
        pilha.push_back(elm);
      }
      else if (mtrx[im][jm]==-1)
      {
        zz=0;
        mtrx[im][jm]=1;
        im=0;
        jm=0;
        caminho.clear();
        pilha.clear();
        move=1;
      }
      else if (mtrx[im][jm]==0)
      {
        zz=0;
        yy=0;
        elm.l=im;
        elm.c=jm;
        caminho.push_back(elm);
      }
      passos++;
    }

    if (zz==1)
    {
      gg=1;
      switch (move)
      {
        case 1:
          if (mtrx[im][jm+1]!=-2 && jm<rsize && !VerCam(im,jm+1) && !VerPilha(im,jm+1))
          {
            jm+=1;
            gg=0;
          }
          break;
        case 2:
          if (mtrx[im+1][jm]!=-2 && im<rsize && !VerCam(im+1,jm) && !VerPilha(im+1,jm))
          {
            im+=1;
            gg=0;
          }
          break;
        case 3:
          if (mtrx[im][jm-1]!=-2 && jm>0 && !VerCam(im,jm-1) && !VerPilha(im,jm-1))
          {
            jm-=1;
            gg=0;
          }
          break;
        case 4:
          if (mtrx[im-1][jm]!=-2 && im>0 && !VerCam(im-1,jm) && !VerPilha(im-1,jm))
          {
            im-=1;
            gg=0;
          }
          break;
      }
    }
    
    if (gg==1)
    {
      vr=1;
      while (vr!=0)
      {
        nmove=SetCam(mtrx, im,jm,move,rsize);
        if (nmove==0)
        {
          pilha.pop_back();
          passos++;
          nn=pilha.size();
          im=pilha[nn].l;
          jm=pilha[nn].c;
        }
        else
        {
          vr=0;
          move=nmove;
          gg=0;
        }
      }
    } 
  }
  for (int i=0; i<rsize; i++)
    delete[] mtrx[i];
  delete[] mtrx;
}

unsigned short int LabProf::SetCam(int **mtrx, int i, int j, unsigned short int move, int rsize)
{
  int nmove=0;
  if (move==1 || move==3)
  {
    if (mtrx[i+1][j]!=-2 && i<rsize && !VerCam(i+1,j) && !VerPilha(i+1,j))
      nmove=2;
    else if (mtrx[i-1][j]!=-2 && i>0 && !VerCam(i-1,j) && !VerPilha(i-1,j))
      nmove=4;
  }
  else
  {
    if (mtrx[i][j+1]!=-2 && j<rsize && !VerCam(i,j+1) && !VerPilha(i,j+1))
      nmove=1;
    else if (mtrx[i][j-1]!=-2 && j>0 && !VerCam(i,j-1) && !VerPilha(i,j-1))
      nmove=3;
  }
  return nmove;
}

bool LabProf::VerCam(int i, int j)
{
  for (long unsigned int b=0; b<caminho.size(); b++)
  {
    if (i==caminho[b].l && j==caminho[b].c)
      return true;
  }
  return false;
}

bool LabProf::VerPilha(int i, int j)
{
  for (long unsigned int b=0; b<pilha.size(); b++)
  {
    if (i==pilha[b].l && j==pilha[b].c)
      return true;
  }
  return false;
}

void LabProf::CamPerc()
{
  int size=Tam(), i, j;
  cout << "\n---CAMINHO PERCORRIDO---" << endl;
  cout << "@ : posicao acessada, X : nao acessada" << endl << endl;
  
  char **mtr=new char*[size];
  for (i=0; i<size; i++)
    mtr[i]=new char[size];

  for (i=0; i<size; i++)
  {
    for (j=0; j<size; j++)
    {
      mtr[i][j] = 'X';
    }
  }

  for (long unsigned int b=0; b<caminho.size(); b++)
  {
    i=caminho[b].l;
    j=caminho[b].c;
    mtr[i][j] = '@';
  }

  ofstream matt;

  matt.open("dataset/output.data");
  matt << size << " " << size << endl;

  for (i=0; i<size; i++)
  {
    for (j=0; j<size; j++)
    {
      matt << mtr[i][j] << " ";
      cout << mtr[i][j] << " ";
     }
    matt << endl;
    cout << endl;
  }
  matt << endl;
  cout << endl;
}

int LabProf::Getpassos()
{
  return passos;
}

void LabProf::resetpassos()
{
  passos=0;
}