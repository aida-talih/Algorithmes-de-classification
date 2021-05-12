#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


int signe(  vector<vector<double>> X, vector<double> w,int k){
             double s=0;
             for(int j=0;j<w.size();j++){

                 s=s+w[j]*X[k][j];

                 }
                 if(s>=0){
                 return 1;
                 }
                 else
                   return -1;
}

int main()
{

     float s;
     int cpt=0;
     float moy;
     float e;
     string const nomFichier("test.csv");
     ofstream file(nomFichier.c_str());

  vector<vector<double>> X
    {
        {1.0,0.0, 2.0},
        {1.0,1.0, 0.0},
        {1.0,1.0, 1.0},
        {1.0,1.0, 2.0},
        {1.0,1.0, 3.0},
        {1.0,1.0, 3.5},
        {1.0,2.0, 1.0},
        {1.0,2.0, 2.0},
        {1.0,2.0, 3.0},
        {1.0,2.0, 3.5},
        {1.0,3.0, 0.0},
        {1.0,3.0, 2.0},
        {1.0,2.7, 3.3},
        {1.0,4.0, 1.0},
        {1.0,1.0, 4.0},
        {1.0,2.0, 4.0},
        {1.0,2.0, 5.0},
        {1.0,2.5, 3.0},
        {1.0,2.5, 4.0},
        {1.0,3.0, 3.0},
        {1.0,3.0, 4.5},
        {1.0,3.0, 6.0},
        {1.0,4.0, 2.5},
        {1.0,4.0, 3.5},
        {1.0,4.0, 5.0},
        {1.0,5.0, 2.0},
        {1.0,5.0, 3.0},
        {1.0,5.0, 4.0},
    };

 vector<double> y
    {
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0,
        -1.0
    };

vector<double> w
    {
        0.0,
        1.0,
        1.0
    };



     /*
X[0][0]=1;X[0][1]=2;X[0][2]=1;
X[1][0]=1;X[1][1]=3;X[1][2]=1;
X[2][0]=1;X[2][1]=3;X[2][2]=2;
X[3][0]=1;X[3][1]=4;X[3][2]=2;
X[4][0]=1;X[4][1]=1;X[4][2]=2;
X[5][0]=1;X[5][1]=2;X[5][2]=2;
X[6][0]=1;X[6][1]=2;X[6][2]=3;
X[7][0]=1;X[7][1]=3;X[7][2]=3;

w[0]=0;w[1]=1;w[2]=1;


y[0]=-1;y[1]=-1;y[2]=-1;y[3]=-1;y[4]=1;y[5]=1;y[6]=1;y[7]=1;

*/

for(int z=0;z<2000;z++)

{
        for(int i=0;i<X.size();i++){


                 e=y[i]-signe(X,w,i);


                 if(e!=0){
                         for(int k=0;k<w.size();k++){
                            w[k]=w[k]+2*e*X[i][k];
                    }

                 }

             }
        }




  int f=0;
    file<<"X";
    file<<";";
    file<<"W";
    file<<";";
    file<<"Y";
    file<<"\n";
    for(int i=0; i<X.size(); i++)
    {
        for(int j=0; j<w.size(); j++)
        {
            file<<X[i][j];
            if(i==0)
            {
                file<<";";
                file<<w[j];
            }
            if(f<X.size())
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

for(int i=0;i<w.size();i++){
    cout<<w[i]<<endl;

}
    return 0;
}
