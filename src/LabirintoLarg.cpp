#include "LabirintoLarg.hpp"
int LabLarg::passos=0;

LabLarg::LabLarg()
{}

void LabLarg::Readfile()
{
  ifstream matt;
  int a, size=Tam(), i, j;

  matt.open("dataset/input.data");
  matt >> a >> a;

  char **mtr=new char*[size];
  for (i=0; i<size; i++)
    mtr[i]=new char[size];

  for (i=0; i<size; i++)
  {
    for (j=0; j<size; j++)
    {
      matt >> mtr[i][j];
    }
  }

  for (i=0; i<size; i++)
  {
    for (j=0; j<size; j++)
    {
      cout << mtr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  matt.close();

  mtrx=new int*[size];
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
}

int LabLarg::Tam()
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

void LabLarg::WalkMatrix()
{
  unsigned short int yy=1, zz=1;
  int rsize=Tam()-1, im=0, jm=0;
  pos elm;

  while (yy==1)
  {
    passos++;
    if (mtrx[im][jm]==1)
    {
      zz=1;
      elm.l=im;
      elm.c=jm;
      caminho.push_back(elm);
    }
    else if (mtrx[im][jm]==-1)
    {
      zz=0;
      mtrx[im][jm]=1;
      im=0;
      jm=0;
      fila.clear();
      caminho.clear();
    }
    else if (mtrx[im][jm]==0)
    {
      zz=0;
      yy=0;
      elm.l=im;
      elm.c=jm;
      caminho.push_back(elm);
    }

    if (zz==1)
    {
      if (jm<rsize)
      {
        if (!VerFila(im,jm+1) && !VerCam(im,jm+1) && mtrx[im][jm+1]!=-2)
        {
          elm.l=im;
          elm.c=jm+1;
          fila.push_back(elm);
        }
      }
      
      if (im<rsize)
      {
        if (!VerFila(im+1,jm) && !VerCam(im+1,jm) && mtrx[im+1][jm]!=-2)
        {
          elm.l=im+1;
          elm.c=jm;
          fila.push_back(elm);
        }
      }

      if (jm>0)
      {
        if (!VerFila(im,jm-1) && !VerCam(im,jm-1) && mtrx[im][jm-1]!=-2)
        {
          elm.l=im;
          elm.c=jm-1;
          fila.push_back(elm);
        }
      }

      if (im>0)
      {
        if (!VerFila(im-1,jm) && !VerCam(im-1,jm) && mtrx[im-1][jm]!=-2)
        {
          elm.l=im-1;
          elm.c=jm;
          fila.push_back(elm);
        }
      }

      im=fila[0].l;
      jm=fila[0].c;
      fila.erase(fila.begin());
    }
  }
}

bool LabLarg::VerFila(int i, int j)
{
  for (long unsigned int b=0; b<fila.size(); b++)
  {
    if (i==fila[b].l && j==fila[b].c)
      return true;
  }
  return false;
}

bool LabLarg::VerCam(int i, int j)
{

  for (long unsigned int b=0; b<caminho.size(); b++)
  {
    if (i==caminho[b].l && j==caminho[b].c)
      return true;
  }
  return false;
}

void LabLarg::CamPerc()
{
  int size=Tam(), i, j;
  cout << "\n---CAMINHO PERCORRIDO---" << endl;
  cout << "@ : posicao acessada, X : nao acessada" << endl << endl;

  char **mtr=new char*[size];
  for (i=0; i<size; i++)
    mtr[i]=new char[size];

  for (i=0; i<size; i++)
    delete[] mtrx[i];
  delete[] mtrx;

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

int LabLarg::Getpassos()
{
  return passos;
}

void LabLarg::resetpassos()
{
  passos=0;
}