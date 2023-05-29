#include "Labirinto.hpp"
int LabRand::passos=0;

LabRand::LabRand()
{}

void LabRand::Readfile()
{
  ifstream matt;
  int a, size=Tam(), i, j;

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

int LabRand::Tam()
{
  int size;
  ifstream tam;

  tam.open("dataset/input.data");

  tam >> size;

  tam.close();

  return size;
}

void LabRand::WalkMatrix()
{
  unsigned short int move;
  int im=0, jm=0, rsize=Tam()-1;
  posr elm;

  while (mtrx[im][jm]!=0)
  {
    move=1+rand()%8;
    elm.l=im;
    elm.c=jm;
    caminho.push_back(elm);
    passos++;
    
    switch(move)
    {
      case 1:
        if (im>0 && jm<rsize)
        {
          if (mtrx[im-1][jm+1]>=0)
          {
            im--;
            jm++;
          }
          else if (mtrx[im-1][jm+1]==-1)
          {
            mtrx[im-1][jm+1] = 1;
            im=0;
            jm=0;
            caminho.clear();
          }
        }
        break;
      case 2:      
        if (jm<rsize)  
        {
          if (mtrx[im][jm+1]>=0)
            jm++;
          else if (mtrx[im][jm+1]==-1)
          {
            mtrx[im][jm+1] = 1;
            im=0;
            jm=0;
            caminho.clear();
          }
        }
        break;
      case 3: 
        if (im<rsize && jm<rsize)
        {
          if (mtrx[im+1][jm+1]>=0)
          {
            im++;
            jm++;
          }
          else if (mtrx[im+1][jm+1]==-1)
          {
            mtrx[im+1][jm+1] = 1;
            im=0;
            jm=0;
            caminho.clear();
          }
        }
        break;
      case 4:
        if (im<rsize)
        {
          if (mtrx[im+1][jm]>=0)
            im++;
          else if (mtrx[im+1][jm]==-1)
          {
            mtrx[im+1][jm] = 1;
            im=0;
            jm=0;
            caminho.clear();
          }
        }
        break;  
      case 5:    
        if (im<rsize && jm>0)
        {
          if (mtrx[im+1][jm-1]>=0)
          {
            im++;
            jm--;
          }
          else if (mtrx[im+1][jm-1]==-1)
          {
            mtrx[im+1][jm-1] = 1;
            im=0;
            jm=0;
            caminho.clear();
          }
        }
        break;
      case 6:
        if (jm>0)
        {
          if (mtrx[im][jm-1]>=0)
            jm--;
          else if (mtrx[im][jm-1]==-1)
          {
            mtrx[im][jm-1] = 1;
            im=0;
            jm=0;
            caminho.clear();
          }
        }
        break;
      case 7:
        if (im>0 && jm>0)
        {
          if (mtrx[im-1][jm-1]>=0)
          {
            im--;
            jm--;
          }
          else if (mtrx[im-1][jm-1]==-1)
          {
            mtrx[im-1][jm-1] = 1;
            im=0;
            jm=0;
            caminho.clear();
          }
        }
        break;
      case 8:
        if (im>0)
        {
          if (mtrx[im-1][jm]>=0)
            im--;
          else if (mtrx[im-1][jm]==-1)
          {
            mtrx[im-1][jm] = 1;
            im=0;
            jm=0;
            caminho.clear();
          }
        }
        break;
    }
  }
  elm.l=im;
  elm.c=jm;
  caminho.push_back(elm);
}

void LabRand::CamPerc()
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

int LabRand::Getpassos()
{
  return passos;
}

void LabRand::resetpassos()
{
  passos=0;
}
