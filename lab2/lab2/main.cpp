//
//  main.cpp
//  lab2
//
//  Created by hell 'n silence on 10/2/18.
//  Copyright © 2018 Bohdan Podvirnyi. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace std;

int i, j, m, k, size, p;
double max_number, temp;

void print(double** matrix)
{
    cout << "-- -- -- --" << endl;
    for (int i = 0; i < size-1; i ++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double** rotation(double** matrix)
{
    //n-1 етапів прямого ходу
    double c, s, first, second, coeff;
    for(int q = 0; q < size - 1; q++) {
        for(int j = q + 1; j < size - 1; j++) {
            coeff = sqrt(pow(matrix[q][q], 2) + pow(matrix[j][q], 2));
            c = matrix[q][q] / coeff;
            s = matrix[j][q] / coeff;
            for(int i = 0; i < size; i++) {
                first = matrix[q][i];
                second = matrix[j][i];
                matrix[q][i] = c * first + s * second;
                matrix[j][i] = -s * first + c * second;
                p++;
            }
//            print(matrix);
        }
    }
    return matrix;
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
        
        print(matrix);
        
        //прямий хід
        matrix = rotation(matrix);
        
        print(matrix);
        
        double* x;
        x = (double *)malloc(size* sizeof(double));
        
        //зворотній хід
        x[size - 2] = matrix[size - 2][size - 1] / matrix[size - 2][size - 2];
        for (int k = size - 3; k >= 0; k--)
        {
            double sum = 0;
            for (int j = size - 2; j > k; j--)
                sum += matrix[k][j] * x[j];
            x[k] = (matrix[k][size-1] - sum) / matrix[k][k];
        }
        
        double det = 1;
        for (int i = 0; i < size-1; i++)
        {
            det *= matrix[i][i];
        }
        
        if (det == 0)
        {
            cout << "matrix has no solution" << endl;
            return 0;
        }
        
        //результат
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
    string filename = "test.txt";
    calc_matrix(filename);
    return 0;
}
