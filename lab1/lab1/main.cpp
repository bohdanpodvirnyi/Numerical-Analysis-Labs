//
//  main.cpp
//  lab1
//
//  Created by hell 'n silence on 9/11/18.
//  Copyright © 2018 Bohdan Podvirnyi. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace std;

const double e = 1.0/10000000;

int i, j, m, k, size, p;
double max_number, temp;

double** max_element(double **a, int k)
{
    double mk=a[k][k];
    int ik=k;
    for (int t = k; t < size; t++)
        if (abs(a[t][k]) > abs(mk))
        {
            mk = a[t][k];
            ik = t;
        }
    if (abs(mk) <= e)
    {
        cout << "matrix has no solution" << endl;
        return 0;
    }
    if (ik != k)
    {
        p++;
        for (int j = 0; j <= size; j++)
        {
            swap(a[ik][j], a[k][j]);
        }
    }
    return a;
}

int calc_matrix(string filename)
{
    p = 0;
    string line;
    ifstream myfile;
    myfile.open(filename);
    if (myfile.is_open())
    {
        int lines = 0;
        int cols = 0;
        while (getline(myfile, line))
        {
            cout << line << endl;
            istringstream iss(line, istringstream::in);
            string word;
            cols = 0;
            while( iss >> word ) { cols++; }
            lines++;
        }
        size = cols;
        double **matrix = new double* [size-2];
        for (int m = 0; m < size-1; m++)
        {
            matrix[m] = new double [cols];
        }
        myfile.close();
        
        myfile.open(filename);
        lines = 0;
        cols = 0;
        while (getline(myfile, line))
        {
            istringstream iss(line, istringstream::in);
            string word;
            cols = 0;
            while( iss >> word )
            {
                matrix[lines][cols] = stod(word);
                cols++;
            }
            lines++;
        }
        myfile.close();
        
        for (int i = 0; i < size-1; i ++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        
        double* x;
        x = (double *)malloc(size* sizeof(double));
        
        for (int k = 0; k < size - 1; k++)
        {
            matrix = max_element(matrix, k);
            if (matrix == 0)
            {
                return 0;
            }
//            for (int i = 0; i < size-1; i ++)
//            {
//                for (int j = 0; j < size; j++)
//                {
//                    cout << matrix[i][j] << " ";
//                }
//                cout << endl;
//            }
//            cout << endl << endl;
            
            // calc m and transform matrix
            for (int i = k + 1; i < size-1; i++)
            {
                double m = (-1) * matrix[i][k] / matrix[k][k];
                for (int j = k; j < size; j++)
                    matrix[i][j] = matrix[i][j] + m * matrix[k][j];
            }
            
            
        }
        
        x[size - 2] = matrix[size - 2][size - 1] / matrix[size - 2][size - 2];
        for (int k = size - 3; k >= 0; k--)
        {
            double sum = 0;
            for (int j = size - 2; j > k; j--)
                sum += matrix[k][j] * x[j];
            x[k] = (matrix[k][size-1] - sum) / matrix[k][k];
        }
        
        // calc det
        double det = 1;
        for (int i = 0; i < size-1; i++)
        {
            det *= matrix[i][i];
        }
        det = det * pow(-1, p);
        
        if (det == 0)
        {
            cout << "matrix has no solution" << endl;
            return 0;
        }
        
        // showing result
        cout << endl << "Result: " << endl;
        cout << "detA = " << det<< endl;
        for (i = 0; i < size - 1; i++)
        {
            cout << "x"<< i + 1 << " = " << x[i] << endl;
        }
    }
    return 0;
}

int main()
{
    string filename = "testing.txt";
    calc_matrix(filename);
    return 0;
}
