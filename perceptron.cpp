#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;




int main()
{
    float X[8][3],w[3],s;
    int y[8];
    int n=8;
    int m=3;
    int cpt=0;
    float Ls;
    string const nomFichier("test.csv");
    ofstream file(nomFichier.c_str());

    X[0][0]=1;
    X[0][1]=-0.22;
    X[0][2]=0.51;
    X[1][0]=1;
    X[1][1]=-0.64;
    X[1][2]=0.37;
    X[2][0]=1;
    X[2][1]=-0.82;
    X[2][2]=-0.16;
    X[3][0]=1;
    X[3][1]=-0.22;
    X[3][2]=0.04;
    X[4][0]=1;
    X[4][1]=0.47;
    X[4][2]=0.23;
    X[5][0]=1;
    X[5][1]=-0.47;
    X[5][2]=-0.84;
    X[6][0]=1;
    X[6][1]=0.16;
    X[6][2]=-0.62;
    X[7][0]=1;
    X[7][1]=0.41;
    X[7][2]=-0.25;


    w[0]=0;
    w[1]=1;
    w[2]=1;


    y[0]=1;
    y[1]=1;
    y[2]=1;
    y[3]=1;
    y[4]=-1;
    y[5]=-1;
    y[6]=-1;
    y[7]=-1;

    do
    {
        cpt=0;
        for(int i=0; i<n; i++)
        {
            s=0;
            for(int j=0; j<m; j++)
            {
                s=s+w[j]*X[i][j];
            }

            if(s*y[i]<0)
            {
                cpt++;

                for(int z=0; z<m; z++)
                {
                    w[z]=w[z]+X[i][z]*y[i];
                }
            }

        }
    }
    while((float)cpt/n != 0.0);
    int f=0;
    file<<"X";
    file<<";";
    file<<"W";
    file<<";";
    file<<"Y";
    file<<"\n";
    for(int i=0; i<n*3; i++)
    {
        for(int j=0; j<m; j++)
        {
            file<<X[i][j];
            if(i==0)
            {
                file<<";";
                file<<w[j];
            }
            if(f<n*8)
            {
                if(i==0)
                {
                    file<<";";
                }
                else
                {
                    file<<";";
                    file<<";";
                }
                file<<y[f];
                f++;
            }
            file<< " \n";
        }



    }

    for(int i=0; i<3; i++)
    {
        cout<<w[i]<<endl;

    }
    return 0;
}
