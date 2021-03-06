#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


float Ls(float* c,vector<vector<double>> X, vector<double> y)
{
    int cpt=0;
    float s;
    for(int i=0; i<27; i++)
    {
      //produit scalaire
        s=0.0;
        for(int j=0; j<3; j++)
        {
            s=s+c[j]*X[i][j];


        }

        if(s*y[i]<0.0)
        {
            cpt++;

        }

    }

    return (float)cpt/27;

}


int main()
{
    string const nomFichier("test.csv");
    ofstream file(nomFichier.c_str());
    float w[3];
    float s;

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

    w[0]=0;
    w[1]=1;
    w[2]=1;

    float ws[3];
    float erreur_old;
    float erreur;

    //initialisation ws
    for(int q=0; q<3; q++)
    {
        ws[q]=w[q];

    }


    for(int i=0; i<1000; i++)
    {

        erreur_old=Ls(ws,X,y);


        for(int j=0; j<27; j++)
        {
            s=0;
            for(int e=0; e<3; e++)
            {
                s=s+w[e]*X[j][e];
            }

            if(s*y[j]<0)
            {

                for(int z=0; z<3; z++)
                {
                    w[z]=w[z]+X[j][z]*y[j];

                }

            }

        }
                erreur=Ls(w,X,y);

                if(erreur<erreur_old)
                {
                    for(int k=0; k<3; k++)
                    {
                        ws[k]=w[k];

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
    for(int i=0; i<27; i++)
    {
        for(int j=0; j<3; j++)
        {
            file<<X[i][j];
            if(i==0)
            {
                file<<";";
                file<<ws[j];
            }
            if(f<27)
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
        cout << ws[i] << endl;

    return 0;
}


    /*vector<vector<double>> X
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
*/


	/*
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
*/

