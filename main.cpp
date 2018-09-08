#include <iostream>
#include <stdlib.h>
using namespace std;

void printmat(int mat[][8] , int dim);
void q3(int mat[][8] , int Dir[] , int El[], int posD , int &posE , int fi ,int ff ,int ci, int cf);

int main()
{
    int matriz[8][8];
    int Dir[1111];
    int El[65];
    int posD=1;
    int posE=1;
    int fi=0;
    int ff=7;
    int ci=0;
    int cf=7;
    int h=0;
    for (int i=0; i<=7;i++)
        for(int j=0; j<=7;j++)
            matriz[i][j]=h++;

    cout << "Hello world!" << endl;
    printmat(matriz , 8);

    q3(matriz,Dir,El,posD,posE,fi,ci,ff,cf);


    cout<<endl<<endl;
    for (int i=1;i<65;i++)
        cout<<El[i]<<" << ";
    cout<<endl<<endl;

    for (int i=1;i<38;i++)
        cout<<Dir[i]<<" << ";
    return 0;
}

void q3(int mat[][8] , int Dir[] , int El[], int posD , int &posE , int fi ,int ci ,int ff, int cf)
{
    if((ff-fi)!=1)
    {
        int aux;
        cout<<fi<<ff<<ci<<cf<<endl;

        cout<<"Llego con posD: "<<posD<<". Llego con posE: "<<posE<<endl;

        aux = posD*4+1;
        Dir[posD] = aux;
        q3(mat,Dir,El,aux,posE,fi,ci,(fi+ff)/2,(ci+cf)/2);

        aux = (posD+1)*4+1;
        Dir[posD+1] = aux;
        q3(mat,Dir,El,aux,posE,fi,(ci+cf)/2+1,(fi+ff)/2,cf);

        aux = (posD+2)*4+1;
        Dir[posD+2] = aux;
        q3(mat,Dir,El,aux,posE,(fi+ff)/2 +1,ci,ff,(ci+cf)/2);

        aux = (posD+3)*4+1;
        Dir[posD+3] = aux;
        q3(mat,Dir,El,aux,posE,(fi+ff)/2 +1,(ci+cf)/2 +1,ff,cf);

    }
    else{

        El[posE]=mat[fi][ci];
        El[posE+1]=mat[fi][cf];
        El[posE+2]=mat[ff][ci];
        El[posE+3]=mat[ff][cf];

        int aux = posE;



        if(aux > 1)
        {
            aux = aux +12*(posE-1)/4 ;
        }
         posE=posE+4;

        Dir[posD]=(-1)*aux;
        Dir[posD + 1] = (-1)*(aux + 4);
        Dir[posD + 2] = (-1)*(aux + 8);
        Dir[posD + 3] = (-1)*(aux + 12);

        cout<<"pasa con ";
        cout<<fi<<ff<<ci<<cf;
        cout<<" y posD: "<<posD<<"posE: "<<posE<<endl;

    }
}

void printmat(int mat[][8] , int dim)
{
    for(int i = 0 ; i<dim ; i++)
    {
        for(int j = 0 ; j<dim ; j++)
            if(mat[i][j]<=9)
                cout<<"* "<<mat[i][j]<<"  *";
            else
                cout<<"* "<<mat[i][j]<<" *";
        cout<<endl;
    }

}
