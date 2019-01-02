////
////  main.cpp
////  lab1
////
////  Created by hell 'n silence on 9/11/18.
////  Copyright © 2018 Bohdan Podvirnyi. All rights reserved.
////
//
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <fstream>
//#include <sstream>
//
//using namespace std;
//
//string filename = "test1.txt";
//int i, j, m, k, size, p;
//double max_number, temp;
//
//int main()
//{
//    p = 0;
//    string line;
//    ifstream myfile;
//    myfile.open(filename);
//    if (myfile.is_open())
//    {
//        int lines = 0;
//        int cols = 0;
//        while (getline(myfile, line))
//        {
//            cout << line << endl;
//            istringstream iss(line, istringstream::in);
//            string word;
//            cols = 0;
//            while( iss >> word ) { cols++; }
//            lines++;
//        }
//        size = lines;
//        double **matrix = new double* [size+1];
//        for (int m = 0; m < size; m++)
//        {
//            matrix[m] = new double [cols+1];
//        }
//        myfile.close();
//        
//        myfile.open(filename);
//        lines = 0;
//        cols = 0;
//        while (getline(myfile, line))
//        {
//            istringstream iss(line, istringstream::in);
//            string word;
//            cols = 0;
//            while( iss >> word )
//            {
//                matrix[lines][cols] = stod(word);
//                cols++;
//            }
//            lines++;
//        }
//        myfile.close();
//        
//        // check if matrix is written right
//        //        for (int i = 0; i < 4; i ++)
//        //        {
//        //            for (int j = 0 ; j < 4; j++)
//        //            {
//        //                cout << matrix[i][j] << " ";
//        //            }
//        //            cout << endl;
//        //        }
//        
//        double* x;
//        x = (double *)malloc(size* sizeof(double));
//        
//        for (int k = 0; k < size - 1; k++)
//        {
//            // search for max element
//            max_number = abs(matrix[k][k]);
//            i = k;
//            for(m = k + 1; m < size; m++)
//            {
//                if(abs(matrix[m][k]) > max_number)
//                {
//                    i = m;
//                    max_number = abs(matrix[m][k]);
//                }
//            }
//            
//            // check if max is 0 -> matrix has no solution
//            if (max_number == 0)
//            {
//                cout << "Error" << endl;
//                return 0;
//            }
//            
//            // calc m and transform matrix
//            for (int i = k + 1; i < size; i++)
//            {
//                double m = (-1) * matrix[i][k] / matrix[k][k];
//                for (int j = k; j < size + 1; j++)
//                    matrix[i][j] = matrix[i][j] + m * matrix[k][j];
//            }
//        }
//        x[size - 1] = matrix[size - 1][size] / matrix[size - 1][size - 1];
//        for (int k = size - 2; k >= 0; k--)
//        {
//            double sum = 0;
//            for (int j = size - 1; j > k; j--)
//                sum += matrix[k][j] * x[j];
//            x[k] = (matrix[k][size] - sum) / matrix[k][k];
//        }
//        
//        //        for (k = 0; k < size; k++)
//        //        {
//        //            // search for max element
//        //            max_number = abs(matrix[k][k]);
//        //            i = k;
//        //            for(m = k + 1; m < size; m++)
//        //            {
//        //                if(abs(matrix[m][k]) > max_number)
//        //                {
//        //                    i = m;
//        //                    max_number = abs(matrix[m][k]);
//        //                }
//        //            }
//        //
//        //            // check if max is 0 -> matrix has no solution
//        //            if (max_number == 0)
//        //            {
//        //                cout << "Error" << endl;
//        //                return 0;
//        //            }
//        //
//        //            //  swap()
//        //            if (i != k)
//        //            {
//        //                for (j = k; j < size + 1; j++)
//        //                {
//        //                    swap(matrix[k][j], matrix[i][j]);
//        //                    p++;
//        //                }
//        //            }
//        //
//        //            // calc m (multipliers)
//        //            max_number = matrix[k][k];
//        //            matrix[k][k] = 1;
//        //            for (j = k + 1; j < size + 1; j++)
//        //            {
//        //                matrix[k][j] = matrix[k][j] / max_number;
//        //            }
//        //
//        //            // transforming all lines with k-line
//        //            for (i = k + 1; i < size; i++)
//        //            {
//        //                temp = matrix[i][k];
//        //                matrix[i][k] = 0;
//        //                if (temp != 0)
//        //                {
//        //                    for (j = k + 1; j < size + 1; j++)
//        //                    {
//        //                        matrix[i][j] = matrix[i][j] - temp * matrix[k][j];
//        //                    }
//        //                }
//        //            }
//        //        }
//        //
//        //        // calc result
//        //        for (i = size - 1; i >= 0; i--)
//        //        {
//        //            x[i] = 0;
//        //            max_number = matrix[i][size];
//        //            for (j = size; j > i; j--)
//        //            {
//        //                max_number = max_number - matrix[i][j] * x[j];
//        //            }
//        //            x[i] = max_number;
//        //        }
//        
//        
//        // calc det
//        double det = 1;
//        for (int i = 0; i < size; i++)
//        {
//            det *= matrix[i][i];
//        }
//        det = det * pow(-1, p);
//        
//        // showing result
//        cout << "Result: " << endl;
//        cout << "detA = " << det<< endl;
//        for (i = 0; i<  size; i++)
//        {
//            cout << "x"<< i + 1 << " = " << x[i] << ", ";
//        }
//    }
//    return 0;
//}
