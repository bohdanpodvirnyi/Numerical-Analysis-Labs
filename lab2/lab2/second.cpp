////
////  second.cpp
////  lab2
////
////  Created by hell 'n silence on 10/3/18.
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
//int i, j, m, k, size, p;
//double max_number, temp;
//
//void print(double** matrix)
//{
//    cout << "-- -- -- --" << endl;
//    for (int i = 0; i < size-1; i ++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
////double calc_coeff(double a1, double a2, double a3)
////{
////    return (a1 / sqrt(pow(a2, 2) + pow(a3, 2)));
////}
//
//double** rotation(double** matrix)
//{
//    
//    //    for (int q = 0; q < size - 2; q++)
//    //    {
//    //        for (int j = q + 1; j < size - 1; j++)
//    //        {
//    //            double a0 = matrix[q][q];
//    //            for (int i = q; i < size; i++)
//    //            {
//    //                double c = calc_coeff(a0, a0, matrix[j][q]);
//    //                double s = calc_coeff(matrix[j][q], a0, matrix[j][q]);
//    //                matrix[j][i] = (-1) * s * matrix[q][i] + c * matrix[j][i];
//    //                matrix[q][i] = c * matrix[q][i] + s * matrix[j][i];
//    //
//    //            }
//    //            print(matrix);
//    //        }
//    //    }
//    
//    //n-1 етапів прямого ходу
//    double c, s, e, sqrts, elem;
//    for(int q = 0; q < size-1; q++) {
//        for(int j = q + 1; j < size - 1; j++) {
//            sqrts = sqrt(pow(matrix[q][q], 2) + pow(matrix[j][q], 2));
//            c = matrix[q][q] / sqrts;
//            s = matrix[j][q] / sqrts;
//            for(int i = 0; i < size-1+1; i++) {
//                e = matrix[q][i];
//                elem = matrix[j][i];
//                matrix[q][i] = c * e + s * elem;
//                matrix[j][i] = -s * e + c * elem;
//            }
//            print(matrix);
//        }
//    }
//    return matrix;
//}
//
//int calc_matrix(string filename)
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
//            istringstream iss(line, istringstream::in);
//            string word;
//            cols = 0;
//            while( iss >> word ) { cols++; }
//            lines++;
//        }
//        size = cols;
//        double **matrix = new double* [size-2];
//        for (int m = 0; m < size-1; m++)
//        {
//            matrix[m] = new double [cols];
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
//        print(matrix);
//        
//        //прямий хід
//        matrix = rotation(matrix);
//        if (matrix == 0) { return 0; }
//        
//        double* x;
//        x = (double *)malloc(size* sizeof(double));
//        
//        //зворотній хід
//        x[size - 2] = matrix[size - 2][size - 1] / matrix[size - 2][size - 2];
//        for (int k = size - 3; k >= 0; k--)
//        {
//            double sum = 0;
//            for (int j = size - 2; j > k; j--)
//                sum += matrix[k][j] * x[j];
//            x[k] = (matrix[k][size-1] - sum) / matrix[k][k];
//        }
//        
//        // showing result
//        cout << endl << "Result: " << endl;
//        for (i = 0; i < size - 1; i++)
//        {
//            cout << "x"<< i + 1 << " = " << x[i] << endl;
//        }
//    }
//    return 0;
//}
//
//int main()
//{
//    string filename = "test.txt";
//    calc_matrix(filename);
//    return 0;
//}
