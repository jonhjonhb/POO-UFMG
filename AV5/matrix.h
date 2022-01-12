#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

class Matrix {
    private:

        double** m;
        int nRows;
        int nCols;

    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, const double &value = 0.0);
        Matrix(std::ifstream &myFile);
        Matrix(const Matrix& that);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows()const{return nRows;}
        int getCols()const{return nCols;}
        double get(int row, int col)const;
        
        // other methods
        void fillWith(const double &value);
        void print() const;
        void unit();
        void zeros(){this->fillWith(0.0);}
        void ones(){this->fillWith(1.0);}
        double& operator()(const int rows, const int cols);
        Matrix operator+(const Matrix& matrixData)const;
        Matrix& operator-=(const Matrix& matrixData);
        Matrix operator-(const Matrix& matrixData);
        Matrix& operator+=(const Matrix& matrixData);
        Matrix operator~();
        Matrix& operator*=(const double& multiplicateData);
};

#endif